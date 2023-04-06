#include<iostream>
#include<algorithm>
using namespace std;
//https://action.informatika.bg/problems/130

int cabel[100005];
int n;      // брой кабели
int k;      // брой парчета, които са нужни

bool OK(int x){
    int numberOfCabels = 0;     //брой нарязани кабели с дължина x
    for(int i = 0; i < n; i++){
        numberOfCabels += (cabel[i]/x);
    }
    return numberOfCabels >= k;
   
}

int main(){
    int rightBound = 1;         // минимална дължина на кабел по условие

    scanf("%d %d",&n, &k);

    for(int i = 0; i < n; i++){
        scanf("%d", &cabel[i]);
        rightBound = max(rightBound, cabel[i]);
    }

     //binary Search

    int left = 1;
    int right = rightBound;
    int mid; 
    int maxLengthOfCabel = 0; // максимална дължина на кабел, която можем да изрежем
                              // по условие е 0

    while(left <= right){
        mid = left + (right - left )/2;
        if(OK(mid)){
            left = mid + 1;
            maxLengthOfCabel = max(maxLengthOfCabel, mid);
        }
        else{
            right = mid - 1;
        }
    }
    printf("%d\n", maxLengthOfCabel);
}