#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define len(x) x.size()
using namespace std;
typedef long long ll;
set<ll> s1, s2;
ll n, a, ans = 0;
int k;

int main()
{
    // freopen("a.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    rep(i, k)
    {
        cin >> a;
        ans += n / a;
        set<ll> t;
        for (ll j : s1)
        {
            if (n / a >= j && n / j >= a)
            {
                ans -= n / (a * j);
                t.insert(a * j);
            }
        }
        s1.insert(a);
        for (ll j : s2)
        {
            if (n / a >= j && n / j >= a)
            {
                ans += n / (a * j);
                s1.insert(a * j);
            }
        }
        for (ll j : t)
            s2.insert(j);
    }

    cout << ans << "\n";
}