/* Gregory Greene
2/5/2022, SNHU
This program is intended to gain investment data from the user and calculate balance/interest information
*/

#include <string_view>
#include <iostream>
#include <iomanip>
#include "ReportGenerator.h"
#include "Calculations.h"

using namespace std;

const char* YEAR = "Year";
const char* YEAR_END_BAL = "Year End Balance";
const char* YEAR_END_INTEREST = "Year End Interest";

// Constructor
ReportGenerator::ReportGenerator() {}

// Output column titles
void ReportGenerator::printColHeader() {
    cout << string(66, '=') << endl;
    cout << setw(9) << YEAR << setw(26) << YEAR_END_BAL << setw(27) << YEAR_END_INTEREST << endl;
    cout << string(66, '-') << endl;
}

// Output report header
void ReportGenerator::reportGenerator(InvestmentInfo& t_dataOne, InvestmentInfo& t_dataTwo) {
    cout << "     Balance and Interest Without Additional Monthly Deposits     \n" << endl;
    annualReport(t_dataOne);

    cout << "     Balance and Interest With Additional Monthly Deposits     \n" << endl;
    annualReport(t_dataTwo);
}

// Output financial rows
void ReportGenerator::annualReport(InvestmentInfo& t_data) {
    // Set local vars to producing accurate report
    vector<int> years = t_data.getMYears();
    vector<double> yearEndBalances = t_data.getMYearEndBalances();
    vector<double> yearEndEarnedInterests = t_data.getMYearEndEarnedInterests();

    printColHeader();

    // Loop over InvestmentInfo object
    for (int i = 0; i < years.size(); ++i) {
        cout << setw(9) << years.at(i) << fixed << setprecision(2);
        cout << setw(26) << yearEndBalances.at(i) << fixed << setprecision(2);
        cout << setw(27) << yearEndEarnedInterests.at(i) << fixed << setprecision(2) << endl;
    }
    cout << endl << endl;
}

// Prompt user to re-run program
bool ReportGenerator::additionalSessionCheck() {
    string text;

    cout << "Press enter to try more values (press 'q' to quit)\n";
    cin >> text;

    if (text.empty()) {
        return true;
    }
    else {
        return false;
    }
}