CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
SET(project ncio)
SET(subdir ${project})
PROJECT(${project} CXX C)

############################## compile settings ##############################
# choose the language standard
SET(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)
# strip symbols from release builds
SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s")
SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -s")
# compile flags
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Wno-unused-local-typedefs")
SET(CMAKE_THREAD_PREFER_PTHREAD TRUE)
# flag used for abi compatibility post-gcc-5.1
ADD_DEFINITIONS(-D_GLIBCXX_USE_CXX11_ABI=0 -D${project}_STATIC)

# main library
FILE(GLOB srcs ${PROJECT_SOURCE_DIR}/src/${subdir}/*.cpp)
ADD_LIBRARY(${project} STATIC ${srcs})
# google test
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/ext/googletest)
INCLUDE_DIRECTORIES(${gtest_SOURCE_DIR} ${gtest_SOURCE_DIR}/include)
# Doxygen
FIND_PACKAGE(Doxygen)
INCLUDE_DIRECTORIES(/usr/local/include)
# Curses
FIND_PACKAGE(Curses REQUIRED)
INCLUDE_DIRECTORIES(${CURSES_INCLUDE_DIR})

# version
SET(${project}_VERSION 1.0)
CONFIGURE_FILE(src/${subdir}/version_config.h.in ${CMAKE_BINARY_DIR}/generated/version_config.h)
INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR}/generated/)

# documentation
FILE(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/doc/html)
CONFIGURE_FILE(${PROJECT_SOURCE_DIR}/src/Doxyfile.in
  ${CMAKE_BINARY_DIR}/Doxyfile @ONLY)
ADD_CUSTOM_TARGET(doc ${DOXYGEN_EXECUTABLE}
  ${CMAKE_BINARY_DIR}/Doxyfile
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  COMMENT "Generating Doxygen documentation" VERBATIM
  )

# installation
SET(CMAKE_INSTALL_PREFIX "$ENV{HOME}")
FILE(GLOB headers ${PROJECT_SOURCE_DIR}/src/${subdir}/*.hpp)
INSTALL(FILES ${headers} DESTINATION include/${project})
INSTALL(DIRECTORY ${CMAKE_BINARY_DIR}/doc/html DESTINATION doc/${project})
INSTALL(TARGETS ${project}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  )

# custom targets
add_custom_target(format COMMAND ${CMAKE_COMMAND} -E env clang-format -i ${CMAKE_SOURCE_DIR}/src/ncio/*.hpp)
add_custom_target(tidy COMMAND ${CMAKE_COMMAND} -E env clang-tidy ${CMAKE_SOURCE_DIR}/src/ncio/*.hpp -extra-arg=std=c++17)

ADD_SUBDIRECTORY(tests)
ADD_SUBDIRECTORY(apps)
