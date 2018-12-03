/* Copyright 2018 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

// GPU (ROCm / CUDA) specific type handle resolution

#ifndef TENSORFLOW_STREAM_EXECUTOR_GPU_GPU_TYPES_H_
#define TENSORFLOW_STREAM_EXECUTOR_GPU_GPU_TYPES_H_

#if TENSORFLOW_USE_ROCM
// #include "rocm/include/hip/hip_runtime.h"
#else // CUDA
#include "cuda/include/cuda.h"
#endif

namespace stream_executor {
namespace gpu {

#if TENSORFLOW_USE_ROCM

// using GpuStreamHandle = hipStream_t;
// using GpuEventHandle = hipEvent_t;
// using GpuFunctionHandle = hipFunction_t;
// using GpuFunctionAttribute = hipDeviceAttribute_t;  // not a typo!
// using GpuDeviceHandle = hipDevice_t;
// using GpuDevicePtr = hipDeviceptr_t;
// using GpuDeviceAttribute = hipDeviceAttribute_t;
// using GpuDeviceProperty = hipDeviceProp_t;
// using GpuModuleHandle = hipModule_t;
// using GpuStatus = hipError_t;
// using GpuFuncCachePreference = hipFuncCache_t;
// using GpuSharedMemConfig = hipSharedMemConfig;

#else // CUDA

using GpuStreamHandle = CUstream;
using GpuEventHandle = CUevent;
using GpuFunctionHandle = CUfunction;
using GpuFunctionAttribute = CUfunction_attribute;
using GpuDeviceHandle = CUdevice;
using GpuDevicePtr = CUdeviceptr;
using GpuDeviceAttribute = CUdevice_attribute;
using GpuDeviceProperty = CUdevprop;
using GpuModuleHandle = CUmodule;
using GpuStatus = CUresult;
using GpuFuncCachePreference = CUfunc_cache;
using GpuSharedMemConfig = CUsharedconfig;

#endif

}  // namespace gpu
}  // namespace stream_executor

#endif // TENSORFLOW_STREAM_EXECUTOR_GPU_GPU_TYPES_H_
