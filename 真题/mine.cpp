

#include <bits/stdc++.h>

using namespace std;
int m,n;

// void WriteOut(int sum){
//     for(int i = 1;i <= m;i++){
//         for(int j = 1;j <= n;j++){
//        if(sum[i][j] == -1){
//             cout << "*";
//         }else{
//             cout << sum[i][j];
//         }
//         }
//     }
// }

// void Core(int sum[][]){
//     int out[m + 2][n + 2] = {0};
//     char N = '?',Y = '*';
//     for(int i = 1;i < m;i++){
//         for(int j = 1;j < n;j++){
//             if(sum[i][j] == N){
//                 if(sum[i + 1][j] == Y){
//                     out[i][j]++;
//                 }
//                 if(sum[i - 1][j] == Y){
//                     out[i][j]++;
//                 }
//                 if(sum[i + 1][j + 1] == Y){
//                     out[i][j]++;
//                 }
//                 if(sum[i - 1][j + 1] == Y){
//                     out[i][j]++;
//                 }
//                 if(sum[i + 1][j - 1] == Y){
//                     out[i][j]++;
//                 }
//                 if(sum[i - 1][j - 1] == Y){
//                     out[i][j]++;
//                 }
//                 if(sum[i][j + 1] == Y){
//                     out[i][j]++;
//                 }
//                 if(sum[i][j - 1] == Y){
//                     out[i][j]++;
//                 }
//             }else{
//                 out[i][j] -= 1;
//             }
//         }
//     }
//     WriteOut(out);
// }

void Input(){
    cin >> m >> n;
    int sum[m + 2][n + 2];
    for(int i = 1;i < m + 1;i++){
        for(int j = 1;j < n + 1;j++){
            cin >> sum[i][j];
        }
    }
    //Core(sum);
    int out[m + 2][n + 2];
    char N = '?',Y = '*';
    for(int i = 1;i < m;i++){
        for(int j = 1;j < n;j++){
            if(sum[i][j] == N){
                if(sum[i + 1][j] == Y){
                    out[i][j]++;
                }
                if(sum[i - 1][j] == Y){
                    out[i][j]++;
                }
                if(sum[i + 1][j + 1] == Y){
                    out[i][j]++;
                }
                if(sum[i - 1][j + 1] == Y){
                    out[i][j]++;
                }
                if(sum[i + 1][j - 1] == Y){
                    out[i][j]++;
                }
                if(sum[i - 1][j - 1] == Y){
                    out[i][j]++;
                }
                if(sum[i][j + 1] == Y){
                    out[i][j]++;
                }
                if(sum[i][j - 1] == Y){
                    out[i][j]++;
                }
            }else{
                out[i][j] -= 1;
            }
        }
    }
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
       if(sum[i][j] == -1){
            cout << "*";
        }else{
            cout << sum[i][j];
        }
        }
    }

}

int main(){
    Input();
    return 0;
}