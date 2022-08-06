#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define len(x) (int)x.size()
typedef long long ll;
using namespace std;
const int N = 1e5 + 5;
vector<vector<int>> adj(N);
vector<pair<int, int>> vp;
queue<int> q;
int n, m, a, b;
bool vis[N];

int main()
{
    // freopen("a.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    rep(i, m)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int f = 0;
    rep(i, n)
    {
        if (!vis[i + 1])
        {
            vis[i + 1] = 1;
            q.push(i + 1);
            if (f != 0)
                vp.push_back({f, i + 1});
            while (!q.empty())
            {
                f = q.front();
                q.pop();
                rep(j, len(adj[f]))
                {
                    if (!vis[adj[f][j]])
                    {
                        q.push(adj[f][j]);
                        vis[adj[f][j]] = 1;
                    }
                }
            }
        }
    }
    cout << len(vp) << "\n";
    for (auto i : vp)
        cout << i.first << " " << i.second << "\n";
}