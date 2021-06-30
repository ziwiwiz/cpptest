MESSAGE("测试工程当前目录: "  ${CMAKE_CURRENT_SOURCE_DIR})

# 查找 GTest 库
find_package(GTest REQUIRED)
# GTest 的头文件
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/test)

AUX_SOURCE_DIRECTORY("${CMAKE_CURRENT_SOURCE_DIR}" DIR_TESTS)

add_executable(test_func ${DIR_TESTS})

target_link_libraries(test_func
  PRIVATE
    example
    ${GTEST_BOTH_LIBRARIES}
    pthread
    gcov
  )

# automatic discovery of unit tests
include(GoogleTest)
gtest_discover_tests(test_func
  PROPERTIES
    LABELS "unit"
  DISCOVERY_TIMEOUT  # how long to wait (in seconds) before crashing
    240
  )
