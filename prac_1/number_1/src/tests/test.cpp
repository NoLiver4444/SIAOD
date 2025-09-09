#include "test.h"

// Тесты для 1.a
TEST(a_1, test_1) {
    cout << "x : " << 255 << endl;
    cout << "maska : " << "00000001" << endl;
    cout << "move : " << 4 << endl;
    
    EXPECT_EQ(bit_mask(255, 1, 4), 239);
}

TEST(a_1, test_2) {
    cout << "x : " << 154 << endl;
    cout << "maska : " << "00000001" << endl;
    cout << "move : " << 4 << endl;

    EXPECT_EQ(bit_mask(154, 1, 4), 138);
}

TEST(a_1, test_3) {
    cout << "x : " << 73 << endl;
    cout << "maska : " << "00000001" << endl;
    cout << "move : " << 4 << endl;

    EXPECT_EQ(bit_mask(73, 1, 4), 73);
}

// Тесты для 1.б
TEST(b_1, test_1) {
    cout << "x : " << 0 << endl;
    cout << "maska : " << "00000001" << endl;
    cout << "move : " << 7 << endl;

    EXPECT_EQ(bit_mask_to_1(0, 1, 7), 128); }

TEST(b_1, test_2) { 
    cout << "x : " << 8 << endl;
    cout << "maska : " << "00000001" << endl;
    cout << "move : " << 7 << endl;

    EXPECT_EQ(bit_mask_to_1(8, 1, 7), 136); }

TEST(b_1, test_3) { 
    cout << "x : " << 1 << endl;
    cout << "maska : " << "00000001" << endl;
    cout << "move : " << 7 << endl;
    
    EXPECT_EQ(bit_mask_to_1(1, 1, 7), 129); }