

#include <bits/stdc++.h>

using namespace std;

int N,M,fnum;
long long int h[10001][101] = {0};
int flag[10001][101] = {0};

int PD(int a,int b){
	if(a > b){
		return a + b;
	}else{
		return b - a;
	}
}


int bao(int num,int H,int out){
	if(H == N){
		return out + h[H][num];
	}else{
		out += h[H][num];
		//cout << H << " " << num << endl;
		return bao(PD(h[H][num],M),flag[H][num] + H,out);
	}
}


void Input(){
	cin >> N >> M;
	for(int i = 0;i < N;i++){
		for(int j = 0;j < M;j++){
			cin >> flag[i][j] >> h[i][j];
		}
	}
	cin >> fnum;
	cout << bao(fnum,1,0) % 20123;
}
int main(){
	Input();
	return 0;
}
