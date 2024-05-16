#ifndef DATAWRITER_H
#define DATAWRITER_H

#include <vector>
#include "TemperatureData.h"

using namespace std;

class DataWriter
{
	public:
		DataWriter();
		void writeDataPerYear(const vector<string> data, const string filename);
		void writeDataByYear(const vector<vector<vector<Temperature>>>& data);
	private:
		const string outputFolder = "Results";
};

#endif