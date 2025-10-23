#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include "InvestmentCalculator.h"

namespace {
    // Read a double with validation and a prompt message.
    double readDouble(const std::string& prompt, double minValue, double maxValue) {
        while (true) {
            std::cout << prompt;
            double value;
            if (std::cin >> value && value >= minValue && value <= maxValue) {
                return value;
            }
            std::cout << "Input was not valid. Try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    // Read a positive integer with validation.
    int readInt(const std::string& prompt, int minValue, int maxValue) {
        while (true) {
            std::cout << prompt;
            int value;
            if (std::cin >> value && value >= minValue && value <= maxValue) {
                return value;
            }
            std::cout << "Input was not valid. Try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    void printHeader(const std::string& title) {
        std::cout << "\n";
        std::cout << std::string(60, '=') << "\n";
        std::cout << title << "\n";
        std::cout << std::string(60, '=') << "\n";
    }

    void printReport(const std::string& title, const std::vector<YearResult>& results) {
        printHeader(title);
        std::cout << std::left
                  << std::setw(10) << "Year"
                  << std::setw(25) << "End Balance"
                  << std::setw(25) << "Interest Earned" << "\n";
        std::cout << std::string(60, '-') << "\n";

        std::cout.setf(std::ios::fixed);
        std::cout << std::setprecision(2);

        for (const auto& yr : results) {
            std::cout << std::left
                      << std::setw(10) << yr.yearNumber
                      << std::setw(25) << yr.endBalance
                      << std::setw(25) << yr.interestEarned << "\n";
        }
    }
}

int main() {
    std::cout << "Airgead Banking, Investment Growth App\n";

    bool keepRunning = true;
    while (keepRunning) {
        // Collect user input with validation.
        double initialInvestment = readDouble("Enter initial investment amount: $", 0.0, 1e12);
        double monthlyDeposit    = readDouble("Enter monthly deposit: $", 0.0, 1e9);
        double annualRatePercent = readDouble("Enter annual interest rate, percent: ", 0.0, 100.0);
        int years                = readInt("Enter number of years: ", 1, 120);

        // Create calculator and run both scenarios.
        InvestmentCalculator calc(initialInvestment, monthlyDeposit, annualRatePercent, years);

        auto withoutDeposits = calc.calculateWithoutDeposits();
        auto withDeposits    = calc.calculateWithDeposits();

        // Display outputs.
        std::cout << "\nInput Summary\n";
        std::cout << "Initial investment: $" << initialInvestment << "\n";
        std::cout << "Monthly deposit: $"    << monthlyDeposit    << "\n";
        std::cout << "Annual rate: "        << annualRatePercent << "%\n";
        std::cout << "Years: "               << years             << "\n";

        printReport("Balance and Interest Without Additional Monthly Deposits", withoutDeposits);
        printReport("Balance and Interest With Additional Monthly Deposits", withDeposits);

        // Ask to run again.
        std::cout << "\nWould you like to run another scenario, Y or N? ";
        char again {};
        std::cin >> again;
        if (again != 'Y' && again != 'y') {
            keepRunning = false;
        }
        std::cout << "\n";
    }

    std::cout << "Thank you for using Airgead Banking. Goodbye.\n";
    return 0;
}
