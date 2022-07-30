#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t, x, y;
    cin >> t;
    while (t--)
    {
        cin >> x >> y;
        if (y >= x)
        {
            if (y % 2 || y == x)
                cout << y * y - x + 1 << "\n";
            else
                cout << (y - 1) * (y - 1) + x << "\n";
        }
        else
        {
            if (x % 2)
                cout << (x - 1) * (x - 1) + y << "\n";
            else
                cout << x * x - y + 1 << "\n";
        }
    }
}