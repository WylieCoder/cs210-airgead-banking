#ifndef INVESTMENT_CALCULATOR_H
#define INVESTMENT_CALCULATOR_H

#include <vector>

// A small data object to hold a single year of results.
struct YearResult {
    int yearNumber {0};
    double endBalance {0.0};
    double interestEarned {0.0};
};

// InvestmentCalculator performs the compound interest math
// for two scenarios, with and without monthly deposits.
class InvestmentCalculator {
public:
    InvestmentCalculator(double initialInvestment,
                         double monthlyDeposit,
                         double annualRatePercent,
                         int years);

    std::vector<YearResult> calculateWithoutDeposits() const;
    std::vector<YearResult> calculateWithDeposits() const;

private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualRate; // stored as a decimal, example, 5 percent becomes 0.05
    int m_years;

    double monthlyRate() const; // helper
};

#endif // INVESTMENT_CALCULATOR_H
