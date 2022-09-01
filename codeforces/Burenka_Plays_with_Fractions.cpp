#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll ad = a * d, bc = b * c;
        if (ad < bc)
            swap(ad, bc);
        if (a * d == b * c)
            cout << 0 << "\n";
        else if (bc == 0 || ad % bc == 0)
            cout << 1 << "\n";
        else
            cout << 2 << "\n";
    }
}