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
void DataVisualizer::displayTopic(string message)
{
    cout << "<<< " << message << " >>>" << endl << endl;
}

void DataVisualizer::displayRowsAndColumns(const int rows, const int columns)
{
    cout << "Rows: " << rows << endl;
    cout << "Columns: " << columns << endl << endl;

    /*logger.write("Rows: " + to_string(rows));
    logger.write("Columns: " + to_string(columns));*/
}

void DataVisualizer::displayStartAndEndDate(const string startDate, const string endDate)
{
    cout << "Start date: " << startDate << endl;
	cout << "End date: " << endDate << endl << endl;

	/*logger.write("Start date: " + startDate);
    	logger.write("End date: " + endDate);*/
}

void DataVisualizer::displayYears(const vector<int>& years)
{
    cout << "Years in the file:" << endl << endl;

    for (const int& year : years) {
	    cout << year << endl;
	}

    cout << endl;
}

void DataVisualizer::displayDataPerYear(const vector<vector<Temperature>>& data)
{
    displayHottestDayPerYear(data);
    displayColdestDayPerYear(data);
    displayMeanTemperaturePerYear(data);
    displayMedianTemperaturePerYear(data);
    displayModeTemperaturePerYear(data);
    displayColdestMeanTemperatureMonthPerYear(data);
    displayHottestMeanTemperatureMonthPerYear(data);
    displayLowestVarienceMonthPerYear(data);
    displayStandardDeviationPerYear(data);
}

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

void DataVisualizer::displayDataByMonth(const vector<vector<vector<Temperature>>>& data, int month)
{
    displayHottestDayByMonth(data, month);
	displayColdestDayByMonth(data, month);
}

// Private members
void DataVisualizer::displayHottestDayPerYear(const vector<vector<Temperature>>& data)
{
    Temperature hottest = DataAnalyzer::hottestDayOfYear(data);

    displayTopic("Hottest temperature");

    cout << "Temperature: " << hottest.temperature << endl;
    cout << "Date: " << hottest.year << "-" << hottest.month << "-" << hottest.day << endl;

    cout << endl << endl;
}

void DataVisualizer::displayHottestDayByYear(const vector<vector<vector<Temperature>>>& data)
{
    displayTopic("Hottest temperature by year");
    /*logger.write("Hottest temperature by year");*/

    cout << setw(yearWidth) << left << "Year"
        << setw(monthWidth) << left << "Month"
        << setw(dayWidth) << left << "Day"
        << setw(tempWidth) << left << "Temperature" << endl;

    /*logger.write("Year,Month,Day,Temperature");*/

    for (const vector<vector<Temperature>>& year : data) {
        Temperature hottest = DataAnalyzer::hottestDayOfYear(year);

        cout << setw(yearWidth) << left << hottest.year
            << setw(monthWidth) << left << hottest.month
            << setw(dayWidth) << left << hottest.day
            << setw(tempWidth) << left << hottest.temperature << endl;
    }

    cout << endl << endl;
}


void DataVisualizer::displayColdestDayPerYear(const vector<vector<Temperature>>& data)
{
    Temperature coldest = DataAnalyzer::coldestDayOfYear(data);

	displayTopic("Coldest temperature");

	cout << "Temperature: " << coldest.temperature << endl;
	cout << "Date: " << coldest.year << "-" << coldest.month << "-" << coldest.day << endl;

    cout << endl << endl;
}

void DataVisualizer::displayColdestDayByYear(const vector<vector<vector<Temperature>>>& data)
{
    displayTopic("Coldest temperature by year");

    cout << setw(yearWidth) << left << "Year"
        << setw(monthWidth) << left << "Month"
        << setw(dayWidth) << left << "Day"
        << setw(tempWidth) << left << "Temperature" << endl;

    for (const vector<vector<Temperature>>& year : data) {
        Temperature hottest = DataAnalyzer::coldestDayOfYear(year);

        cout << setw(yearWidth) << left << hottest.year
            << setw(monthWidth) << left << hottest.month
            << setw(dayWidth) << left << hottest.day
            << setw(tempWidth) << left << hottest.temperature << endl;
    }

    cout << endl << endl;
}


void DataVisualizer::displayMeanTemperaturePerYear(const vector<vector<Temperature>>& data)
{
    double mean = DataAnalyzer::meanTemperatureOfYear(data);

    displayTopic("Mean temperature");

    cout << "Temperature: " << mean << endl;

    cout << endl << endl;
}

void DataVisualizer::displayMeanTemperatureByYear(const vector<vector<vector<Temperature>>>& data)
{
    displayTopic("Mean temperature by year");

    cout << setw(yearWidth) << left << "Year"
        << setw(tempWidth) << left << "Temperature" << endl;

    for (const vector<vector<Temperature>>& year : data) {
        int currentYear = getCurrentYear(year);

        cout << setw(yearWidth) << left << currentYear
            << setw(tempWidth) << left << DataAnalyzer::meanTemperatureOfYear(year) << endl;
    }

    cout << endl << endl;
}


void DataVisualizer::displayMedianTemperaturePerYear(const vector<vector<Temperature>>& data)
{
    double median = DataAnalyzer::medianTemperatureOfYear(data);

    displayTopic("Median temperature");

    cout << "Temperature: " << median << endl;

    cout << endl << endl;
}

void DataVisualizer::displayMedianTemperatureByYear(const vector<vector<vector<Temperature>>>& data)
{
    displayTopic("Median temperature by year");

    cout << setw(yearWidth) << left << "Year"
        << setw(tempWidth) << left << "Temperature" << endl;

    for (const vector<vector<Temperature>>& year : data) {
        int currentYear = getCurrentYear(year);

        cout << setw(yearWidth) << left << currentYear
            << setw(tempWidth) << left << DataAnalyzer::medianTemperatureOfYear(year) << endl;
    }

    cout << endl << endl;
}


void DataVisualizer::displayModeTemperaturePerYear(const vector<vector<Temperature>>& yearData)
{
	double mode = DataAnalyzer::modeTemperatureOfYear(yearData);

    displayTopic("Mode temperature");

	cout << "Temperature: " << mode << endl;

	cout << endl << endl;
}

void DataVisualizer::displayModeTemperatureByYear(const vector<vector<vector<Temperature>>>& allData)
{
    displayTopic("Mode temperature by year");

	cout << setw(yearWidth) << left << "Year"
		<< setw(tempWidth) << left << "Temperature" << endl;

    for (const vector<vector<Temperature>>& year : allData) {
        int currentYear = getCurrentYear(year);

		cout << setw(yearWidth) << left << currentYear
			<< setw(tempWidth) << left << DataAnalyzer::modeTemperatureOfYear(year) << endl;
	}

	cout << endl << endl;
}


void DataVisualizer::displayColdestMeanTemperatureMonthPerYear(const vector<vector<Temperature>>& yearData)
{
	Temperature coldestMean = DataAnalyzer::coldestMeanTemperatureMonthOfYear(yearData);

	displayTopic("Coldest average temperature");

    cout << "Month: " << coldestMean.month << endl;
    cout << "Temperature: " << coldestMean.temperature << endl;

	cout << endl << endl;
}

void DataVisualizer::displayColdestMeanTemperatureMonthByYear(const vector<vector<vector<Temperature>>>& allData)
{
    displayTopic("Coldest average temperature month by year");

	cout << setw(yearWidth) << left << "Year"
		<< setw(monthWidth) << left << "Month"
		<< setw(tempWidth) << left << "Temperature" << endl;

    for (const vector<vector<Temperature>>& year : allData) {
        int currentYear = getCurrentYear(year);

		Temperature coldestMean = DataAnalyzer::coldestMeanTemperatureMonthOfYear(year);

		cout << setw(yearWidth) << left << currentYear
			<< setw(monthWidth) << left << coldestMean.month
			<< setw(tempWidth) << left << coldestMean.temperature << endl;
	}

	cout << endl << endl;
}


void DataVisualizer::displayHottestMeanTemperatureMonthPerYear(const vector<vector<Temperature>>& yearData)
{
    Temperature hottestMean = DataAnalyzer::hottestMeanTemperatureMonthOfYear(yearData);

	displayTopic("Hottest average temperature");

	cout << "Month: " << hottestMean.month << endl;
	cout << "Temperature: " << hottestMean.temperature << endl;

	cout << endl << endl;
}

void DataVisualizer::displayHottestMeanTemperatureMonthByYear(const vector<vector<vector<Temperature>>>& allData)
{
    displayTopic("Hottest average temperature month by year");

	cout << setw(yearWidth) << left << "Year"
		<< setw(monthWidth) << left << "Month"
		<< setw(tempWidth) << left << "Temperature" << endl;

    for (const vector<vector<Temperature>>& year : allData) {
        int currentYear = getCurrentYear(year);

		Temperature hottestMean = DataAnalyzer::hottestMeanTemperatureMonthOfYear(year);

		cout << setw(yearWidth) << left << currentYear
			<< setw(monthWidth) << left << hottestMean.month
			<< setw(tempWidth) << left << hottestMean.temperature << endl;
	}

	cout << endl << endl;
}


void DataVisualizer::displayLowestVarienceMonthPerYear(const vector<vector<Temperature>>& yearData)
{
    VarienceMonth lowestVariance = DataAnalyzer::lowestVarianceMonthOfYear(yearData);

    displayTopic("Lowest variance month");

    cout << "Month: " << lowestVariance.month << endl;
    cout << "Average temperature: " << lowestVariance.mean << endl;
    cout << "Varience: " << lowestVariance.varience << endl;

    cout << endl << endl;
}

void DataVisualizer::displayLowestVarienceMonthByYear(const vector<vector<vector<Temperature>>>& allData)
{
	displayTopic("Lowest variance month by year");

	cout << setw(yearWidth) << left << "Year"
		<< setw(monthWidth) << left << "Month"
        << setw(avgTempWidth) << left << "Average temperature" << endl;

    for (const vector<vector<Temperature>>& year : allData) {
		int currentYear = getCurrentYear(year);

		VarienceMonth lowestVariance = DataAnalyzer::lowestVarianceMonthOfYear(year);

		cout << setw(yearWidth) << left << currentYear
			<< setw(monthWidth) << left << lowestVariance.month
			<< setw(avgTempWidth) << left << lowestVariance.mean << endl;
	}

	cout << endl << endl;
}


void DataVisualizer::displayStandardDeviationPerYear(const vector<vector<Temperature>>& yearData)
{
    double standardDeviation = DataAnalyzer::standardDeviationOfYear(yearData);
    double percentageOfDaysWithinOneSD = DataAnalyzer::percentageOfDaysWithinOneSD(yearData, standardDeviation);

    displayTopic("Standard deviation");

    cout << "Standard deviation: " << standardDeviation << endl;
    cout << "Percentage of days within one standard deviation: " << percentageOfDaysWithinOneSD << "%" << endl;

    cout << endl << endl;
}

void DataVisualizer::displayStandardDeviationByYear(const vector<vector<vector<Temperature>>>& allData)
{
    displayTopic("Standard deviation by year");

	cout << setw(yearWidth) << left << "Year"
		<< setw(SDWidth) << left << "Standard deviation"
		<< setw(SDWidth) << left << "% days within one SD" << endl;

    for (const vector<vector<Temperature>>& year : allData) {
		int currentYear = getCurrentYear(year);

		double standardDeviation = DataAnalyzer::standardDeviationOfYear(year);
		double percentageOfDaysWithinOneSD = DataAnalyzer::percentageOfDaysWithinOneSD(year, standardDeviation);

		cout << setw(yearWidth) << left << currentYear
			<< setw(SDWidth) << left << standardDeviation
			<< setw(SDWidth) << left << percentageOfDaysWithinOneSD << endl;
	}

	cout << endl << endl;
}


void DataVisualizer::displayColdestDayByMonth(const vector<vector<vector<Temperature>>>& data, int month)
{
    displayTopic("Coldest temperature by month");

	Temperature coldest = DataAnalyzer::coldestDayByMonth(data, month);

	cout << "Temperature: " << coldest.temperature << endl;
	cout << "Date: " << coldest.year << "-" << coldest.month << "-" << coldest.day << endl;

	cout << endl << endl;
}

void DataVisualizer::displayHottestDayByMonth(const vector<vector<vector<Temperature>>>& data, int month)
{
    displayTopic("Hottest temperature by month");

    Temperature hottest = DataAnalyzer::hottestDayByMonth(data, month);

    cout << "Temperature: " << hottest.temperature << endl;
    cout << "Date: " << hottest.year << "-" << hottest.month << "-" << hottest.day << endl;

    cout << endl << endl;
}


int DataVisualizer::getCurrentYear(const vector<vector<Temperature>>& yearData)
{
    for (const vector<Temperature>& month : yearData) {
        for (const Temperature& day : month) {
            return day.year;
        }
    }
}
