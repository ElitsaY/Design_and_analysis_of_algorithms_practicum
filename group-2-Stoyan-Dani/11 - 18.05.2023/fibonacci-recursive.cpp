class Solution {
public:
    vector<int> memo;

    int calcFib(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        if (memo[n] != -1)
        {
            return memo[n];
        }

        memo[n] = fib(n - 1) + fib(n - 2);
        return memo[n];
    }

    int fib(int n) {
        memo.resize(n + 1);
        fill(memo.begin(), memo.end(), -1);

        return calcFib(n);
    }
};
