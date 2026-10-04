# Non Overlapping Intervals

## Category
- Intervals

## Problem Summary
This problem was solved by translating the requirements into a clean algorithmic pattern and validating edge cases.

## Files
- solution.cpp

## Approach
Sort or merge intervals to keep overlapping ranges compact and easy to reason about.

## Solution Trace
1. Sort the intervals by start position to normalize the input order.
2. Merge overlapping or touching intervals using the current boundary state.
3. Carry forward any remaining non-overlapping pieces after the merge.
4. Return the final merged structure in the required output format.

## Code Trace
1. `The input is sorted or normalized before the main logic so comparisons are consistent and adjacent states are easy to reason about.`
2. `The algorithm scans the sorted values or merged intervals and updates the answer as soon as the condition is satisfied.`
3. `When the scan reaches the end, the maintained state already contains the correct final result.`
4. `The result is returned in the required order and format.`

## Code Walkthrough
- The input is sorted or normalized before the main logic so comparisons are consistent and adjacent states are easy to reason about.
- The algorithm scans the sorted values or merged intervals and updates the answer as soon as the condition is satisfied.
- When the scan reaches the end, the maintained state already contains the correct final result.
- The result is returned in the required order and format.

## Mermaid Diagram
```mermaid
flowchart TD
    A[Sort values or intervals] --> B[Scan current item]
    B --> C{Condition holds?}
    C -- Yes --> D[Update answer]
    C -- No --> E[Move ahead]
    D --> F{Reached end?}
    E --> F
    F -- No --> B
    F -- Yes --> G[Return final answer]
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
- 03-non-overlapping-intervals
