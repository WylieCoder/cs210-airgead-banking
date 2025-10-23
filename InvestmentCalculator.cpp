#include "InvestmentCalculator.h"
#include <cmath>

InvestmentCalculator::InvestmentCalculator(double initialInvestment,
                                           double monthlyDeposit,
                                           double annualRatePercent,
                                           int years)
    : m_initialInvestment(initialInvestment),
      m_monthlyDeposit(monthlyDeposit),
      m_annualRate(annualRatePercent / 100.0),
      m_years(years) {}

double InvestmentCalculator::monthlyRate() const {
    return m_annualRate / 12.0;
}

std::vector<YearResult> InvestmentCalculator::calculateWithoutDeposits() const {
    std::vector<YearResult> results;
    results.reserve(static_cast<std::size_t>(m_years));

    double balance = m_initialInvestment;
    double rate = monthlyRate();

    for (int year = 1; year <= m_years; ++year) {
        double interestAccrued = 0.0;

        for (int month = 0; month < 12; ++month) {
            double interest = balance * rate;
            interestAccrued += interest;
            balance += interest;
        }

        results.push_back(YearResult{year, balance, interestAccrued});
    }

    return results;
}

std::vector<YearResult> InvestmentCalculator::calculateWithDeposits() const {
    std::vector<YearResult> results;
    results.reserve(static_cast<std::size_t>(m_years));

    double balance = m_initialInvestment;
    double rate = monthlyRate();

    for (int year = 1; year <= m_years; ++year) {
        double interestAccrued = 0.0;

        for (int month = 0; month < 12; ++month) {
            // Deposit happens before interest accrues each month.
            balance += m_monthlyDeposit;
            double interest = balance * rate;
            interestAccrued += interest;
            balance += interest;
        }

        results.push_back(YearResult{year, balance, interestAccrued});
    }

    return results;
}
