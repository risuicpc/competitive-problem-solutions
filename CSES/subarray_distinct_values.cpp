#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
typedef long long ll;
using namespace std;
ll an = 0, l = 0;
int n, k, d = 0;
map<int, int> mp;
vector<int> v;

int main()
{
    // freopen("a.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    rep(i, n)
    {
        int x;
        cin >> x;
        v.pb(x);
    }
    int j = 0;
    rep(i, n)
    {
        if (mp[v[i]] == 0)
            d++;
        mp[v[i]]++;
        l++;
        while (d > k)
        {
            if (mp[v[j]] == 1)
                d--;
            mp[v[j]]--;
            j++;
            l--;
        }

        if (d <= k)
            an += l;

        // cout << "dis " << d << "\n";
        // cout << "len " << l << "\n";
        // for (auto ii : mp)
        //     cout << ii.first << " " << ii.second << "\n";
        // cout << "\n";
    }
    cout << an << "\n";
}