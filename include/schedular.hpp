#pragma once
#include <memory>
#include <queue>
#include <cstdint>

#include "task.hpp"
#include "task_comparitor.hpp"

class Schedular {

public:
  Schedular(std::size_t capacity) : capacity_(capacity) {}

  bool addTask(std::unique_ptr<Task> task) {
    if (schedular_.size() >= capacity_) {
      std::cout << "[Schedular] at capacity cannot add task\n";
      return false;
    }

    schedular_.push(std::move(task));
    return true;
  }

  void runTask() {

    if (!schedular_.empty()) {
      schedular_.top()->run();
      schedular_.pop();
    } else {
      std::cout << "[Schedular] queue empty\n";
    }
  }

private:
  std::priority_queue<std::unique_ptr<Task>, std::vector<std::unique_ptr<Task>>, TaskComparitor>
      schedular_;
  std::size_t capacity_;
};