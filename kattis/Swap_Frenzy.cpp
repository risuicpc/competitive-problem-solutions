#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
vector<int> v(20);
int si, k;
ll n;

int max(int i)
{
    int x = v[i], l = i;
    for (int j = si - 1; j > i; j--)
    {
        if (v[j] > x)
        {
            x = v[j];
            l = j;
        }
    }
    return l;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    si = ceil(log10(n));
    int i = si - 1;
    while (n > 0)
        v[i--] = n % 10, n /= 10;
    if (k >= si)
    {
        sort(v.rbegin(), v.rend());
        for (int i = 0; i < si; i++)
            cout << v[i];
        cout << '\n';

        return 0;
    }
    for (i = 0; i < si && k > 0; i++)
    {
        int j = max(i);
        if (j != i)
        {
            swap(v[i], v[j]);
            k--;
        }
    }

    if (k > 0 && k % 2)
        swap(v[si - 1], v[si - 2]);

    for (int i = 0; i < si; i++)
        cout << v[i];
    cout << '\n';

    return 0;
}