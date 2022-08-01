#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
int n, a, b;
multiset<ll> si;

int main()
{
    // freopen("a.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> a >> b;
    vector<ll> v(n + 1, 0);
    ll an = LONG_LONG_MIN, sum = 0;
    rep(i, n)
    {
        cin >> v[i + 1];
        v[i + 1] += v[i];
    }
    // for (int i : v)
    //     cout << i << " ";
    // cout << "\n";
    int flag = 0;
    si.insert(0);
    for (int i = a; i < n + 1; i++)
    {
        if (i - b >= 0 && flag == 0)
        {
            si.erase(si.find(0));
            flag = 1;
        }
        if (i - a >= 0)
            si.insert(v[i - a]);
        an = max(an, v[i] - *si.begin());

        if (i - b >= 0 && flag)
            si.erase(si.find(v[i - b]));
    }

    cout << an << "\n";
}