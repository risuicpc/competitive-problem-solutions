#include <bits/stdc++.h>
#define mod 1000000007
#define N 1000000
using namespace std;
typedef long long ll;

ll dp[N + 1];
void findWays(int n)
{

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 0;
        for (int j = 1; j <= 6; j++)
            if (i - j >= 0)
                dp[i] = (dp[i] + dp[i - j]) % mod;
    }

    cout << dp[n];
}

int main()
{
    int n;
    cin >> n;
    findWays(n);
    return 0;
}
