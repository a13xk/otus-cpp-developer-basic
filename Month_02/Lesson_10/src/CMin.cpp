#include "CMin.h"

/**
 * Constructor initializes m_min with minimum finite value of type double
 * The CMin class encapsulates calculation of minimum value from given sequence
 */
CMin::CMin() : m_min{std::numeric_limits<double>::min()} {}
/**
 * Trivial destructor
 */
CMin::~CMin() = default;
/**
 * Update m_min value by next appropriate number from input sequence
 * @param next
 */
void CMin::update(double next) {
    if (next < m_min) {
        m_min = next;
    }
}
/**
 * Return current value of m_min
 */
double CMin::eval() const {
    return m_min;
}
/**
 * Return name of statistical operation
 * @return
 */
const char *CMin::name() const {
    return "min";
}


