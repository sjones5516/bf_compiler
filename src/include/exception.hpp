#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP
#include <stdexcept>
#include <string>

namespace bf {
class SyntaxError : public std::runtime_error {
 private:
  inline static const std::string prefix = "Syntax Error: ";

 public:
  SyntaxError(const std::string& msg) : std::runtime_error(prefix + msg) {}
};

class UnexpectedTokenError : public SyntaxError {
 private:
  inline static const std::string prefix = "Unexpected token at ";

 public:
  UnexpectedTokenError(const std::string& index)
      : SyntaxError(prefix + index) {}
};

class UnmatchedBracketError : public SyntaxError {
 private:
  inline static const std::string prefix = "Unmatched bracket at ";

 public:
  UnmatchedBracketError(const std::string& index)
      : SyntaxError(prefix + index) {}
};
}  // namespace bf

#endif
