#include <bits/stdc++.h>
#define mod 1000000007
#define N 1000000
using namespace std;
typedef long long ll;
vector<int> v;
int n, x, a;
ll an = 0;

ll findWays(ll x, int i)
{
    if (x <= v[i])
    {
        if (x == v[i])
            an++;
        return 0;
    }
    for (int j = i; j < n; j++)
    {
        findWays(x - v[j], j);
        findWays(x - v[j], j + 1);
    }

    return an;
}

int main()
{
    freopen("a.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    cout << findWays(x, 0) << "\n";

    return 0;
}
