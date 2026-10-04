# Merge k Sorted Lists

## Category
- Linked Lists

## Problem Summary
Solved Hard Topics

## Files
- solution.cpp

## Approach
Track pointers carefully and manipulate next relationships while handling edge cases like null heads and cycles.

## Solution Trace
1. Understand the pointer mutations required by the operation.
2. Handle head, tail, and null cases explicitly before performing the core algorithm.
3. Use temporary pointers to preserve the original structure during rewiring.
4. Verify the final linked list order before returning the result.

## Code Trace
1. `If the value is new, it is inserted into the tracking structure so it can be compared later in the scan.`
2. `The main loop walks through the input one element at a time and applies the decision logic to every position.`
3. `Sorting normalizes the structure of the input so adjacent values or intervals can be compared in a predictable order.`

## Code Walkthrough
- If the value is new, it is inserted into the tracking structure so it can be compared later in the scan.
- The main loop walks through the input one element at a time and applies the decision logic to every position.
- Sorting normalizes the structure of the input so adjacent values or intervals can be compared in a predictable order.

## Mermaid Diagram
```mermaid
flowchart TD
    A[Handle null and head cases] --> B[Track current and previous]
    B --> C[Rewire next pointers]
    C --> D{More nodes left?}
    D -- Yes --> B
    D -- No --> E[Return updated head]
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
- 10-merge-k-sorted-list
