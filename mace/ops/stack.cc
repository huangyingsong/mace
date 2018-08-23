// Copyright 2018 Xiaomi, Inc.  All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "mace/ops/stack.h"

namespace mace {
namespace ops {

void Register_Stack(OperatorRegistryBase *op_registry) {
  MACE_REGISTER_OPERATOR(op_registry, OpKeyBuilder("Stack")
                                          .Device(DeviceType::CPU)
                                          .TypeConstraint<float>("T")
                                          .Build(),
                         StackOp<DeviceType::CPU, float>);
  MACE_REGISTER_OPERATOR(op_registry, OpKeyBuilder("Stack")
                                          .Device(DeviceType::CPU)
                                          .TypeConstraint<int32_t>("T")
                                          .Build(),
                         StackOp<DeviceType::CPU, int32_t>);
  MACE_REGISTER_OPERATOR(op_registry, OpKeyBuilder("Stack")
                                          .Device(DeviceType::GPU)
                                          .TypeConstraint<float>("T")
                                          .Build(),
                         StackOp<DeviceType::GPU, float>);
  MACE_REGISTER_OPERATOR(op_registry, OpKeyBuilder("Stack")
                                          .Device(DeviceType::GPU)
                                          .TypeConstraint<int32_t>("T")
                                          .Build(),
                         StackOp<DeviceType::GPU, int32_t>);
}

}  // namespace ops
}  // namespace mace
