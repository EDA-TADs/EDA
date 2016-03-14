# Design and analysis of iterative algorithms

#### November 11, 2015

Given the following specification for an algorithm

```
{ n >= 0 ^ lenght(v) >= n }
fun algorithm (int v[], int n) return int r
{ r = (#i : 0 <= i < n : vi = ( SUM j : i + 1 <= j <= n - 1 : v[j] )) }
```

* **Write** in your own words the meaning of the precondition and the postcondition.
* **Implement** an iterative algorithm, as efficient as possible, that holds the provided specification.
* **Write** the invariant of your loop.
* **Calculate** the complexity of the algorithm.
* **Implement** the *main* function and provide examples of the correct behaviour of the algorithm.
