# Valid Parentheses

## Category
- Stack

## Problem Summary
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid. An input string is valid if: Open brackets must be closed by the same type of brackets.

## Files
- solution.cpp

## Approach
Use stack-based state tracking to handle order-sensitive operations and nested structure problems.

## Solution Trace
1. Analyze the input and identify the key invariant or constraint the solution must maintain.
2. Transform the problem into a compact state representation that makes the decision easy to evaluate.
3. Apply the selected algorithm and update the answer as the scan progresses.
4. Validate the result against special cases such as empty input, duplicates, boundaries, and single-element cases.

## Code Trace
1. `The main loop walks through the input one element at a time and applies the decision logic to every position.`
2. `The function returns immediately when a duplicate is found, which keeps the solution efficient and avoids extra work.`
3. `The stack or deque preserves the order of pending work so the algorithm can revisit states in the correct sequence.`

## Code Walkthrough
- The main loop walks through the input one element at a time and applies the decision logic to every position.
- The function returns immediately when a duplicate is found, which keeps the solution efficient and avoids extra work.
- The stack or deque preserves the order of pending work so the algorithm can revisit states in the correct sequence.

## Mermaid Diagram
```mermaid
flowchart TD
    A[Read next value] --> B{Condition requires push or pop?}
    B -- Push --> C[Push to stack]
    B -- Pop --> D[Pop while condition holds]
    C --> E[Continue scanning]
    D --> E
    E --> F{End reached?}
    F -- No --> A
    F -- Yes --> G[Return stack-driven result]
```

## Algorithm
1. Read the problem constraints and identify the correct state to track.
2. Choose the most fitting pattern for the data structure involved.
3. Process the collection or graph in a single pass where possible.
4. Maintain the answer and verify correctness against edge cases.
5. Return the final value or structure after the traversal is complete.

## Complexity Analysis
- Time Complexity: O(n) or O(n log n), depending on the exact operation pattern used in the solution.
- Space Complexity: O(n) or O(1) auxiliary space, based on the chosen data structure and recursion/stack usage.

## Core Intuition
The solution reduces the problem to a smaller, trackable state and then uses the correct structural pattern to process the input efficiently. This keeps the implementation both easy to follow and correct for the constraints.

## Edge Cases
- Empty input or single-element input
- Duplicate values or repeated edges
- Boundary values and extreme indices
- Already-sorted or reverse-sorted scenarios
- Cycles, null nodes, or disconnected components when relevant

## Folder
- 01.valid-parenthesis
