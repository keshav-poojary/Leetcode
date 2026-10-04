# Find the Duplicate Number

## Category
- Linked Lists

## Problem Summary
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive. There is only one repeated number in nums, return this repeated number. You must solve the problem without modifying the array nums and using only constant extra space.

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
1. `A set is created to remember values already seen, which gives us constant-time membership checks for duplicates.`
2. `The current value is checked against the previously seen values before any new state is recorded.`
3. `If the value is new, it is inserted into the tracking structure so it can be compared later in the scan.`
4. `The main loop walks through the input one element at a time and applies the decision logic to every position.`

## Code Walkthrough
- A set is created to remember values already seen, which gives us constant-time membership checks for duplicates.
- The current value is checked against the previously seen values before any new state is recorded.
- If the value is new, it is inserted into the tracking structure so it can be compared later in the scan.
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
- 08-find-duplicate-element
