# Construct Binary Tree from Inorder and Postorder Traversal

## Category
- Binary Tree

## Problem Summary
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

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
- 14-construct-bin-tree-from-inorder-and-post-rder
