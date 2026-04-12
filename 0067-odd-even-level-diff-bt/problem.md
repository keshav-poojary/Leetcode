Odd even level difference


Given a Binary Tree. Find the difference between the sum of node values at even levels and the sum of node values at odd levels.

Examples:

Input: root [1, 2, 3]
            1
          /   \
         2     3
Output: -4
Explanation: sum at odd levels - sum at even levels = (1)-(2+3) = 1-5 = -4
Input: root = [10, 20, 30, 40, 60]
            10
          /    \
        20      30
       /     \         
     40    60      
Output: 60
Explanation: sum at odd levels - sum at even levels = (10+40+60) - (20+30) = 110 - 50 = 60 
Input: root = [1, 2, 4]
            1
          /   \
         2     4
Output: -4
Explanation: sum at odd levels - sum at even levels = (1)-(2+4) = 1-6 = -5
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105