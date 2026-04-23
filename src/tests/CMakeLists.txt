target_sources(BF_test PRIVATE
  token_test.cpp
  ir_test.cpp
)

target_link_libraries(BF_test
PRIVATE BF_Core
)
