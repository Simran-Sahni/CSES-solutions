#include <bits/stdc++.h>
using namespace std;
  #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #define endl "\n"
  #define all(v) v.begin(),v.end()
#define int long long 
  #define double long double
  #define trace1(x)                cerr<<#x<<": "<<x<<endl
  #define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
  #define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
  #define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
  #define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<< ": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
  #define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
  #define cases int testcases;cin>>testcases; while(testcases--)
const int mod = 1000000007;
const double PI = 3.1415926535898;
#define N 1005
const int INF = (1LL << 62) - 1;
 
int dp[N][N];
 
int arr[N][N];
int n,q;
 
int32_t main()
{
 
 
  cin >> n >> q;
  for(int i = 1; i <= n; i++)
  {
    for(int j = 1; j <= n; j++)
    {
      char ch;
      cin >> ch;
      if(ch == '*')arr[i][j] = 1;
      else arr[i][j] = 0;
    }
  }
 
  dp[1][1] = arr[1][1];
 
  for(int i = 2; i <= n; i++)
  {
    dp[1][i] = dp[1][i-1] + (arr[1][i] == 1);
    dp[i][1] = dp[i-1][1] + (arr[i][1] == 1);
  }
 
 
 
 
  for(int i = 2; i <= n; i++)
  {
    for(int j = 2; j <= n; j++)
    {
      dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + (arr[i][j] == 1);
    }
  }
 
 
 
 
 
  while(q--)
  {
    int x1,x2,y1,y2;
    cin >> y1 >> x1 >> y2 >> x2;
    swap(x1,y1);
    swap(x2,y2);
 
    cout << dp[x2][y2] -dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1] << endl;
  }
 
 
 
 
 
    return 0;
}
 