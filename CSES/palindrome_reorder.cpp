#include <bits/stdc++.h>
using namespace std;

int main()
{
    string n;
    cin >> n;
    int l = n.size();
    char str[l / 2 + 1], m[2];
    sort(n.begin(), n.end());
    int i = 0, j = 0;
    while (i < l - 1)
    {
        if (n[i] == n[i + 1])
        {
            str[j] = n[i];
            i += 2;
            j++;
        }
        else
        {
            m[0] = n[i];
            i += 1;
        }
    }
    if (i == l - 1)
        m[0] = n[l - 1];
    if (l != 2 * strlen(str) + strlen(m))
        cout << "NO SOLUTION\n";
    else
    {
        cout << str << m;
        for (int i = l / 2 - 1; i >= 0; i--)
            cout << str[i];
        cout << "\n";
    }
}
