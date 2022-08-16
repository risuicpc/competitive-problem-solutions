#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define PAIR pair<int, int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define mod 1000000007
#define N 200010
using namespace std;
typedef long long ll;
vector<pair<PAIR, ll>> V;
map<int, ll> M;
int n, a, b, p;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    rep(i, n)
    {
        cin >> a >> b >> p;
        V.pb({{a, b}, p});
    }
    sort(all(V));
    rep(i, n)
    {
        if (i == 0)
            M[V[i].fi.fi - 1] = 0, M[V[i].fi.se] = V[i].se;
        else
        {
            auto f = M.lower_bound(V[i].fi.fi);
            auto s = M.lower_bound(V[i].fi.se);
            if (s == M.end() || s->fi > V[i].fi.se)
                s--;
            M[V[i].fi.se] = max((--f)->se + V[i].se, s->se);
            ll mx = M[V[i].fi.se];
            auto l = M.upper_bound(V[i].fi.se);
            auto r = l;
            while (r != M.end() && mx >= r->se)
                r++;
            if (l != r)
                M.erase(l, r);
        }
    }

    cout << M.rbegin()->se << "\n";
}