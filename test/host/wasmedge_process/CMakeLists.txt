# SPDX-License-Identifier: Apache-2.0

add_executable(wasmedgeProcessTests
  wasmedge_process.cpp
)

add_test(wasmedgeProcessTests wasmedgeProcessTests)

target_link_libraries(wasmedgeProcessTests
  PRIVATE
  wasmedgeAST
  wasmedgeHostModuleWasmEdgeProcess
  utilGoogleTest
)

target_include_directories(wasmedgeProcessTests
  PRIVATE
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/thirdparty
)
