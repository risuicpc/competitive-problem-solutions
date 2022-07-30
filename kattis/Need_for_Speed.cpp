#include <bits/stdc++.h>

using namespace std;
int n;
double d[1000], s[1000];
double time(double c)
{
    double t = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] + c <= 0)
        {
            return -1;
        }
        else
        {
            t += d[i] / (s[i] + c);
        }
    }
    return t;
}

int main()
{
    cout << fixed << setprecision(9);
    int t;
    cin >> n >> t;
    for (int i = 0; i < n; i++)
        cin >> d[i] >> s[i];

    double l = -100000100, r = 100000100, m;
    for (int i = 0; i < 400; i++)
    {
        m = (l + r) / 2.0;
        double temp = time(m);
        // cout << m << " " << temp <<  endl;
        if (temp >= 0)
            if (t > temp)
                r = m;
            else
                l = m;
        else
        {
            l = m;
        }
    }
    cout << m << endl;
}