#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
typedef long long ll;
using namespace std;
vector<ll> v;
ll mx = 0;
int n;

int main()
{
    // freopen("a.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    rep(i, n)
    {
        ll x;
        cin >> x;
        v.pb(x);
    }
    sort(all(v));
    rep(i, n)
    {
        if (v[i] > mx + 1)
        {
            cout << mx + 1 << "\n";
            return 0;
        }
        else
            mx += v[i];
    }
    cout << mx + 1 << "\n";
}