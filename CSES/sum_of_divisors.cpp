#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007

ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return (res + p) % p;
}

int main()
{
    while (l <= n)
    {
        ll k = n / l;
        ll r = n / k;
        k %= mod;
        ll t1 = ((((r % mod) * ((r + 1) % mod)) % mod) * mi) % mod;
        ll t2 = (((((l - 1) % mod) * (l % mod)) % mod) * mi) % mod;
        ans += ((t1 - t2) * k) % mod;
        ans %= mod;
        l = r + 1;
    }
    ans = ans % mod;
    if (ans < 0)
    {
        cout << ans + mod << '\n';
    }
    else
    {
        cout << ans << '\n';
    }
}
