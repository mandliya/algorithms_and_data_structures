##Problems solved using stack
1. A simple demo of stack
2. Stock Span Problem
    Given : We have series of n daily price quotes for a stock. 
    Required: We need to calculate **span** of stock's price for all n days.
              Span for ith day is defined as **maximum** number of consecutive days,
              for which the price of the stock was less than or equal to ith day.
    Example: For stock quotes {100, 60, 70, 65, 80, 85} span will be {1, 1, 2, 1, 4, 5}.
             Span for day 1 is always 1, now for day 2 stock is at 60, and there is no day befor it when stock was less than 60.
             So span remains 1. For day 3, the stock is priced at 70, so its span is 2, as previous day it was 60, and so on.
    Approach:
            1. First approach is to scan backwards on each day and count the number of days stock was lesser than given day.
               As soon we hit a bigger price, we stop. This solution is inefficient and would be O(n^2).
            2. Solving it using stack.
                1. Span of day1 is always 1. Put it on stack.
                2. From day 2, We repeat next steps for all the remaining days
                3. If price of the stock on the day on top of stack is less than price of stack on current day, pop it.
                4. If price of the stock on the day on top of stack is greater than price of stock on current day, 
                   calculate the span ( span = currentDay - day on top of stack)
                5. Push the current day index on the stack.
                6. Although it looks like it more than O(n), however each day is pushed on stack once and removed once, 
                   Hence its O(n)
