#include <fstream>
#include <iostream>
#include <string>
#include <direct.h>

#include "DataWriter.h"

using namespace std;

DataWriter::DataWriter()
{
    try {
        if (_mkdir("../x64/Debug/results") == -1) {
            cerr << "Error creating folder results" << endl;
        }
	}
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
}

void DataWriter::writeDataPerYear(const vector<string> data, const string filename)
{
    ofstream outfile("../x64/Debug/results/" + filename);

    if (!outfile.is_open()) {
        cerr << "Error opening "<< filename << " file." << endl;
    }

    outfile << "Month,Hottest Temperature,Coldest Temperature,Average Temperature,Median Temperature" << endl;

    for (string row : data) {
		outfile << row << endl;
	}

    outfile.close();
}

void DataWriter::writeDataByYear(const vector<vector<vector<Temperature>>>& data)
{
}
