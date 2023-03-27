/**
 * @author Lyuben Georgiev
 * @brief Problem B2: http://www.math.bas.bg/infos/EK_2018_NOI_1/u/B.pdf
 * @date 09/03/2023
 * 
*/

#include <cstdio>
#include <algorithm>


// I am using "typedef" instead of "using" because the high school arena won't compile "using"
typedef std::pair<int, int> Dot;

struct Rectangle
{
    int start;
    int end;
    int height = 0;

};

int n, m, length, res;
Rectangle rects[10420];
Dot dots[100420];


int main()
{
    scanf("%d%d", &n, &m);
    int w, h;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &w, &h);
        rects[i].start = length;
        rects[i].end = length + w;
        rects[i].height = h;
        length += w;
    }

    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &dots[i].first, &dots[i].second);
    }

    std::sort(dots, dots + m);

    int rectIdx = 0;
    for (int i = 0; i < m; ++i)
    {
        int curDotX = dots[i].first;
        int curDotY = dots[i].second;
        // Move forward from the old Rectangles if needed
        while (rectIdx < n && rects[rectIdx].end < curDotX)
        {
            ++rectIdx;
        }

        if (rectIdx == n)
            break;

        if (rects[rectIdx].height >= curDotY ||
            (rects[rectIdx].end == curDotX && rects[rectIdx+1].height >= curDotY))
        {
            ++res;
        }
    }

    printf("%d\n", res);

    return 0;
}