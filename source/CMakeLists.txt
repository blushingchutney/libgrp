set(
    LIBKSGRP_SOURCE_FILES
    ksgrp.cxx
    ksgrp.hxx
)

add_library(
    ksgrp_static STATIC
    ${LIBKSGRP_SOURCE_FILES}
)

add_library(
    ksgrp_shared SHARED
    ${LIBKSGRP_SOURCE_FILES}
)

add_subdirectory(test)
