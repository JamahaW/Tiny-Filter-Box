#pragma once

namespace tfb {

/// Экспоненциальный фильтр
template<typename T> struct Exponential {
    float k;
    T filtered;

    constexpr explicit Exponential(const float &k, T &&init_value = T{}) :
        k{k}, filtered{init_value} {}

    const T &calc(const T &value) {
        filtered += (value - filtered) * k;
        return filtered;
    }
};

}