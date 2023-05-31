#include <iostream>
#include <cstring>

using namespace std;

const int MAX_PEOPLE = 100;

int n;

double memo1[MAX_PEOPLE][MAX_PEOPLE][370];
double chanceOfPeopleOnFirstDay(int peopleCnt, int onFirstDayGoal, const int days)
{
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

double memo2[370][MAX_PEOPLE][2];
double solve(int days, int peopleCnt, bool achieved)
{
    if (days == 0)
    {
        if (achieved == true)
        {
            return 1;
        }

        return 0;
    }
    if (memo2[days][peopleCnt][achieved] == memo2[days][peopleCnt][achieved])
    {
        return memo2[days][peopleCnt][achieved];
    }

    double res = 0;
    for (int peopleToday = 0; peopleToday <= peopleCnt; peopleToday++)
    {
        double eventChance = chanceOfPeopleOnFirstDay(peopleCnt, peopleToday, days);
        if (peopleToday < n)
        {
            res += eventChance * solve(days - 1, peopleCnt - peopleToday, achieved);
        }
        else
        {
            res += eventChance * solve(days - 1, peopleCnt - peopleToday, true);
        }
    }

    memo2[days][peopleCnt][achieved] = res;
    return res;
}

int main()
{
    cin >> n;

    memset(memo1, -1, sizeof(memo1));
    memset(memo2, -1, sizeof(memo2));

    for (int k = 1; ; k++)
    {
        if(solve(365, k, false) > 0.5)
        {
            cout << k << '\n';
            break;
        }
    }
}

