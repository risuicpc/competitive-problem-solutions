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
vector<int> an(N);
queue<int> q, q1;
int n, m, a, b;

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
    rep(i, n) q1.push(i + 1);
    while (!q1.empty())
    {
        a = q1.front();
        q1.pop();
        if (an[a] == 0)
        {
            q.push(a);
            an[a] = 1;
            while (!q.empty())
            {
                int fr = q.front();
                q.pop();
                int i = an[fr] == 1 ? 2 : 1;
                rep(j, len(adj[fr]))
                {
                    if (an[fr] == an[adj[fr][j]])
                    {
                        cout << "IMPOSSIBLE\n";
                        return 0;
                    }
                    else if (an[adj[fr][j]] == 0)
                    {
                        q.push(adj[fr][j]);
                        an[adj[fr][j]] = i;
                    }
                }
            }
        }
    }
    rep(i, n) cout << an[i + 1] << " ";
}