#pragma once

#include <string>
#include <cstdint>
#include <iostream>

struct Task {
  std::string name;
  std::uint64_t duration;
  int priority;

  Task(std::string name_, std::uint64_t duration_, int priority_)
      : name(name_), duration(duration_), priority(priority_) {}

  void run() { std::cout << "[Task] running task: " << name << " for: " << duration << "\n"; }
};