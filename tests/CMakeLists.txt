# tests
ADD_DEFINITIONS("-DPUNCH_TEST_ROOT=\"${CMAKE_CURRENT_SOURCE_DIR}\"")
INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}")

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
  TARGET_LINK_LIBRARIES(${unit_test}_test ${project} stdc++ ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
  ADD_DEPENDENCIES(check ${unit_test}_test)
ENDFOREACH(src)

#ADD_DEFINITIONS(-DBOOST_ALL_NO_LIB)
