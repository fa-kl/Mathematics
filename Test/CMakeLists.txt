# Mathematics/Test/CMakeLists.txt
link_directories(../Utils)

# ComplexTest
add_executable(ComplexTest Utils/src/ComplexTest.cpp)
target_link_libraries(ComplexTest PRIVATE Utils gtest_main)
gtest_discover_tests(ComplexTest)