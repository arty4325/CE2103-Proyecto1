# Find the SDL2 library
#
#  SDL2_INCLUDE_DIRS - where to find SDL.h, etc.
#  SDL2_LIBRARIES    - List of libraries when using SDL2.
#  SDL2_FOUND        - True if SDL2 found.

find_path(SDL2_INCLUDE_DIR SDL.h PATH_SUFFIXES SDL2)
find_library(SDL2_LIBRARY NAMES SDL2)

set(SDL2_LIBRARIES ${SDL2_LIBRARY})
set(SDL2_INCLUDE_DIRS ${SDL2_INCLUDE_DIR})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SDL2 DEFAULT_MSG SDL2_LIBRARY SDL2_INCLUDE_DIR)

mark_as_advanced(SDL2_INCLUDE_DIR SDL2_LIBRARY)
