#include <iostream>
#include <memory>
#include <string>
#include "task.hpp"
#include "schedular.hpp"
#include "task_comparitor.hpp"

int main() {

  auto schedular = std::make_unique<Schedular>(100);

  auto task1 = std::make_unique<Task>("task1", 1000, 0);
  auto task2 = std::make_unique<Task>("task2", 1000, 1);
  auto task3 = std::make_unique<Task>("task3", 1000, 1);
  auto task4 = std::make_unique<Task>("task4", 1000, 2);

  schedular->addTask(std::move(task1));
  schedular->addTask(std::move(task2));
  schedular->addTask(std::move(task3));
  schedular->addTask(std::move(task4));

  schedular->runTask();
  schedular->runTask();
  schedular->runTask();
  schedular->runTask();

  std::cout << "sanity" << std::endl;
  return 0;
}

