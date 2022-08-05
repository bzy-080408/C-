

#include <bits/stdc++.h>

using namespace std;

int n;
bool cmp(int a,int b){
    if(a > 0){
        return a > b;
    }else{
        return a < b;
    }
}
void Input(){
    cin >> n;
    int a[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a,a + n,cmp);
    //debug:
    // for(int i = 0;i < n;i++){
    //     cout << a[i] << " ";
    // }
    for(int i = 0;i < n;i++){
        if(a[i] < 0){
          //  cout << "-";
        }else{
            if(i != 0){
                cout << "+";
            }
        }
        if(a[i] != 1){
            cout << a[i] << "x^" << n  - i;
        }else{
            cout << "x^" << n  - i;
        }
    }
}
int main(){
    Input();
    return 0;
}