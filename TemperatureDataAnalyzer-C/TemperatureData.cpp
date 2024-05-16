#include <fstream>
#include <sstream>
#include <iostream>
#include "TemperatureData.h"

using namespace std;

TemperatureData::TemperatureData(const string filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }

    int currentYear = -1;
    int currentMonth = -1;

    vector<vector<Temperature>> year(12);
    vector<Temperature> month;

    string line;

    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;

        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (ss.eof() && line.back() == ',') {
            tokens.push_back("");
        }

        if (columns == 0) {
            columns = tokens.size();
        }

        if (tokens.size() >= 6) {
            Temperature temp{};

            for (string token : tokens) {
                if (token.empty()) {
					continue;
				}
			}

            try {
                temp.year = stoi(tokens[2]);
                temp.month = stoi(tokens[3]);
                temp.day = stoi(tokens[4]);
                temp.temperature = stod(tokens[5]);
            }
            catch (const invalid_argument& e) {
                continue;
                /*cerr << "Invalid data in file: " << filename << " at row: " << data.size() + 1 << endl;*/ // TODO: include column number
            }

            // Initialy set current year and month
            if (currentYear == -1 && currentMonth == -1) {
                currentYear = temp.year;
                currentMonth = temp.month;

                if (startYear < 0) {
					startYear = currentYear;
				}

                if (startMonth < 0) {
                    startMonth = currentMonth;
                }
            }

            // Check for month changes
            if (temp.month != currentMonth) {
                year[currentMonth - 1] = month;

                month.clear();

                currentMonth = temp.month;
            }

            // Check for year changes
            if (temp.year != currentYear) {
                data.push_back(year);
                years.push_back(currentYear);

                clearYearData(year);

                currentYear = temp.year;
                currentMonth = temp.month;
            }

            if (startDate < 0) {
				startDate = temp.day;
			}

            month.push_back(temp);

            rows++;
        }
    }

    // Adding the last month of the last year
    year[currentMonth - 1] = month;

    // Adding the last year
    data.push_back(year);
    years.push_back(currentYear);

    endYear = currentYear;
    endMonth = currentMonth;
    endDate = month.back().day;

    file.close();
}

const vector<int>& TemperatureData::getYears() const
{
    return years;
}

const vector<vector<Temperature>>& TemperatureData::getYearData(const int year) const
{
    return data[year - startYear];
}

const vector<vector<vector<Temperature>>>& TemperatureData::getData() const
{
    return data;
}

int TemperatureData::getRows() const {
    return rows;
}

int TemperatureData::getColumns() const {
    return columns;
}

string TemperatureData::getStartDate() const
{
    return to_string(startYear) + "-" + to_string(startMonth) + "-" + to_string(startDate);
}

string TemperatureData::getEndDate() const
{
	return to_string(endYear) + "-" + to_string(endMonth) + "-" + to_string(endDate);
}

void TemperatureData::clearYearData(vector<vector<Temperature>>& yearData) {
    for (vector<Temperature>& month : yearData) {
		month.clear();
	}
}
