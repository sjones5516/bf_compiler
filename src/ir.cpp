#include "include/ir.hpp"

#include <cstddef>
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
    case TokenType::kDecrementDataPointer:
      return Command(CommandType::kDecPointer, 1);
    case TokenType::kIncrementByte:
      return Command(CommandType::kIncByte, 1);
    case TokenType::kDecrementByte:
      return Command(CommandType::kDecByte, 1);
    case TokenType::kOutputByte:
      return Command(CommandType::kOutput);
    case TokenType::kAcceptByte:
      return Command(CommandType::kAccept);
    case TokenType::kStartLoop:
      // Label is defined later
      return Command(CommandType::kJumpForward);
    case TokenType::kEndLoop:
      // Label is defined later
      return Command(CommandType::kJumpBackward, 1);
    default:
      throw UnexpectedTokenError(std::to_string(token.get_index()));
  }
}

Sequence::Sequence(const std::vector<Token>& tokens) {
  std::stack<std::pair<size_t, size_t>> token_stack;
  size_t label_ct = 0;

  for (Token token : tokens) {
    // Iterate over every token and map to a command.
    // The only semantic analysis that needs to be done is ensure matching [ and
    Command command = MapToken(token);

    if (token.get_type() == TokenType::kStartLoop) {
      token_stack.push({label_ct, token.get_index()});
      command.set_n(label_ct++);
    }

    if (token.get_type() == TokenType::kEndLoop) {
      if (token_stack.empty())
        throw UnmatchedBracketError(std::to_string(token.get_index()));

      command.set_n(token_stack.top().first);
      token_stack.pop();
    }

    sequence_.push_back(command);
  }

  if (!token_stack.empty()) {
    /// TODO add missing token index
    size_t top_token_index = token_stack.top().second;
    throw UnmatchedBracketError(std::to_string(top_token_index));
  }
}
}  // namespace bf
