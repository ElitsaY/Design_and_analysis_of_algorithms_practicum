#include <iostream>

using namespace std;

#define MAX 2100000

int n, a[MAX], b[MAX];

void merge(int l1, int r1, int l2, int r2)
{
    int ind = 0, ind1 = l1, ind2 = l2;
    while(ind1 <= r1 && ind2 <= r2)
    {
        if(a[ind1] < a[ind2])b[ind++] = a[ind1++];
        else b[ind++] = a[ind2++];
    }
    while(ind1 <= r1)b[ind++] = a[ind1++];
    while(ind2 <= r2) b[ind++] = a[ind2++];

    for(int i = 0; i < ind; i++)a[l1 + i] = b[i];
    return ;
}

void MergeSort(int l, int r)
{
    if(l >= r)return ;
    int mid = (l + r) / 2; // l + (r - l) / 2
    MergeSort(l, mid);
    MergeSort(mid + 1, r);
    merge(l, mid, mid + 1, r);
    return ;

}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)cin >> a[i];

    MergeSort(0, n - 1);
    for(int i = 0; i < n; i++)cout << a[i] << " ";
    cout << endl;
    return 0;
}
