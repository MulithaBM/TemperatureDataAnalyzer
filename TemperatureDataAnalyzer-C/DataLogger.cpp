#include <iostream>
#include <fstream>

#include "DataLogger.h"

using namespace std;

DataLogger::DataLogger(const string filename)
{
    logFile.open(filename, ios::app);

    if (!logFile.is_open()) {
        cerr << "Failed to open log file: " << filename << endl;
    }
}

void DataLogger::logData(const string message)
{
    if (logFile && logFile.is_open()) {
        logFile << message << endl;
    }
    else {
        std::cerr << "Log file is not open. Message: " << std::endl;
    }
}

void DataLogger::closeFile()
{
    if (logFile) {
        if (logFile.is_open()) {
            logFile.close();
        }
    }
}
