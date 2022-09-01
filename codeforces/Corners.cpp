#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string st[n];
        int one = 0, l = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> st[i];
            for (int j = 0; j < m; j++)
                if (st[i][j] == '1')
                    one++;
        }
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < m - 1; j++)
            {
                int c = st[i][j] == '0' ? 1 : 0;
                c += st[i + 1][j] == '0' ? 1 : 0;
                c += st[i][j + 1] == '0' ? 1 : 0;
                c += st[i + 1][j + 1] == '0' ? 1 : 0;
                l = max(l, c);
            }
            if (l > 1)
                break;
        }
        if (l > 1)
            cout << one << "\n";
        else if (l == 1)
            cout << one - 1 << "\n";
        else
            cout << one - 2 << "\n";
    }
}