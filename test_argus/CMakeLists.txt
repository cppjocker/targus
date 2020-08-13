cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)


project(targus)

set(CMAKE_SKIP_RPATH ON)
set(CMAKE_SKIP_INSTALL_RPATH ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR OFF)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(INSTALL_BIN_DIR bin CACHE PATH "Installation directory for executables")


# Compilers setup
if(MSVC)
  set(CMAKE_DEBUG_POSTFIX d)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc")
endif()





set(targus_HEADER_FILES
	test_argus/BlurCommand.h
	test_argus/Command.h
	test_argus/ExitCommand.h
	test_argus/FactoryCommands.h
	test_argus/HelpCommand.h
	test_argus/LoadCommand.h
	test_argus/ResizeCommand.h
	test_argus/StoreCommand.h
	test_argus/utility.h
)

set(targus_SOURCE_FILES
	test_argus/BlurCommand.cpp
	test_argus/Command.cpp
	test_argus/ExitCommand.cpp
	test_argus/FactoryCommands.cpp
	test_argus/HelpCommand.cpp
	test_argus/LoadCommand.cpp
	test_argus/ResizeCommand.cpp
	test_argus/StoreCommand.cpp
)




add_executable( targus test_argus/main.cpp ${targus_SOURCE_FILES} ${targus_HEADER_FILES}  )


# Magick
find_package(Magick REQUIRED)


target_include_directories(targus PRIVATE  ${MAGICK_INCLUDE_DIRS})
target_link_libraries(targus  ${MAGICK_LIBRARIES} )

