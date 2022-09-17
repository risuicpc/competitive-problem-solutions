#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define inf 1000000000000000
#define N 100001
using namespace std;
typedef long long ll;

vector<pair<int, ll>> g1[N], g2[N];
vector<tuple<int, int, ll>> e;
vector<ll> d1(N), d2(N);
int n, m;

void DJ(int u, vector<ll> &dis, vector<pair<int, ll>> g[])
{
    priority_queue<pair<ll, int>> q;
    vector<bool> vis(n + 1, 0);

    q.push({0, u});
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto i : g[u])
        {
            if (!vis[i.first] && dis[u] + i.second < dis[i.first])
            {
                dis[i.first] = dis[u] + i.second;
                q.push({-dis[i.first], i.first});
            }
        }
    }
}

void DISCOUNT()
{
    rep(i, n - 1) d1[i + 2] = inf;
    rep(i, n) d2[i] = inf;
    DJ(1, d1, g1);
    DJ(n, d2, g2);
    ll mn = inf;
    for (auto i : e)
        mn = min(mn, d1[get<0>(i)] + d2[get<1>(i)] + get<2>(i) / 2);

    cout << mn << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    rep(i, m)
    {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        e.emplace_back(make_tuple(u, v, c));
        g1[u].emplace_back(make_pair(v, c));
        g2[v].emplace_back(make_pair(u, c));
    }
    DISCOUNT();
}