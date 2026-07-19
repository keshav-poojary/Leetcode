Algorithm
  Count the frequency of each character.
  Traverse the string.
   Decrease the frequency of the current character.
   If the character is already in the stack, continue.

   While:
        the stack is not empty,
        the current character is smaller than the top,
        and the top character appears later (freq[top] > 0),
    pop the top character.
    set vis of the popped character to false. (because the same letter will appear later)

Push the current character into the stack.
set vis of current character to true.


Return the stack as a string.