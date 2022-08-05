

#include <bits/stdc++.h>

using namespace std;

#define LLT long long int

inline LLT hanglieshi(int a[][]){
    LLT out = 0;
    int sum = sqrt(sizeof(a));
    for(int i = 1;i <= sum;i++){
        for(int j = i;j <= sum;j++){
            out += a[j][j - i + 1];
        }
    }
    for(int i = 1;i <= sum;i++){
        for(int j = i;j > 0;j--){
            out -= a[j][]
        }
    }
}

int main(){
    
}