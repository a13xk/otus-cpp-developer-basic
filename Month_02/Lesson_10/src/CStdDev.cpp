#include "CStdDev.h"
/**
 * Constructor initializes m_std_dev with zero to start accumulation of values
 * The CStdDev class encapsulates calculation of standard deviation value from given sequence
 */
CStdDev::CStdDev() : m_std_dev{0.0} {}
/**
 * Trivial destructor
 */
CStdDev::~CStdDev() = default;
/**
 * Accumulate values and calculate Standard Deviation
 * @param next The next appropriate number from input sequence
 */
void CStdDev::update(double next) {
    // Calculate arithmetic mean of input values
    m_input_values.push_back(next);
    double sum_of_inputs = 0.0;
    for(double &input_value : m_input_values) {
        sum_of_inputs += input_value;
    }
    double mean_of_inputs = sum_of_inputs / static_cast<double>(m_input_values.size());

    // Calculate sum of squared differences from the mean
    double sum_of_squared_deviations = 0.0;
    for(double &input_value : m_input_values) {
        sum_of_squared_deviations += pow((input_value - mean_of_inputs), 2);
    }

    // Calculate Standard Deviation
    double variance = sum_of_squared_deviations / static_cast<double>(m_input_values.size());
    m_std_dev = sqrt(variance);
}
/**
 * Return current value of Standard Deviation
 */
double CStdDev::eval() const {
    return m_std_dev;
}
/**
 * Return name of statistical operation
 */
const char *CStdDev::name() const {
    return "std_dev";
}