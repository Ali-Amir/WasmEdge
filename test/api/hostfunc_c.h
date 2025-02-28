// SPDX-License-Identifier: Apache-2.0
//===-- wasmedge/test/api/hostfunc_c.h - Spec test host functions for C API ==//
//
// Part of the WasmEdge Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file parse and run tests of Wasm test suites extracted by wast2json.
/// Test Suits: https://github.com/WebAssembly/spec/tree/master/test/core
/// wast2json: https://webassembly.github.io/wabt/doc/wast2json.1.html
///
//===----------------------------------------------------------------------===//

#ifndef __HOSTFUNC_C_H__
#define __HOSTFUNC_C_H__

#include "api/wasmedge.h"

#ifdef __cplusplus
extern "C" {
#endif

/// Function type: {} -> {}
WasmEdge_Result SpecTestPrint(void *Data,
                              WasmEdge_MemoryInstanceContext *MemCxt,
                              const WasmEdge_Value *In, WasmEdge_Value *Out);

/// Function type: {i32} -> {}
WasmEdge_Result SpecTestPrintI32(void *Data,
                                 WasmEdge_MemoryInstanceContext *MemCxt,
                                 const WasmEdge_Value *In, WasmEdge_Value *Out);

/// Function type: {f32} -> {}
WasmEdge_Result SpecTestPrintF32(void *Data,
                                 WasmEdge_MemoryInstanceContext *MemCxt,
                                 const WasmEdge_Value *In, WasmEdge_Value *Out);

/// Function type: {f64} -> {}
WasmEdge_Result SpecTestPrintF64(void *Data,
                                 WasmEdge_MemoryInstanceContext *MemCxt,
                                 const WasmEdge_Value *In, WasmEdge_Value *Out);

/// Function type: {i32, f32} -> {}
WasmEdge_Result SpecTestPrintI32F32(void *Data,
                                    WasmEdge_MemoryInstanceContext *MemCxt,
                                    const WasmEdge_Value *In,
                                    WasmEdge_Value *Out);

/// Function type: {f64, f64} -> {}
WasmEdge_Result SpecTestPrintF64F64(void *Data,
                                    WasmEdge_MemoryInstanceContext *MemCxt,
                                    const WasmEdge_Value *In,
                                    WasmEdge_Value *Out);

WasmEdge_ImportObjectContext *createSpecTestModule();

#ifdef __cplusplus
} /// extern "C"
#endif

#endif /// __HOSTFUNC_C_H__
