#ifndef DATAVISUALIZER_H
#define DATAVISUALIZER_H

#include <vector>
#include "TemperatureData.h"

using namespace std;

static const int avgTempWidth = 20;
static const int SDWidth = 20;
static const int tempWidth = 13;
static const int yearWidth = 6;
static const int monthWidth = 6;
static const int dayWidth = 6;

class DataVisualizer
{
public:
	/*DataVisualizer(const string logFileName);*/
	static void displayTopic(string message);
	static void displayRowsAndColumns(const int rows, const int columns);
	static void displayStartAndEndDate(const string startDate, const string endDate);
	static void displayYears(const vector<int>& years);
	static void displayDataPerYear(const vector<vector<Temperature>>& yearData);
	static void displayDataByYear(const vector<vector<vector<Temperature>>>& allData);
	static void displayDataByMonth(const vector<vector<vector<Temperature>>>& allData, int month);
private:
	/*static Logger logger;*/

	static void displayHottestDayPerYear(const vector<vector<Temperature>>& yearData);
	static void displayHottestDayByYear(const vector<vector<vector<Temperature>>>& allData);

	static void displayColdestDayPerYear(const vector<vector<Temperature>>& yearData);
	static void displayColdestDayByYear(const vector<vector<vector<Temperature>>>& allData);

	static void displayMeanTemperaturePerYear(const vector<vector<Temperature>>& yearData);
	static void displayMeanTemperatureByYear(const vector<vector<vector<Temperature>>>& allData);

	static void displayMedianTemperaturePerYear(const vector<vector<Temperature>>& yearData);
	static void displayMedianTemperatureByYear(const vector<vector<vector<Temperature>>>& allData);

	static void displayModeTemperaturePerYear(const vector<vector<Temperature>>& yearData);
	static void displayModeTemperatureByYear(const vector<vector<vector<Temperature>>>& allData);

	static void displayColdestMeanTemperatureMonthPerYear(const vector<vector<Temperature>>& yearData);
	static void displayColdestMeanTemperatureMonthByYear(const vector<vector<vector<Temperature>>>& allData);

	static void displayHottestMeanTemperatureMonthPerYear(const vector<vector<Temperature>>& yearData);
	static void displayHottestMeanTemperatureMonthByYear(const vector<vector<vector<Temperature>>>& allData);

	static void displayLowestVarienceMonthPerYear(const vector<vector<Temperature>>& yearData);
	static void displayLowestVarienceMonthByYear(const vector<vector<vector<Temperature>>>& allData);

	static void displayStandardDeviationPerYear(const vector<vector<Temperature>>& yearData);
	static void displayStandardDeviationByYear(const vector<vector<vector<Temperature>>>& allData);

	static void displayColdestDayByMonth(const vector<vector<vector<Temperature>>>& allData, int month);
	static void displayHottestDayByMonth(const vector<vector<vector<Temperature>>>& allData, int month);

	static int getCurrentYear(const vector<vector<Temperature>>& yearData);
};

#endif