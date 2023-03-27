/**
 * @author Lyuben Georgiev
 * @brief Problem B2: http://www.math.bas.bg/infos/EK_2018_NOI_1/u/B.pdf
 * @date 09/03/2023
 * 
*/

#include <cstdio>
#include <algorithm>


int n, m, length = 1, res;
int arr[1000420];

int main()
{
    scanf("%d %d", &n, &m);
    int w, h;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d", &w, &h);
        arr[length-1] = std::max(arr[length-1], h);
        for (int j = 0; j < w; ++j)
        {
            if (length + j <= 1000000)
            {
                arr[length + j] = h;
            }
        }
        length += w;
    }

    int x, y;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d %d", &x, &y);

        res += (y <= arr[x]);
    }

    printf("%d\n", res);

    return 0;
}