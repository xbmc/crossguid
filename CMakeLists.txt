cmake_minimum_required(VERSION 3.2)

project(crossguid LANGUAGES CXX)

set(crossguid_VERSION 0.1)

if(MSVC)
  set(CMAKE_DEBUG_POSTFIX "d")
endif()


add_library(crossguid STATIC
  guid.h
  guid.cpp
)
target_include_directories(
  crossguid PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  INTERFACE
  $<INSTALL_INTERFACE:include>
)

target_compile_definitions(
  crossguid PUBLIC
  GUID_WINDOWS
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/crossguid-config-version.cmake
  VERSION ${crossguid_VERSION}
  COMPATIBILITY AnyNewerVersion
)

install(TARGETS crossguid EXPORT crossguid
  RUNTIME DESTINATION bin
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib)


install(FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/guid.h
  DESTINATION include)

install(EXPORT crossguid
  FILE
    crossguid.cmake
  NAMESPACE
    crossguid::
  DESTINATION
    lib/cmake/crossguid
)
install(
  FILES
    cmake/crossguid-config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/crossguid-config-version.cmake
  DESTINATION
    lib/cmake/crossguid
)