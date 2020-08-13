find_package(PkgConfig)


find_path(MAGICK_INCLUDE_DIR NAMES Magick++.h PATHS ${CMAKE_CURRENT_SOURCE_DIR}/imagemagick/include/ )
find_library(MAGICK_LIBRARY NAMES CORE_RL_Magick++_  HINTS  ${CMAKE_CURRENT_SOURCE_DIR}/imagemagick/lib)

message(${MAGICK_LIBRARY})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(MAGICK DEFAULT_MSG
                                  MAGICK_LIBRARY MAGICK_INCLUDE_DIR)

mark_as_advanced(MAGICK_INCLUDE_DIR MAGICK_LIBRARY )


set(MAGICK_LIBRARIES ${MAGICK_LIBRARY} )
set(MAGICK_INCLUDE_DIRS ${MAGICK_INCLUDE_DIR} )



