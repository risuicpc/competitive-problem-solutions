#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, s, r, x, i;
    cin >> n >> s >> r;
    vector<int> v(n + 1, 1);
    for (i = 0; i < s; i++)
    {
        cin >> x;
        v[x] = 0;
    }
    for (i = 0; i < r; i++)
    {
        cin >> x;
        if (!v[x])
            v[x] = 1;
        else if (!v[x - 1])
            v[x - 1] = 1;
        else if (x < n)
            v[x + 1] = 1;
    }

    int c = 0;
    for (i = 1; i <= n; i++)
    {
        if (!v[i])
            c++;
    }
    cout << c << "\n";
}