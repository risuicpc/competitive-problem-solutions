#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int p, k, n;
    cin >> p;
    while (p--)
    {
        cin >> k >> n;
        vector<ll> vp;
        vector<ll> sm(n + 1, 0);

        int a = 0, b = 1, c = 1, d = n;
        vp.push_back(b);
        while (c <= n)
        {
            int k = (n + b) / d, aa = a, bb = b;
            a = c;
            b = d;
            c = k * c - aa;
            d = k * d - bb;
            vp.push_back(b);
        }
        int num = -1;
        for (auto i : vp)
        {
            if (num != -1)
                sm[i] += num;
            num = i;
        }
        vector<pair<ll, ll>> v;
        for (ll i = 1; i <= n; i++)
        {
            ll g = __gcd(sm[i], i);
            v.push_back({sm[i] / g, i / g});
        }
        cout << k << " ";
        pair<ll, ll> an = {0, 1};
        for (auto i : v)
        {
            ll g = (an.second * i.second) / __gcd(an.second, i.second);
            an = {i.second * an.first + an.second * i.first, g};
        }
        cout << an.first << "/" << an.second << "\n";
    }
}