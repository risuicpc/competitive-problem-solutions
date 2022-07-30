#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long ans = 0;
    int n, x, prev = -1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (i > 0)
            ans += max(0, prev - x);
        prev = max(x, prev);
    }
    cout << ans << "\n";
}