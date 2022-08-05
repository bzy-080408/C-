

#include <bits/stdc++.h>

using namespace std;
int n;
struct pen
{
    int allmon;
    int sum;
    int onemon;
} sum[3];
void Input()
{
    cin >> n;
    for (int i = 0; i < 3; i++)
    {
        cin >> sum[i].sum >> sum[i].allmon;
        sum[i].onemon = sum[i].sum + sum[i].allmon;
    }
}

bool cmp1(pen a, pen b)
{
    return a.onemon < b.onemon;
}

void Core()
{
    sort(sum, sum + 3, cmp1);
    vector<int> out;
    for (int i = 0; i < 3; i++)
    {
        if (n % sum[i].sum == 0)
        {
            out.clear();
            out.push_back(n / i * sum[i].allmon);
            cout << out[0];
            return;
        }
        else
        {
            if (n % sum[i].sum < sum[i - 1].sum)
            {
                out.clear();
                out.push_back(n / sum[i].sum * sum[i].allmon + sum[i - 1].allmon);
                // out.push_back(n / i * sum[allmon);
                cout << out[0];
            }
            else
            {
                if (n % sum[i].sum % sum[i - 1] == 0)
                {
                    out.clear();
                    out.push_back(n / sum[i].sum * sum[i].allmon + sum[i - 1].allmon);
                    //  out.push_back(n / i * allmon);
                    cout << out[0];
                }
                else
                {
                    out.push_back((n / sum[i] + 1) * sum[i].mon);
                }
            }
        }
    }
    sort(out.begin(), out.end());
    cout << out;
}
int main()
{
    Input();
    Core();
    return 0;
}