#ifndef DATAWRITER_H
#define DATAWRITER_H

#include <vector>
#include <string>
#include "TemperatureData.h"

using namespace std;

static const string OUT_DIR = "../x64/Debug/results";

class DataWriter
{
	public:
		DataWriter();
		void writeDataPerYear(const vector<string> data, const string filename);
		void writeDataByYear(const vector<vector<vector<Temperature>>>& data);
};

#endif