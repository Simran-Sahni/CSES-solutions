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
#define N 200005
const int INF = (1LL << 62) - 1;
 
int n,q;
vector<int> v(N,0),pre(N);
 
int32_t main()
{
 
 
 
 
  cin >> n >> q;
 
 
 
  for(int i = 1; i <= n; i++)
  {
    cin >> v[i];
  }
 
  for(int i = 1; i <= n; i++)
  {
    pre[i] += pre[i-1] + v[i];
 
  }
 
 
  while(q--)  
  {
    int l,r;
    cin >> l >> r;
    cout << pre[r] - pre[l-1] << endl;
  }
 
 
 
 
 
    return 0;
}
 