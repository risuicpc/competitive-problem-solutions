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
bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.fi == b.fi)
        return a.se > b.se;
    return a.fi < b.fi;
}
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
        v.pb(mp(k, 1));
        v.pb(mp(x, -1));
    }
    sort(all(v), comp);

    int sum = 0;
    rep(i, 2 * n)
    {
        sum += v[i].se;
        ans = max(ans, sum);
    }
    cout << ans << "\n";
}