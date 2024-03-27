# Create test executables
# array
add_executable(array_tests asVectorTest.cpp)
target_link_libraries(array_tests gtest_main container_code)

# linked list
add_executable(linked_list_tests asLinkedListTest.cpp)
target_link_libraries(linked_list_tests gtest_main container_code)
# google test stuff
include(GoogleTest)
gtest_discover_tests(array_tests)
gtest_discover_tests(linked_list_tests)

