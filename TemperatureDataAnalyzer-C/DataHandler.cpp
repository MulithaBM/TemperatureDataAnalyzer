#include<sstream>
#include "DataHandler.h"
#include "DataVisualizer.h"
#include "DataAnalyzer.h"
#include "DataWriter.h"
#include "DataLogger.h"

using namespace std;

DataHandler& DataHandler::getInstance()
{
	if (handler == nullptr) {
		handler = new DataHandler();
	}

	return *handler;
}

void DataHandler::handleDataByYear(const vector<vector<vector<Temperature>>>& allData)
{
	DataVisualizer::displayDataByYear(allData);

	prepareWriteData(allData);

	logData();
}

void DataHandler::handleDataPerYear(const vector<vector<Temperature>>& yearData)
{
	DataVisualizer::displayDataPerYear(yearData);

	logData();
}

void DataHandler::handleDataByMonth(const vector<vector<vector<Temperature>>>& allData, int month)
{
	DataVisualizer::displayDataByMonth(allData, month);

	logData();
}

void DataHandler::addLogMessage(const string message)
{
	logMessages.push_back(message);
}

void DataHandler::prepareWriteData(const vector<vector<vector<Temperature>>>& allData)
{
    DataWriter dataWriter;

    int currentYear = 0;
    int currentMonth = 1;

    for (const vector<vector<Temperature>>& year : allData) {
        vector<string> outputData;

        for (const vector<Temperature>& month : year) {
            stringstream row;

            if (month.empty()) {
                row << getMonthString(currentMonth) << "," << "" << "," << "" << "," << "" << "," << "";
            }
            else {
                currentYear = month[0].year;

                double hottest = DataAnalyzer::hottestDayOfMonth(month).temperature;
                double coldest = DataAnalyzer::coldestDayOfMonth(month).temperature;
                double mean = DataAnalyzer::meanTemperatureOfMonth(month);
                double median = DataAnalyzer::medianTemperatureOfMonth(month);

                row << getMonthString(currentMonth) << ","
                    << hottest << ","
                    << coldest << ","
                    << mean << ","
                    << median;
            }

            outputData.push_back(row.str());

            currentMonth++;
        }

        currentMonth = 1;

        dataWriter.writeDataPerYear(outputData, to_string(currentYear) + ".csv");
    }
}

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

void DataHandler::logData()
{
	DataLogger logger(LOG_FILE);

	for (const string& message : logMessages) {
		logger.logData(message);
	}

	logger.closeFile();
}
