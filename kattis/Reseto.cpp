#include <bits/stdc++.h>
using namespace std;

bool vis[100100];

int pri(int n, int k)
{
    int c = 0;
    for (int i = 2; i <= n; i++)
    {
        if (vis[i])
            continue;
        c++;
        if (c == k)
            return i;
        for (int j = 2 * i; j <= n; j += i)
        {
            if (!vis[j])
                c++;
            if (c == k)
                return j;
            vis[j] = 1;
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << pri(n, k);
}