#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define pr(x) cout << x << " "
#define end cout << "\n"
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define mod 1000000007
#define N 100000
using namespace std;
typedef long long ll;
int n, m, a, b;

vector<pair<int, ll>> adj[N + 1];
priority_queue<pair<ll, int>> q;
vector<ll> dis(N + 1);
bool vis[N + 1];
ll c;

void djShoPath()
{
    rep(i, n) dis[i + 1] = LONG_LONG_MIN;
    dis[1] = 0;
    q.push({0, 1});
    while (!q.empty())
    {
        a = q.top().se;
        q.pop();
        vis[a] = 1;
        for (auto i : adj[a])
        {
            if (dis[a] + i.se > dis[i.fi])
            {
                dis[i.fi] = dis[a] + i.se;
                if (!vis[i.fi])
                    q.push({dis[i.fi], i.fi});
                // else if (i.fi != 4 && dis[a] + i.se > 0)
                // {
                //     cout << -1 << "\n";
                //     return;
                // }
            }
        }
    }
    pr(dis[n]);
    end;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    rep(i, m)
    {
        cin >> a >> b >> c;
        adj[a].pb({b, c});
    }
    djShoPath();
}