#include "../include/token.hpp"

#include <gtest/gtest.h>

TEST(TokenTest, BasicAssertions) {
  using namespace bf;
  std::vector<char> input = {'>', '<', '+', '-', '.', ',', '[', ']'};
  std::vector<Token> actual = TokenizeChars(input);
  EXPECT_EQ(actual[0].get_type(), TokenType::kIncrementDataPointer);
  EXPECT_EQ(actual[1].get_type(), TokenType::kDecrementDataPointer);
  EXPECT_EQ(actual[2].get_type(), TokenType::kIncrementByte);
  EXPECT_EQ(actual[3].get_type(), TokenType::kDecrementByte);
  EXPECT_EQ(actual[4].get_type(), TokenType::kOutputByte);
  EXPECT_EQ(actual[5].get_type(), TokenType::kAcceptByte);
  EXPECT_EQ(actual[6].get_type(), TokenType::kStartLoop);
  EXPECT_EQ(actual[7].get_type(), TokenType::kEndLoop);
}

TEST(TokenTest, RemovesComments) {
  using namespace bf;
  std::vector<char> input = {'>', 'a', 'b', '<'};
  std::vector<Token> actual = TokenizeChars(input);
  EXPECT_EQ(actual.size(), 2);
  EXPECT_EQ(actual[0].get_type(), TokenType::kIncrementDataPointer);
  EXPECT_EQ(actual[0].get_type(), TokenType::kDecrementDataPointer);
}
