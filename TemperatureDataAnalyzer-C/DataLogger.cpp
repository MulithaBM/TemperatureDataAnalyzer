/*
* Program Name: TemperatureDataAnalyzer
* Programmer: MulithaBM
* File: DataLogger.cpp
* Date: 2024-05-12
* Description: Method implementations for the DataLogger class
*/

#include <iostream>
#include <fstream>

#include "DataLogger.h"

using namespace std;

/*
* Function: DataLogger constructor
* Parameters: Log file name
*/
DataLogger::DataLogger(const string filename)
{
    logFile.open(filename, ios::app); // Open the file in append mode

    // Check if the file is open
    if (!logFile.is_open()) {
        cerr << "Failed to open log file: " << filename << endl; // If unable to open, print error message
    }
}

/*
* Function: Log data to the file
* Parameters: Log message
*/
void DataLogger::logData(const string message)
{
    // Check if the file is not null and open
    if (logFile && logFile.is_open()) {
        logFile << message << endl; // Write the message to the file
    }
    else {
        std::cerr << "Log file is not open. Message: " << std::endl; // If file is null or cannot be opened, print error message
    }
}

/*
* Function: Close the log file
*/
void DataLogger::closeFile()
{
    // Check if the file is not null and open
    if (logFile && logFile.is_open()) {
        logFile.close(); // Close the file
    }
}
