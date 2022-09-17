
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
vector<int> P, N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    char op = '+';
    int n, c = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '?')
            c++;
        else if (s[i] != '*')
        {
            if (op == '+')
                P.push_back(c);
            else
                N.push_back(c);
            op = s[i];
            c = 0;
        }
    }
    if (op == '+')
        P.push_back(c);
    else
        N.push_back(c);
    sort(P.begin(), P.end());
    sort(N.rbegin(), N.rend());
    int n0, n1, n2;
    cin >> n0 >> n1 >> n2;

    ll an = 0;
    for (auto i : N)
    {
        if (n0 < 0)
        {
            n1 += n0;
            n0 = 0;
        }
        else if (n1 < 0)
        {
            n2 += n1;
            an -= (1 << (-n1));
            n1 = 0;
        }

        if (n0 > 0)
            n0 -= i;
        else if (n1 > 0)
        {
            if (n1 >= i)
                an -= 1;
            n1 -= i;
        }

        else
        {
            an -= (1 << i);
            n2 -= i;
        }
    }
    for (auto i : P)
    {
        if (n0 < 0)
        {
            n1 += n0;
            n0 = 0;
        }
        else if (n1 < 0)
        {
            n2 += n1;
            an += (1 << (-n1));
            n1 = 0;
        }
        if (n0 > 0)
            n0 -= i;
        else if (n1 > 0)
        {
            if (n1 >= i)
                an += 1;
            n1 -= i;
        }

        else
        {
            an += (1 << i);
            n2 -= i;
        }
    }
    cout << an << "\n";
}