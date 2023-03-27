/**
 * @author Lyuben Georgiev
 * @brief Problem: http://www.math.bas.bg/infos/files/2015-01-04-B3.pdf
 * @date 09/03/2023
 * 
*/

#include <cstdio>
#include <algorithm>
#include <climits> // INT_MAX


#define start 0
#define dot 1
#define end 2 

struct Point
{
    int coordinate;
    int type;
    int index = INT_MAX;
    
    bool operator <(Point other)
    {
        return coordinate < other.coordinate ||
               (coordinate == other.coordinate && type < other.type);
    }

};

bool cmpByIndex(Point a, Point b)
{
    return a.index < b.index;
}

int n, m;
Point points[300420];


int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0, tempStart, tempEnd; i < n; ++i)
    {
        scanf("%d%d", &tempStart, &tempEnd);
        if (tempEnd < tempStart)
            std::swap(tempStart, tempEnd);

        points[i].coordinate = tempStart;
        points[i].type = start;
        points[n+i].coordinate = tempEnd;
        points[n+i].type = end;
    }

    n *= 2;
    for (int i = 0, tempDot; i < m; ++i)
    {
        scanf("%d", &tempDot);
        points[n+i].coordinate = tempDot;
        points[n+i].type = dot;
        points[n+i].index = i;
    }

    n += m; // n is the number of starts + ends + dots
    std::sort(points, points + n);

    int intervals = 0;
    for (int i = 0; i < n; ++i)
    {
        switch (points[i].type)
        {
        case start:
            ++intervals;
            break;
        case dot:
            points[i].coordinate = intervals; // Store here the result for this dot
            break;
        case end:
            --intervals;
            break;
        }
    }

    // Sort by index (Note that starts and ends have index == INT_MAX)
    std::sort(points, points + n, cmpByIndex);

    for (int i = 0; i < m; ++i)
    {
        printf("%d ", points[i].coordinate);
    }

    return 0;
}