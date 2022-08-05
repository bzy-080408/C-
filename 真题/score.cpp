

#include <bits/stdc++.h>

using namespace std;

struct mark{
    int num;
    int mark;
};
int m,n;

bool cmp1(mark a,mark b){
    return a.num < b.num;
}
bool cmp2(mark a,mark b){
    return a.mark > b.mark;
}
void Input(){
    cin >> n >> m;
}
void Core(){
    mark man[n];
    for(int i = 0;i < n;i++){
        cin >> man[i].num >> man[i].mark;
    }
    sort(man,man + n,cmp1);
    sort(man,man + n,cmp2);
    int  xian = man[int(double(m) * 1.50)].mark;
    int sum = 0;
    for(int i = 0;i < n;i++){
        if(man[i].mark >= xian){
            sum++;
        }else{
            continue;
        }
    }
    cout << xian << " " << sum << endl;
    for(int i = 0;i < sum;i++){
        cout << man[i].num << " " << man[i].mark << endl;
    }
}
int main(){
    Input();
    Core();
    return 0;
}