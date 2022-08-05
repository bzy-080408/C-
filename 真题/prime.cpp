

#include <bits/stdc++.h>

using namespace std;
long long int n = 0;
void Input(){
    cin >> n;
}
void Core(){
    int tmp = 0;
    for(int i = 2;i < n/2;i++){
        if(n % i == 0){
            tmp = i;
            continue;
        }
    }
    cout << tmp;
}
int main(){
    Input();
    Core();
    return 0;
}