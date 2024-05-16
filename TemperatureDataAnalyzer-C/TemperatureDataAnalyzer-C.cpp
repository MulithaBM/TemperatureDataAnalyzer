// TemperatureDataAnalyzer-C.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TemperatureData.h"
#include "DataVisualizer.h"
#include "DataHandler.h"

using namespace std;

int main() {
    cout << "Turing Moore Engineering Temperature Data Analyser 1.0" << endl;
    cout << "Name: " << endl;
    cout << "Student ID : " << endl;
    cout << "Desired Level : HD" << endl << endl;

    cout << "Welcome! This program helps determine the best times of year to manufacture composite halls for new boats based on temperature data" << endl;

    char continueChoice;

    do {
        cout << "\nPlease choose a data file:" << endl;

        cout << "1. Avalon Airport Temperature Data-2022.csv" << endl;
        cout << "2. Avalon Airport Temperature Data-all.csv" << endl;
        cout << "3. Bendigo Airport Temperature Data-2022.csv" << endl;
        cout << "4. Bendigo Airport Temperature Data-all.csv" << endl << endl;

        cout << "Enter file number: ";

        int fileChoice;
        cin >> fileChoice;

        cout << endl;

        if (fileChoice >= 1 && fileChoice <= 4) {
            /*Logger logger("log.txt");

            logger.write("User selection: " + string(1, choice) + "\n");*/

            /*string filename = "D:/Development/Outsource Projects/TemperatureDataAnalyzer/TemperatureDataAnalyzer-C/x64/Debug/";*/
            string filename = "../x64/Debug/";

            if (fileChoice == 1) {
                filename += "Avalon Airport Temperature Data-2022.csv";
                /*logger.write("Avalon Airport Temperature Data-2022.csv:\n\n");*/
            }
            else if (fileChoice == 2) {
                filename += "Avalon Airport Temperature Data-all.csv";
                /*logger.write("Bendigo-all.csv:\n\n");*/
            }
            else if (fileChoice == 3) {
                filename += "Bendigo Airport Temperature Data-2022.csv";
                /*logger.write("Bendigo-2022.csv:\n\n");*/
            }
            else if (fileChoice == 4) {
                filename += "Bendigo Airport Temperature Data-all.csv";
                /*logger.write("Bendigo-all.csv:\n\n");*/
            }

            TemperatureData data(filename);
            const vector<vector<vector<Temperature>>>& groupedData = data.getData();

            const int rows = data.getRows();
            const int columns = data.getColumns();

            DataVisualizer::displayRowsAndColumns(rows, columns);

            if (fileChoice == 1 || fileChoice == 3) {
                DataHandler::HandleDataPerYear(groupedData[0]);
            }
            else {
                const vector<int>& years = data.getYears();

                DataVisualizer::displayStartAndEndDate(data.getStartDate(), data.getEndDate());

                cout << "Enter 1 to display data by year or enter 2 to display data by month" << endl << endl;
                cout << "Enter option: ";

                int timeChice;
                cin >> timeChice;

                if (timeChice == 1) {
                    DataVisualizer::displayYears(years);

                    cout << "Choose a year to display yearly data or * to display all years" << endl << endl;
                    cout << "Enter year: ";

                    string yearChoice;
                    cin >> yearChoice;

                    if (yearChoice == "*") {
                        DataHandler::HandleDataByYear(groupedData);
                    }
                    else {
                        int year = stoi(yearChoice);

                        if (year < years[0] || year > years[years.size() - 1]) {
                            cout << "Invalid year.\n\n";
                        }
                        else {
                            const vector<vector<Temperature>>& yearData = data.getYearData(year);

                            DataHandler::HandleDataPerYear(yearData);
                        }
                    }
                }
                else if (timeChice == 2) {
                    cout << "Choose a month to display monthly data (Enter a month number from 1 to 12)" << endl << endl;
                    cout << "Enter month: ";

                    int monthChoice;
                    cin >> monthChoice;

                    if (monthChoice >= 1 && monthChoice <= 12) {
						DataHandler::HandleDataByMonth(groupedData, monthChoice);
					}
                    else {
						cout << "Invalid month.\n\n";
					}
                }
                else {
                    cout << "Invalid choice.\n\n";
                }
            }
		}
        else {
            cout << "Invalid file number.\n\n";
        }

        cout << "Do you want to continue (c) or exit (e)? ";
        cin >> continueChoice;
    } while (tolower(continueChoice) == 'c');

    cout << "Exiting program. Thank you!\n";

    return 0;
}