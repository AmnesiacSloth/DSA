#include "asLinkedList.h"
#include <gtest/gtest.h>

static const int SETUPSIZE = 6;
static const int ZERO = 0;
/*
 * Test Fixture for AmnesiacSloth's Custom Linked List Class :)
 */
class asLinkedListTest : public ::testing::Test {
protected:
    asLinkedList<int> emptyLinked; // initially 0
    asLinkedList<int> baselineLink; // initially has 6 elements
    // SetUp() invoked for each test individually
    // Meant to initialize common resources
    void SetUp() {
        // enter dummy values
        for (int i = 0; i < SETUPSIZE; i++) {
            baselineLink.pushBack(i+1);
        }
    }
    // TearDown() invoked at end of each test or at point of failure(?)
    // Cleans up resources utilized
    // Teardown not needed since destructor does everything

    void TearDown() {
        return;
    }
};


/**
 * Test size()
 */
TEST_F(asLinkedListTest, SizeFunctionality) {
    // test on initial empty LL
    EXPECT_EQ(emptyLinked.getSize() , 0);
    // test after insertion
    emptyLinked.insert(0,4);
    EXPECT_EQ(emptyLinked.getSize(), 1 );
    // test after removal
    emptyLinked.popFront();
    EXPECT_EQ(emptyLinked.getSize(), 0);
    // test on initial prefilled LL
    EXPECT_EQ(baselineLink.getSize() , 6);
}
/**
 * Test empty()
 */
TEST_F(asLinkedListTest,EmptyFunctionality) {
    // test on initially empty LL
    EXPECT_TRUE(emptyLinked.isEmpty());
    // test on initially prefilled linked list
    EXPECT_FALSE(baselineLink.isEmpty());
}
/**
 * Test valueAt()
 */
TEST_F(asLinkedListTest,ValueAtFunctionality) {
    // Test value out of bounds
    EXPECT_EQ(emptyLinked.valueAt(3), -1 );
    // Test value within bounds
    EXPECT_EQ(baselineLink.valueAt(3),4);
}
/**
 * Test pushFront()
 */
TEST_F(asLinkedListTest,PushFrontFunctionality) {
    // check before and after pushfront() on empty list
    EXPECT_EQ(emptyLinked.valueAt(0),-1);
    emptyLinked.pushFront(7);
    EXPECT_EQ(emptyLinked.valueAt(0),7);
    // check before and after pushfront() on list with preexisting values
    EXPECT_EQ(baselineLink.valueAt(0),1);
    baselineLink.pushFront(7);
    EXPECT_EQ(baselineLink.valueAt(0),7);
}
/**
 * Test popFront()
 */
TEST_F(asLinkedListTest,PopFrontFunctionality) {
    // check on empty list
    EXPECT_EQ(emptyLinked.popFront(),-1);

    // check on list with held values
    for (int i = 0; i < SETUPSIZE; i++) {
        EXPECT_EQ(baselineLink.popFront(),i+1);
    }
    // check that values were all popped from list
    EXPECT_EQ(baselineLink.getSize(),0);
}
/**
 * Test pushBack()
 */
TEST_F(asLinkedListTest,PushBackFunctionality) {
    // test size on prefilled list
    EXPECT_EQ(baselineLink.getSize(),SETUPSIZE);
    for (int i = 0; i < 3; i++) {
        baselineLink.pushBack(i);
    }
    // test that all elements were inserted
    EXPECT_EQ(baselineLink.getSize(),SETUPSIZE+3);
    EXPECT_EQ(baselineLink.back(), 2); // check that the last element is 2
}
/**
 * Test popBack()
 */
TEST_F(asLinkedListTest,PopBackFunctionality) {
    // test size on prefilled list
    EXPECT_EQ(baselineLink.getSize(),SETUPSIZE);
    for (int i = SETUPSIZE; i > 0; i++) {
        EXPECT_EQ(baselineLink.popBack(),i);
    }
    // test that all elements were inserted
    EXPECT_EQ(baselineLink.getSize(),0); // test that list was emptied
}
/**
 * Test front()
 */
TEST_F(asLinkedListTest,FrontFunctionality) {
    // check before and after a pop
    EXPECT_EQ(baselineLink.front(), 1);
    baselineLink.popFront();
    EXPECT_EQ(baselineLink.front(),2);
}
/**
 * Test back()
 */
TEST_F(asLinkedListTest,BackFunctionality) {
    // check before and after a pop
    EXPECT_EQ(baselineLink.getSize(),SETUPSIZE);
    EXPECT_EQ(baselineLink.back(), 6);
    baselineLink.popBack();
    EXPECT_EQ(baselineLink.getSize(),SETUPSIZE-1);
    EXPECT_EQ(baselineLink.back(),5);
}

/**
* Test insert()
*/
TEST_F(asLinkedListTest,InsertFunctionality) {
    // Test on inserting many elements
    EXPECT_EQ(emptyLinked.getSize(),0);
    for (int i = 0; i < SETUPSIZE; i++) {
        emptyLinked.insert(i,i+1);
        EXPECT_EQ(emptyLinked.back(), i+1);
    }
    EXPECT_EQ(emptyLinked.getSize(), SETUPSIZE);
    // Test on out-of-bounds insert
    emptyLinked.insert(17,9);
    EXPECT_EQ(emptyLinked.getSize(),6);
}
/**
* Test erase()
*/
TEST_F(asLinkedListTest,EraseFunctionality) {
    // test on index outside of bounds
    baselineLink.erase(9);
    EXPECT_EQ(baselineLink.getSize(),SETUPSIZE);
    // test erasing an element in the middle of a list
    EXPECT_EQ(baselineLink.valueAt(1),2);
    EXPECT_EQ(baselineLink.valueAt(2),3);
    baselineLink.erase(2);
    EXPECT_EQ(baselineLink.valueAt(1),2); // make sure 2nd element at in list remains the same
    EXPECT_EQ(baselineLink.valueAt(2),4); // 3rd element was removed and replaced

}
/**
* Test valueNFromEnd()
*/
TEST_F(asLinkedListTest,ValueNFromEndFunctionality) {
    // test on n =0, no different from back()
    EXPECT_EQ(baselineLink.valueNFromEnd(0),6);
    // test on n that keeps search within bounds
    EXPECT_EQ(baselineLink.valueNFromEnd(4),2);
    // test on n that goes past bounds
    EXPECT_EQ(baselineLink.valueNFromEnd(8),-1);
}
/**
* Test reverse()
*/
TEST_F(asLinkedListTest,ReverseFunctionality) {
    int arr[6] = {6,5,4,3,2,1};
    baselineLink.reverse();
    // check correct order reversal
    for (int i = 0; i < SETUPSIZE; i++) {
        EXPECT_EQ(baselineLink.valueAt(i),arr[i]);

    }
}
/**
* Test removeValue()
*/
TEST_F(asLinkedListTest,RemoveValueFunctionality) {
    EXPECT_EQ(baselineLink.getSize(),6); // get size of list before insertions
    baselineLink.pushBack(3);
    baselineLink.pushBack(3);
    EXPECT_EQ(baselineLink.getSize(), 8); // get size of list after insertions

    baselineLink.removeValue(3);
    EXPECT_EQ(baselineLink.getSize(),5); // remove 3 instances of value 3 in the list; size 8->5
}