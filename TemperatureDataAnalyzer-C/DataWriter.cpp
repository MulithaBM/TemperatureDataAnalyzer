#include <fstream>
#include <iostream>
#include <string>
#include <direct.h>

#include "DataWriter.h"

using namespace std;

DataWriter::DataWriter(const string subdir)
{
    string root = "../x64/Debug/results";
    string sub = root + "/" + subdir;

    const char* rootDirectory = root.c_str();
    const char* subDirectory = sub.c_str();

    int result;

    result = _mkdir(rootDirectory) == -1;
    result = _mkdir(subDirectory) == -1;

    path = sub;
}

void DataWriter::writeDataPerYear(const vector<string> data, const string filename)
{
    ofstream outfile(path + "/" + filename);

    if (!outfile.is_open()) {
        cerr << "Error opening "<< filename << " file." << endl;
    }

    outfile << "Month,Hottest Temperature,Coldest Temperature,Average Temperature,Median Temperature" << endl;

    for (string row : data) {
		outfile << row << endl;
	}

    outfile.close();
}
