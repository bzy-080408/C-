

#include <bits/stdc++.h>

using namespace std;

int main(){
	string in;
	cin >> in;
	int tmp2 = 0;
	if(in[0] = '-'){
		cout << "-";
		tmp2 = 1;
	}
	for(int i = 0;i < in.size() - tmp2;i++){
		cout << in[in.size() - 1];
	}
	return 0;
}
