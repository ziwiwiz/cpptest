CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
MESSAGE("源程序工程当前目录: "  ${CMAKE_CURRENT_SOURCE_DIR})

AUX_SOURCE_DIRECTORY("${CMAKE_CURRENT_SOURCE_DIR}" DIR_SRCS)

add_executable(main ${DIR_SRCS})

add_library(example SHARED)

target_sources(example
  PRIVATE
    callfun.cpp
    func.cpp
  )

target_include_directories(example
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )

# we use this to get code coverage
# flags are only valid with the GNU compiler and on Linux
set(ENABLE_COVERAGE FALSE)
if(ENABLE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES GNU AND CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Use gcov for code coverage test")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
    target_compile_options(example
    PUBLIC
      "--coverage"
    )
    target_link_options(example
    INTERFACE
      "--coverage"
    )
endif()