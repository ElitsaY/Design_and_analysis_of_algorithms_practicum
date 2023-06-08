#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int64_t> fib;

bool isPrime(int64_t n)
{
    if (n == 1)
    {
        return false;
    }

    for (int64_t d = 2; d * d <= n; d++)
    {
        if (n % d == 0)
        {
            return false;
        }
    }

    return true;
}

map<int64_t, int> memo;
int f(int64_t n)
{
    if (n == 0)
    {
        return 0;
    }
    if (memo.count(n))
    {
        return memo[n];
    }

    int ans = 0;
    for (int64_t num : fib)
    {
        ans = max(ans, f(n / num));
    }
    ans += isPrime(n);

    memo[n] = ans;
    return ans;
}

int main()
{
    int64_t n;
    cin >> n;

    fib.push_back(0);
    fib.push_back(1);
    while (fib.back() <= n)
    {
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    }
    fib.erase(fib.begin());
    fib.erase(fib.begin());
    fib.erase(fib.begin());

    cout << f(n) << '\n';
}
