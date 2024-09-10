/*
* Program Name: TemperatureDataAnalyzer
* Programmer: MulithaBM
* File: DataAnalyzer.h
* Date: 2024-05-12
* Description: Header file for the class that analyzes the temperature data
*/

#ifndef DATAANALYZER_H
#define DATAANALYZER_H

#include <vector>
#include "TemperatureData.h"

using namespace std;

static const double MIN_TEMPERATURE = -273.15;
static const double MAX_TEMPERATURE = numeric_limits<double>::max();

struct VarienceMonth {
    int month;
    double mean;
	double variance;
};

class DataAnalyzer {
public:
    static Temperature hottestDayOfYear(const vector<vector<Temperature>>& yearData);
    static Temperature hottestDayOfMonth(const vector<Temperature>& monthData);
    static Temperature coldestDayOfYear(const vector<vector<Temperature>>& yearData);
    static Temperature coldestDayOfMonth(const vector<Temperature>& monthData);
    static double meanTemperatureOfYear(const vector<vector<Temperature>>& yearData);
    static double meanTemperatureOfMonth(const vector<Temperature>& monthData);
    static double medianTemperatureOfYear(const vector<vector<Temperature>>& yearData);
    static double medianTemperatureOfMonth(const vector<Temperature>& monthData);
    static Temperature hottestMeanTemperatureMonthOfYear(const vector<vector<Temperature>>& yearData);
    static Temperature coldestMeanTemperatureMonthOfYear(const vector<vector<Temperature>>& yearData);
    static double modeTemperatureOfYear(const vector<vector<Temperature>>& yearData);
    static double varienceOfMonth(const vector<Temperature>& monthData);
    static VarienceMonth lowestVarianceMonthOfYear(const vector<vector<Temperature>>& yearData);
    static double standardDeviationOfYear(const vector<vector<Temperature>>& yearData);
    static double percentageOfDaysWithinOneSD(const vector<vector<Temperature>>& yearData, const double standardDeviation);
    static Temperature coldestDayByMonth(const vector<vector<vector<Temperature>>>& allData, int month);
    static Temperature hottestDayByMonth(const vector<vector<vector<Temperature>>>& allData, int month);
    static int lowestVarianceYearByMonth(const vector<vector<vector<Temperature>>>& allData, int month);
private:
    static int getCurrentYear(const vector<vector<Temperature>>& yearData);
};

#endif