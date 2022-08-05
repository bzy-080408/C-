

#include <bits/stdc++.h>

using namespace std;

string In;
int out = 0;
int x = 0;
int y = 0;
void Input(){
    cin >> x >> y;
    for(int i = 1;i <= x;i++){
        In.push_back(char(i + 48));
    }
}
void Core(){
    for(int i = 0;i < In.size() - 1;i++){
        //cout << In[i] << y;
        if(In[i] == y){
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