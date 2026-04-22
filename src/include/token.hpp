#ifndef TOKEN_HPP
#define TOKEN_HPP

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
  kEndLoop
};
}

#endif
