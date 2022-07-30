#include <bits/stdc++.h>
using namespace std;
#define size 2e5 + 5
typedef long long ll;

int n, m, k;

int main()
{
   cin >> n >> m >> k;
   vector<ll> a(n), b(m);

   for (int i = 0; i < n; i++)
      cin >> a[i];
   sort(a.begin(), a.end());

   for (int i = 0; i < m; i++)
      cin >> b[i];
   sort(b.begin(), b.end());

   int ans = 0, i = 0, j = 0;
   while (i < n && j < m)
   {
      if (abs(a[i] - b[j]) <= k)
      {
         i++;
         j++;
         ans++;
      }
      else if (a[i] > b[j])
         j++;
      else
         i++;
   }

   cout << ans << "\n";
}
