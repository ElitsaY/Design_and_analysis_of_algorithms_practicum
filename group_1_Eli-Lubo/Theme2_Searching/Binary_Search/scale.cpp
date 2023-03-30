/**
 * @author Lyuben Georgiev
 * @brief Problem: https://www.hackerrank.com/contests/daa-2021-2022-winter-1/challenges/challenge-2593
 * @date 30/03/2023
 * 
*/

#include <iostream>
#include <algorithm>


struct Student
{
    std::string name;
    int fn;
    int points;

    Student(int points = 0)
        : name(""), fn(0), points(points) {}
 
    bool operator<(const Student &other)
    {
        return (points == other.points && fn < other.fn) || points < other.points;
    }
};

int n, q, x;
Student fmi[100001];
 
 
int main()
{
    scanf("%d%d", &n, &q);
 
    for (int i = 0; i < n; ++i)
    {
        std::cin >> fmi[i].name;
        scanf("%d%d", &fmi[i].fn, &fmi[i].points);
    }
    std::sort(fmi, fmi + n);
 
    for (int i = 0; i < q; ++i)
    {
        scanf("%d", &x);

        Student* res = std::lower_bound(fmi, fmi + n, Student(x));
        std::cout << res->name << ' ' << res->fn << '\n';
    }
 
    return 0;
}