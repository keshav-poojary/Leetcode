Number of paths


Given a grid of size m x n, the task is to determine the number of distinct paths from the top-left corner to the bottom-right corner. At each step, one can either move down or right. Given the integers m and n, return the number of unique paths from the top-left corner to the bottom-right corner.

Note: The test cases are designed such that the answer will always fit within a 32-bit integer.

Examples:

Input: m = 3, n = 3
Output: 6
Explanation: Let the given input 3*3 grid is filled as such:
A B C
D E F
G H I
The possible unique paths which exists to reach 'I' from 'A' following above conditions are as follows: ABCFI, ABEHI, ADGHI, ADEFI, ADEHI, ABEFI.
Input: m = 2, n = 3
Output: 3
Explanation: Let the given input 2*3 grid is filled as such:
A B C
D E F
The possible unique paths which exists to reach 'F' from 'A' following above conditions are as follows: ABCF, ADEF and ABEF.
Input: m = 1, n = 4
Output: 1
Explanation: Let the given input 1*4 grid is filled as such:
A B C D 
The only possible unique path is ABCD.
Constraints:
1 ≤ m ≤ 100
1 ≤ n ≤ 100

Expected Complexities