#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define len(x) x.size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define mod 1000000007
#define N 100001
using namespace std;
typedef long long ll;
vector<vector<int>> adj(N);
queue<pair<int, int>> q;
vector<bool> vis(N);
vector<int> an(N);
int n, m, a, b;

void dis(int i)
{
    if (i != 0)
    {
        dis(an[i]);
        cout << i << " ";
    }
}

int main()
{
    // freopen("a.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    rep(i, m)
    {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    q.push({1, 1});
    vis[1] = 1;
    an[1] = 0;
    while (!q.empty())
    {
        auto fr = q.front();
        q.pop();
        rep(j, len(adj[fr.fi]))
        {
            if (adj[fr.fi][j] == n)
            {
                an[n] = fr.fi;
                cout << fr.se + 1 << "\n";
                dis(n);
                return 0;
            }
            else if (!vis[adj[fr.fi][j]])
            {
                q.push({adj[fr.fi][j], fr.se + 1});
                vis[adj[fr.fi][j]] = 1;
                an[adj[fr.fi][j]] = fr.fi;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}