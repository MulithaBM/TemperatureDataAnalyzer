/*
* Program Name: TemperatureDataAnalyzer
* Programmer: Vasim Ashhar
* File: DataHandler.cpp
* Date: 2024-05-12
* Description: Method implementations for the DataHandler class
*/

#include<sstream>
#include "DataHandler.h"
#include "DataVisualizer.h"
#include "DataAnalyzer.h"
#include "DataWriter.h"
#include "DataLogger.h"

using namespace std;

DataHandler* DataHandler::handler = nullptr; // initialize static property

// public members

/*
* Function: get a reference to the DataHandler instance
* Return: DataHandler instance reference
*/
DataHandler& DataHandler::getInstance()
{
	if (handler == nullptr) {
		handler = new DataHandler();
	}

	return *handler;
}

/*
* Function: handle of each year
* Parameters: 3D vector of all the data for each year and source of the data
*/
void DataHandler::handleDataByYear(const vector<vector<vector<Temperature>>>& allData, const string source)
{
	DataVisualizer::displayDataByYear(allData); // display data to console

	prepareWriteDataByYear(allData, source); // prepare data to write to log file

	logData(); // log data to log file
}

/*
* Function: handle data for a single year
* Parameters: 2D vector of all the data for a single year
*/
void DataHandler::handleDataPerYear(const vector<vector<Temperature>>& yearData)
{
	DataVisualizer::displayDataPerYear(yearData); // display data to console

	logData(); // log data to log file
}

/*
* Function: handle data for a given month in all the years
* Parameters: 3D vector of all the data for each year and month and specific month
*/
void DataHandler::handleDataByMonth(const vector<vector<vector<Temperature>>>& allData, int month)
{
	DataVisualizer::displayDataByMonth(allData, month); // display data to console

	logData(); // log data to log file
}

/*
* Function: add log messages to the logMessages vector
* Parameters: message to log
*/
void DataHandler::addLogMessage(const string message)
{
	logMessages.push_back(message);
}

// private members

/*
* Function: prepare data to write to log file for all the years
* Parameters: 3D vector of all the data for each year and source of the data and the dataset source
*/
void DataHandler::prepareWriteDataByYear(const vector<vector<vector<Temperature>>>& allData, const string source)
{
    DataWriter dataWriter(source); // create a DataWriter instance

    int currentYear = 0; // initialize current year
    int currentMonth = 1; // initialize current month

    for (const vector<vector<Temperature>>& year : allData) {
        vector<string> outputData; // declare output data vector

        for (const vector<Temperature>& month : year) {
            stringstream row; // declare a stringstream for a row

            if (month.empty()) {
                row << getMonthString(currentMonth) << "," << "" << "," << "" << "," << "" << "," << ""; // write empty row
            }
            else {
                currentYear = month[0].year; // set current year

                double hottest = DataAnalyzer::hottestDayOfMonth(month).temperature; // get hottest day of the month
                double coldest = DataAnalyzer::coldestDayOfMonth(month).temperature; // get coldest day of the month
                double mean = DataAnalyzer::meanTemperatureOfMonth(month); // get mean temperature of the month
                double median = DataAnalyzer::medianTemperatureOfMonth(month); // get median temperature of the month

                row << getMonthString(currentMonth) << ","
                    << hottest << ","
                    << coldest << ","
                    << mean << ","
                    << median; // write row
            }

            outputData.push_back(row.str()); // add row to output data

            currentMonth++; // increment current month
        }

        currentMonth = 1; // reset current month

        dataWriter.writeDataPerYear(outputData, to_string(currentYear) + ".csv"); // write data to file
    }
}

/*
* Function: get month string
* Parameters: month number
* Return: month string
*/
string DataHandler::getMonthString(const int month)
{
    switch (month) {
	case 1:
		return "January";
	case 2:
		return "February";
	case 3:
		return "March";
	case 4:
		return "April";
	case 5:
		return "May";
	case 6:
		return "June";
	case 7:
		return "July";
	case 8:
		return "August";
	case 9:
		return "September";
	case 10:
		return "October";
	case 11:
		return "November";
	case 12:
		return "December";
	default:
		return "Invalid month";
	}
}

/*
* Function: log data to log file
*/
void DataHandler::logData()
{
	DataLogger logger(LOG_FILE); // create a DataLogger instance

	// loop through log messages
	for (const string& message : logMessages) {
		logger.logData(message); // log message
	}

	logger.closeFile(); // close log file
}
