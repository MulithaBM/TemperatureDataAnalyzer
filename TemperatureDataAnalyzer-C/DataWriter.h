/*
* Program Name: TemperatureDataAnalyzer
* Programmer: MulithaBM
* File: DataWriter.h
* Date: 2024-05-12
* Description: Header file for the class that writes the data to result files
*/

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
	DataWriter(const string subdir);
	void writeDataPerYear(const vector<string> data, const string filename);
private:
	string path;
};

#endif