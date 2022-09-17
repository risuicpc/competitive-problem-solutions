#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int upside_down(int n)
{
    int an = 0, b = 1;
    while (n)
    {
        an *= b;
        an += n % 10;
        n /= 10;
        b *= 10;
    }
    return an;
}
map<int, int> a, b, r;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s, x;
    cin >> n >> s;
    while (n--)
    {
        cin >> x;
        a[x]++;
        int up = upside_down(x);
        if (up != x)
        {
            b[up]++;
            r[x] = up;
        }
    }

    for (auto i : a)
    {
        int d = s - i.first;
        if (a.count(d) && (d != i.first || a[d] > 1))
        {
            cout << "YES\n";
            return 0;
        }
        if (b.count(d))
        {
            if (!r.count(i.first) || r[i.first] != d || b[d] > 1)
            {
                cout << "YES\n";
                return 0;
            }
        }
    }
    for (auto i : b)
    {
        int d = s - i.first;
        if (b.count(d) && (d != i.first || b[d] > 1))
        {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}