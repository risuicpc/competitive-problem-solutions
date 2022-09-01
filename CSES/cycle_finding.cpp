#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define N 3000
using namespace std;
typedef long long ll;

struct Edge
{
    int u;
    int v;
    ll d;
};

vector<ll> dis(N, LONG_LONG_MAX);
vector<bool> vis(N);
int n, m;

int no_ = 0;
void disp(int no, int v, vector<int> &p)
{
    if (v == no)
        no_++;
    if (v == no && no_ == 2)
    {
        cout << v << " ";
        return;
    }

    disp(no, p[v], p);
    cout << v << " ";
}

void BF(int u, vector<Edge> &e)
{
    vector<int> parent(n, -1);
    dis[u] = 0;
    bool f = 0;
    rep(i, n - 1)
    {
        if (f)
            break;
        f = 1;
        rep(j, m)
        {
            if (dis[e[j].u] != LONG_LONG_MAX &&
                dis[e[j].u] + e[j].d < dis[e[j].v])
            {
                dis[e[j].v] = dis[e[j].u] + e[j].d;
                parent[e[j].v] = e[j].u;
                f = 0;
            }
        }
    }
    int no = 0;
    rep(j, m)
    {
        if (dis[e[j].u] != LONG_LONG_MAX &&
            dis[e[j].u] + e[j].d < dis[e[j].v])
        {
            parent[e[j].v] = e[j].u;
            no = e[j].v;
            break;
        }
    }
    if (no != 0)
    {

        for (int i = 0; i < n; i++)
            no = parent[no];
        cout << "YES\n";
        disp(no, no, parent);
        cout << "\n";
        exit(0);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vector<Edge> e(m);
    rep(i, m) cin >> e[i].u >> e[i].v >> e[i].d;

    rep(i, n) if (dis[i + 1] == LONG_LONG_MAX) BF(i + 1, e);

    cout << "NO\n";
}