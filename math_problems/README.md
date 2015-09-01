## Permutations of a string

- **Problem**: Print all the permutations of a string.
- **Details**: Permutation is "arrangement number" or "order". So problem is given a string, how many strings can we produce by rearranging them.
- **Example**: Permutations of ABC are ABC, ACB, BCA, BAC, CAB, CBA   
- **Approach**:
    * Lets take a backtracking approach. We select one letter, then recursively permute the remaining letters.
    * At each step of permutation process, the given set will have two parts, a part we have already processed and the part we are yet to process.
    * So, at ith step we exchange the i’th value with the value being chosen at that stage. 



