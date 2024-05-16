#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <vector>
#include "TemperatureData.h"

using namespace std;

class DataHandler
{
public:
	static void HandleDataByYear(const vector<vector<vector<Temperature>>>& allData);
	static void HandleDataPerYear(const vector<vector<Temperature>>& yearData);
	static void HandleDataByMonth(const vector<vector<vector<Temperature>>>& allData, int month);
private:
	static void PrepareWriteData(const vector<vector<vector<Temperature>>>& allData);
	static string getMonthString(const int month);
};

#endif