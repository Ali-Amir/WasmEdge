// SPDX-License-Identifier: Apache-2.0
//===-- wasmedge/test/ast/moduleTest.cpp - AST module unit tests ----------===//
//
// Part of the WasmEdge Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contents unit tests of AST module node and the main function.
///
//===----------------------------------------------------------------------===//

#include "ast/module.h"
#include "loader/filemgr.h"
#include "gtest/gtest.h"

namespace {

WasmEdge::FileMgr Mgr;
WasmEdge::Configure Conf;

TEST(ModuleTest, LoadInvalidModule) {
  /// 1. Test load empty file
  WasmEdge::AST::Module Mod;
  EXPECT_FALSE(Mod.loadBinary(Mgr, Conf));
}

TEST(ModuleTest, LoadEmptyModule) {
  /// 2. Test load empty module
  WasmEdge::AST::Module Mod;
  std::vector<unsigned char> Vec = {0x00U, 0x61U, 0x73U, 0x6DU,
                                    0x01U, 0x00U, 0x00U, 0x00U};
  Mgr.setCode(Vec);
  EXPECT_TRUE(Mod.loadBinary(Mgr, Conf) && Mgr.getRemainSize() == 0);
}

TEST(ModuleTest, LoadValidSecModule) {
  /// 3. Test load module with valid empty sections
  WasmEdge::AST::Module Mod;
  std::vector<unsigned char> Vec = {
      0x00U, 0x61U, 0x73U, 0x6DU,                      /// Magic
      0x01U, 0x00U, 0x00U, 0x00U,                      /// Version
      0x00U, 0x80U, 0x80U, 0x80U, 0x80U, 0x00U,        /// Custom section
      0x01U, 0x81U, 0x80U, 0x80U, 0x80U, 0x00U, 0x00U, /// Type section
      0x02U, 0x81U, 0x80U, 0x80U, 0x80U, 0x00U, 0x00U, /// Import section
      0x03U, 0x81U, 0x80U, 0x80U, 0x80U, 0x00U, 0x00U, /// Function section
      0x04U, 0x81U, 0x80U, 0x80U, 0x80U, 0x00U, 0x00U, /// Table section
      0x05U, 0x81U, 0x80U, 0x80U, 0x80U, 0x00U, 0x00U, /// Memory section
      0x06U, 0x81U, 0x80U, 0x80U, 0x80U, 0x00U, 0x00U, /// Global section
      0x07U, 0x81U, 0x80U, 0x80U, 0x80U, 0x00U, 0x00U, /// Export section
      0x08U, 0x81U, 0x80U, 0x80U, 0x80U, 0x00U, 0x00U, /// Start section
      0x09U, 0x81U, 0x80U, 0x80U, 0x80U, 0x00U, 0x00U, /// Element section
      0x0AU, 0x81U, 0x80U, 0x80U, 0x80U, 0x00U, 0x00U, /// Code section
      0x0BU, 0x81U, 0x80U, 0x80U, 0x80U, 0x00U, 0x00U  /// Data section
  };
  Mgr.setCode(Vec);
  EXPECT_TRUE(Mod.loadBinary(Mgr, Conf) && Mgr.getRemainSize() == 0);
}

TEST(ModuleTest, LoadInvalidSecModule) {
  /// 4. Test load module with invalid sections
  WasmEdge::AST::Module Mod;
  std::vector<unsigned char> Vec = {
      0x00U, 0x61U, 0x73U, 0x6DU,                      /// Magic
      0x01U, 0x00U, 0x00U, 0x00U,                      /// Version
      0x00U, 0x80U, 0x80U, 0x80U, 0x80U, 0x00U,        /// Custom section
      0x01U, 0x81U, 0x80U, 0x80U, 0x80U, 0x00U, 0x00U, /// Type section
      0x02U, 0x81U, 0x80U, 0x80U, 0x80U, 0x00U, 0x00U, /// Import section
      0x03U, 0x81U, 0x80U, 0x80U, 0x80U, 0x00U, 0x00U, /// Function section
      0x04U, 0x81U, 0x80U, 0x80U, 0x80U, 0x00U, 0x00U, /// Table section
      0x05U, 0x81U, 0x80U, 0x80U, 0x80U, 0x00U, 0x00U, /// Memory section
      0x06U, 0x81U, 0x80U, 0x80U, 0x80U, 0x00U, 0x00U, /// Global section
      0x07U, 0x81U, 0x80U, 0x80U, 0x80U, 0x00U, 0x00U, /// Export section
      0x08U, 0x81U, 0x80U, 0x80U, 0x80U, 0x00U, 0x00U, /// Start section
      0x09U, 0x81U, 0x80U, 0x80U, 0x80U, 0x00U, 0x00U, /// Element section
      0x0AU, 0x81U, 0x80U, 0x80U, 0x80U, 0x00U, 0x00U, /// Code section
      0x0BU, 0x81U, 0x80U, 0x80U, 0x80U, 0x00U, 0x00U, /// Data section
      0x0DU, 0x81U, 0x80U, 0x80U, 0x80U, 0x00U, 0x00U  /// Invalid section
  };
  Mgr.setCode(Vec);
  EXPECT_FALSE(Mod.loadBinary(Mgr, Conf));
}

} // namespace

GTEST_API_ int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
