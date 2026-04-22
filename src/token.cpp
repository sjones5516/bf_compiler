#include "include/token.hpp"

#include <cstddef>

namespace bf {
static Token MapChar(const char& token) {
  /*
   * Maps a character to the corresponding token enum.
   */
  switch (token) {
    case '>':
      return Token::kIncrementDataPointer;
      break;
    case '<':
      return Token::kDecrementDataPointer;
      break;
    case '+':
      return Token::kIncrementByte;
      break;
    case '-':
      return Token::kDecrementByte;
      break;
    case '.':
      return Token::kOutputByte;
      break;
    case ',':
      return Token::kAcceptByte;
      break;
    case '[':
      return Token::kStartLoop;
      break;
    case ']':
      return Token::kEndLoop;
      break;
    default:
      return Token::kComment;
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
    Token mapped = MapChar(input[i]);
    if (mapped != Token::kComment) output.push_back(mapped);
  }

  return output;
}
}  // namespace bf
