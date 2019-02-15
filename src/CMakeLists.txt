add_library(interval_merge_lib STATIC "${CMAKE_CURRENT_SOURCE_DIR}/Interval.cxx")
add_library(Merge::Intervals ALIAS interval_merge_lib)
target_include_directories(interval_merge_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable (interval_merge  "${CMAKE_CURRENT_SOURCE_DIR}/main.cxx")
target_link_libraries(interval_merge PRIVATE Merge::Intervals)

