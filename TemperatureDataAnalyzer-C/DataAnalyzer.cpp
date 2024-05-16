#include <algorithm>
#include <array>
#include "DataAnalyzer.h"

using namespace std;

// Public members
Temperature DataAnalyzer::hottestDayOfYear(const vector<vector<Temperature>>& yearData)
{
	Temperature hottest{hottest.temperature = MIN_TEMPERATURE};

	for (const vector<Temperature>& month : yearData) {
		for (const Temperature& day : month) {
			if (day.temperature > hottest.temperature) {
				hottest = day;
			}
		}
	}

	return hottest;
}

Temperature DataAnalyzer::hottestDayOfMonth(const vector<Temperature>& monthData)
{
	Temperature hottest{hottest.temperature = MIN_TEMPERATURE};

	for (const Temperature& day : monthData) {
		if (day.temperature > hottest.temperature) {
			hottest = day;
		}
	}

	return hottest;
}

Temperature DataAnalyzer::coldestDayOfYear(const vector<vector<Temperature>>& yearData)
{
	Temperature coldest{coldest.temperature = MAX_TEMPERATURE};

	for (const vector<Temperature>& month : yearData) {
		for (const Temperature& day : month) {
			if (day.temperature < coldest.temperature) {
				coldest = day;
			}
		}
	}

	return coldest;
}

Temperature DataAnalyzer::coldestDayOfMonth(const vector<Temperature>& monthData)
{
	Temperature coldest{coldest.temperature = MAX_TEMPERATURE};

	for (const Temperature& day : monthData) {
		if (day.temperature < coldest.temperature) {
			coldest = day;
		}
	}

	return coldest;
}

double DataAnalyzer::meanTemperatureOfYear(const vector<vector<Temperature>>& yearData)
{
	double sum = 0;
	int count = 0;

	for (const vector<Temperature>& month : yearData) {
		for (const Temperature& day : month) {
			sum += day.temperature;
			++count;
		}
	}

	return sum / count;
}

double DataAnalyzer::meanTemperatureOfMonth(const vector<Temperature>& monthData)
{
	double sum = 0;
	int count = 0;

	for (const Temperature& day : monthData) {
		sum += day.temperature;
		count++;
	}

	return sum / count;
}

double DataAnalyzer::medianTemperatureOfYear(const vector<vector<Temperature>>& yearData)
{
	vector<double> temperatures;

	for (const vector<Temperature>& month : yearData) {
		for (const Temperature& day : month) {
			temperatures.push_back(day.temperature);
		}
	}

	sort(temperatures.begin(), temperatures.end());

	if (temperatures.size() % 2 == 0) {
		return (temperatures[temperatures.size() / 2 - 1] + temperatures[temperatures.size() / 2]) / 2;
	} else {
		return temperatures[temperatures.size() / 2];
	}
}

double DataAnalyzer::medianTemperatureOfMonth(const vector<Temperature>& monthData)
{
	vector<double> temperatures;

	for (const Temperature& day : monthData) {
		temperatures.push_back(day.temperature);
	}

	sort(temperatures.begin(), temperatures.end());

	if (temperatures.size() % 2 == 0) {
		return (temperatures[temperatures.size() / 2 - 1] + temperatures[temperatures.size() / 2]) / 2;
	} else {
		return temperatures[temperatures.size() / 2];
	}
}

Temperature DataAnalyzer::hottestMeanTemperatureMonthOfYear(const vector<vector<Temperature>>& yearData)
{
	array<double, 12> monthlyMeans = {};
	monthlyMeans.fill(MIN_TEMPERATURE);

	for (int i = 0; i < 12; i++) {
		if (yearData[i].size() > 0) {
			monthlyMeans[i] = meanTemperatureOfMonth(yearData[i]);
		}
	}

	int hottestMonth = 0;
	double hottestMean = monthlyMeans[0];

	for (int i = 1; i < 12; i++) {
		if (monthlyMeans[i] > monthlyMeans[hottestMonth]) {
			hottestMonth = i;
			hottestMean = monthlyMeans[i];
		}
	}

	return Temperature{ 0, hottestMonth + 1, 0, hottestMean };
}

Temperature DataAnalyzer::coldestMeanTemperatureMonthOfYear(const vector<vector<Temperature>>& yearData)
{
	array<double, 12> monthlyMeans = {};
	monthlyMeans.fill(MAX_TEMPERATURE);

	for (int i = 0; i < 12; i++) {
		if (yearData[i].size() > 0) {
			monthlyMeans[i] = meanTemperatureOfMonth(yearData[i]);
		}
	}

	int coldestMonth = 0;
	double coldestMean = monthlyMeans[0];

	for (int i = 1; i < 12; i++) {
		if (monthlyMeans[i] < monthlyMeans[coldestMonth]) {
			coldestMonth = i;
			coldestMean = monthlyMeans[i];
		}
	}

	return Temperature{ 0, coldestMonth + 1, 0, coldestMean };
}

double DataAnalyzer::modeTemperatureOfYear(const vector<vector<Temperature>>& yearData)
{
	return 0.0;
}

double DataAnalyzer::varienceOfMonth(const vector<Temperature>& monthData)
{
	double mean = meanTemperatureOfMonth(monthData);
	double sum = 0;
	int count = 0;

	for (const Temperature& day : monthData) {
		sum += pow(day.temperature - mean, 2);
		count++;
	}

	return sum / count;
}

VarienceMonth DataAnalyzer::lowestVarianceMonthOfYear(const vector<vector<Temperature>>& yearData)
{
	array<double, 12> monthlyVariances = {};
	monthlyVariances.fill(-1);

	for (int i = 0; i < 12; i++) {
		if (yearData[i].size() > 0) {
			monthlyVariances[i] = varienceOfMonth(yearData[i]);
		}
	}

	int lowestVarianceMonth = -1;
	double lowestVariance = -1;

	for (int i = 0; i < 12; i++) {
		if (monthlyVariances[i] != -1) {
			if (lowestVariance == -1 || monthlyVariances[i] < lowestVariance) {
				lowestVariance = monthlyVariances[i];
				lowestVarianceMonth = i;
			}
		}
	}

	return VarienceMonth{ lowestVarianceMonth + 1, lowestVariance };
}

double DataAnalyzer::standardDeviationOfYear(const vector<vector<Temperature>>& yearData)
{
	double sum = 0;
	int count = 0;
	double mean = meanTemperatureOfYear(yearData);

	for (const vector<Temperature>& month : yearData) {
		for (const Temperature& day : month) {
			sum += pow(day.temperature - mean, 2);
			count++;
		}
	}

	return sqrt(sum / count);
}

double DataAnalyzer::percentageOfDaysWithinOneSD(const vector<vector<Temperature>>& yearData, const double standardDeviation)
{
	double mean = meanTemperatureOfYear(yearData);
	int days = 0;
	int daysWithinOneSD = 0;

	for (const vector<Temperature>& month : yearData) {
		for (const Temperature& day : month) {
			if (abs(day.temperature - mean) <= standardDeviation) {
				daysWithinOneSD++;
			}

			days++;
		}
	}

	return (double)daysWithinOneSD / days * 100;
}

Temperature DataAnalyzer::coldestDayByMonth(const vector<vector<vector<Temperature>>>& allData, int month)
{
	Temperature coldest{coldest.temperature = MAX_TEMPERATURE};

	for (const vector<vector<Temperature>>& year : allData) {
		Temperature coldestOfYear = coldestDayOfMonth(year[month - 1]);

		if (coldestOfYear.temperature < coldest.temperature) {
			coldest = coldestOfYear;
		}
	}

	return coldest;
}

Temperature DataAnalyzer::hottestDayByMonth(const vector<vector<vector<Temperature>>>& allData, int month)
{
	Temperature hottest{hottest.temperature = MIN_TEMPERATURE};

	for (const vector<vector<Temperature>>& year : allData) {
		Temperature hottestOfYear = hottestDayOfMonth(year[month - 1]);

		if (hottestOfYear.temperature > hottest.temperature) {
			hottest = hottestOfYear;
		}
	}

	return hottest;
}

int DataAnalyzer::lowestVarienceYearByMonth(const vector<vector<vector<Temperature>>>& allData, int month)
{
	int lowestVarianceYear = -1;
	double lowestVariance = -1;

	for (const vector<vector<Temperature>>& year : allData) {
		double varianceOfYear = varienceOfMonth(year[month - 1]);

		if (lowestVariance == -1 || varianceOfYear < lowestVariance) {
			lowestVariance = varianceOfYear;
			lowestVarianceYear = getCurrentYear(year);
		}
	}

	return lowestVarianceYear;
}

// Private members
int DataAnalyzer::getCurrentYear(const vector<vector<Temperature>>& yearData)
{
	for (const vector<Temperature>& month : yearData) {
		for (const Temperature& day : month) {
			return day.year;
		}
	}
}
