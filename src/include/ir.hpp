#ifndef IR_HPP
#define IR_HPP

#include <vector>

#include "token.hpp"

namespace bf {
class Command {};
class Parameterized {
 private:
  int n_;

 public:
  explicit Parameterized(int n) : n_(n) {}
  [[nodiscard]] inline const int get_n(void) { return n_; }
  inline void set_n(int n) { n_ = n; }
};

class IncPointer : public Command, public Parameterized {
  using Parameterized::Parameterized;
};
class DecPointer : public Command, public Parameterized {
  using Parameterized::Parameterized;
};
class IncByte : public Command, public Parameterized {
  using Parameterized::Parameterized;
};
class DecByte : public Command, public Parameterized {
  using Parameterized::Parameterized;
};
class Output : public Command {};
class Accept : public Command {};
class JumpForward : public Command {};
class JumpBackward : public Command {};

class Sequence {
 private:
  std::vector<Command> sequence_;

 public:
  Sequence(const std::vector<Token> tokens);
};

}  // namespace bf

#endif
