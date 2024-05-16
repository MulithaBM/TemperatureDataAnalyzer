#ifndef TEMPERATUREDATA_H
#define TEMPERATUREDATA_H

#include <string>
#include <vector>
#include <map>

using namespace std;

struct Temperature {
    int year;
    int month;
    int day;
    double temperature;
};

class TemperatureData {
public:
    TemperatureData(const string filename);
    const vector<int>& getYears() const;
    const vector<vector<Temperature>>& getYearData(const int year) const;
    const vector<vector<vector<Temperature>>>& getData() const;
    int getRows() const;
    int getColumns() const;
    string getStartDate() const;
    string getEndDate() const;
private:
    int startYear = -1;
    int startMonth = -1;
    int startDate = -1;
    int endYear = -1;
    int endMonth = -1;
    int endDate = -1;
    vector<int> years;
    int rows = 0;
    int columns = 0;
    vector<vector<vector<Temperature>>> data;
    static void clearYearData(vector<vector<Temperature>>& yearData);
};

#endif