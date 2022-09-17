#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    while (cin >> n >> m)
    {
        vector<int> v(2 * n, 0);
        vector<pair<int, ll>> an(2 * n);
        for (int i = 1; i <= n; i++)
            an[i] = {1, i};
        int rt = n + 1;
        while (m--)
        {
            int t, p, q;
            cin >> t >> p;
            int pp = p;
            while (v[p])
                p = v[p];
            if (t == 1)
            {
                cin >> q;
                int qq = q;
                while (v[q])
                    q = v[q];
                if (p != q)
                {
                    if (qq != q)
                    {
                        an[q].first += an[p].first;
                        an[q].second += an[p].second;
                        v[p] = q;
                    }
                    else if (pp != p)
                    {
                        an[p].first += an[q].first;
                        an[p].second += an[q].second;
                        v[q] = p;
                    }
                    else
                    {
                        an[rt].first = an[p].first + an[q].first;
                        an[rt].second = an[p].second + an[q].second;
                        v[p] = rt;
                        v[q] = rt;
                        rt++;
                    }
                }
            }
            else if (t == 2)
            {
                cin >> q;
                int qq = q;
                while (v[q])
                    q = v[q];
                if (p != q)
                {
                    an[p].first--;
                    an[p].second -= pp;
                    if (qq == q)
                    {
                        an[rt].first = an[q].first + 1;
                        an[rt].second = an[q].second + pp;
                        v[q] = rt;
                        v[pp] = rt;
                        rt++;
                    }
                    else
                    {
                        an[q].first++;
                        an[q].second += pp;
                        v[pp] = q;
                    }
                }
            }
            else
                cout << an[p].first << " " << an[p].second << "\n";
        }
    }
}