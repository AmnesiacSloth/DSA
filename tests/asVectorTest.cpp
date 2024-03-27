#include "asVector.h"
#include <gtest/gtest.h>

static const int BASICSETUPSIZE = 3;
/*
 * Test Fixture for AmnesiacSloth's Custom Vector Class :)
 */
class asVectorTest : public ::testing::Test {
protected:
    asVector slothVec;
    asVector slothVecEmpty;
    // SetUp() invoked for each test individually
    // Meant to initialize common resources
    void SetUp() override {
        // array should be [1,2,3,...]
        for (int i = 1; i <= BASICSETUPSIZE; i++) {
            slothVec.push(i);
        }
    }
    // TearDown() invoked at end of each test or at point of failure(?)
    // Cleans up resources utilized
    // Teardown not needed since destructor does everything



};

/**
 * Tests isEmpty()
 */
TEST_F(asVectorTest, IsEmpty) {
    // tests before and after adding an element to vector
    EXPECT_TRUE(slothVecEmpty.isEmpty());
    slothVec.push(4);
    EXPECT_FALSE(slothVec.isEmpty());
}

/**
* Tests at()
*/
TEST_F(asVectorTest, AtPosition) {
    // Test on vector with structure [1,2,3,...]
    EXPECT_EQ(slothVec.at(2),3);
    // Test on empty vector
    EXPECT_EQ(slothVecEmpty.at(0),-1);
    // Test on out of bounds via size
    EXPECT_EQ(slothVec.at(15),-1);
    // Test on out of bounds via capacity
    EXPECT_EQ( slothVec.at(20),-1);
}

/**
* Tests push()
*/
TEST_F(asVectorTest, PushFunctionality) {
    // Push on array with no elements
    EXPECT_TRUE(slothVecEmpty.push(1));
    // Push on prepopulated array
    EXPECT_TRUE(slothVec.push(4));
}
/**
* Tests insert()
*/
TEST_F(asVectorTest, InsertFunctionality) {
    // insert on empty array, greater than capacity
    EXPECT_FALSE(slothVecEmpty.insert(5,16));
    // insert on empty array with initial capacity of 16 elements, inserts at 15th position
    EXPECT_TRUE(slothVecEmpty.insert(5,15));


    EXPECT_TRUE(slothVec.insert(15,15)); // Insert into current final position
    // insert on prepopulated array, into index greater than capacity
    EXPECT_FALSE(slothVec.insert(18,16)); // Will fail since array has not had to resize
    // insert after array has resized
    for (int i = 3; i <= 8; i++) {
        slothVec.push(i);
    }
    std::cout << "Size after insertions: " <<slothVec.getSize() << std::endl;
    std::cout << "Capacity after insertions: " << slothVec.getCapacity() << std::endl;
    EXPECT_TRUE(slothVec.insert(25,31)); // insert into last elem of newly resized array

}

/**
* Tests prepend()
*/
TEST_F(asVectorTest, PrependFunctionality) {
    // prepend on prefilled array
    EXPECT_TRUE(slothVec.prepend(9));
    EXPECT_EQ(slothVec.at(0),9); // check if value in first idx was prepended
    // ensure that everything else got pushed over
    for (int i =1; i < slothVec.getSize();i++) {
        EXPECT_EQ(i,slothVec.at(i));
    }
}
/**
* Tests pop()
*/
TEST_F(asVectorTest, PopFunctionality) {
    // test on empty array
    EXPECT_EQ(slothVecEmpty.pop(),-1);
    // test on prefilled array
    EXPECT_EQ(slothVec.pop(), 1);
}
/**
* Tests deleteAt()
*/
TEST_F(asVectorTest, DeleteAtFunctionality) {
    // test on empty
    EXPECT_FALSE(slothVecEmpty.deleteAt(0));
    // test on prepopulated array
    EXPECT_TRUE(slothVec.deleteAt(1));
    EXPECT_EQ(slothVec.at(1),3); // check to see if elements were shifted
    EXPECT_EQ(slothVec.getSize(),2); // check for updated elements
}
/**
* Tests remove()
*/
TEST_F(asVectorTest, RemoveFunctionality) {
    EXPECT_EQ(0, slothVecEmpty.remove(1)); // remove element from already empty array
    EXPECT_EQ(1,slothVec.remove(1)); // remove single element
    slothVecEmpty.push(1);
    slothVecEmpty.push(1);
    EXPECT_EQ(2,slothVecEmpty.remove(1)); // remove multiple instances of element

}
/**
* Tests Find()
*/
TEST_F(asVectorTest, FindFunctionality) {
    // Find on single element in array
    EXPECT_EQ(0, slothVec.find(1)); // 1 should be at idx 0
    // find on element that doesn't exist in array
    EXPECT_EQ(-1, slothVec.find(8));

    slothVec.push(1);
    // Find on element that exists in array more than once
    EXPECT_EQ(0,slothVec.find(1));

}

/**
* Test resize()
*/
TEST_F(asVectorTest, ResizeFunctionality) {
    EXPECT_EQ(slothVecEmpty.getCapacity(),16);
    for (int i = 0; i < 15; i++) {
        slothVecEmpty.push(i+1);
    }
    EXPECT_EQ(slothVecEmpty.getCapacity(),32);
    for (int i = 0; i < 12;i++) {
        slothVecEmpty.pop();
    }
    EXPECT_EQ(slothVecEmpty.getCapacity(),16);
}