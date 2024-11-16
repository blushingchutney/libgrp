add_executable(
    test
    test.cxx
)
target_link_libraries(
    test PRIVATE
    ksgrp_shared
)
target_include_directories(
    test PRIVATE
    ${CMAKE_SOURCE_DIR}/source
)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/test.grp
    ${CMAKE_CURRENT_BINARY_DIR}/test.grp
    COPYONLY
)
