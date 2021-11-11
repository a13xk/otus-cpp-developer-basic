#pragma once

#include "IStatistics.h"

#include <vector>

class CPct95 : public IStatistics {

public:
    CPct95();
    ~CPct95() override;
    void update(double next) override;
    double eval() const override;
    const char * name() const override;

private:
    double m_pct95;
    double const m_percentile = 95.0;
    std::vector<double> m_input_values;
};
