#include "asVector.h"
#include <gtest/gtest.h>

/*
 * Test Fixture for AmnesiacSloth's Custom Vector Class :)
 */
class asVectorTest : public ::testing::Test {
protected:
    asVector slothVec;
    // SetUp() invoked for each test individually
    // Meant to initialize common resources

    // TearDown() invoked at end of each test or at point of failure(?)
    // Cleans up resources utilized
    // Teardown not needed since destructor does everything

};

TEST_F(asVectorTest, isEmptyInitially) {
    SUCCEED();
}

TEST_F(asVectorTest,isTEST) {
    SUCCEED();
}