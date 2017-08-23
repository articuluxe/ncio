# tests
ADD_DEFINITIONS("-DNCIO_TEST_ROOT=\"${CMAKE_CURRENT_SOURCE_DIR}\"")
INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/src")

FIND_PACKAGE(Threads REQUIRED)
ENABLE_TESTING()
ADD_CUSTOM_TARGET(check COMMAND ${CMAKE_CTEST_COMMAND} --verbose)

FILE(GLOB srcs "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
FOREACH(src ${srcs})
  GET_FILENAME_COMPONENT(basename ${src} NAME_WE)
  SET(unit_test "${project}_${basename}")
  MESSAGE(STATUS "Creating unit test ${unit_test}")
  ADD_EXECUTABLE(${unit_test}_test EXCLUDE_FROM_ALL ${src})
  ADD_TEST(${unit_test}_test ${unit_test}_test)
  TARGET_LINK_LIBRARIES(${unit_test}_test gtest gtest_main)
  if(NOT ${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	SET(RTLIB -lrt)
  ENDIF()
  TARGET_LINK_LIBRARIES(${unit_test}_test ${project} stdc++ ${CMAKE_THREAD_LIBS_INIT} ${RTLIB})
  ADD_DEPENDENCIES(check ${unit_test}_test)
ENDFOREACH(src)

#ADD_DEFINITIONS(-DBOOST_ALL_NO_LIB)
