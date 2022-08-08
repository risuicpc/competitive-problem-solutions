#include <bits/stdc++.h>
#define mod 1000000007
#define N 1000000
using namespace std;
typedef long long ll;
vector<int> v;
int n, x, a;

ll dp[N + 1];
void findWays()
{

    dp[0] = 1;
    for (int i = 1; i <= x; i++)
    {
        dp[i] = 0;
        for (int j = 0; j < n; j++)
            if (i - v[j] >= 0)
                dp[i] = (dp[i] + dp[i - v[j]]) % mod;
    }

    cout << dp[x] << "\n";
}

int main()
{
    // freopen("a.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    findWays();
    return 0;
}
