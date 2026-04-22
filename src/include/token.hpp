#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <cstddef>
#include <vector>

namespace bf {
enum class TokenType {
  /*
   * Represents all executable tokens in a BF program.
   */
  kIncrementDataPointer,
  kDecrementDataPointer,
  kIncrementByte,
  kDecrementByte,
  kOutputByte,
  kAcceptByte,
  kStartLoop,
  kEndLoop,
  kComment
};

class Token {
 public:
  Token(TokenType type, size_t index) : type(type), index(index) {}
  [[nodiscard]] inline const TokenType get_type(void) { return type; }
  [[nodiscard]] inline const size_t get_index(void) { return index; }

 private:
  TokenType type;
  size_t index;
};

[[nodiscard]] std::vector<Token> TokenizeChars(const std::vector<char>& input);
}  // namespace bf
#endif
