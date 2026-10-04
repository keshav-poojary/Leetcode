# Find Minimum in Rotated Sorted Array

## Category
- Binary Search

## Problem Summary
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become: [4,5,6,7,0,1,2] if it was rotated 4 times. [0,1,2,4,5,6,7] if it was rotated 7 times.

## Files
- solution.cpp

## Approach
Reduce the search space by checking the sorted property and moving the boundary toward the valid answer.

## Solution Trace
1. Find the sorted invariant that allows the answer to be narrowed efficiently.
2. Set the left and right boundaries based on the search condition.
3. Move only one pointer at a time while preserving the valid answer range.
4. Return the boundary value once the search condition is fully satisfied.

## Code Trace
1. `The search space is defined by the left and right pointer boundaries instead of iterating through every element.`
2. `The midpoint is evaluated against the sorted invariant to decide whether the answer lives on the left or right side.`
3. `Pointers move toward each other until the valid range collapses to a single answer.`
4. `The final pointer position is returned as the correct result.`

## Code Walkthrough
- The search space is defined by the left and right pointer boundaries instead of iterating through every element.
- The midpoint is evaluated against the sorted invariant to decide whether the answer lives on the left or right side.
- Pointers move toward each other until the valid range collapses to a single answer.
- The final pointer position is returned as the correct result.

## Mermaid Diagram
```mermaid
flowchart TD
    A[Set low and high bounds] --> B[mid = (low + high) / 2]
    B --> C{Condition at mid is valid?}
    C -- Yes --> D[Move high = mid]
    C -- No --> E[Move low = mid + 1]
    D --> B
    E --> B
    B --> F[Return final boundary value]
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
- 05-find-min-in-rotated-and-sorted-arr
