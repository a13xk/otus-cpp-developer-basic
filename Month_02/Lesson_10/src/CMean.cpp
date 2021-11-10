#include "CMean.h"
/**
 * Constructor initializes m_mean with zero to start accumulation of values
 * The CMean class encapsulates calculation of mean value from given sequence
 */
CMean::CMean() : m_mean{0.0} {}
/**
 * Trivial destructor
 */
CMean::~CMean() = default;
/**
 * Accumulate values and calculate arithmetic mean
 * @param next The next appropriate number from input sequence
 */
void CMean::update(double next) {
    m_input_values.push_back(next);
    double sum_of_inputs = 0.0;
    for(double &input_value : m_input_values) {
        sum_of_inputs += input_value;
    }
    m_mean = sum_of_inputs/static_cast<double>(m_input_values.size());
}
/**
 * Return current value of m_mean
 */
double CMean::eval() const {
    return m_mean;
}
/**
 * Return name of statistical operation
 */
const char *CMean::name() const {
    return "mean";
}