cmake_minimum_required (VERSION 2.8.4)

project(algogen)

set(SOURCE_FILES main.cpp motmystere.cpp population.cpp)

add_executable(algogen ${SOURCE_FILES})

set(TEST_FILES tests/tests.cpp tests/testf.cpp)

set(BOOST_DIR /Users/moreau/dev/local/boost)

include_directories(. ${BOOST_DIR})

enable_testing()
add_executable(test_exe tests/tests.cpp motmystere.cpp )
add_executable(testf_exe tests/testf.cpp motmystere.cpp population.cpp)
add_test(TestMot test_exe)
add_test(TestPop testf_exe)
