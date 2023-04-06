#include<iostream>
#include<algorithm>
using namespace std;

int n, q;
int shoes[100005];
long long prefix[1000005];

int binarySearch(int shoe){
    int l = 0;
    int r = n - 1;
    int mid;
    while(l <= r){
        mid = (l + r)/2;
        //130 70 50 .. 20
        if(shoes[mid] > shoe){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return l;
}

int binarySearchPairs(int start, int money){
    int l = start;
    int r = n - 1;
    int mid;
    while(l <= r){
        mid = (l + r)/2;
        //първото по-голямо от money
        // 130 200 250...
        // 
        long long curSum;
        if(start == 0){
            curSum = prefix[mid];
        }
        else{
            curSum = prefix[mid] - prefix[start - 1];
        }
        if(curSum <= money){
           l = mid + 1; 
        }
        else{
            r = mid - 1;
        }
    }
    return l - start;
}

int main(){
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++){
        scanf("%d",&shoes[i]);
    }
    sort(shoes, shoes + n, [](int s1, int s2){return  s1 > s2;});
    prefix[0] = shoes[0];
    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i - 1] + shoes[i];
    }
    int money, expn;
    for(int i = 0; i < q; i++){
        scanf("%d %d", &money, &expn);
        int pos = binarySearch(expn);
        printf("%d\n", binarySearchPairs(pos, money));
    }   
}