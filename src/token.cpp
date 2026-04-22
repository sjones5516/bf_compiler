#include "include/token.hpp"

#include <cstddef>

namespace bf {
static TokenType MapChar(const char& token) {
  /*
   * Maps a character to the corresponding token enum.
   */
  switch (token) {
    case '>':
      return TokenType::kIncrementDataPointer;
      break;
    case '<':
      return TokenType::kDecrementDataPointer;
      break;
    case '+':
      return TokenType::kIncrementByte;
      break;
    case '-':
      return TokenType::kDecrementByte;
      break;
    case '.':
      return TokenType::kOutputByte;
      break;
    case ',':
      return TokenType::kAcceptByte;
      break;
    case '[':
      return TokenType::kStartLoop;
      break;
    case ']':
      return TokenType::kEndLoop;
      break;
    default:
      return TokenType::kComment;
      break;
  }
}

[[nodiscard]] std::vector<Token> TokenizeChars(const std::vector<char>& input) {
  /*
   * Maps a vector of characters into a vector of Tokens.
   */
  // Allocate space for output
  size_t input_size = input.size();
  std::vector<Token> output;

  // Iterate over every character and map it to a token enum
  for (size_t i = 0; i < input_size; i++) {
    TokenType mapped = MapChar(input[i]);
    if (mapped != TokenType::kComment) output.push_back(Token(mapped, i));
  }

  return output;
}
}  // namespace bf
