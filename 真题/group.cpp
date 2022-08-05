

#include <bits/stdc++.h>

using namespace std;
int w = 0,n,out = 0;
vector<int> all;
void Core(int sum[]){
    sort(sum,sum + n);
    while(all.size() > 1){
        for(int i = 0;i < all.size();i++){
            if(all[0] + all[all.size() - i - 1] <= w){
                out++;
                all.erase(all.begin());
                int tmp = all.size() - i - 1;
                all.erase(all.begin() + tmp);
                continue;
            }
        }
    }
    if(all.size() == 1){
        out++;
    }
    cout << out;
}
void Input(){
    //ifstream infile("group.in");
    cin >> w >> n;
    int sum[n];
    for(int i = 0;i < n;i++){
        int tmp = 0;
        cin >> tmp;
        all.push_back(tmp);
    }
    Core(sum);
}
int main(){
    Input();
    return 0;
}