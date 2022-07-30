#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define vl vector<ll>
#define len(x) x.size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mod 1000000007
#define N 200010
using namespace std;
typedef long long ll;
int n;
vl v;
ll t, x;

ll f(ll l, ll r)
{
    ll m = (l + r) / 2;
    if (l == r)
        return l;
    else
    {
        ll ans = 0;
        rep(i, n) ans += m / v[i];
        if (ans < t)
            f(m + 1, r);
        else
            f(l, m);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("a.txt", "r", stdin);
    cin >> n >> t;
    rep(i, n)
    {
        cin >> x;
        v.pb(x);
    }
    sort(all(v));
    cout << f(v[0], t * v[0]) << "\n";
}