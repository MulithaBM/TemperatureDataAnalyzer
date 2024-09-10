/*
* Program Name: TemperatureDataAnalyzer
* Programmer: MulithaBM
* File: TemperatureData.cpp
* Date: 2024-05-12
* Description: Method implementations for the TemperatureData class
*/

#include <fstream>
#include <sstream>
#include <iostream>
#include "TemperatureData.h"
#include "DataVisualizer.h"

using namespace std;

/*
* Function: Constructor for the TemperatureData class
* Parameters: Dataset filename
*/
TemperatureData::TemperatureData(const string filename) {
    ifstream file(filename); // Open the file

    // Check if the file is open
    if (!file.is_open()) {
        DataVisualizer::displayMessage("Error opening file: " + filename); // If unable to open the file, display an error message
        exit(1); // Exit the program
    }

    int currentYear = -1; // Initialize the current year
    int currentMonth = -1; // Initialize the current month

    vector<vector<Temperature>> year(12); // Initialize a vector of 12 months
    vector<Temperature> month; // Initialize a vector of temperatures for a month

    string line; // Initialize a string to store the line read from the file

    getline(file, line); // Read the first line of the file
    rows++; // Increment the number of rows

    // Read the data from the file
    while (getline(file, line)) {
        stringstream ss(line); // Initialize a string stream to read the line
        string token; // Initialize a string to store the token
        vector<string> tokens; // Initialize a vector of strings to store the tokens

        // Split the line by commas
        while (getline(ss, token, ',')) {
            tokens.push_back(token); // Add the token to the vector
        }

        // Check if the end of the line is a comma
        if (ss.eof() && line.back() == ',') {
            tokens.push_back(""); // Add an empty string to the vector
        }

        // Check if the number of columns is 0
        if (columns == 0) {
            columns = tokens.size(); // Set the number of columns
        }

        // Check if there are at least 6 tokens
        if (tokens.size() >= 6) {
            // Check if the tokens are not empty
            if (!tokens[2].empty() && !tokens[3].empty() && !tokens[4].empty() && !tokens[5].empty()) {
                Temperature temp{}; // Initialize a temperature object

                // Loop through the tokens
                for (int i = 2; i < 6; i++) {
                    try {
                        // Check if the column is the temperature column
                        if (i == 5) {
                            double dTest = stod(tokens[i]); // Convert the token to a double
                        }
                        else {
                            int iTest = stoi(tokens[i]); // Convert the token to an integer
                        }
                    }
                    catch (const invalid_argument& e) {
                        DataVisualizer::displayMessage("Invalid data in file: " + filename + " at row: " + to_string(rows + 1) + " at column: " + to_string(i + 1)); // Display an error message if the data is invalid
                        exit(1); // Exit the program
                    }
                }

                temp.year = stoi(tokens[2]); // Set the year
                temp.month = stoi(tokens[3]); // Set the month
                temp.day = stoi(tokens[4]); // Set the day
                temp.temperature = stod(tokens[5]); // Set the temperature

                // Check if the year and month is less than 0
                if (currentYear == -1 && currentMonth == -1) {
                    currentYear = temp.year; // Set the current year
                    currentMonth = temp.month; // Set the current month

                    // Check if the year is less than 0
                    if (startYear < 0) {
                        startYear = currentYear; // Set the start year
                    }

                    // Check if the month is less than 0
                    if (startMonth < 0) {
                        startMonth = currentMonth; // Set the start month
                    }
                }

                // Check for month changes
                if (temp.month != currentMonth) {
                    year[currentMonth - 1] = month; // Add the month to the year

                    month.clear(); // Clear the month data

                    currentMonth = temp.month; // Set the current month
                }

                // Check for year changes
                if (temp.year != currentYear) {
                    data.push_back(year); // Add the year to the data
                    years.push_back(currentYear); // Add the year to the years

                    clearYearData(year); // Clear the year data

                    currentYear = temp.year; // Set the current year
                    currentMonth = temp.month; // Set the current month
                }

                // Check for start date
                if (startDate < 0) {
                    startDate = temp.day; // Set the start date
                }

                month.push_back(temp); // Add the temperature to the month
            }
        }

        rows++; // Increment the number of rows
    }

    year[currentMonth - 1] = month; // Adding the last month

    data.push_back(year); // Add the last year to the data
    years.push_back(currentYear); // Add the last year to the years

    endYear = currentYear; // Set the end year
    endMonth = currentMonth; // Set the end month
    endDate = month.back().day; // Set the end date

    file.close(); // Close the file
}

/*
* Function: Get all the years in the file
*/
const vector<int>& TemperatureData::getYears() {
    return years;
}

/*
* Function: Get the data for a specific year
* Parameters: Year
*/
const vector<vector<Temperature>>& TemperatureData::getYearData(const int year) {
    return data[year - startYear];
}

/*
* Function: Get all the data of the file
*/
const vector<vector<vector<Temperature>>>& TemperatureData::getData() {
    return data;
}

/*
* Function: Get the number of rows in the file
*/
int TemperatureData::getRows() {
    return rows;
}

/*
* Function: Get the number of columns in the file
*/
int TemperatureData::getColumns() {
    return columns;
}

/*
* Function: Get the start date of the file
*/
string TemperatureData::getStartDate() {
    return to_string(startYear) + "-" + to_string(startMonth) + "-" + to_string(startDate);
}

/*
* Function: Get the end date of the file
*/
string TemperatureData::getEndDate() {
	return to_string(endYear) + "-" + to_string(endMonth) + "-" + to_string(endDate);
}

/*
* Function: Clear the data of a year
* Parameters: 2D vector of year data
*/
void TemperatureData::clearYearData(vector<vector<Temperature>>& yearData) {
    // Loop through the months
    for (vector<Temperature>& month : yearData) {
		month.clear(); // Clear the month data
	}
}
