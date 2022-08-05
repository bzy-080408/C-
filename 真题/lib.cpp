

#include <bits/stdc++.h>

using namespace std;

struct man
{
    int num;
    int sum;
};

int main()
{
    int n, q;
    cin >> n >> q;
    man men[q];
    int book[n];
    for (int i = 0; i < n; i++)
    {
        cin >> book[i];
    }
    for (int i = 0; i < q; i++)
    {
        cin >> men[i].sum >> men[i].num;
    }
    sort(book, book + n);
    for (int i = 0; i < q; i++)
    {
        bool tmp2 = true;
        for (int j = 0; j < n; j++)
        {
            int tmp = pow(10, men[i].sum);
            if (book[j] % tmp == men[i].num)
            {
                cout << book[j] << endl;
                book[j] = 0;
                tmp2 = false;
                break;
            }
        }
        if (tmp2)
        {
            cout << "-1" << endl;
        }
    }
    return 0;
}