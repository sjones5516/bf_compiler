#include "include/ir.hpp"

#include <stack>
#include <string>
#include <vector>

#include "include/exception.hpp"
#include "include/token.hpp"

namespace bf {
static Command MapToken(Token token) {
  switch (token.get_type()) {
    case TokenType::kIncrementDataPointer:
      return Command(CommandType::kIncPointer, 1);
      break;
    case TokenType::kDecrementDataPointer:
      return Command(CommandType::kDecPointer, 1);
      break;
    case TokenType::kIncrementByte:
      return Command(CommandType::kIncByte, 1);
      break;
    case TokenType::kDecrementByte:
      return Command(CommandType::kDecByte, 1);
      break;
    case TokenType::kOutputByte:
      return Command(CommandType::kOutput);
      break;
    case TokenType::kAcceptByte:
      return Command(CommandType::kAccept);
      break;
    case TokenType::kStartLoop:
      return Command(CommandType::kJumpForward);
      break;
    case TokenType::kEndLoop:
      return Command(CommandType::kJumpBackward, 1);
      break;
    default:
      throw UnexpectedTokenError(std::to_string(token.get_index()));
      break;
  }
}

Sequence::Sequence(const std::vector<Token> tokens) {
  std::stack<Token> token_stack;
  for (Token token : tokens) {
    // Iterate over every token and map to a command.
    // The only semantic analysis that needs to be done is ensure matching [ and
    Command command = MapToken(token);
    sequence_.push_back(command);

    if (token.get_type() == TokenType::kStartLoop) token_stack.push(token);

    if (token.get_type() == TokenType::kEndLoop) {
      if (token_stack.empty())
        throw UnmatchedBracketError(std::to_string(token.get_index()));

      token_stack.pop();
    }
  }

  if (!token_stack.empty()) {
    Token unmatched = token_stack.top();
    throw UnmatchedBracketError(std::to_string(unmatched.get_index()));
  }
}
}  // namespace bf
