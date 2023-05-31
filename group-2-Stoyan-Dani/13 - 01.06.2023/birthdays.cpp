#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MAX_PEOPLE = 3500;

int n;

double memo1[MAX_PEOPLE][25][370];
double chanceOfPeopleOnFirstDay(int peopleCnt, int onFirstDayGoal, const int days)
{
    if (onFirstDayGoal > peopleCnt)
    {
        return 0;
    }
    if (peopleCnt == 0)
    {
        if (onFirstDayGoal == 0)
        {
            return 1;
        }

        return 0;
    }
    if (memo1[peopleCnt][onFirstDayGoal][days] == memo1[peopleCnt][onFirstDayGoal][days])
    {
        return memo1[peopleCnt][onFirstDayGoal][days];
    }

    double res = 0;
    if (onFirstDayGoal > 0)
    {
        res += chanceOfPeopleOnFirstDay(peopleCnt - 1, onFirstDayGoal - 1, days) / days;
    }
    res += (chanceOfPeopleOnFirstDay(peopleCnt - 1, onFirstDayGoal, days) * (days - 1)) / days;

    memo1[peopleCnt][onFirstDayGoal][days] = res;
    return res;
}

double memo2[370][MAX_PEOPLE];
double solve(int days, int peopleCnt)
{
    if (days == 0)
    {
        return 1;
    }
    if (memo2[days][peopleCnt] == memo2[days][peopleCnt])
    {
        return memo2[days][peopleCnt];
    }

    double res = 0;
    for (int peopleToday = 0; peopleToday <= min(peopleCnt, n - 1); peopleToday++)
    {
        double eventChance = chanceOfPeopleOnFirstDay(peopleCnt, peopleToday, days);
        res += eventChance * solve(days - 1, peopleCnt - peopleToday);
    }

    memo2[days][peopleCnt] = res;
    return res;
}

int main()
{
    n = 10;

    memset(memo1, -1, sizeof(memo1));
    memset(memo2, -1, sizeof(memo2));

    for (int k = 1; ; k++)
    {
        cout << "at k = " << k << '\n';
        if(1 - solve(365, k) > 0.5)
        {
            cout << "ans[" << n << "] = " << k << '\n';
            break;
        }
    }
}
