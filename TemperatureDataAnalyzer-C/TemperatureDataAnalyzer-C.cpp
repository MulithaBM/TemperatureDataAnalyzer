// TemperatureDataAnalyzer-C.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TemperatureData.h"
#include "DataVisualizer.h"
#include "DataHandler.h"
#include "DataLogger.h"

using namespace std;

int main() {
    DataHandler& dataHandler = DataHandler::getInstance();

    DataVisualizer::displayWelcomeMessage();

    char continueChoice;

    do {
        DataVisualizer::displayFileSelectionMessage();

        DataVisualizer::displayInputMessage("Please enter file number: ");

        int fileChoice;
        cin >> fileChoice;

        dataHandler.addLogMessage("User input: " + to_string(fileChoice) + "\n");

        cout << endl;

        if (fileChoice >= 1 && fileChoice <= 4) {

            string filename = "../x64/Debug/";

            if (fileChoice == 1) {
                filename += "Avalon Airport Temperature Data-2022.csv";
            }
            else if (fileChoice == 2) {
                filename += "Avalon Airport Temperature Data-all.csv";
            }
            else if (fileChoice == 3) {
                filename += "Bendigo Airport Temperature Data-2022.csv";
            }
            else if (fileChoice == 4) {
                filename += "Bendigo Airport Temperature Data-all.csv";
            }

            TemperatureData data(filename);
            const vector<vector<vector<Temperature>>>& groupedData = data.getData();

            const int rows = data.getRows();
            const int columns = data.getColumns();

            DataVisualizer::displayRowsAndColumns(rows, columns);

            if (fileChoice == 1 || fileChoice == 3) {
                dataHandler.handleDataPerYear(groupedData[0]);
            }
            else {
                const vector<int>& years = data.getYears();

                DataVisualizer::displayStartAndEndDate(data.getStartDate(), data.getEndDate());

                DataVisualizer::displayMessage("Enter 1 to display data by year or enter 2 to display data by month\n");
                DataVisualizer::displayInputMessage("Enter option: ");

                int timeChice;
                cin >> timeChice;

                dataHandler.addLogMessage("User input: " + to_string(timeChice) + "\n");

                DataVisualizer::displayNewLine();

                if (timeChice == 1) {
                    DataVisualizer::displayYears(years);

                    DataVisualizer::displayMessage("Choose a year to display yearly data or * to display all years\n");
                    DataVisualizer::displayInputMessage("Enter year: ");

                    string yearChoice;
                    cin >> yearChoice;

                    dataHandler.addLogMessage("User input: " + yearChoice + "\n");

                    DataVisualizer::displayNewLine();

                    if (yearChoice == "*") {
                        dataHandler.handleDataByYear(groupedData);
                    }
                    else {
                        int year = stoi(yearChoice);

                        if (year < years[0] || year > years[years.size() - 1]) {
                            DataVisualizer::displayMessage("Invalid year.\n");
                        }
                        else {
                            const vector<vector<Temperature>>& yearData = data.getYearData(year);

                            dataHandler.handleDataPerYear(yearData);
                        }
                    }
                }
                else if (timeChice == 2) {
                    DataVisualizer::displayMessage("Choose a month to display monthly data (Enter a month number from 1 to 12)\n");
                    DataVisualizer::displayInputMessage("Enter month: ");

                    int monthChoice;
                    cin >> monthChoice;

                    dataHandler.addLogMessage("User input: " + to_string(monthChoice) + "\n");

                    if (monthChoice >= 1 && monthChoice <= 12) {
                        dataHandler.handleDataByMonth(groupedData, monthChoice);
					}
                    else {
                        DataVisualizer::displayMessage("Invalid month.\n");
					}
                }
                else {
                    DataVisualizer::displayMessage("Invalid choice.\n");
                }
            }
		}
        else {
            DataVisualizer::displayMessage("Invalid file number.\n");
        }

        cout << "Do you want to continue (c) or exit (e)? ";
        cin >> continueChoice;
    } while (tolower(continueChoice) == 'c');

    DataVisualizer::displayMessage("Exiting program.Thank you!");

    return 0;
}