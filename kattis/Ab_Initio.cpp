#include <bits/stdc++.h>
using namespace std;

const int si = 4001;
const int mod = 1000000007;

bool adj[si][si];
int v, e, q;

void complement()
{
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            if (i != j)
                adj[i][j] = !adj[i][j];
}

int main()
{
    cin >> v >> e >> q;
    bool cc = true, tr = 0;
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x][y] = cc;
    }

    for (int i = 0; i < q; i++)
    {
        int qi;
        cin >> qi;
        if (qi == 1)
        {
            v++;
            for (int j = 0; j < v; j++)
            {
                adj[v - 1][j] = !cc;
                adj[j][v - 1] = !cc;
            }
        }
        else if (qi == 2)
        {
            int x, y;
            cin >> x >> y;
            if (tr)
                adj[y][x] = cc;
            else
                adj[x][y] = cc;
        }
        else if (qi == 3)
        {
            int x;
            cin >> x;
            for (int j = 0; j < v; j++)
            {
                adj[x][j] = !cc;
                adj[j][x] = !cc;
            }
        }
        else if (qi == 4)
        {
            int x, y;
            cin >> x >> y;
            if (tr)
                adj[y][x] = !cc;
            else
                adj[x][y] = !cc;
        }
        else if (qi == 5)
        {
            tr = (!tr);
        }
        else if (qi == 6)
        {
            // complement();
            cc = (!cc);
        }
    }

    cout << v << endl;
    for (int i = 0; i < v; i++)
    {
        long long ans = 0, c = 1;
        q = 0;
        for (int j = 0; j < v; j++)
        {
            if (i != j)
            {
                if (tr)
                {
                    if (adj[j][i] == cc)
                    {
                        ans = (ans + (j * c) % mod) % mod;
                        c = (c * 7) % mod;
                        q++;
                    }
                }
                else if (adj[i][j] == cc)
                {
                    ans = (ans + (j * c) % mod) % mod;
                    c = (c * 7) % mod;
                    q++;
                }
            }
        }
        cout << q << " " << ans << endl;
    }
}