

#include <bits/stdc++.h>

using namespace std;

vector<string> in;
string PDword;
int output = 0;
// bool PD(string a,string b){
//     bool out = false;
//     if(a.size() != b.size()) return out;
//     for(int i = 0;i < a.size();i++){
//         if(a[i] == b[i]){

//         }
//     }
// }
bool frist = true;
void Input(){
    cin >> PDword;
    string tmp;
    while(cin >> tmp){
        in.push_back(tmp);
    }
}
void Core(){
    for(int i = 0;i < in.size();i++){
        if(in[i] == PDword){
            output++;
            if(frist){
                cout << i;
                frist = false;
            }
        }else{
            if(int(in[i][0] - 32) == int(PDword[0]))
            for(int j = 1;j < in[i].size();j++){
                if(in[i][j] != PDword[j]){
                    continue;
                }
            }
            output++;
            if(frist){
                cout << i;
                frist = false;
            }
        }
    }

}

int main(){
    Input();
    Core();
    return 0;
}