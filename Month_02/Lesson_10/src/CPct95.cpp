#include "CPct95.h"
#include <bits/stdc++.h>
/**
 * Constructor initializes m_pct95 with zero to start accumulation of values
 * The CPct90 class encapsulates calculation of Percentile 95 value from given sequence
 */
CPct95::CPct95() : m_pct95{0.0} {}
/**
 * Trivial destructor
 */
CPct95::~CPct95() = default;
/**
 * Accumulate values and calculate Percentile 95
 * @param next The next appropriate number from input sequence
 */
void CPct95::update(double next) {
    // Sort input values in ascending order
    m_input_values.push_back(next);
    std::sort(m_input_values.begin(), m_input_values.end());

    // Calculate rank: r = (p/100) * (n - 1) + 1
    double rank = (m_percentile/100.0)*(static_cast<double>(m_input_values.size())-1)+1;

    // Get integer and fractional parts of rank
    double fractional_part, integer_part;
    fractional_part = modf(rank, &integer_part);

    // Calculate Percentile 95: p95 = sorted_values[ip-1] + fp*(sorted_values[ip]-sorted_values[ip-1])
    auto ip = static_cast<unsigned long>(integer_part);
    if (m_input_values.size() >= 2) {
        m_pct95 = m_input_values.at(ip-1)+fractional_part*(m_input_values.at(ip)-m_input_values.at(ip-1));
    }
}
/**
 * Return current value of Percentile 95
 */
double CPct95::eval() const {
    return m_pct95;
}
/**
 * Return name of statistical operation
 */
const char *CPct95::name() const {
    return "pct95";
}