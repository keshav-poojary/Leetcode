# Word Search

## Category
- Backtracking

## Problem Summary
Given an m x n grid of characters board and a string word, return true if word exists in the grid. The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

## Files
- solution.cpp

## Approach
Explore candidate choices recursively and backtrack once a branch is invalid or complete.

## Solution Trace
1. Analyze the input and identify the key invariant or constraint the solution must maintain.
2. Transform the problem into a compact state representation that makes the decision easy to evaluate.
3. Apply the selected algorithm and update the answer as the scan progresses.
4. Validate the result against special cases such as empty input, duplicates, boundaries, and single-element cases.

## Code Trace
1. `The current value is checked against the previously seen values before any new state is recorded.`
2. `The main loop walks through the input one element at a time and applies the decision logic to every position.`
3. `The function returns immediately when a duplicate is found, which keeps the solution efficient and avoids extra work.`
4. `Visited state is marked as soon as a value or node is processed so repeated work is avoided during the traversal.`

## Code Walkthrough
- The current value is checked against the previously seen values before any new state is recorded.
- The main loop walks through the input one element at a time and applies the decision logic to every position.
- The function returns immediately when a duplicate is found, which keeps the solution efficient and avoids extra work.
- Visited state is marked as soon as a value or node is processed so repeated work is avoided during the traversal.

## Mermaid Diagram
```mermaid
flowchart TD
    A[Initialize state] --> B[Loop over input]
    B --> C{Check condition on current item}
    C -- True --> D[Update answer or state]
    C -- False --> E[Skip or continue]
    D --> F{End loop?}
    E --> F
    F -- No --> B
    F -- Yes --> G[Return result]
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
- 06-word-search
