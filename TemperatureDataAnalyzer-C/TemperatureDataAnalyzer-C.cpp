/*
* Program Name: TemperatureDataAnalyzer
* Programmer: MulithaBM
* File: DataAnalyzer.cpp
* Date: 2024-05-12
* Description: This file contains the 'main' function
*/

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

        DataVisualizer::displayInputMessage("Please enter file name: ");

        string fileChoice;
        cin >> fileChoice;

        dataHandler.addLogMessage("User input: " + fileChoice + "\n");
        cout << endl;

        if (fileChoice == "avalon" || fileChoice == "bendingo") {

            string filename;

            if (fileChoice == "avalon") {
                filename += "Avalon Airport Temperature Data-all.csv";
            }
            else if (fileChoice == "bendingo") {
                filename += "Bendigo Airport Temperature Data-all.csv";
            }

            TemperatureData data(filename);
            const vector<vector<vector<Temperature>>>& groupedData = data.getData();

            const int rows = data.getRows();
            const int columns = data.getColumns();

            DataVisualizer::displayRowsAndColumns(rows, columns);

            DataVisualizer::displayStartAndEndDate(data.getStartDate(), data.getEndDate());

            DataVisualizer::displayMessage("Enter 1 to display data by year or enter 2 to display data by month\n");
            DataVisualizer::displayInputMessage("Enter option: ");

            int timeChoice;
            cin >> timeChoice;

            dataHandler.addLogMessage("User input: " + to_string(timeChoice) + "\n");
            cout << endl;

            if (timeChoice == 1) {
                const vector<int>& years = data.getYears();

                DataVisualizer::displayYears(years);

                DataVisualizer::displayMessage("Choose a year to display yearly data or * to display all years\n");
                DataVisualizer::displayInputMessage("Enter year: ");

                string yearChoice;
                cin >> yearChoice;

                dataHandler.addLogMessage("User input: " + yearChoice + "\n");
                cout << endl;

                if (yearChoice == "*") {
                    dataHandler.handleDataByYear(groupedData, fileChoice);
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
            else if (timeChoice == 2) {
                DataVisualizer::displayMessage("Choose a month to display monthly data (Enter a month number from 1 to 12)\n");
                DataVisualizer::displayInputMessage("Enter month: ");

                int monthChoice;
                cin >> monthChoice;

                dataHandler.addLogMessage("User input: " + to_string(monthChoice) + "\n");
                cout << endl;

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
        else {
            DataVisualizer::displayMessage("Invalid input.\n");
        }

        DataVisualizer::displayMessage("Do you want to continue (c) or exit (e)?: ");
        cin >> continueChoice;

        dataHandler.addLogMessage("User input: " + to_string(continueChoice)+"\n");
        cout << endl;
    } while (tolower(continueChoice) == 'c');

    DataVisualizer::displayMessage("Exiting program.Thank you!");

    return 0;
}