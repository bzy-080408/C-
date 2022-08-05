

#include <bits/stdc++.h>
#include "main.h"

using namespace std;

int main()
{
    bool a[10], b[10];
    gaojingdu::init(sizeof(a), sizeof(b));
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 10; i++)
    {
        cin >> b[i];
    }
    cout << gaojingdu::sizeofa << " " << gaojingdu::sizeofb << endl;
    for (int i = 0; i < 10; i++)
    {
        //    cout << a[i] << " ";
    }
}