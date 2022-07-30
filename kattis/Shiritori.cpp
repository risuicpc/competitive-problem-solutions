#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, bool> m;
    char c;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (i > 0 && s[0] != c || m[s])
        {
            cout << "player " << i % 2 + 1 << " lost\n";
            return 0;
        }
        c = s[s.size() - 1];
        m[s] = 1;
    }

    cout << "Fair Game\n";
}