#include "../include/ir.hpp"

#include <gtest/gtest.h>

#include <cstddef>
#include <stack>

#include "../include/exception.hpp"

static bool ValidateLabels(bf::Sequence& sequence) {
  std::stack<size_t> label_stack;
  for (bf::Command command : sequence.get_sequence()) {
    bf::CommandType command_type = command.get_command_type();
    if (command_type == bf::CommandType::kJumpForward) {
      label_stack.push(command.get_n());
    }

    if (command_type == bf::CommandType::kJumpBackward) {
      size_t expected_label = command.get_n();

      if (label_stack.empty() || expected_label != label_stack.top()) {
        return false;
      }

      label_stack.pop();
    }
  }

  return label_stack.empty();
}

TEST(SequenceTest, MatchLabels) {
  using namespace bf;
  std::vector<char> input = {'[', '[', ']', '[', ']', ']'};
  Sequence sequence(input);
  EXPECT_TRUE(ValidateLabels(sequence));
}

TEST(SequenceTest, UnmatchedBracket) {
  using namespace bf;
  std::vector<char> input = {'[', ']', '[', ']', ']'};
  EXPECT_THROW(new Sequence(input), UnmatchedBracketError);
}
