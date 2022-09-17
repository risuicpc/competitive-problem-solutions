#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<string> v;
map<char, int> a;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    while (cin >> n)
    {
        ll an = 9, c = 1;
        while (an < n)
        {
            if (c % 2)
                an *= 2;
            else
                an *= 9;
            c++;
        }
        if (c % 2)
            cout << "Stan wins.\n";
        else
            cout << "Ollie wins.\n";
    }
}