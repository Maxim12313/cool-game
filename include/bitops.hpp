#ifndef BITOPS_HPP
#define BITOPS_HPP

#include <cstdint>

inline std::uint32_t setIthBit(std::uint32_t a, std::uint32_t i) {
    return a | (1u << i);
}

inline std::uint32_t unsetIthBit(std::uint32_t a, std::uint32_t i) {
    return a & ~(1u << i);
}

#endif
