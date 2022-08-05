

#include <bits/stdc++.h>

using namespace std;
int in1,in2,L;
void Input(){
    cin >> in1 >> in2 >> L;
}
void Core(){
    int i = 0;
    bool tmp1 = false,tmp2 = false;
    while(tmp1 == false && tmp2 == false){
        if(int(in1 % i) == 0 && int(in2 % i) == 0){
            tmp1 = false;
            in1 /= i;
            in2 /= i;
        }else{
            tmp1 = true;
        }
        if(min(in1,in2) > L){
            tmp2 = false;
            in1 /= L;
            in2 /= L;
        }else{
            tmp2 = true;
        }
    }
    // while(min(in1,in2) > L){
    //     in1 /= double(L);
    //     in2 /= double(L);
    // }
    cout << in1 << " " << in2;
}
int main(){
    Input();
    Core();
    return 0;
}