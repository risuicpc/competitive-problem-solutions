#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define PAIR pair<int, int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define mod 1000000007
#define N 200010
using namespace std;
typedef long long ll;
vector<pair<int, PAIR>> V;
int n, x, y;

bool comp(pair<int, PAIR> x, pair<int, PAIR> y)
{
    return x.fi < y.fi || (x.fi == y.fi && x.se.fi > y.se.fi);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int> an(n, 0), ans(n, 0);
    rep(i, n)
    {
        cin >> x >> y;
        V.pb({x, {y, i}});
    }
    sort(all(V));
    auto j = V.rbegin();
    for (auto i = ++V.rbegin(); i != V.rend(); i++)
    {
        if (i->se.fi >= j->se.fi)
        {
            an[i->se.se] = 1;
            if (i->fi == j->fi && i->se.fi == j->se.fi)
                an[j->se.se] = 1;
        }
        else
        {
            if (i->fi == j->fi)
                an[j->se.se] = 1;
            j = i;
        }
    }
    for (int i : an)
        cout << i << " ";
    cout << "\n";
    sort(all(V), comp);
    auto k = V.begin();
    for (auto i = ++V.begin(); i != V.end(); i++)
    {
        if (i->se.fi <= k->se.fi)
        {
            ans[i->se.se] = 1;
            if (i->fi == k->fi && i->se.fi == k->se.fi)
                ans[k->se.se] = 1;
        }
        else
            k = i;
    }
    for (int i : ans)
        cout << i << " ";
    cout << "\n";
}