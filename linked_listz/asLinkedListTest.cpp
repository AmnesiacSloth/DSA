#include "asLinkedList.h"
#include <gtest/gtest.h>

static const int SETUPSIZE = 6;
/*
 * Test Fixture for AmnesiacSloth's Custom Linked List Class :)
 */
class asLinkedListTest : public ::testing::Test {
protected:
    asLinkedList emptyLinked;
    asLinkedList baselineLink;
    // SetUp() invoked for each test individually
    // Meant to initialize common resources
    void SetUp() {
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

    // test after insertion

    // test after removal

    // test on initial prefilled LL

}
/**
 * Test empty()
 */
TEST_F(asLinkedListTest,EmptyFunctionality) {
    
}
/**
 * Test valueAt()
 */
TEST_F(asLinkedListTest,ValueAtFunctionality) {

}
/**
 * Test pushFront()
 */
TEST_F(asLinkedListTest,PushFrontFunctionality) {

}
/**
 * Test popFront()
 */
TEST_F(asLinkedListTest,PopFrontFunctionality) {

}
/**
 * Test pushBack()
 */
TEST_F(asLinkedListTest,PushBackFunctionality) {

}
/**
 * Test popBack()
 */
TEST_F(asLinkedListTest,PopBackFunctionality) {

}
/**
 * Test front()
 */
TEST_F(asLinkedListTest,FrontFunctionality) {

}
/**
 * Test back()
 */
TEST_F(asLinkedListTest,BackFunctionality) {

}

/**
* Test insert()
*/
TEST_F(asLinkedListTest,InsertFunctionality) {

}
/**
* Test erase()
*/
TEST_F(asLinkedListTest,EraseFunctionality) {

}
/**
* Test valueNFromEnd()
*/
TEST_F(asLinkedListTest,ValueNFromEndFunctionality) {

}
/**
* Test reverse()
*/
TEST_F(asLinkedListTest,ReverseFunctionality) {

}
/**
* Test removeValue()
*/
TEST_F(asLinkedListTest,RemoveValueFunctionality) {

}