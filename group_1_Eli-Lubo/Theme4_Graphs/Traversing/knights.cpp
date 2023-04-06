/**
 * @author Lyuben Georgiev
 * @brief Problem Рицари: https://judge.openfmi.net/practice/open_contest?contest_id=178
 * @date 06/04/2023
 * 
*/

#include <cstdio>
#include <queue>

int n, m, k, hx, hy, kx, ky, px, py;
int board[2001][2001];
int dx[] = {2, 2, -2, -2, 1, -1, 1, -1};
int dy[] = {1, -1, 1, -1, 2, 2, -2, -2};

bool valid(int x, int y)
{
    return x >= 0 && y >= 0 && x < n && y < n && board[x][y] >= 0;
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d %d", &hx, &hy);
        board[hx][hy] = -1;
    }
    for (int i = 0; i < k; ++i)
    {
        scanf("%d %d", &kx, &ky);
        board[kx][ky] = 1;
    }
    scanf("%d %d", &px, &py);

    std::queue<std::pair<int, int>> q;
    q.push({px, py});
    board[px][py] = -1;
    int dist = 0, rem = 1, res = 0, cnt = 0;

    while (!q.empty())
    {
        int cx = q.front().first, cy = q.front().second;
        q.pop();
        --rem;

        for (int i = 0; i < 8; ++i)
        {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (valid(nx, ny))
            {
                if (board[nx][ny] == 1)
                {
                    res = dist + 1;
                    ++cnt;
                }

                board[nx][ny] = -1;
                q.push({nx, ny});
            }
        }

        if (rem == 0)
        {
            rem = q.size();
            ++dist;
        }
    }

    printf("%d %d", cnt, res);

    return 0;
}