/**
 * @author Lyuben Georgiev
 * @brief Problem Още една редица: https://judge.openfmi.net/practice/open_contest?contest_id=178
 * @date 06/04/2023
 * 
*/

#include <cstdio>
#include <queue>


int a, b;
const int m = 1000007;
bool used[m+1] = {false,};

int rev(int x)
{
    int res = 0;
    while (x)
    {
        res *= 10;
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main()
{
    scanf("%d%d", &a, &b);

    std::queue<int> q;
    q.push(a);
    used[a] = true;
    int level = 1, curCnt = 1;

    while (q.front() != b)
    {
        int x = (q.front() + 1) % m, y = rev(q.front()) % m;
        q.pop();
        --curCnt;

        if (!used[x])
        {
            used[x] = true;
            q.push(x);
        }
        if (!used[y])
        {
            used[y] = true;
            q.push(y);
        }

        if (curCnt == 0)
        {
            curCnt = q.size();
            ++level;
        }
    }

    printf("%d", level);

    return 0;
}