#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100001
#define inf 1000000000000000
int n, m, k;
vector<pair<int, ll>> adj[N];
vector<vector<ll>> dis(N, vector<ll>(10, inf));
priority_queue<pair<ll, int>> pq;

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    dis[1][0] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        int u = pq.top().second;
        ll d = -pq.top().first;
        pq.pop();

        if (dis[u][k - 1] < d)
            continue;

        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            if (dis[v][k - 1] > d + adj[u][i].second)
            {
                dis[v][k - 1] = d + adj[u][i].second;
                sort(dis[v].begin(), dis[v].end());
                pq.push({-(d + adj[u][i].second), v});
            }
        }
    }

    for (int i = 0; i < k; i++)
    {
        if (i > 0)
            cout << " ";
        cout << dis[n][i];
    }
}
