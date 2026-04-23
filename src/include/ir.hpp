#ifndef IR_HPP
#define IR_HPP

#include <vector>

#include "token.hpp"

namespace bf {
enum class CommandType {
  kIncPointer,
  kDecPointer,
  kIncByte,
  kDecByte,
  kOutput,
  kAccept,
  kJumpForward,
  kJumpBackward
};

class Command {
 private:
  int n_ = 0;
  CommandType command_type_;

 public:
  explicit Command(CommandType command_type) : command_type_(command_type) {}
  explicit Command(CommandType command_type, int n)
      : command_type_(command_type), n_(n) {}
  [[nodiscard]] inline const int get_n(void) { return n_; }
  inline void set_n(int n) { n_ = n; }
  [[nodiscard]] inline const CommandType get_command_type(void) {
    return command_type_;
  }
  inline void set_command_type(CommandType command_type) {
    command_type_ = command_type;
  }
};

class Sequence {
 private:
  std::vector<Command> sequence_;

 public:
  Sequence(const std::vector<Token>& tokens);
  Sequence(const std::vector<char>& chars) : Sequence(TokenizeChars(chars)) {};
  [[nodiscard]] inline const std::vector<Command> get_sequence(void) {
    return sequence_;
  }
};

}  // namespace bf

#endif
