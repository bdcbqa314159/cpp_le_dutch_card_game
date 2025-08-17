#include "cards_common.hpp"

namespace cards {

std::ostream& operator<<(std::ostream& os, const std::u8string& str) {
#ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8);  // Set console output to UTF-8 encoding
#endif
  return os.write(reinterpret_cast<const char*>(str.data()), str.size());
}

std::ostream& operator<<(std::ostream& os, const Suit& suit) { 
  std::u8string symbol;

  switch (suit) {
    case Suit::heart:
      symbol = u8"\u2661";
      break;
    case Suit::diamond:
      symbol = u8"\u2662";
      break;
    case Suit::spade:
      symbol = u8"\u2660";
      break;
    case Suit::club:
      symbol = u8"\u2663";
      break;
    default:
      symbol = u8"-error-";
  }

  os << symbol;
  return os;
}
}  // namespace cards