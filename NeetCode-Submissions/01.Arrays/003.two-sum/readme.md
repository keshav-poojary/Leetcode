# Two Sum

## Category
- Arrays

## Problem Summary
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target. You may assume that each input would have exactly one solution, and you may not use the same element twice. You can return the answer in any order.

## Files
- solution.cpp

## Approach
Use array scanning and counting patterns, keeping track of state while minimizing redundant passes.

## Solution Trace
1. Analyze the input and identify the key invariant or constraint the solution must maintain.
2. Transform the problem into a compact state representation that makes the decision easy to evaluate.
3. Apply the selected algorithm and update the answer as the scan progresses.
4. Validate the result against special cases such as empty input, duplicates, boundaries, and single-element cases.

## Code Trace
1. `The current value is checked against the previously seen values before any new state is recorded.`
2. `The main loop walks through the input one element at a time and applies the decision logic to every position.`

## Code Walkthrough
- The current value is checked against the previously seen values before any new state is recorded.
- The main loop walks through the input one element at a time and applies the decision logic to every position.

## Mermaid Diagram
```mermaid
flowchart TD
    A[Create map for counts or index state] --> B[Scan each element]
    B --> C{Is key already tracked?}
    C -- Yes --> D[Update or compare value]
    C -- No --> E[Insert key with state]
    D --> F{More elements?}
    E --> F
    F -- Yes --> B
    F -- No --> G[Return computed answer]
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
- 003.two-sum
