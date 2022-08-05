

#include <bits/stdc++.h>

using namespace std;

int m,n;
int out = 0;

void Core(int sum[],int M[]){
    sort(sum,sum + n);
    for(int i = 0;i < n;i++){
        sort(M,M + m);
        M[0] += sum[i];
    }
    sort(M,M + m);
    cout << M[m - 1];
}

void Input(){
    cin >> m >> n;
    int sum[n];
    for(int i = 0;i < n;i++){
        cin >> sum[i];
    }
    int M[m] = {0};
    Core(sum,M);
}

int main(){
    Input();
    return 0;
}