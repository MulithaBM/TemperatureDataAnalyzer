#ifndef DATALOGGER_H
#define DATALOGGER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class DataLogger
{
public:
	DataLogger(const string filename);
	void logData(const string message);
	void closeFile();
private:
	ofstream logFile;
};

#endif