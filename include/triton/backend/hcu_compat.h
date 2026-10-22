/*******************************************************************************
# Copyright (c) 2026 Hygon Information Technology Co., Ltd.
# SPDX-License-Identifier: BSD-3-Clause
*******************************************************************************/

// HCU (Hygon DTK / ROCm) compatibility shim for triton-backend-utils.
//
// When USE_HCU is defined this header pulls in the HIP runtime and maps the
// CUDA runtime names used by the backend onto their HIP equivalents, so the
// existing sources (public headers + .cc bodies) compile unchanged on the HCU
// path. When USE_HCU is not defined the header expands to nothing and the
// normal CUDA path is used.
//
#pragma once

#ifdef USE_HCU
#include <hip/hip_runtime.h>

#ifndef CUDART_CB
#define CUDART_CB
#endif

// Type aliases: keep the existing CUDA-named signatures valid on the HIP path.
using cudaStream_t = hipStream_t;
using cudaEvent_t = hipEvent_t;
using cudaError_t = hipError_t;
using cudaDeviceProp = hipDeviceProp_t;
using cudaMemcpyKind = hipMemcpyKind;

// Enumerators.
#define cudaSuccess hipSuccess
#define cudaErrorNoDevice hipErrorNoDevice
#define cudaErrorInsufficientDriver hipErrorInsufficientDriver
#define cudaMemcpyDefault hipMemcpyDefault
#define cudaMemcpyDeviceToDevice hipMemcpyDeviceToDevice
#define cudaMemcpyHostToDevice hipMemcpyHostToDevice
#define cudaMemcpyDeviceToHost hipMemcpyDeviceToHost
#define cudaHostAllocPortable hipHostMallocPortable
#define cudaStreamDefault hipStreamDefault

// Runtime API.
#define cudaGetErrorString hipGetErrorString
#define cudaGetLastError hipGetLastError
#define cudaGetDevice hipGetDevice
#define cudaSetDevice hipSetDevice
#define cudaGetDeviceCount hipGetDeviceCount
#define cudaGetDeviceProperties hipGetDeviceProperties
#define cudaStreamCreateWithPriority hipStreamCreateWithPriority
#define cudaStreamDestroy hipStreamDestroy
#define cudaStreamSynchronize hipStreamSynchronize
#define cudaEventRecord hipEventRecord
#define cudaEventSynchronize hipEventSynchronize
#define cudaLaunchHostFunc hipLaunchHostFunc
#define cudaMemcpy hipMemcpy
#define cudaMemcpyAsync hipMemcpyAsync
#define cudaMemcpyPeerAsync hipMemcpyPeerAsync
#define cudaHostAlloc hipHostAlloc
#define cudaFreeHost hipHostFree
#define cudaMalloc hipMalloc
#define cudaFree hipFree
#endif  // USE_HCU
