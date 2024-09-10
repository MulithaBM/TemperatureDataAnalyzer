/*
* Program Name: TemperatureDataAnalyzer
* Programmer: MulithaBM
* File: DataVisualizer.cpp
* Date: 2024-05-12
* Description: Method implementations for the DataVisualizer class
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include "DataVisualizer.h"
#include "DataHandler.h"
#include "DataAnalyzer.h"
#include "DataWriter.h"

using namespace std;

//DataVisualizer::DataVisualizer(const string logFileName) {
//    logger = Logger(logFileName);
//}

// Public members

/*
* Function: display the welcome message
*/
void DataVisualizer::displayWelcomeMessage()
{
    displayMessage("Turing Moore Engineering Temperature Data Analyser 1.0");
    displayMessage("Name: MulithaBMr");
    displayMessage("Student ID: DU23FP0248");
    displayMessage("Assignment due date: 17/05/2024");
    displayMessage("Desired Level: HD\n");

    displayMessage("Welcome! This program helps determine the best times of year to manufacture composite halls for new boats based on temperature data\n");
}

/*
* Function: display the file selection message
*/
void DataVisualizer::displayFileSelectionMessage()
{
    string fileSelectionMessage = "Please choose a data file (Enter file name in lowercase. Dont type any whitespaces or special characters):\n\n";

    fileSelectionMessage += "1. Avalon\n";
    fileSelectionMessage += "2. Bendigo\n";

    displayMessage(fileSelectionMessage);
}

/*
* Function: add a new empty line
*/
void DataVisualizer::displayNewLine()
{
    displayMessage("\n");
}

/*
* Function: display information
* Parameters: information
*/
void DataVisualizer::displayMessage(string message)
{
    cout << message << endl;

    DataHandler& dataHandler = DataHandler::getInstance();

    dataHandler.addLogMessage(message);
}

/*
* Function: display the input message
* Parameters: input message
*/
void DataVisualizer::displayInputMessage(string message)
{
    cout << message;

    DataHandler& dataHandler = DataHandler::getInstance();

    dataHandler.addLogMessage(message);
}

/*
* Function: display a topic
* Parameters: topic
*/
void DataVisualizer::displayTopic(string topic)
{
    displayMessage("<< " + topic + " >>" + "\n");
}

/*
* Function: display rows and columns
* Parameters: number of rows and columns
*/
void DataVisualizer::displayRowsAndColumns(const int rows, const int columns)
{
    displayMessage("Rows: " + to_string(rows));
    displayMessage("Columns: " + to_string(columns) + "\n");
}

/*
* Function: display the start and end date
* Parameters: start date and end date
*/
void DataVisualizer::displayStartAndEndDate(const string startDate, const string endDate)
{
    displayMessage("Start date: " + startDate);
	displayMessage("End date: " + endDate + "\n");
}

/*
* Function: display the list of years
* Parameters: vector of years
*/
void DataVisualizer::displayYears(const vector<int>& years)
{
    displayTopic("Years in the file");

    for (const int& year : years) {
        displayMessage(to_string(year));
	}

    displayNewLine();
}

/*
* Function: display the data of a single year
* Parameters: 2D vector of the year data
*/
void DataVisualizer::displayDataPerYear(const vector<vector<Temperature>>& yearData)
{
    displayHottestDayPerYear(yearData);
    displayColdestDayPerYear(yearData);
    displayMeanTemperaturePerYear(yearData);
    displayMedianTemperaturePerYear(yearData);
    displayModeTemperaturePerYear(yearData);
    displayColdestMeanTemperatureMonthPerYear(yearData);
    displayHottestMeanTemperatureMonthPerYear(yearData);
    displayLowestVarienceMonthPerYear(yearData);
    displayStandardDeviationPerYear(yearData);
}

/*
* Function: display the data of each year
* Parameters: 3D vector of all the data
*/
void DataVisualizer::displayDataByYear(const vector<vector<vector<Temperature>>>& data)
{
    displayHottestDayByYear(data);
    displayColdestDayByYear(data);
    displayMeanTemperatureByYear(data);
    displayMedianTemperatureByYear(data);
    displayModeTemperatureByYear(data);
    displayColdestMeanTemperatureMonthByYear(data);
    displayHottestMeanTemperatureMonthByYear(data);
    displayLowestVarienceMonthByYear(data);
    displayStandardDeviationByYear(data);
}

/*
* Function: display the data of a given month in all the years
* Parameters: 3D vector of all the data and the month
*/
void DataVisualizer::displayDataByMonth(const vector<vector<vector<Temperature>>>& data, int month)
{
    displayHottestDayByMonth(data, month);
	displayColdestDayByMonth(data, month);
    displayLowestVarienceYearByMonth(data, month);
}

// Private members

/*
* Function: display the hottest day of the year
* Parameters: 2D vector of the year data
*/
void DataVisualizer::displayHottestDayPerYear(const vector<vector<Temperature>>& data)
{
    Temperature hottest = DataAnalyzer::hottestDayOfYear(data); // calculate the hottest day of the year

    displayTopic("Hottest temperature"); // display the topic

    displayMessage("Temperature: " + to_string(hottest.temperature) + "\n");
    displayMessage("Date: " + to_string(hottest.year) + "-" + to_string(hottest.month) + "-" + to_string(hottest.day) + "\n\n");
}

/*
* Function: display the hottest day of each year
* Parameters: 3D vector of all the data
*/
void DataVisualizer::displayHottestDayByYear(const vector<vector<vector<Temperature>>>& data)
{
    displayTopic("Hottest temperature by year"); // display the topic
    
    stringstream header;

    header << setw(yearWidth) << left << "Year"
        << setw(monthWidth) << left << "Month"
        << setw(dayWidth) << left << "Day"
        << setw(tempWidth) << left << "Temperature";

    displayMessage(header.str()); // display the header

    // loop through the data
    for (const vector<vector<Temperature>>& year : data) {
        Temperature hottest = DataAnalyzer::hottestDayOfYear(year);

        stringstream row;

        row << setw(yearWidth) << left << hottest.year
			<< setw(monthWidth) << left << hottest.month
			<< setw(dayWidth) << left << hottest.day
			<< setw(tempWidth) << left << hottest.temperature;

        displayMessage(row.str()); // display the data of the hottest day of the year
    }

    displayNewLine();
}

/*
* Function: display the coldest day of the year
* Parameters: 2D vector of the year data
*/
void DataVisualizer::displayColdestDayPerYear(const vector<vector<Temperature>>& data)
{
    Temperature coldest = DataAnalyzer::coldestDayOfYear(data); // calculate the coldest day of the year

	displayTopic("Coldest temperature"); // display the topic

    displayMessage("Temperature: " + to_string(coldest.temperature) + "\n");
	displayMessage("Date: " + to_string(coldest.year) + "-" + to_string(coldest.month) + "-" + to_string(coldest.day) + "\n\n");
}

/*
* Function: display the coldest day of each year
* Parameters: 3D vector of all the data
*/
void DataVisualizer::displayColdestDayByYear(const vector<vector<vector<Temperature>>>& data)
{
    displayTopic("Coldest temperature by year"); // display the topic

    stringstream header;

    header << setw(yearWidth) << left << "Year"
        << setw(monthWidth) << left << "Month"
        << setw(dayWidth) << left << "Day"
        << setw(tempWidth) << left << "Temperature";

    displayMessage(header.str()); // display the header

    // loop through the data
    for (const vector<vector<Temperature>>& year : data) {
        Temperature hottest = DataAnalyzer::coldestDayOfYear(year); // calculate the coldest day of the year

        stringstream row;

        row << setw(yearWidth) << left << hottest.year
			<< setw(monthWidth) << left << hottest.month
			<< setw(dayWidth) << left << hottest.day
			<< setw(tempWidth) << left << hottest.temperature;

        displayMessage(row.str()); // display the data of the coldest day of the year
    }

    displayNewLine();
}

/*
* Function: display the mean temperature of the year
* Parameters: 2D vector of the year data
*/
void DataVisualizer::displayMeanTemperaturePerYear(const vector<vector<Temperature>>& data)
{
    double mean = DataAnalyzer::meanTemperatureOfYear(data); // calculate the mean temperature of the year

    displayTopic("Mean temperature"); // display the topic

    displayMessage("Temperature: " + to_string(mean) + "\n\n");
}

/*
* Function: display the mean temperature of each year
* Parameters: 3D vector of all the data
*/
void DataVisualizer::displayMeanTemperatureByYear(const vector<vector<vector<Temperature>>>& data)
{
    displayTopic("Mean temperature by year"); // display the topic

    stringstream header;

    header << setw(yearWidth) << left << "Year"
		<< setw(tempWidth) << left << "Temperature";

    displayMessage(header.str()); // display the header

	// loop through the data
	for (const vector<vector<Temperature>>& year : data) {
		int currentYear = getCurrentYear(year); // get the current year

		stringstream row;

		row << setw(yearWidth) << left << currentYear
			<< setw(tempWidth) << left << DataAnalyzer::meanTemperatureOfYear(year);

		displayMessage(row.str()); // display the mean temperature of the year
	}

    displayNewLine();
}

/*
* Function: display the median temperature of the year
* Parameters: 2D vector of the year data
*/
void DataVisualizer::displayMedianTemperaturePerYear(const vector<vector<Temperature>>& data)
{
    double median = DataAnalyzer::medianTemperatureOfYear(data); // calculate the median temperature of the year

    displayTopic("Median temperature"); // display the topic

    displayMessage("Temperature: " + to_string(median) + "\n\n");
}

/*
* Function: display the median temperature of each year
* Parameters: 3D vector of all the data
*/
void DataVisualizer::displayMedianTemperatureByYear(const vector<vector<vector<Temperature>>>& data)
{
    displayTopic("Median temperature by year"); // display the topic

    stringstream header;

    header << setw(yearWidth) << left << "Year"
        << setw(tempWidth) << left << "Temperature";

    displayMessage(header.str()); // display the header

    // loop through the data
    for (const vector<vector<Temperature>>& year : data) {
		int currentYear = getCurrentYear(year); // get the current year

		stringstream row;

		row << setw(yearWidth) << left << currentYear
			<< setw(tempWidth) << left << DataAnalyzer::medianTemperatureOfYear(year);

		displayMessage(row.str()); // display the median temperature of the year
	}

    displayNewLine();
}

/*
* Function: display the mode temperature of the year
* Parameters: 2D vector of the year data
*/
void DataVisualizer::displayModeTemperaturePerYear(const vector<vector<Temperature>>& yearData)
{
	double mode = DataAnalyzer::modeTemperatureOfYear(yearData); // calculate the mode temperature of the year

    displayTopic("Mode temperature"); // display the topic

    displayMessage("Temperature: " + to_string(mode) + "\n\n");
}

/*
* Function: display the mode temperature of each year
* Parameters: 3D vector of all the data
*/
void DataVisualizer::displayModeTemperatureByYear(const vector<vector<vector<Temperature>>>& allData)
{
    displayTopic("Mode temperature by year"); // display the topic

    stringstream header;

    header << setw(yearWidth) << left << "Year"
		<< setw(tempWidth) << left << "Temperature";

    displayMessage(header.str()); // display the header

	// loop through the data
	for (const vector<vector<Temperature>>& year : allData) {
        int currentYear = getCurrentYear(year); // get the current year

		stringstream row;

		row << setw(yearWidth) << left << currentYear
			<< setw(tempWidth) << left << DataAnalyzer::modeTemperatureOfYear(year);

		displayMessage(row.str()); // display the mode temperature of the year
	}

    displayNewLine();
}

/*
* Function: display the month with the coldest mean temperature of the year
* Parameters: 2D vector of the year data
*/
void DataVisualizer::displayColdestMeanTemperatureMonthPerYear(const vector<vector<Temperature>>& yearData)
{
	Temperature coldestMean = DataAnalyzer::coldestMeanTemperatureMonthOfYear(yearData); // calculate the month with the coldest mean temperature of the year

	displayTopic("Coldest average temperature"); // display the topic

    displayMessage("Month: " + to_string(coldestMean.month));
    displayMessage("Temperature: " + to_string(coldestMean.temperature) + "\n\n");
}

/*
* Function: display the month with the coldest mean temperature of each year
* Parameters: 3D vector of all the data
*/
void DataVisualizer::displayColdestMeanTemperatureMonthByYear(const vector<vector<vector<Temperature>>>& allData)
{
    displayTopic("Coldest average temperature month by year"); // display the topic

    stringstream header;

    header << setw(yearWidth) << left << "Year"
		<< setw(monthWidth) << left << "Month"
		<< setw(tempWidth) << left << "Temperature";

    displayMessage(header.str()); // display the header

	// loop through the data
    for (const vector<vector<Temperature>>& year : allData) {
        int currentYear = getCurrentYear(year); // get the current year

        Temperature coldestMean = DataAnalyzer::coldestMeanTemperatureMonthOfYear(year); // calculate the month with the coldest mean temperature of the year

        stringstream row;

        row << setw(yearWidth) << left << currentYear
            << setw(monthWidth) << left << coldestMean.month
            << setw(tempWidth) << left << coldestMean.temperature;

        displayMessage(row.str()); // display the month with the coldest mean temperature of the year
    }

    displayNewLine();
}

/*
* Function: display the month with the hottest mean temperature of the year
* Parameters: 2D vector of the year data
*/
void DataVisualizer::displayHottestMeanTemperatureMonthPerYear(const vector<vector<Temperature>>& yearData)
{
    Temperature hottestMean = DataAnalyzer::hottestMeanTemperatureMonthOfYear(yearData); // calculate the month with the hottest mean temperature of the year

	displayTopic("Hottest average temperature"); // display the topic

	displayMessage("Month: " + to_string(hottestMean.month));
    displayMessage("Temperature: " + to_string(hottestMean.temperature) + "\n\n");
}

/*
* Function: display the month with the hottest mean temperature of each year
* Parameters: 3D vector of all the data
*/
void DataVisualizer::displayHottestMeanTemperatureMonthByYear(const vector<vector<vector<Temperature>>>& allData)
{
    displayTopic("Hottest average temperature month by year"); // display the topic

    stringstream header;

    header << setw(yearWidth) << left << "Year"
        << setw(monthWidth) << left << "Month"
        << setw(tempWidth) << left << "Temperature";

    displayMessage(header.str()); // display the header

    // loop through the data
    for (const vector<vector<Temperature>>& year : allData) {
		int currentYear = getCurrentYear(year); // get the current year

		Temperature hottestMean = DataAnalyzer::hottestMeanTemperatureMonthOfYear(year); // calculate the month with the hottest mean temperature of the year

		stringstream row;

		row << setw(yearWidth) << left << currentYear
			<< setw(monthWidth) << left << hottestMean.month
			<< setw(tempWidth) << left << hottestMean.temperature;

		displayMessage(row.str()); // display the month with the hottest mean temperature of the year
	}

    displayNewLine();
}

/*
* Function: display the month with the lowest variance of the year
* Parameters: 2D vector of the year data
*/
void DataVisualizer::displayLowestVarienceMonthPerYear(const vector<vector<Temperature>>& yearData)
{
    VarienceMonth lowestVariance = DataAnalyzer::lowestVarianceMonthOfYear(yearData); // calculate the month with the lowest variance of the year

    displayTopic("Lowest variance month"); // display the topic

    displayMessage("Month: " + to_string(lowestVariance.month));
    displayMessage("Average temperature: " + to_string(lowestVariance.mean));
    displayMessage("Variance: " + to_string(lowestVariance.variance) + "\n\n");
}

/*
* Function: display the month with the lowest variance of each year
* Parameters: 3D vector of all the data
*/
void DataVisualizer::displayLowestVarienceMonthByYear(const vector<vector<vector<Temperature>>>& allData)
{
	displayTopic("Lowest variance month by year"); // display the topic

    stringstream header;

    header << setw(yearWidth) << left << "Year"
		<< setw(monthWidth) << left << "Month"
		<< setw(tempWidth) << left << "Temperature"
		<< setw(SDWidth) << left << "Variance";

    displayMessage(header.str()); // display the header

	// loop through the data
	for (const vector<vector<Temperature>>& year : allData) {
        int currentYear = getCurrentYear(year); // get the current year

		VarienceMonth lowestVariance = DataAnalyzer::lowestVarianceMonthOfYear(year); // calculate the month with the lowest variance of the year

		stringstream row;

		row << setw(yearWidth) << left << currentYear
			<< setw(monthWidth) << left << lowestVariance.month
			<< setw(tempWidth) << left << lowestVariance.mean
			<< setw(SDWidth) << left << lowestVariance.variance;

		displayMessage(row.str()); // display the month with the lowest variance of the year
	}

    displayNewLine();
}

/*
* Function: display the standard deviation and the percentage of days within one standard deviation of the year
* Parameters: 2D vector of the year data
*/
void DataVisualizer::displayStandardDeviationPerYear(const vector<vector<Temperature>>& yearData)
{
    double standardDeviation = DataAnalyzer::standardDeviationOfYear(yearData); // calculate the standard deviation of the year
    double percentageOfDaysWithinOneSD = DataAnalyzer::percentageOfDaysWithinOneSD(yearData, standardDeviation); // calculate the percentage of days within one standard deviation

    displayTopic("Standard deviation"); // display the topic

    displayMessage("Standard deviation: " + to_string(standardDeviation));
    displayMessage("Percentage of days within one standard deviation: " + to_string(percentageOfDaysWithinOneSD) + "\n\n");
}

/*
* Function: display the standard deviation and the percentage of days within one standard deviation of each year
* Parameters: 3D vector of all the data
*/
void DataVisualizer::displayStandardDeviationByYear(const vector<vector<vector<Temperature>>>& allData)
{
    displayTopic("Standard deviation by year"); // display the topic

    stringstream header;

    header << setw(yearWidth) << left << "Year"
		<< setw(SDWidth) << left << "Standard Deviation"
		<< setw(SDWidth) << left << "Percentage of days within one SD";

    displayMessage(header.str()); // display the header

    // loop through the data
    for (const vector<vector<Temperature>>& year : allData) {
		int currentYear = getCurrentYear(year); // get the current year

		double standardDeviation = DataAnalyzer::standardDeviationOfYear(year); // calculate the standard deviation of the year
		double percentageOfDaysWithinOneSD = DataAnalyzer::percentageOfDaysWithinOneSD(year, standardDeviation); // calculate the percentage of days within one standard deviation

		stringstream row;

		row << setw(yearWidth) << left << currentYear
			<< setw(SDWidth) << left << standardDeviation
			<< setw(SDWidth) << left << percentageOfDaysWithinOneSD;

		displayMessage(row.str()); // display the standard deviation and the percentage of days within one standard deviation of the year
	}

    displayNewLine();
}

/*
* Function: display the coldest day of a given month in all the years
* Parameters: 3D vector of all the data and the month
*/
void DataVisualizer::displayColdestDayByMonth(const vector<vector<vector<Temperature>>>& data, int month)
{
    displayTopic("Coldest temperature by month"); // display the topic

	Temperature coldest = DataAnalyzer::coldestDayByMonth(data, month); // calculate the coldest day of the month

    displayMessage("Temperature: " + to_string(coldest.temperature));
    displayMessage("Date: " + to_string(coldest.year) + "-" + to_string(coldest.month) + "-" + to_string(coldest.day) + "\n\n");
}

/*
* Function: display the hottest day of a given month in all the years
* Parameters: 3D vector of all the data and the month
*/
void DataVisualizer::displayHottestDayByMonth(const vector<vector<vector<Temperature>>>& data, int month)
{
    displayTopic("Hottest temperature by month"); // display the topic

    Temperature hottest = DataAnalyzer::hottestDayByMonth(data, month); // calculate the hottest day of the month

    displayMessage("Temperature: " + to_string(hottest.temperature));
    displayMessage("Date: " + to_string(hottest.year) + "-" + to_string(hottest.month) + "-" + to_string(hottest.day) + "\n\n");
}

/*
* Function: display the lowest variance year of a given month in all the years
* Parameters: 3D vector of all the data and the month
*/
void DataVisualizer::displayLowestVarienceYearByMonth(const vector<vector<vector<Temperature>>>& allData, int month)
{
	displayTopic("Lowest variance year by month"); // display the topic

	int year = DataAnalyzer::lowestVarianceYearByMonth(allData, month); // calculate the year with the lowest variance of the given month

    displayMessage("Year: " + to_string(year) + "\n\n");
}

/*
* Function: find the year of the data
* Parameters: 2D vector of the year data
* Returns: Year of the data
*/
int DataVisualizer::getCurrentYear(const vector<vector<Temperature>>& yearData)
{
    // loop through the data
    for (const vector<Temperature>& month : yearData) {
        for (const Temperature& day : month) {
            return day.year; // return the year of the first data element
        }
    }
}
