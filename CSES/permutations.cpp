#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 1)
        cout << 1 << "\n";
    else if (n < 4)
        cout << "NO SOLUTION\n";
    else
    {
        int i = 2;
        while (i <= n)
        {
            cout << i << " ";
            i += 2;
        }
        i = 1;
        while (i <= n)
        {
            cout << i << " ";
            i += 2;
        }
    }
}