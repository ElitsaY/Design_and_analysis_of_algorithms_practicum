#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(pair<int, int>& l1, pair<int, int>& l2){
    return l1.first == l2.first ? l1.second < l2.second : l1.first < l2.first;
}

int main(){
    int n; // дължина на линийката
    int m; // колко лепенки имаме

    cin>> n>> m;
    //scanf("%d %d", &n, &m);
    vector< pair<int, int> > label;
    //pair<int, int> label[1000005]

    int start, end;
    for(int i = 0; i < m; i++){
        cin>> start >> end;
        label.push_back({start, end});
        //cin>>label[i].first>>label[i].second;
    }

    sort(label.begin(), label.end(), cmp);

    int dots = 0;
    int left = label[0].first;
    int right = label[0].second;

    for(int i = 1; i < m; i++){
        	if(label[i].first <= right){
                right = max(right, label[i].second);
            }
            else{
                dots += (right - left + 1);
                left  = label[i].first;
                right = label[i].second;
            }
    }
    dots += (right - left + 1);
    //printf("dots = %d ", dots);
    cout<<dots<<endl;

}