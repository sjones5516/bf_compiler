#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <vector>

namespace bf {
enum class Token {
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
[[nodiscard]] std::vector<Token> TokenizeChars(const std::vector<char>& input);
}  // namespace bf
#endif
