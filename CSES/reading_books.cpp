#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
typedef long long ll;
vector<ll> v;
ll sum = 0;
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("a.txt", "r", stdin);
    cin >> n;
    rep(i, n)
    {
        ll a;
        cin >> a;
        sum += a;
        v.pb(a);
    }
    sort(all(v));
    if (v[n - 1] > sum - v[n - 1])
        cout << 2 * v[n - 1] << "\n";
    else
        cout << sum << "\n";
}