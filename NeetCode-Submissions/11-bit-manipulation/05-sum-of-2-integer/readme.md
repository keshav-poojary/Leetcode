# Sum of Two Integers (Without Using `+` or `-`)

## Problem

Given two integers `a` and `b`, return their sum **without using the `+` or `-` operators**.

## Approach

The solution uses **bit manipulation** to simulate binary addition.

- **XOR (`^`)** computes the sum of two bits **without considering the carry**.
- **AND (`&`)** identifies the positions where a carry is generated.
- **Left Shift (`<<`)** moves the carry to the next higher bit.
- Repeat the process until there is no carry left.

### Algorithm

1. Compute the carry:
   ```cpp
   carry = (a & b) << 1;
   ```
2. Compute the sum without carry:
   ```cpp
   a = a ^ b;
   ```
3. Update `b` with the carry.
4. Repeat until `b == 0`.
5. Return `a`.

## Dry Run

**Input:**

```text
a = 3 (0011)
b = 5 (0101)
```

### Iteration 1

```text
a = 0011
b = 0101

Sum (XOR)   = 0110 (6)
Carry (AND) = 0001
Carry << 1  = 0010 (2)
```

Now,

```text
a = 0110 (6)
b = 0010 (2)
```

### Iteration 2

```text
Sum (XOR)   = 0100 (4)
Carry (AND) = 0010
Carry << 1  = 0100 (4)
```

Now,

```text
a = 0100 (4)
b = 0100 (4)
```

### Iteration 3

```text
Sum (XOR)   = 0000
Carry (AND) = 0100
Carry << 1  = 1000 (8)
```

Now,

```text
a = 0000
b = 1000
```

### Iteration 4

```text
Sum (XOR)   = 1000 (8)
Carry (AND) = 0000
```

Since the carry becomes `0`, the loop terminates.

**Output:**

```text
8
```

## Code

```cpp
class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int carry = (a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};
```

## Time Complexity

- **O(1)**

The loop runs at most **32 times** for a 32-bit integer, with constant-time work in each iteration.

## Space Complexity

- **O(1)**

Only a constant amount of extra space (`carry`) is used.
