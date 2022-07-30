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
vi ans(N);
multimap<int, int> v;
vector<pair<int, pair<int, int>>> vii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("a.txt", "r", stdin);
    cin >> n;
    rep(i, n)
    {
        int a, b;
        cin >> a >> b;
        vii.pb(mp(a, mp(b, i)));
    }
    sort(all(vii));
    int j = 0;
    rep(i, n)
    {
        bool nr = 1;
        if (i > 0)
        {
            // for (auto l : v)
            //     cout << l.fi << " " << l.se << ",\n";
            auto lower = v.lower_bound(vii[i].fi);
            if (lower != v.begin())
            {
                lower--;
                nr = 0;
                ans[vii[i].se.se] = ans[lower->se];
                v.insert(vii[i].se);
                v.erase(lower);
            }
        }
        if (nr)
        {
            v.insert(vii[i].se);
            ans[vii[i].se.se] = ++j;
        }
    }
    cout << j << "\n";
    rep(i, n) cout << ans[i] << " ";
}