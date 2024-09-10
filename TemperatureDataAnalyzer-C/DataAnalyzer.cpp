/*
* Program Name: TemperatureDataAnalyzer
* Programmer: MulithaBM
* File: DataAnalyzer.cpp
* Date: 2024-05-12
* Description: Method implementations for the DataAnalyzer class
*/

#include <algorithm>
#include <array>
#include "DataAnalyzer.h"

using namespace std;

// Public members

/*
* Function: find the hottest day of the year
* Inputs: 2D vector of temperatures for the year
* Returns: Temperature struct of hottest day of the year
*/
Temperature DataAnalyzer::hottestDayOfYear(const vector<vector<Temperature>>& yearData)
{
	Temperature hottest{ 0, 0, 0, MIN_TEMPERATURE }; // Initial temperature struct with minimum temperature

	// Loop through all the days of the year
	for (const vector<Temperature>& month : yearData) {
		for (const Temperature& day : month) {
			if (day.temperature > hottest.temperature) { // If the temperature of the day is greater than the current hottest temperature
				hottest = day; // Set the current day as the hottest day
			}
		}
	}

	return hottest;
}

/*
* Function: find the hottest day of the month
* Inputs: vector of temperatures for the month
* Returns: Temperature struct of hottest day of the month
*/
Temperature DataAnalyzer::hottestDayOfMonth(const vector<Temperature>& monthData)
{
	Temperature hottest{ 0, 0, 0, MIN_TEMPERATURE }; // Initial temperature struct with minimum temperature

	// Loop through all the days of the month
	for (const Temperature& day : monthData) {
		if (day.temperature > hottest.temperature) { // If the temperature of the day is greater than the current hottest temperature
			hottest = day; // Set the current day as the hottest day
		}
	}

	return hottest;
}

/*
* Function: find the coldest day of the year
* Inputs: 2D vector of temperatures for the year
* Returns: Temperature struct of coldest day of the year
*/
Temperature DataAnalyzer::coldestDayOfYear(const vector<vector<Temperature>>& yearData)
{
	Temperature coldest{ 0, 0, 0, MAX_TEMPERATURE }; // Initial temperature struct with maximum temperature

	// Loop through all the days of the year
	for (const vector<Temperature>& month : yearData) {
		for (const Temperature& day : month) {
			if (day.temperature < coldest.temperature) { // If the temperature of the day is less than the current coldest temperature
				coldest = day; // Set the current day as the coldest day
			}
		}
	}

	return coldest;
}

/*
* Function: find the coldest day of the month
* Inputs: vector of temperatures for the month
* Returns: Temperature struct of coldest day of the month
*/
Temperature DataAnalyzer::coldestDayOfMonth(const vector<Temperature>& monthData)
{
	Temperature coldest{ 0, 0, 0, MAX_TEMPERATURE }; // Initial temperature struct with maximum temperature

	// Loop through all the days of the month
	for (const Temperature& day : monthData) {
		if (day.temperature < coldest.temperature) { // If the temperature of the day is less than the current coldest temperature
			coldest = day; // Set the current day as the coldest day
		}
	}

	return coldest;
}

/*
* Function: find the mean temperature of the year
* Inputs: 2D vector of temperatures for the year
* Returns: mean temperature of the year
*/
double DataAnalyzer::meanTemperatureOfYear(const vector<vector<Temperature>>& yearData)
{
	double sum = 0; // Sum of all the temperatures
	int count = 0; // Count of all the days

	// Loop through all the days of the year
	for (const vector<Temperature>& month : yearData) { 
		for (const Temperature& day : month) {
			sum += day.temperature; // Add the temperature of the day to the sum
			++count; // Increment the count by 1
		}
	}

	return sum / count; // Return the mean temperature of the year
}

/*
* Function: find the mean temperature of the month
* Inputs: vector of temperatures for the month
* Returns: mean temperature of the month
*/
double DataAnalyzer::meanTemperatureOfMonth(const vector<Temperature>& monthData)
{
	double sum = 0; // Sum of all the temperatures
	int count = 0; // Count of all the days

	// Loop through all the days of the month
	for (const Temperature& day : monthData) {
		sum += day.temperature; // Add the temperature of the day to the sum
		count++; // Increment the count by 1
	}

	return sum / count; // Return the mean temperature of the month
}

/*
* Function: find the median temperature of the year
* Inputs: 2D vector of temperatures for the year
* Returns: median temperature of the year
*/
double DataAnalyzer::medianTemperatureOfYear(const vector<vector<Temperature>>& yearData)
{
	vector<double> temperatures; // Vector to store all the temperatures of the year

	// Loop through all the days of the year
	for (const vector<Temperature>& month : yearData) {
		for (const Temperature& day : month) {
			temperatures.push_back(day.temperature); // Add the temperature of the day to the vector
		}
	}

	sort(temperatures.begin(), temperatures.end()); // Sort the temperatures in ascending order

	// Check if the number of temperatures is even
	if (temperatures.size() % 2 == 0) {
		return (temperatures[temperatures.size() / 2 - 1] + temperatures[temperatures.size() / 2]) / 2; // If even, return the average of the middle two temperatures
	} else {
		return temperatures[temperatures.size() / 2]; // If odd, return the middle temperature
	}
}

/*
* Function: find the median temperature of the month
* Inputs: vector of temperatures for the month
* Returns: median temperature of the month
*/
double DataAnalyzer::medianTemperatureOfMonth(const vector<Temperature>& monthData)
{
	vector<double> temperatures; // Vector to store all the temperatures of the month

	// Loop through all the days of the month
	for (const Temperature& day : monthData) {
		temperatures.push_back(day.temperature); // Add the temperature of the day to the vector
	}

	sort(temperatures.begin(), temperatures.end()); // Sort the temperatures in ascending order

	// Check if the number of temperatures is even
	if (temperatures.size() % 2 == 0) {
		return (temperatures[temperatures.size() / 2 - 1] + temperatures[temperatures.size() / 2]) / 2; // If even, return the average of the middle two temperatures
	} else {
		return temperatures[temperatures.size() / 2]; // If odd, return the middle temperature
	}
}

/*
* Function: find the month with the hottest mean temperature of the year
* Inputs: 2D vector of temperatures for the year
* Returns: Temperature struct of month with the hottest mean temperature of the year
*/
Temperature DataAnalyzer::hottestMeanTemperatureMonthOfYear(const vector<vector<Temperature>>& yearData)
{
	array<double, 12> monthlyMeans = {}; // Array to store the mean temperatures of the 12 months
	monthlyMeans.fill(MIN_TEMPERATURE); // Initialize the array with minimum temperature

	// Loop through all the months of the year
	for (int i = 0; i < 12; i++) {
		if (yearData[i].size() > 0) { // Check if the month has any data
			monthlyMeans[i] = meanTemperatureOfMonth(yearData[i]); // Calculate the mean temperature of the month
		}
	}

	int hottestMonth = 0; // Index of the month with the hottest mean temperature
	double hottestMean = monthlyMeans[0]; // Hottest mean temperature

	// Loop through all the months
	for (int i = 1; i < 12; i++) {
		// Check if the mean temperature of the month is greater than the current hottest mean temperature
		if (monthlyMeans[i] > monthlyMeans[hottestMonth]) {
			hottestMonth = i; // Set the current month as the hottest month
			hottestMean = monthlyMeans[i]; // Set the current mean temperature as the hottest mean temperature
		}
	}

	return Temperature{ 0, hottestMonth + 1, 0, hottestMean };
}

/*
* Function: find the month with the coldest mean temperature of the year
* Inputs: 2D vector of temperatures for the year
* Returns: Temperature struct of month with the coldest mean temperature of the year
*/
Temperature DataAnalyzer::coldestMeanTemperatureMonthOfYear(const vector<vector<Temperature>>& yearData)
{
	array<double, 12> monthlyMeans = {}; // Array to store the mean temperatures of the 12 months
	monthlyMeans.fill(MAX_TEMPERATURE); // Initialize the array with maximum temperature

	// Loop through all the months of the year
	for (int i = 0; i < 12; i++) {
		// Check if the month has any data
		if (yearData[i].size() > 0) {
			monthlyMeans[i] = meanTemperatureOfMonth(yearData[i]); // Calculate the mean temperature of the month
		}
	}

	int coldestMonth = 0; // Index of the month with the coldest mean temperature
	double coldestMean = monthlyMeans[0]; // Coldest mean temperature

	// Loop through all the months
	for (int i = 1; i < 12; i++) {
		// Check if the mean temperature of the month is less than the current coldest mean temperature
		if (monthlyMeans[i] < monthlyMeans[coldestMonth]) {
			coldestMonth = i; // Set the current month as the coldest month
			coldestMean = monthlyMeans[i]; // Set the current mean temperature as the coldest mean temperature
		}
	}

	return Temperature{ 0, coldestMonth + 1, 0, coldestMean };
}

/*
* Function: find the mode temperature of the year
* Inputs: 2D vector of temperatures for the year
* Returns: double of mode temperature of the year
*/
double DataAnalyzer::modeTemperatureOfYear(const vector<vector<Temperature>>& yearData)
{
	vector<double> temperatures; // Vector to store all the temperatures of the year

	// Loop through all the days of the year
	for (const vector<Temperature>& month : yearData) {
		for (const Temperature& day : month) {
			temperatures.push_back(day.temperature); // Add the temperature of the day to the vector
		}
	}

	sort(temperatures.begin(), temperatures.end()); // Sort the temperatures in ascending order

	double current = temperatures[0]; // Current temperature
	double mode = temperatures[0]; // Mode temperature
	int count = 0; // Count of the current temperature
	int maxCount = 0; // Count of the mode temperature

	// Loop through all the temperatures
	for (double temperature : temperatures) {
		// Check if the temperature is the same as the current temperature
		if (temperature == current) {
			count++; // Increment the count by 1
		} else {
			// Check if the count is greater than the current max count
			if (count > maxCount) {
				mode = current; // Set the current temperature as the mode temperature
				maxCount = count; // Set the count as the max count
			}
			else {
				current = temperature; // Set the current temperature as the new temperature
				count = 1; // Reset the count to 1
			}
		}
	}

	return mode >= 0 ? floor(mode) : ceil(mode); // If mode is positive, return the floor of the mode, else return the ceil of the mode
}

/*
* Function: find the mode temperature of the month
* Inputs: vector of temperatures for the month
* Returns: mode temperature of the month
*/
double DataAnalyzer::varienceOfMonth(const vector<Temperature>& monthData)
{
	double mean = meanTemperatureOfMonth(monthData); // Calculate mean temperature of the month
	double sum = 0; // Sum of the squared differences
	int count = 0; // Count of all the days

	// Loop through all the days of the month
	for (const Temperature& day : monthData) {
		sum += pow(day.temperature - mean, 2); // Add the squared difference to the sum
		count++; // Increment the count by 1
	}

	return sum / count; // Return the variance of the month
}

/*
* Function: find the month with the lowest varience of the year
* Inputs: 2D vector of temperatures for the year
* Returns: VarienceMonth struct of month with the lowest varience of the year
*/
VarienceMonth DataAnalyzer::lowestVarianceMonthOfYear(const vector<vector<Temperature>>& yearData)
{
	array<double, 12> monthlyVariances = {}; // Array to store the variances of the 12 months
	monthlyVariances.fill(-1); // Initialize the array with -1 (as varience >= 0)

	// Loop through all the months of the year
	for (int i = 0; i < 12; i++) {
		// Check if the month has any data
		if (yearData[i].size() > 0) {
			monthlyVariances[i] = varienceOfMonth(yearData[i]); // Calculate the variance of the month and store it in the array
		}
	}

	int lowestVarianceMonth = -1; // Index of the month with the lowest variance
	double lowestVariance = -1; // Lowest variance

	// Loop through all the months
	for (int i = 0; i < 12; i++) {
		// Check if the varience of the i th month is not -1 (i.e. the month has valid varience data)
		if (monthlyVariances[i] != -1) {
			// Check if the lowest variance is -1 or the varience of the i th month is less than the current lowest variance
			if (lowestVariance == -1 || monthlyVariances[i] < lowestVariance) {
				lowestVariance = monthlyVariances[i]; // Set the varience of the i th month as the lowest variance
				lowestVarianceMonth = i; // Set the i th month as the month with the lowest variance
			}
		}
	}

	double mean = meanTemperatureOfMonth(yearData[lowestVarianceMonth]); // Calculate the mean temperature of the month with the lowest variance

	return VarienceMonth{ lowestVarianceMonth + 1, mean, lowestVariance };
}

/*
* Function: find the standard deviation of the year
* Inputs: 2D vector of temperatures for the year
* Returns: standard deviation of the year
*/
double DataAnalyzer::standardDeviationOfYear(const vector<vector<Temperature>>& yearData)
{
	double sum = 0; // Sum of the squared differences
	int count = 0; // Count of all the days
	double mean = meanTemperatureOfYear(yearData); // Calculate mean temperature of the year

	// Loop through all the days of the year
	for (const vector<Temperature>& month : yearData) {
		for (const Temperature& day : month) {
			sum += pow(day.temperature - mean, 2); // Add the squared difference to the sum
			count++; // Increment the count by 1
		}
	}

	return sqrt(sum / count); // Return the standard deviation of the year
}

/*
* Function: find the percentage of days within one standard deviation of the mean temperature of the year
* Inputs: 2D vector of temperatures for the year
* Returns: percentage of days within one standard deviation of the mean temperature of the year
*/
double DataAnalyzer::percentageOfDaysWithinOneSD(const vector<vector<Temperature>>& yearData, const double standardDeviation)
{
	double mean = meanTemperatureOfYear(yearData); // Calculate mean temperature of the year
	int days = 0; // Count of all the days
	int daysWithinOneSD = 0; // Count of all the days within one standard deviation of the mean temperature

	// Loop through all the days of the year
	for (const vector<Temperature>& month : yearData) {
		for (const Temperature& day : month) {
			// Check if the temperature of the day is within one standard deviation of the mean temperature
			if (abs(day.temperature - mean) <= standardDeviation) {
				daysWithinOneSD++; // Increment the count of days within one standard deviation by 1
			}

			days++; // Increment the count of all the days by 1
		}
	}

	return (double)daysWithinOneSD / days * 100; // Return the percentage of days within one standard deviation of the mean temperature
}

/*
* Function: find the coldest day of the given month from all the years
* Inputs: 3D vector of temperatures for all the years
* Returns: Temperature struct of coldest day of the month from all the years
*/
Temperature DataAnalyzer::coldestDayByMonth(const vector<vector<vector<Temperature>>>& allData, int month)
{
	Temperature coldest{ 0, 0, 0, MAX_TEMPERATURE }; // Initial temperature struct with maximum temperature

	// Loop through the years in all the data
	for (const vector<vector<Temperature>>& year : allData) {
		Temperature coldestOfYear = coldestDayOfMonth(year[month - 1]); // Find the coldest day of the given month of the year

		// Check if the temperature of the coldest day of the given month in the current year is less than the current coldest temperature
		if (coldestOfYear.temperature < coldest.temperature) {
			coldest = coldestOfYear; // Set the coldest day of the given month in the current year as the coldest day
		}
	}

	return coldest;
}

/*
* Function: find the hottest day of the given month from all the years
* Inputs: 3D vector of temperatures for all the years
* Returns: Temperature struct of hottest day of the month from all the years
*/
Temperature DataAnalyzer::hottestDayByMonth(const vector<vector<vector<Temperature>>>& allData, int month)
{
	Temperature hottest{ 0, 0, 0, MIN_TEMPERATURE }; // Initial temperature struct with minimum temperature

	// Loop through the years in all the data
	for (const vector<vector<Temperature>>& year : allData) {
		Temperature hottestOfYear = hottestDayOfMonth(year[month - 1]); // Find the hottest day of the given month of the year

		// Check if the temperature of the hottest day of the given month in the current year is greater than the current hottest temperature
		if (hottestOfYear.temperature > hottest.temperature) {
			hottest = hottestOfYear; // Set the hottest day of the given month in the current year as the hottest day
		}
	}

	return hottest;
}

/*
* Function: find the year with the given month having the lowest varience from all the years
* Inputs: 3D vector of temperatures for all the years
* Returns: year with the given month having the lowest varience from all the years
*/
int DataAnalyzer::lowestVarianceYearByMonth(const vector<vector<vector<Temperature>>>& allData, int month)
{
	int lowestVarianceYear = -1; // Year with the given month having the lowest variance
	double lowestVariance = -1; // Lowest variance

	// Loop through all the years in the data
	for (const vector<vector<Temperature>>& year : allData) {
		double varianceOfYear = varienceOfMonth(year[month - 1]); // Calculate the variance of the given month of the year

		// Check if the lowest variance is -1 or the variance of the given month of the year is less than the current lowest variance
		if (lowestVariance == -1 || varianceOfYear < lowestVariance) {
			lowestVariance = varianceOfYear; // Set the variance of the given month of the year as the lowest variance
			lowestVarianceYear = getCurrentYear(year); // Set the year as the year with the lowest variance
		}
	}

	return lowestVarianceYear;
}

// Private members

/*
* Function: find the year year of the given data
* Inputs: 2D vector of temperatures for the year
* Returns: year of the given data
*/
int DataAnalyzer::getCurrentYear(const vector<vector<Temperature>>& yearData)
{
	// Loop through all the days of the year
	for (const vector<Temperature>& month : yearData) {
		for (const Temperature& day : month) {
			return day.year; // Return the year of the first day
		}
	}
}
