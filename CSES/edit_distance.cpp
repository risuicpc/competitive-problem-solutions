#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[5001][5001];

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size(), a = n;
    for (int i = 0; i < n; i++)
        dp[i + 1][m + 1] = a--;
    a = m;
    for (int i = 0; i < m; i++)
        dp[n + 1][i + 1] = a--;

    for (int i = n; i > 0; i--)
        for (int j = m; j > 0; j--)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i + 1][j + 1];
            else
                dp[i][j] = 1 + min(min(dp[i + 1][j + 1], dp[i + 1][j]), dp[i][j + 1]);
        }

    cout << dp[1][1] << "\n";
}