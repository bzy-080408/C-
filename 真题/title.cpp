

#include <bits/stdc++.h>

using namespace std;

int main(){
    bool a = true;
    int out = 0;
    while(a){
        char a;
        cin >> a;
        out++;
        if(a == '^'){
            cout << out;
            return 0;
        }
    }
}