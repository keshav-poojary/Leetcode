# Set Matrix Zeroes

## Category
- 10 Math Geometry

## Problem Summary
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's. You must do it in place.

## Files
- solution.cpp

## Approach
Use the core pattern that matches the input constraints and the target behavior.

## Solution Trace
1. Analyze the input and identify the key invariant or constraint the solution must maintain.
2. Transform the problem into a compact state representation that makes the decision easy to evaluate.
3. Apply the selected algorithm and update the answer as the scan progresses.
4. Validate the result against special cases such as empty input, duplicates, boundaries, and single-element cases.

## Code Trace
1. `A set is created to remember values already seen, which gives us constant-time membership checks for duplicates.`
2. `The main loop walks through the input one element at a time and applies the decision logic to every position.`

## Code Walkthrough
- A set is created to remember values already seen, which gives us constant-time membership checks for duplicates.
- The main loop walks through the input one element at a time and applies the decision logic to every position.

## Mermaid Diagram
```mermaid
flowchart TD
    A[Create empty set] --> B[i = 0]
    B --> C{ i < nums.size? }
    C -- Yes --> D{ nums[i] in set? }
    D -- Yes --> E[Return true]
    D -- No --> F[Insert nums[i] into set]
    F --> G[i = i + 1]
    G --> C
    C -- No --> H[Return false]
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
- 04-set-matrix-zero
