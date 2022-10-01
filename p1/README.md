# Problem Set 1

## All-in-All

"if you can remove characters from *t* such that the concatenation of the remaining characters is *s*" was a huge hint to how to implement my algorithm. Instead of removing characters to be left-over with `s`, you could just count if you've seen the characters of `s`. I had a greedy algorithm in `O(n)` which iterates through `t` and uses a counter, `curr`, if a letter in `s` was found in `t`. At the end, if `curr` did not match the size of `s`, then it wasn't a subsequence.

There was no challenge in doing this problem.

## Alternating Subsequences

I have solved a similar problem in the past related to tracking boolean states by "toggling" a push button.

So the algorithm to solve this problem is `O(n)` and requires two variables to track the current and previous state denoted as `curr_sign` and `prev_sign` respectively. We also define `sum` and `max` to keep track of the running sum and current max.

The skeleton of the algorithm looks like this:
```cpp
int sum = 0;
int max = a[0];
bool prev_sign = a[0] > 0 ? true : false; // true/+, false/-
for (int i = 0; i < n; i++) {
    bool curr_sign = a[i] > 0 ? true : false;
    ...

    prev_sign = curr_sign;
}
```

The remaining part of implementing the algorithm is to write the `if` conditions.

If the sign has changed, then we need to sum the max. We then update `max` to reflect that the current element could be a potential max.
```cpp
if (curr_sign != prev_sign) {
    sum += max;
    max = a[i];
}
```

If the sign has not changed, then we don't do anything but just check if the current element is greater than `max`.
```cpp
if (curr_sign == prev_sign) {
    max = a[i] > max ? a[i] : max;
}
```

There is one more case to consider which is add the remaining `max` to `sum` from the last same-sign subsequence.
```cpp
for (...) {
    ...
}
sum += max;
```

When I was testing my algorithm, I had a stack overflow (if I remember correctly). This was because the size of `int` was too small for `sum` and `max` so I used `int64_t` instead. I personally don't know why `long long` is suggested by the course when `int64_t` exists, which is 2 characters shorter and clearer on how many bits there are.

## Coin Collector

## Ferry Loading

My first instinct to solve the problem was to apply the sliding window algorithm because:
- There are `n` total cars and you can only take `m` at a time as the cars arrive (contiguous and ordered).

However, a sliding window algorithm would be complex to implement and not required since the cars are already ordered by time. The algorithm may be greedy:
- We only care about the latest time the car is able to arrive (in hindsight, not true).
- The number of trips is just how many groups of `n` cars the ferry can ferry at once.

A basis for the solution is the following:
```cpp
#include <cmath>
#include <iostream>

void solution() {
    int n, t, m;
    std::cin >> n >> t >> m;
    int cars[m];
    for (int i = 0; i < m; i++) {
        std::cin >> cars[i];
    }

    std::cout << cars[m - 1] + t << " " << (int)std::ceil((double)m / n) << "\n";
}

int main() {
    int c;
    std::cin >> c;
    for (int i = 0; i < c; i++) {
        solution();
    }
}
```

> I made some submissions during this time which were tangentially irrelevant to my final algorithm. I have no idea what I was doing.

After reflecting on the above algorithm, I made the following observations:
- Cars are grouped in sizes of `n` **or less**.
- The number of trips is independent from the time taken to make the trips.
- Did not consider the trip durations of the previous groups. What if there was a long queue of cars that arrived at the same time?

```cpp
#include <cmath>
#include <iostream>
using namespace std;

void solution() {
    int n, t, m;
    cin >> n >> t >> m;
    int cars[m];
    for (int i = 0; i < m; i++) {
        cin >> cars[i];
    }

    int ntrips = (int)ceil((double)m / n);
    int mtime = 0;
    for (int i = 0; i < m; i += n) {
        int j = min(i + n - 1, m - 1);
        mtime += cars[j] - cars[i] + t;
    }

    cout << mtime << " " << ntrips << "\n";
}

int main() {
    int c;
    cin >> c;
    for (int i = 0; i < c; i++) {
        solution();
    }
}
```

This is a more correct solution which did not account for return trips if there was a queue of cars.

## The Fair Nut and String