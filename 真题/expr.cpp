

#include <bits/stdc++.h>

using namespace std;

string in;

void Input(){
	cin >> in;
}
long long int num = 0;
long long int sum[1000001];
char fu[10000001];
void convert(){
	long long int tmp = 0;
	long long int tmp2 = 0;
	for(int i = 0;i < in.size();i++){
		if(in[i] > 45){
			tmp++;
			fu[tmp] = in[i]; 
		}else{
			sum[tmp] = int(in[i] - '0') * pow(10,tmp2);
		       tmp2++;
		}
	}
	num = tmp;
}	
void Core(){
	int tmp[1000001] = {0};
	long long int output = 0;
	for(int i = 0;i < num;i++){
		if(fu[i] == '*'){
			//output += sum[i - 1] * sum[i];
			sum[i] = sum[i - 1] * sum[i];
			sum[i - 1] = 0;
		}
	}
	for(int i = 0;i < num;i++){
		output += sum[i];
	}
	int out[4] = {0},tmp2 = 0;
	for(int i = num - 1;i >= 0;i--){
		if(tmp2 == 4){
			for(int j = 3;j >= 0;j--){
				cout << out[i];
			}
			return;
		}
		out[tmp2] = sum[i];
	}
	for(int i = 3;i >= 0;i--){
		cout << out[i];
	}
}
int main(){
	Input();
	convert();
	Core();
	return 0;
}
