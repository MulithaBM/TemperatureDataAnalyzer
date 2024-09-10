/*
* Program Name: TemperatureDataAnalyzer
* Programmer: MulithaBM
* File: DataHandler.h
* Date: 2024-05-12
* Description: Header file for the class that acts as the command class
*/

#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <vector>
#include <string>
#include "TemperatureData.h"

using namespace std;

static const string LOG_FILE = "log.txt";

class DataHandler
{
public:
	static DataHandler& getInstance();
	void handleDataByYear(const vector<vector<vector<Temperature>>>& allData, const string source);
	void handleDataPerYear(const vector<vector<Temperature>>& yearData);
	void handleDataByMonth(const vector<vector<vector<Temperature>>>& allData, int month);
	void addLogMessage(const string message);
private:
	static DataHandler* handler;
	vector<string> logMessages;
	DataHandler() = default;
	static void prepareWriteDataByYear(const vector<vector<vector<Temperature>>>& allData, const string source);
	static string getMonthString(const int month);
	void logData();
};

#endif