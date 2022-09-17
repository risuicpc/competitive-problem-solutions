#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define pb push_back
#define mod 1000000007
#define N 200000
using namespace std;
typedef long long ll;
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<tuple<int, int, int>> b(n), f(n);
    vector<int> bp(n), bh(n), fp(n), fh(n), ba(n), fa(n);
    rep(i, n) cin >> bp[i];
    rep(i, n) cin >> bh[i];
    rep(i, n) cin >> fp[i];
    rep(i, n) cin >> fh[i];

    rep(i, n) b[i] = make_tuple(bp[i], bh[i], i + 1);
    rep(i, n) f[i] = make_tuple(fp[i], fh[i], i + 1);
    sort(all(b));
    sort(all(f));

    // rep(i, n) cout << get<0>(b[i]) << " ";
    // cout << "\n";
    // rep(i, n) cout << get<1>(b[i]) << " ";
    // cout << "\n";
    // rep(i, n) cout << get<0>(f[i]) << " ";
    // cout << "\n";
    // rep(i, n) cout << get<1>(f[i]) << " ";
    // cout << "\n";

    set<pair<int, int>> bs, fs;
    int bi = 0, fi = 0;
    rep(i, n)
    {
        if (bs.empty() && bi < n)
        {
            int p = get<0>(b[bi]);
            while (bi < n && get<0>(b[bi]) == p)
            {
                bs.emplace(make_pair(get<1>(b[bi]), get<2>(b[bi])));
                bi++;
            }
        }
        if (fs.empty() && fi < n)
        {
            int p = get<0>(f[fi]);
            while (fi < n && get<0>(f[fi]) == p)
            {
                fs.emplace(make_pair(get<1>(f[fi]), get<2>(f[fi])));
                fi++;
            }
        }

        if (bs.size() <= fs.size())
        {
            ba[i] = bs.begin()->second;
            auto it = fs.lower_bound(make_pair(bs.begin()->first, -1));
            bs.erase(bs.begin());
            if (it == fs.begin())
            {
                cout << "impossible\n";
                return 0;
            }
            it = prev(it);
            fa[i] = it->second;
            fs.erase(it);
        }
        else
        {
            fa[i] = fs.begin()->second;
            auto it = bs.lower_bound(make_pair(fs.begin()->first + 1, -1));
            fs.erase(fs.begin());
            if (it == bs.end())
            {
                cout << "impossible\n";
                return 0;
            }
            ba[i] = it->second;
            bs.erase(it);
        }
    }
    rep(i, n)
    {
        if (i > 0)
            cout << " ";
        cout << ba[i];
    }
    cout << "\n";
    rep(i, n)
    {
        if (i > 0)
            cout << " ";
        cout << fa[i];
    }
    cout << "\n";
}