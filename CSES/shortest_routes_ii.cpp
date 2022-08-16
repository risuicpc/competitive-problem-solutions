#include <bits/stdc++.h>
#define rep(i, n) for (int i = 1; i <= n; i++)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define pr(x) cout << x << "\n"
#define p(x) cout << x << " "
#define end cout << "\n"
#define pb push_back
#define fi first
#define se second
#define mod 1000000007
#define inf 10000000000000
#define N 501
using namespace std;
typedef long long ll;
ll dis[N][N], c;
int n, m, q, a, b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> q;
    rep(i, n) rep(j, n) if (i != j) dis[i][j] = inf;
    rep(i, m)
    {
        cin >> a >> b >> c;
        dis[a][b] = min(dis[a][b], c);
        dis[b][a] = min(dis[b][a], c);
    };

    rep(k, n) rep(i, n) rep(j, n) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    rep(i, q)
    {
        cin >> a >> b;
        if (dis[a][b] == inf)
            pr(-1);
        else
            pr(dis[a][b]);
    }
}