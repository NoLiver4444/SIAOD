#include "test.h"

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}

TEST(AVL_TREE, construct_no_args) {
  AVL_Tree<int, int> tree_1;
  AVL_Tree<int, int> *tree_2 = new AVL_Tree<int, int>();

  EXPECT_TRUE(tree_1.eq_Tree(tree_2));
  delete tree_2;
}