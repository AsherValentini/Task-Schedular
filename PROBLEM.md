# Task-Schedular
## Problem Statement 
Build a basic task scheduler simulator.
You are given "tasks" that have:

    a name (string)

    a duration in milliseconds (int)

    a priority (integer, higher number = higher priority)

You must design a component that allows:

    adding tasks

    simulating the execution of tasks, one at a time

    tasks with higher priority must run first

    if two tasks have the same priority, the one added earlier runs first

You must expose a method that "runs" the next task and returns its name and duration.
Once a task is run, it is removed from the scheduler.
When no tasks remain, return an appropriate signal.

