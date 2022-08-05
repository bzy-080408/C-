

#include <bits/stdc++.h>
#include <algorithm> 


using namespace std;

struct student{
    int CH;
    int Ma;
    int EN;
    int num;
    int all;
};

bool cmp1(student a,student b){
    return a.num > b.num;
}
bool cmp2(student a,student b){
    return a.CH > b.CH;
}
bool cmp3(student a,student b){
    return a.all > b.all;
}

void Core(int sum,student schule[]){
    sort(schule,schule + sum,cmp1);
    sort(schule,schule + sum,cmp2);
    sort(schule,schule + sum,cmp3);
    for(int i = 0;i < 5;i++){
        cout << schule[i].num << " " << schule[i].all;
    }
}

void Input(){
    int sum = 0;
    cin >> sum;
    student schule[sum];
    for(int i = 0;i < sum;i++){
        cin >> schule[i].CH >> schule[i].Ma >> schule[i].EN;
        schule[i].num = i;
        schule[i].all = schule[i].CH + schule[i].Ma + schule[i].EN;
    }
    Core(sum,schule);
}

int main(){
    Input();
    return 0;
}