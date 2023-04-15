#include <bits/stdc++.h>

using namespace std;

#define MAX 61000

int n, a[MAX], v[MAX];

double calc(long double x)
{
    long double ans = 0.0;
    for(int i = 0; i < n; i++)
    {
        ans = max(ans, abs(a[i] - x) * (1.0 / v[i]));
    }
    return ans;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < n; i++)cin >> v[i];
    
    double l = 0, r = 0, m1, m2, st1, st2;
    for(int i = 0; i < n; i++)r = max(r, (double)(a[i]));
    
    for(int i = 0; i < 64; i++)
    {
        m1 = l + (r - l) * (1.0 / 3);
        m2 = l + (r - l) * (2.0 / 3);
        st1 = calc(m1);
        st2 = calc(m2);
        if(st1 > st2)l = m1;
        else r = m2;
    }
    cout << fixed << setprecision(9) << st1 << endl;
    
    return 0;
}
