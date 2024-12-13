# Note that the source file should be suffixed with "cc",
# otherwise add the source file yourself.
file(GLOB SOURCES "*.cc")

add_library(GraphvizWrapper STATIC
    ${SOURCES}
)

# Set the header file search path.
# Note that to add a header file, start with the include subdirectory.
# e.g: #include "include/types.h"
target_include_directories(GraphvizWrapper PUBLIC
    ${CMAKE_SOURCE_DIR}/
)
