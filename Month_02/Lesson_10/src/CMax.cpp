#include "CMax.h"

/**
 * Constructor initializes m_max with minimum finite value of type double
 * The CMax class encapsulates calculation of maximum value from given sequence
 */
CMax::CMax() : m_max{std::numeric_limits<double>::min()} {}
/**
 * Trivial destructor
 */
CMax::~CMax() = default;
/**
 * Update m_max value by next appropriate number from input sequence
 */
void CMax::update(double next) {
    if (next > m_max) {
        m_max = next;
    }
}
/**
 * Return current value of m_max
 */
double CMax::eval() const {
    return m_max;
}
/**
 * Return name of statistical operation
 */
const char *CMax::name() const {
    return "max";
}