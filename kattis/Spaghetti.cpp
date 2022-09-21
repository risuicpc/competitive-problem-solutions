#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, a, b, c;
        cin >> a >> b >> c >> n;
        for (ll i = 0; i <= n; i++)
            cout << a * i * i + b * i + c << " ";
        cout << "\n";
    }
}