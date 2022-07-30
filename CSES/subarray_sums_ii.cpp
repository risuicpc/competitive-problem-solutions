#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i)
            a[i] += a[i - 1];
    }
    int i = -1, j = 0, ans = 0;
    while (j < n)
    {
        long long temp = i == -1 ? a[j] : a[j] - a[i];
        if (temp == x)
        {
            ans++;
            j++;
            i++;
        }
        else if (temp < x)
            j++;
        else
            i++;
    }

    cout << ans << "\n";
}