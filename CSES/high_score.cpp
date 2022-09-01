#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
using namespace std;
typedef long long ll;

struct Edge
{
    int u;
    int v;
    ll d;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<Edge> e(m);
    vector<ll> dis(n + 1, LONG_LONG_MIN);
    rep(i, m) cin >> e[i].u >> e[i].v >> e[i].d;
    dis[1] = 0;
    rep(i, n - 1) rep(j, m)
    {
        if (dis[e[j].u] != LONG_LONG_MIN &&
            dis[e[j].u] + e[j].d > dis[e[j].v])
            dis[e[j].v] = dis[e[j].u] + e[j].d;
    }

    ll d = dis[n];
    rep(i, n - 1) rep(j, m)
    {
        if (dis[e[j].u] != LONG_LONG_MIN &&
            dis[e[j].u] + e[j].d > dis[e[j].v])
            dis[e[j].v] = 50000000000000;
    }

    if (dis[n] > d)
        cout << -1 << "\n";
    else
        cout << dis[n] << "\n";
}