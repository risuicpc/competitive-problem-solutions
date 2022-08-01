#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
vector<pair<int, int>> v;
multiset<int> si;
int n, k, ans = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    rep(i, n)
    {
        int a, b;
        cin >> a >> b;
        v.pb(mp(a, b));
    }
    sort(all(v));
    rep(i, k) si.insert(v[i].se);

    for (int i = k; i < n; i++)
    {
        auto it = si.upper_bound(v[i].fi);
        if (it != si.begin())
        {
            si.erase(--it);
            si.insert(v[i].se);
            ans++;
        }
        else if (*(--si.end()) > v[i].se)
        {
            si.erase(--si.end());
            si.insert(v[i].se);
        }
    }
    cout << ans + k << "\n";
}