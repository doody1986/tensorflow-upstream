/* Copyright 2015 The TensorFlow Authors. All Rights Reserved.

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

#ifndef TENSORFLOW_STREAM_EXECUTOR_CUDA_CUDA_EVENT_H_
#define TENSORFLOW_STREAM_EXECUTOR_CUDA_CUDA_EVENT_H_

#include "tensorflow/stream_executor/cuda/cuda_driver.h"
#include "tensorflow/stream_executor/cuda/cuda_stream.h"
#include "tensorflow/stream_executor/event.h"
#include "tensorflow/stream_executor/lib/status.h"

namespace stream_executor {
namespace gpu {

// CUDAEvent wraps a GPUEventHandle in the platform-independent EventInterface
// interface.
class CUDAEvent : public internal::EventInterface {
 public:
  explicit CUDAEvent(CUDAExecutor* parent);

  ~CUDAEvent() override;

  // Populates the CUDA-platform-specific elements of this object.
  port::Status Init();

  // Deallocates any platform-specific elements of this object. This is broken
  // out (not part of the destructor) to allow for error reporting.
  port::Status Destroy();

  // Inserts the event at the current position into the specified stream.
  port::Status Record(CUDAStream* stream);

  // Polls the CUDA platform for the event's current status.
  Event::Status PollForStatus();

  // The underlying CUDA event element.
  GPUEventHandle cuda_event();

 private:
  // The Executor used to which this object and GPUEventHandle are bound.
  CUDAExecutor* parent_;

  // The underlying CUDA event element.
  GPUEventHandle cuda_event_;
};

}  // namespace gpu
}  // namespace stream_executor

#endif  // TENSORFLOW_STREAM_EXECUTOR_CUDA_CUDA_EVENT_H_
