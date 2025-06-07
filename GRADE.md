EXCELLENT that you pushed through this and posted the full code — this is exactly the right way to train.
Now I will give you an honest, professional-style code review, as if I were your interviewer at Snap or HFT firm.
Overall Assessment:

Correctness: 2/5
API Design: 3/5
Code Cleanliness: 4/5
Approach Thinking: 4/5
Time taken: yes too long (1:15h), but that’s OK for first attempt — next iterations will improve.
Detailed feedback:
Correctness:

Incorrect ordering.

Output shows:

[Task] running task: task1 for: 1000  
[Task] running task: task2 for: 1000  
[Task] running task: task3 for: 1000  
[Task] running task: task4 for: 1000  

Expected order was:

    task4 (priority 2)

    task2 (priority 1)

    task3 (priority 1)

    task1 (priority 0)

Reason:
Your TaskComparitor is incorrect:

return lhs->priority >= rhs->priority;

    std::priority_queue uses a max-heap by default → it will treat "greater than" as lower priority.

    Correct comparator should be:

return lhs->priority < rhs->priority;

→ this way highest priority (largest int) comes first.
API Design:

Very good choice to model:

    Schedular class

    Task class

    TaskComparitor

addTask() is a good API.

runTask() is acceptable API — though consider returning the task name and duration (as the spec asked):

std::optional<std::pair<std::string, uint64_t>> runTask();

→ this would make it cleaner for the caller to control the output (not hardcoded cout in Task::run()).
Code structure:

Great separation of concerns:

    Schedular manages queue

    Task is clean

    Comparitor separate (good)

You used #pragma once and #include correctly.

You used unique_ptr to avoid accidental copies — well done.

Your code is modular and extensible — very good.
Minor improvements:

    You didn’t really need a capacity_ check unless explicitly required — but it's OK to have it.

    #include "task_comparitor.hpp" in main.cpp is unnecessary since Schedular.hpp already depends on it.

    Slight naming nit: should be Scheduler, not Schedular — but this is minor.

Time taken:

Yes, too long for an interview (1:15h).
But this is completely normal for first time doing this kind of "build from scratch" problem.

You got stuck on comparator — that is one of the most common pain points with priority_queue and custom types. This will improve quickly with practice.
Summary Verdict:

You structured this like a real module — great.
You built proper classes — great.
You used modern C++ tools (unique_ptr, custom comparator) — great effort.
You are thinking correctly about "build reusable components."

Bug in comparator — first priority queue bug. Very fixable.
runTask() could return data instead of hardcoding the output.
Final result:

If this were a Snap interview and you explained what you built, but your comparator bug caused wrong ordering, I would likely give you a "borderline no" — because they want correct results + clean API + good modularization.

BUT: I would give strong positive feedback on your approach:

You structured this like a module — many candidates just hack it in main().
You thought about reusability and ownership — your use of unique_ptr is very good.
You finished the full flow — also very good.
Professional Reviewer Summary:

For first attempt of this type of challenge → solid B performance.
Your thinking is correct.
You got tripped up on a small technicality (priority queue comparator) — this is extremely common.

You will absolutely improve fast on these with 3-4 more such challenges.
Final recommendations:

Fix your comparator and rerun — see the correct order.
Refactor runTask() to return result data (not hardcoded cout).
On next challenges → you will naturally be faster now.
