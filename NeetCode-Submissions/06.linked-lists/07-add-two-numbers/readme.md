# Add Two Numbers

## Category
- Linked Lists

## Problem Summary
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list. You may assume the two numbers do not contain any leading zero, except the number 0 itself.

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
1. `The main loop walks through the input one element at a time and applies the decision logic to every position.`

## Code Walkthrough
- The main loop walks through the input one element at a time and applies the decision logic to every position.

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
- 07-add-two-numbers
