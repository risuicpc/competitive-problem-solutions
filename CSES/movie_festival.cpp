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
int n, m, k, x;
int ans = 0;
vector<pair<int, int>> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("a.txt", "r", stdin);
    cin >> n;
    rep(i, n)
    {
        cin >> k >> x;
        v.pb(mp(k, x));
    }
    sort(all(v));

    int mx = 0;
    rep(i, n)
    {
        if (!mx)
            mx = v[i].se;
        else
        {
            if (mx <= v[i].fi)
            {
                ans++;
                mx = v[i].se;
            }
            else
                mx = min(mx, v[i].se);
        }
    }
    cout << ans + 1 << "\n";
}