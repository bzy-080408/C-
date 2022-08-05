

#include <bits/stdc++.h>

using namespace std;

int sum,out;

void Core(int s[]){
	sort(s,s + sum);
	for(int i = 0;i < sum;i++){
		for(int j = i + 1;j < sum;j++){
			int tmp = s[i] + s[j];
			for(int k = 0;k < sum;k++){
			       if(tmp == s[k]){
			       out++;
			       }
			}
		}
	}
}	
void Input(){
	cin >> sum;
	int s[sum];
	for(int i = 0;i < sum;i++){
		cin >> s[i];
	}
	Core(s);
}
void WriteOut(){
	cout << out;
}
int main(){
	Input();
	WriteOut();
	return 0;
}
