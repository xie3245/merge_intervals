set(PROJECT_TEST_NAME ${PROJECT_NAME}_tests)

include(ParseAndAddCatchTests)

add_executable (${PROJECT_TEST_NAME}  ${CATCH_MAIN_FILE} merge_tests.cxx)
target_link_libraries(${PROJECT_TEST_NAME} PUBLIC Catch2::Catch2 Merge::Intervals)

ParseAndAddCatchTests (${PROJECT_TEST_NAME})

