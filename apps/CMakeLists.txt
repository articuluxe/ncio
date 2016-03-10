# apps
FILE(GLOB_RECURSE subdirs "*/CMakeLists.txt")
FOREACH(subdir ${subdirs})
  GET_FILENAME_COMPONENT(path ${subdir} PATH)
  GET_FILENAME_COMPONENT(target ${path} NAME)
  MESSAGE(STATUS "Creating app ${target}")
  ADD_SUBDIRECTORY(${path})
ENDFOREACH(subdir)

