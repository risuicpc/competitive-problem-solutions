#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define N 100001
using namespace std;
typedef long long ll;

typedef tuple<ll, int, int> ti;

struct comp
{
    constexpr bool operator()(ti const &a, ti const &b) const noexcept
    {
        return get<0>(a) == get<0>(b) ? get<2>(a) > get<2>(b) : get<0>(a) > get<0>(b);
    }
};

priority_queue<ti, vector<ti>, comp> q;
vector<pair<int, ll>> adj[N];
vector<bool> vis(N);
vector<ll> dis(N);
vector<ll> d2(N);
int n, m;

void DJ()
{
    rep(i, n) dis[i + 1] = LONG_LONG_MAX;
    rep(i, n) d2[i + 1] = LONG_LONG_MAX;
    dis[1] = 0;
    d2[1] = 0;
    q.push({0, 1, 0});
    while (!q.empty())
    {
        int u = get<1>(q.top());
        ll mx = get<2>(q.top());
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto i : adj[u])
        {
            if (!vis[i.first])
            {
                if (i.second >= mx)
                {
                    ll d = dis[u] + i.second / 2 + ceil(mx / 2.0);
                    if (d <= dis[i.first])
                    {
                        dis[i.first] = d;
                        q.push({d, i.first, i.second});
                    }
                }
                else
                {
                    ll d = dis[u] + i.second;
                    if (d < dis[i.first])
                    {
                        dis[i.first] = d;
                        q.push({d, i.first, mx});
                    }
                }
            }
        }
    }
    cout << dis[n] << "\n";
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
        adj[u].emplace_back(make_pair(v, c));
    }
    DJ();
}