// Ceres Solver - A fast non-linear least squares minimizer
// Copyright 2010, 2011, 2012 Google Inc. All rights reserved.
// http://code.google.com/p/ceres-solver/
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
// * Neither the name of Google Inc. nor the names of its contributors may be
//   used to endorse or promote products derived from this software without
//   specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// Author: sameeragarwal@google.com (Sameer Agarwal)
//         keir@google.com (Keir Mierle)

#include "ceres/problem.h"

#include <vector>
#include "ceres/problem_impl.h"

namespace ceres {

class ResidualBlock;

Problem::Problem() : problem_impl_(new internal::ProblemImpl) {}
Problem::Problem(const Problem::Options& options)
    : problem_impl_(new internal::ProblemImpl(options)) {}
Problem::~Problem() {}

ResidualBlockId Problem::AddResidualBlock(
    CostFunction* cost_function,
    LossFunction* loss_function,
    const vector<double*>& parameter_blocks) {
  return problem_impl_->AddResidualBlock(cost_function,
                                         loss_function,
                                         parameter_blocks);
}

ResidualBlockId Problem::AddResidualBlock(
    CostFunction* cost_function,
    LossFunction* loss_function,
    double* x0) {
  return problem_impl_->AddResidualBlock(cost_function,
                                         loss_function,
                                         x0);
}

ResidualBlockId Problem::AddResidualBlock(
    CostFunction* cost_function,
    LossFunction* loss_function,
    double* x0, double* x1) {
  return problem_impl_->AddResidualBlock(cost_function,
                                         loss_function,
                                         x0, x1);
}

ResidualBlockId Problem::AddResidualBlock(
    CostFunction* cost_function,
    LossFunction* loss_function,
    double* x0, double* x1, double* x2) {
  return problem_impl_->AddResidualBlock(cost_function,
                                         loss_function,
                                         x0, x1, x2);
}

ResidualBlockId Problem::AddResidualBlock(
    CostFunction* cost_function,
    LossFunction* loss_function,
    double* x0, double* x1, double* x2, double* x3) {
  return problem_impl_->AddResidualBlock(cost_function,
                                         loss_function,
                                         x0, x1, x2, x3);
}

ResidualBlockId Problem::AddResidualBlock(
    CostFunction* cost_function,
    LossFunction* loss_function,
    double* x0, double* x1, double* x2, double* x3, double* x4) {
  return problem_impl_->AddResidualBlock(cost_function,
                                         loss_function,
                                         x0, x1, x2, x3, x4);
}

ResidualBlockId Problem::AddResidualBlock(
    CostFunction* cost_function,
    LossFunction* loss_function,
    double* x0, double* x1, double* x2, double* x3, double* x4, double* x5) {
  return problem_impl_->AddResidualBlock(cost_function,
                                         loss_function,
                                         x0, x1, x2, x3, x4, x5);
}

void Problem::AddParameterBlock(double* values, int size) {
  problem_impl_->AddParameterBlock(values, size);
}

void Problem::AddParameterBlock(double* values,
                                int size,
                                LocalParameterization* local_parameterization) {
  problem_impl_->AddParameterBlock(values, size, local_parameterization);
}

void Problem::SetParameterBlockConstant(double* values) {
  problem_impl_->SetParameterBlockConstant(values);
}

void Problem::SetParameterBlockVariable(double* values) {
  problem_impl_->SetParameterBlockVariable(values);
}

void Problem::SetParameterization(
    double* values,
    LocalParameterization* local_parameterization) {
  problem_impl_->SetParameterization(values, local_parameterization);
}

int Problem::NumParameterBlocks() const {
  return problem_impl_->NumParameterBlocks();
}

int Problem::NumParameters() const {
  return problem_impl_->NumParameters();
}

int Problem::NumResidualBlocks() const {
  return problem_impl_->NumResidualBlocks();
}

int Problem::NumResiduals() const {
  return problem_impl_->NumResiduals();
}

}  // namespace ceres
