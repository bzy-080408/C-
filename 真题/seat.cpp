

#include <bits/stdc++.h>

using namespace std;

int m,n;//教室
int k,l;//横过道，纵过道
int d;//说话sum
struct f{
    int cor;
    int numx;
    int numy;
};

struct x{
    int sum;
    int num;
};
struct y{
    int sum;
    int num;
};
    
bool cmp1(x a,x b){
    return a.sum > b.sum;
}
bool cmp2(y a,y b){
    return a.sum > b.sum;
}
void Core(){
    int class[m][n] = {0};
    for(int i = 1;i <= d;i++){
        int tmpa1,tmpa2,tmpb1,tmpb2;
        cin >> tmpa1 >> tmpa2 >> tmpb1 >> tmpb2;
        class[tmpa1][tmpa2] = i;
        class[tmpb1][tmpb2] = i;
    }
    int sum[m - 1][n - 1];
    f _main[m - 1][n - 1];
    for(int i = 0;i < m - 1;i++){
        for(int j = 0;j < n - 1;j++){
            _main[i][j].numx = i;
            _main[i][j].numy = j; 
            if((class[i][j] == class[i][j + 1] && class[i][j] != 0 && class[i][j + 1] ！= 0) || (class[i][j] == class[i][j + 1] && class[i][j] != 0 && class[i + 1][j] ！= 0)){
                _main[i][j].cor++;
            }
        }
    }

    x X[m - 1];
    y Y[n - 1];
    for(int i = 0;i < m - 1;i++){
        for(int j = 0;j < n - 1;j++){
            X[i].sum += _main[i][j].cor;
            Y[j].sum += _main[i][j].cor;
            X[i].sum = j;
            Y[j].sum = i;
        }
    }
    sort(X,X + m - 1,cmp1);
    sort(Y,Y + n - 1,cmp2);
    for(int i = 0;i < k;i++){
        cout << X[i].num << " ";
    }
    cout << endl;
    for(int i = 0;i < k;i++){
        cout << Y[i].num << " ";
    }
}
void Input(){
    cin >> m >> n >> k >> l >> d;
}

int main(){
    Input();
    Core();
    return 0;
}