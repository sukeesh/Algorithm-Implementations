What are sparse tables? 

- Data structure that allows range queries
- Can answer most queries in O(log n)
- But can answer Range Minimum Queries in O(1) for idempotent functions
- It can be only used on immutable arrays. If you need any change, whole DS needs to be changed

Intuition

- Any non negative number can be uniquely represented as a sum of decreasing powers of 2. This is just a variant of binary representation of a number. For number x, there can be at most log2(x) summands
- So, by the same reasoning, any interval can be represented as a union of intervals with lengths that are decreasing powers of two. Eq.. [2, 14] = [2, 9] U [10, 13] U [14, 14]
- And hence, also here union consists of at most [log2(length of interval)] many intervals.
- MAIN IDEA: Pre-compute all answers for range queries with power of 2 length. So, afterwards combining all of them to receive a complete answer.


Precomputation

- We will maintain a 2D array
- Where table[i][j] will store the answer for the range [i, i + 2^j - 1] which can be split nicely into ranges 
    - [i, i + 2^{j-1} - 1] and [i + 2^(j-1), i + 2^j - 1] both of length 2^{j-1}
    - So, we can generate this table with dynamic programming

logarithmic values
```cpp
int log[MAXN+1];
log[1] = 0;
for (int i = 2; i <= MAXN; i++)
    log[i] = log[i/2] + 1;
```

computing sparse table
```cpp
for (int i = 0; i < MAXN; i++)
    table[i][0] = f(array[i]);

for (int j = 1; j <= K; j++)
    for (int i = 0; i + (1 << j) <= MAXN; i++)
        table[i][j] = f(table[i][j-1], table[i + (1 << (j - 1))][j - 1]);
```
`K = log2(MAXN) + 1`
