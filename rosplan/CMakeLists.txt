
include(DownloadProject)
download_project(PROJ                googletest
                 GIT_REPOSITORY      https://github.com/google/googletest.git
                 GIT_TAG             master
                 ${UPDATE_DISCONNECTED_IF_AVAILABLE}
)
add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

include_directories(
    ./test/fwk/rosplan_planning_system/
    ./test/fwk
    include
    ${GTEST_INCLUDE_DIRS}
)
set(PRODUCT_SOURCES
    src/PlanParsing/FFPlanParser.cpp)

add_executable(test_ff_plan_parser test/test_ff_parser.cpp ${PRODUCT_SOURCES})
target_link_libraries(test_ff_plan_parser gtest gmock_main)

add_executable(print_actions test/print_actions.cpp ${PRODUCT_SOURCES})
