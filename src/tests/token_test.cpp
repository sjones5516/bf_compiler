#include "../include/token.hpp"

#include <gtest/gtest.h>

TEST(TokenTest, BasicAssertions) {
  using namespace bf;
  std::vector<char> input = {'>', '<', '+', '-', '.', ',', '[', ']'};
  std::vector<Token> expected = {Token::kIncrementDataPointer,
                                 Token::kDecrementDataPointer,
                                 Token::kIncrementByte,
                                 Token::kDecrementByte,
                                 Token::kOutputByte,
                                 Token::kAcceptByte,
                                 Token::kStartLoop,
                                 Token::kEndLoop};
  std::vector<Token> actual = TokenizeChars(input);
  EXPECT_EQ(expected, actual);
}

TEST(TokenTest, RemovesComments) {
  using namespace bf;
  std::vector<char> input = {'>', 'a', 'b', '<'};
  std::vector<Token> expected = {Token::kIncrementDataPointer,
                                 Token::kDecrementDataPointer};
  std::vector<Token> actual = TokenizeChars(input);
  EXPECT_EQ(expected, actual);
}
