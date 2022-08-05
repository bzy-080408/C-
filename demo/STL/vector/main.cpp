

#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<int> __list;
	int tmp;
	while(cin >> tmp){
		__list.push_back(tmp);
	}
	for(int i = 0;i < __list.size();i++){
		cout << __list[i] << " ";
	}
	for(vector<int> ::iterator it = __list.end() - 1; it != __list.begin() - 1;it--){
		cout << (*it) << " ";
	}
	return 0;
}
