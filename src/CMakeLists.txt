# Add your algorithm sources to the list below (space delimited):
set(SOURCES sources/playlist.cpp sources/interface.cpp)
# Add your headers to the list below (space delimited):
set(HEADERS headers/playlist.h headers/interface.h)
# Add your test files to the list below (space delimited):
set(SOURCES_TEST tests/playlist_test.cpp)
set(SOURCES_MAIN sources/main.cpp)

SET(GCC_WARNINGS_COMPILE_FLAGS "-Wall -Wextra -pedantic -Werror")
SET(GCC_UB_COMPILE_FLAGS    "-fsanitize=undefined")

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_WARNINGS_COMPILE_FLAGS}")
# Uncomment the following line to find undefined behavior:
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_UB_COMPILE_FLAGS}")

add_executable(playlist_test ${SOURCES_TEST} ${SOURCES} ${HEADERS})
add_executable(playlist ${SOURCES_MAIN} ${SOURCES} ${HEADERS})

target_include_directories(playlist PRIVATE headers)
target_include_directories(playlist_test PRIVATE headers)
target_link_libraries(playlist_test Catch2::Catch2WithMain)

add_custom_target(test
    COMMAND playlist_test
    DEPENDS playlist_test
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)

add_custom_target(run
    COMMAND playlist
    DEPENDS playlist
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
