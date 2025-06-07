#pragma once
#include "task.hpp"
#include <memory>

struct TaskComparitor {
  bool operator()(const std::unique_ptr<Task>& lhs, const std::unique_ptr<Task>& rhs) {
    return lhs->priority >= rhs->priority;
  }
};