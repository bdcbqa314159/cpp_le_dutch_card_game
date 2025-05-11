#pragma once
#ifndef CARDS_LIB_COMMON_HPP
#define CARDS_LIB_COMMON_HPP

#include <iostream>

namespace cards {

// to be able to cout u8string:
std::ostream& operator<<(std::ostream&, const std::u8string&);

enum class Suit : size_t { heart, diamond, spade, club };

std::ostream& operator<<(std::ostream&, const Suit&);

}  // namespace cards

#endif  // CARDS_LIB_COMMON_HPP