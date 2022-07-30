#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int s, d;
        cin >> s >> d;
        int y = (s - d) / 2;
        if (s < d || (s - d) % 2)
            cout << "impossible\n";
        else
            cout << d + y << " " << y << "\n";
    }
}
