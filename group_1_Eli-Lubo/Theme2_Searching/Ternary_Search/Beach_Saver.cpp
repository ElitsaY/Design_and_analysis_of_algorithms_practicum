//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include<iomanip>
#include <cmath>

using namespace std;

double xPancho, yPancho, xDrown, yDrown;
double vSand, vSea;

double findTime(double x){
    double onTheSand = sqrt((x - xPancho)*(x - xPancho) + yPancho*yPancho) / vSand;
    double inTheSea = sqrt((x - xDrown)*(x - xDrown) + yDrown*yDrown) / vSea;
    return onTheSand + inTheSea; 
}

void findShortestTime(){

    double left = min(xPancho, xDrown);
    double right = max(xPancho, xDrown);
    double eps = 0.00001;
    double mid1, mid2;

    while(right - left > eps){
        mid1 = left + (right - left)/3;
        mid2 = right - (right - left)/3;
        
        double time1 = findTime(mid1);
        double time2 = findTime(mid2);

        if(time1 < time2)
            right = mid2;
        else
            left = mid1;
    }
    cout << setprecision(5) << fixed << findTime(left) << endl;
}


int main()
{
    int query;
    cin>>query;
    for(int i = 0 ; i < query; ++i)
    {
        cin>>xPancho>>yPancho;
        cin>>xDrown>>yDrown;
        cin>>vSand>>vSea;
        findShortestTime();
    }

    
}