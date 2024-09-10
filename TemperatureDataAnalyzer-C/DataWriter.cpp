/*
* Program Name: TemperatureDataAnalyzer
* Programmer: MulithaBM
* File: DataWriter.cpp
* Date: 2024-05-12
* Description: Method implementations for the DataWriter class
*/

#include <fstream>
#include <iostream>
#include <string>
#include <direct.h>

#include "DataWriter.h"

using namespace std;

/*
* Function: DataWriter constructor
* Parameters: sub directory name for the dataset file
*/
DataWriter::DataWriter(const string subdir)
{
    string root = "results"; // root directory for the output files
    string sub = root + "/" + subdir; // sub directory for the output files

    const char* rootDirectory = root.c_str(); // convert string to const char*
    const char* subDirectory = sub.c_str(); // convert string to const char*

    int result;

    result = _mkdir(rootDirectory) == -1; // create root directory
    result = _mkdir(subDirectory) == -1; // create sub directory

    path = sub; // set the path to the sub directory
}

/*
* Function: Write output data for a single year
* Parameters: vector of strings containing the data and filename to write the data to
*/
void DataWriter::writeDataPerYear(const vector<string> data, const string filename)
{
    ofstream outfile(path + "/" + filename); // create output file

    // check if the file is open
    if (!outfile.is_open()) {
        cerr << "Error opening "<< filename << " file." << endl; // if unable to open print error message
    }

    outfile << "Month,Hottest Temperature,Coldest Temperature,Average Temperature,Median Temperature" << endl; // write header

    // Loop through the data
    for (string row : data) {
		outfile << row << endl; // write data to the file
	}

    outfile.close(); // close the file
}
