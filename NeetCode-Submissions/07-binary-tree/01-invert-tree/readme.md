# Invert Tree

## Category
- Binary Tree

## Problem Summary
This problem was solved by translating the requirements into a clean algorithmic pattern and validating edge cases.

## Files
- solution.cpp

## Approach
Traverse the tree with DFS or BFS, carrying information through recursive or iterative state.

## Solution Trace
1. Choose a traversal order that matches the problem requirement: DFS for depth logic, BFS for level logic.
2. Pass along the relevant state while visiting each node.
3. Use recursion or an explicit stack to avoid losing context during traversal.
4. Merge child results back to the parent to form the final answer.

## Code Trace
1. `The implementation reads the data, transforms it into a compact state, and then mutates that state in a way that matches the problem constraints.`
2. `Each condition in the code ensures the next action is valid before the solution continues toward the final output.`

## Code Walkthrough
- The implementation reads the data, transforms it into a compact state, and then mutates that state in a way that matches the problem constraints.
- Each condition in the code ensures the next action is valid before the solution continues toward the final output.

## Mermaid Diagram
```mermaid
flowchart TD
    A[Read input] --> B[Transform to working state] --> C[Apply logic on current item] --> D{Condition holds?}
    D -- Yes --> E[Update answer] --> F{Done?}
    D -- No --> F
    F -- No --> C
    F -- Yes --> G[Return final result]
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
- 01-invert-tree
