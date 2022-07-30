#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define vl vector<ll>
#define len(x) x.size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mod 1000000007
#define N 200010
using namespace std;
typedef long long ll;
int n, x;
map<int, int> mii;
multiset<int> si;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("a.txt", "r", stdin);
    cin >> x >> n;
    mii.insert({0, x});
    si.insert(x);
    rep(i, n)
    {
        int a;
        cin >> a;
        auto u = mii.lower_bound(a);
        u--;
        mii.erase(u);
        int l = u->fi, r = u->se;
        auto uu = si.lower_bound(r - l);
        si.erase(uu);

        mii.insert({l, a});
        mii.insert({a, r});
        si.insert(a - l);
        si.insert(r - a);

        cout << (*(--si.end())) << " ";
    }
}