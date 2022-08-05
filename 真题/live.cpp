

#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000

int n, w;

bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int p = 0;
    cin >> n;
    cin >> w;
    vector<int> num;
    int sum[MAXN] = {0};
    int tmp = 0;
    int tmp2 = 0;
    cin >> sum[1];
    num.push_back(sum[1]);
    for (int i = 2; i <= n; i++)
    {
        cin >> sum[i];
        if (sum[i] >= tmp)
        {
            num.push_back(tmp2);
        }
        // sort(sum + 1,sum + i + 1,cmp);
        // if(sum[i] >= tmp){
        tmp = sum[max(1, int(i * w / 100))];
        tmp2 = max(1, int(i * w / 100));
        //}
        cout << sum[max(1, int(i * w / 100))] << " ";
    }
    return 0;
}