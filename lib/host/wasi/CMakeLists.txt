# SPDX-License-Identifier: Apache-2.0

add_library(wasmedgeHostModuleWasi
  wasienv.cpp
  wasifunc.cpp
  wasimodule.cpp
)

target_include_directories(wasmedgeHostModuleWasi
  PUBLIC
  ${Boost_INCLUDE_DIRS}
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/thirdparty
)

target_link_libraries(wasmedgeHostModuleWasi
  PUBLIC
  Threads::Threads
)

target_link_libraries(wasmedgeHostModuleWasi
  PRIVATE
  wasmedgeSystem
)

if(NOT CMAKE_SYSTEM_NAME STREQUAL Darwin)
  target_link_libraries(wasmedgeHostModuleWasi
    PUBLIC
    rt
  )
endif()
