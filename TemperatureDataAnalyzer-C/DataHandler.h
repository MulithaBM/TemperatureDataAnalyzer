#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <vector>
#include <string>
#include "TemperatureData.h"

using namespace std;

static const string LOG_FILE = "../x64/Debug/log.txt";

class DataHandler
{
public:
	static DataHandler& getInstance();
	void handleDataByYear(const vector<vector<vector<Temperature>>>& allData);
	void handleDataPerYear(const vector<vector<Temperature>>& yearData);
	void handleDataByMonth(const vector<vector<vector<Temperature>>>& allData, int month);
	void addLogMessage(const string message);
private:
	DataHandler() {};
	static DataHandler* handler;
	vector<string> logMessages;
	static void prepareWriteData(const vector<vector<vector<Temperature>>>& allData);
	static string getMonthString(const int month);
	void logData();
};

#endif