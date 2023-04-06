#include<iostream>
#include<algorithm>
using namespace std;

int n, p;
int socks[100005];

bool OK(int diff){
    int count = 0; //колко чифта съм образувала

    for(int i = 0; i < n - 1; i++){
        if(socks[i + 1] - socks[i] <= diff){
            count++;
            i++;
        }
    }
    return count >= p;
}

void binarySearch(){
    int l = 0;
    int r = 1000000000;
    int mid;
    int ans;
    while(l <= r){
        mid = l + (r - l)/2;
        if(OK(mid)){
            //ако мога да образувам p чифта чорапи с максимална разлика mid
            //ще се опитам да образувам p чифта чорапи с по-малка макс. разлика
            r = mid - 1;
            ans = mid;        }
        else{
            //не съм успяла да направя p чифта с максимална разлика mid 
            //трябва да увелича mid 
            l = mid + 1;
        }
    }
    printf("%d\n", ans);
}

int main(){
    scanf("%d%d",&n,&p);
    for(int i = 0; i < n; i++){
        scanf("%d",&socks[i]);
    }
    sort(socks, socks + n);
    binarySearch();
}