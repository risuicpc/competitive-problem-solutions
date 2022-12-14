#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;
map<ll, ll> prevSum;
vector<ll> v;
ll x, an = 0, sum = 0;
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("a.txt", "r", stdin);
    cin >> n >> x;
    rep(i, n)
    {
        ll a;
        cin >> a;
        v.pb(a);
    }

    rep(i, n)
    {
        sum += v[i];
        if (sum == x)
            an++;

        if (prevSum.find(sum - x) != prevSum.end())
            an += (prevSum[sum - x]);
        prevSum[sum]++;
    }
    cout << an << "\n";
    return 0;
}
