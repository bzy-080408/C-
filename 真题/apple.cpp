

#include <bits/stdc++.h>

using namespace std;

int Maxheight = 0;
int sum[10];

void Input(){
    for(int i = 0;i < 10;i++){
        cin >> sum[i];
    }
    cin >> Maxheight;
}
void Core(){
    int out = 0;
    for(int i = 0;i < 10;i++){
        if(sum[i] <= Maxheight + 30){
            out++;
        }
    }
    cout << out;
}
int main(){
    Input();
    Core();
    return 0;
}