/*
* Program Name: TemperatureDataAnalyzer
* Programmer:
* File: DataAnalyzer.cpp
* Date: 2024-05-12
* Description: Method implementations for the DataVisualizer class
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include "DataVisualizer.h"
#include "DataAnalyzer.h"
#include "DataWriter.h"

using namespace std;

//DataVisualizer::DataVisualizer(const string logFileName) {
//    logger = Logger(logFileName);
//}

// Public members

/*
* Function: display a topic
* Parameters: topic
*/
void DataVisualizer::displayTopic(string message)
{
    cout << "<<< " << message << " >>>" << endl << endl;
}

/*
* Function: display rows and columns
* Parameters: number of rows and columns
*/
void DataVisualizer::displayRowsAndColumns(const int rows, const int columns)
{
    cout << "Rows: " << rows << endl;
    cout << "Columns: " << columns << endl << endl;

    /*logger.write("Rows: " + to_string(rows));
    logger.write("Columns: " + to_string(columns));*/
}

/*
* Function: display the start and end date
* Parameters: start date and end date
*/
void DataVisualizer::displayStartAndEndDate(const string startDate, const string endDate)
{
    cout << "Start date: " << startDate << endl;
	cout << "End date: " << endDate << endl << endl;

	/*logger.write("Start date: " + startDate);
    	logger.write("End date: " + endDate);*/
}

/*
* Function: display the list of years
* Parameters: vector of years
*/
void DataVisualizer::displayYears(const vector<int>& years)
{
    cout << "Years in the file:" << endl << endl;

    for (const int& year : years) {
	    cout << year << endl;
	}

    cout << endl;
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

    cout << "Temperature: " << hottest.temperature << endl;
    cout << "Date: " << hottest.year << "-" << hottest.month << "-" << hottest.day << endl;

    cout << endl << endl;
}

/*
* Function: display the hottest day of each year
* Parameters: 3D vector of all the data
*/
void DataVisualizer::displayHottestDayByYear(const vector<vector<vector<Temperature>>>& data)
{
    displayTopic("Hottest temperature by year"); // display the topic
    /*logger.write("Hottest temperature by year");*/

    cout << setw(yearWidth) << left << "Year"
        << setw(monthWidth) << left << "Month"
        << setw(dayWidth) << left << "Day"
        << setw(tempWidth) << left << "Temperature" << endl; // display the header

    /*logger.write("Year,Month,Day,Temperature");*/

    // loop through the data
    for (const vector<vector<Temperature>>& year : data) {
        Temperature hottest = DataAnalyzer::hottestDayOfYear(year);

        cout << setw(yearWidth) << left << hottest.year
            << setw(monthWidth) << left << hottest.month
            << setw(dayWidth) << left << hottest.day
            << setw(tempWidth) << left << hottest.temperature << endl; // display the data of the hottest day of the year
    }

    cout << endl << endl;
}

/*
* Function: display the coldest day of the year
* Parameters: 2D vector of the year data
*/
void DataVisualizer::displayColdestDayPerYear(const vector<vector<Temperature>>& data)
{
    Temperature coldest = DataAnalyzer::coldestDayOfYear(data); // calculate the coldest day of the year

	displayTopic("Coldest temperature"); // display the topic

	cout << "Temperature: " << coldest.temperature << endl;
	cout << "Date: " << coldest.year << "-" << coldest.month << "-" << coldest.day << endl;

    cout << endl << endl;
}

/*
* Function: display the coldest day of each year
* Parameters: 3D vector of all the data
*/
void DataVisualizer::displayColdestDayByYear(const vector<vector<vector<Temperature>>>& data)
{
    displayTopic("Coldest temperature by year"); // display the topic

    cout << setw(yearWidth) << left << "Year"
        << setw(monthWidth) << left << "Month"
        << setw(dayWidth) << left << "Day"
        << setw(tempWidth) << left << "Temperature" << endl; // display the header

    // loop through the data
    for (const vector<vector<Temperature>>& year : data) {
        Temperature hottest = DataAnalyzer::coldestDayOfYear(year); // calculate the coldest day of the year

        cout << setw(yearWidth) << left << hottest.year
            << setw(monthWidth) << left << hottest.month
            << setw(dayWidth) << left << hottest.day
            << setw(tempWidth) << left << hottest.temperature << endl; // display the data of the coldest day of the year
    }

    cout << endl << endl;
}

/*
* Function: display the mean temperature of the year
* Parameters: 2D vector of the year data
*/
void DataVisualizer::displayMeanTemperaturePerYear(const vector<vector<Temperature>>& data)
{
    double mean = DataAnalyzer::meanTemperatureOfYear(data); // calculate the mean temperature of the year

    displayTopic("Mean temperature"); // display the topic

    cout << "Temperature: " << mean << endl;

    cout << endl << endl;
}

/*
* Function: display the mean temperature of each year
* Parameters: 3D vector of all the data
*/
void DataVisualizer::displayMeanTemperatureByYear(const vector<vector<vector<Temperature>>>& data)
{
    displayTopic("Mean temperature by year"); // display the topic

    cout << setw(yearWidth) << left << "Year"
        << setw(tempWidth) << left << "Temperature" << endl; // display the header

    // loop through the data
    for (const vector<vector<Temperature>>& year : data) {
        int currentYear = getCurrentYear(year); // get the current year

        cout << setw(yearWidth) << left << currentYear
            << setw(tempWidth) << left << DataAnalyzer::meanTemperatureOfYear(year) << endl; // display the mean temperature of the year
    }

    cout << endl << endl;
}

/*
* Function: display the median temperature of the year
* Parameters: 2D vector of the year data
*/
void DataVisualizer::displayMedianTemperaturePerYear(const vector<vector<Temperature>>& data)
{
    double median = DataAnalyzer::medianTemperatureOfYear(data); // calculate the median temperature of the year

    displayTopic("Median temperature"); // display the topic

    cout << "Temperature: " << median << endl;

    cout << endl << endl;
}

/*
* Function: display the median temperature of each year
* Parameters: 3D vector of all the data
*/
void DataVisualizer::displayMedianTemperatureByYear(const vector<vector<vector<Temperature>>>& data)
{
    displayTopic("Median temperature by year"); // display the topic

    cout << setw(yearWidth) << left << "Year"
        << setw(tempWidth) << left << "Temperature" << endl; // display the header

    // loop through the data
    for (const vector<vector<Temperature>>& year : data) {
        int currentYear = getCurrentYear(year); // get the current year

        cout << setw(yearWidth) << left << currentYear
            << setw(tempWidth) << left << DataAnalyzer::medianTemperatureOfYear(year) << endl; // display the median temperature of the year
    }

    cout << endl << endl;
}

/*
* Function: display the mode temperature of the year
* Parameters: 2D vector of the year data
*/
void DataVisualizer::displayModeTemperaturePerYear(const vector<vector<Temperature>>& yearData)
{
	double mode = DataAnalyzer::modeTemperatureOfYear(yearData); // calculate the mode temperature of the year

    displayTopic("Mode temperature"); // display the topic

	cout << "Temperature: " << mode << endl;

	cout << endl << endl;
}

/*
* Function: display the mode temperature of each year
* Parameters: 3D vector of all the data
*/
void DataVisualizer::displayModeTemperatureByYear(const vector<vector<vector<Temperature>>>& allData)
{
    displayTopic("Mode temperature by year"); // display the topic

	cout << setw(yearWidth) << left << "Year"
		<< setw(tempWidth) << left << "Temperature" << endl; // display the header

    // loop through the data
    for (const vector<vector<Temperature>>& year : allData) {
        int currentYear = getCurrentYear(year); // get the current year

		cout << setw(yearWidth) << left << currentYear
			<< setw(tempWidth) << left << DataAnalyzer::modeTemperatureOfYear(year) << endl; // display the mode temperature of the year
	}

	cout << endl << endl;
}

/*
* Function: display the month with the coldest mean temperature of the year
* Parameters: 2D vector of the year data
*/
void DataVisualizer::displayColdestMeanTemperatureMonthPerYear(const vector<vector<Temperature>>& yearData)
{
	Temperature coldestMean = DataAnalyzer::coldestMeanTemperatureMonthOfYear(yearData); // calculate the month with the coldest mean temperature of the year

	displayTopic("Coldest average temperature"); // display the topic

    cout << "Month: " << coldestMean.month << endl;
    cout << "Temperature: " << coldestMean.temperature << endl;

	cout << endl << endl;
}

/*
* Function: display the month with the coldest mean temperature of each year
* Parameters: 3D vector of all the data
*/
void DataVisualizer::displayColdestMeanTemperatureMonthByYear(const vector<vector<vector<Temperature>>>& allData)
{
    displayTopic("Coldest average temperature month by year"); // display the topic

	cout << setw(yearWidth) << left << "Year"
		<< setw(monthWidth) << left << "Month"
		<< setw(tempWidth) << left << "Temperature" << endl; // display the header

    // loop through the data
    for (const vector<vector<Temperature>>& year : allData) {
        int currentYear = getCurrentYear(year); // get the current year

		Temperature coldestMean = DataAnalyzer::coldestMeanTemperatureMonthOfYear(year); // calculate the month with the coldest mean temperature of the year

		cout << setw(yearWidth) << left << currentYear
			<< setw(monthWidth) << left << coldestMean.month
			<< setw(tempWidth) << left << coldestMean.temperature << endl; // display the month with the coldest mean temperature of the year
	}

	cout << endl << endl;
}

/*
* Function: display the month with the hottest mean temperature of the year
* Parameters: 2D vector of the year data
*/
void DataVisualizer::displayHottestMeanTemperatureMonthPerYear(const vector<vector<Temperature>>& yearData)
{
    Temperature hottestMean = DataAnalyzer::hottestMeanTemperatureMonthOfYear(yearData); // calculate the month with the hottest mean temperature of the year

	displayTopic("Hottest average temperature"); // display the topic

	cout << "Month: " << hottestMean.month << endl;
	cout << "Temperature: " << hottestMean.temperature << endl;

	cout << endl << endl;
}

/*
* Function: display the month with the hottest mean temperature of each year
* Parameters: 3D vector of all the data
*/
void DataVisualizer::displayHottestMeanTemperatureMonthByYear(const vector<vector<vector<Temperature>>>& allData)
{
    displayTopic("Hottest average temperature month by year"); // display the topic

	cout << setw(yearWidth) << left << "Year"
		<< setw(monthWidth) << left << "Month"
		<< setw(tempWidth) << left << "Temperature" << endl; // display the header

    // loop through the data
    for (const vector<vector<Temperature>>& year : allData) {
        int currentYear = getCurrentYear(year); // get the current year

		Temperature hottestMean = DataAnalyzer::hottestMeanTemperatureMonthOfYear(year); // calculate the month with the hottest mean temperature of the year

		cout << setw(yearWidth) << left << currentYear
			<< setw(monthWidth) << left << hottestMean.month
			<< setw(tempWidth) << left << hottestMean.temperature << endl; // display the month with the hottest mean temperature of the year
	}

	cout << endl << endl;
}

/*
* Function: display the month with the lowest variance of the year
* Parameters: 2D vector of the year data
*/
void DataVisualizer::displayLowestVarienceMonthPerYear(const vector<vector<Temperature>>& yearData)
{
    VarienceMonth lowestVariance = DataAnalyzer::lowestVarianceMonthOfYear(yearData); // calculate the month with the lowest variance of the year

    displayTopic("Lowest variance month"); // display the topic

    cout << "Month: " << lowestVariance.month << endl;
    cout << "Average temperature: " << lowestVariance.mean << endl;
    cout << "Varience: " << lowestVariance.varience << endl;

    cout << endl << endl;
}

/*
* Function: display the month with the lowest variance of each year
* Parameters: 3D vector of all the data
*/
void DataVisualizer::displayLowestVarienceMonthByYear(const vector<vector<vector<Temperature>>>& allData)
{
	displayTopic("Lowest variance month by year"); // display the topic

	cout << setw(yearWidth) << left << "Year"
		<< setw(monthWidth) << left << "Month"
        << setw(avgTempWidth) << left << "Average temperature" << endl; // display the header

    // loop through the data
    for (const vector<vector<Temperature>>& year : allData) {
		int currentYear = getCurrentYear(year); // get the current year

		VarienceMonth lowestVariance = DataAnalyzer::lowestVarianceMonthOfYear(year); // calculate the month with the lowest variance of the year

		cout << setw(yearWidth) << left << currentYear
			<< setw(monthWidth) << left << lowestVariance.month
			<< setw(avgTempWidth) << left << lowestVariance.mean << endl; // display the month with the lowest variance of the year
	}

	cout << endl << endl;
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

    cout << "Standard deviation: " << standardDeviation << endl;
    cout << "Percentage of days within one standard deviation: " << percentageOfDaysWithinOneSD << "%" << endl;

    cout << endl << endl;
}

/*
* Function: display the standard deviation and the percentage of days within one standard deviation of each year
* Parameters: 3D vector of all the data
*/
void DataVisualizer::displayStandardDeviationByYear(const vector<vector<vector<Temperature>>>& allData)
{
    displayTopic("Standard deviation by year"); // display the topic

	cout << setw(yearWidth) << left << "Year"
		<< setw(SDWidth) << left << "Standard deviation"
		<< setw(SDWidth) << left << "% days within one SD" << endl; // display the header

    // loop through the data
    for (const vector<vector<Temperature>>& year : allData) {
		int currentYear = getCurrentYear(year); // get the current year

		double standardDeviation = DataAnalyzer::standardDeviationOfYear(year); // calculate the standard deviation of the year
		double percentageOfDaysWithinOneSD = DataAnalyzer::percentageOfDaysWithinOneSD(year, standardDeviation); // calculate the percentage of days within one standard deviation

		cout << setw(yearWidth) << left << currentYear
			<< setw(SDWidth) << left << standardDeviation
			<< setw(SDWidth) << left << percentageOfDaysWithinOneSD << endl; // display the standard deviation and the percentage of days within one standard deviation
	}

	cout << endl << endl;
}

/*
* Function: display the coldest day of a given month in all the years
* Parameters: 3D vector of all the data and the month
*/
void DataVisualizer::displayColdestDayByMonth(const vector<vector<vector<Temperature>>>& data, int month)
{
    displayTopic("Coldest temperature by month"); // display the topic

	Temperature coldest = DataAnalyzer::coldestDayByMonth(data, month); // calculate the coldest day of the month

	cout << "Temperature: " << coldest.temperature << endl;
	cout << "Date: " << coldest.year << "-" << coldest.month << "-" << coldest.day << endl;

	cout << endl << endl;
}

/*
* Function: display the hottest day of a given month in all the years
* Parameters: 3D vector of all the data and the month
*/
void DataVisualizer::displayHottestDayByMonth(const vector<vector<vector<Temperature>>>& data, int month)
{
    displayTopic("Hottest temperature by month"); // display the topic

    Temperature hottest = DataAnalyzer::hottestDayByMonth(data, month); // calculate the hottest day of the month

    cout << "Temperature: " << hottest.temperature << endl;
    cout << "Date: " << hottest.year << "-" << hottest.month << "-" << hottest.day << endl;

    cout << endl << endl;
}

/*
* Function: display the lowest variance year of a given month in all the years
* Parameters: 3D vector of all the data and the month
*/
void DataVisualizer::displayLowestVarienceYearByMonth(const vector<vector<vector<Temperature>>>& allData, int month)
{
	displayTopic("Lowest variance year by month"); // display the topic

	int year = DataAnalyzer::lowestVarianceYearByMonth(allData, month); // calculate the year with the lowest variance of the given month

	cout << "Year: " << year << endl;

	cout << endl << endl;
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
