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
 
 
int st[N][25];
 
vector<int> log_table(N+1,0);
 
 
void build(vector<int> &v)
{
  for(int i = 2; i <= N; i++)
  {
    log_table[i] = log_table[i/2] + 1;
  }
 
  for(int i = 1; i <= v.size(); i++)
  {
    st[i][0] = v[i];
  }
 
  for(int j = 1; j <= 24; j++)
  {
    for(int i = 1; i + (1 << j) <= v.size(); i++)
    {
      st[i][j] = min(st[i][j-1],st[i + (1 << (j-1))][j-1]);
    }
  }
 
}
 
int query(int l,int r)
{
  int k = log_table[r-l];
 
  return min(st[l][k],st[r-(1<<k) + 1][k]);
}
 
 
 
int32_t main()
{
 
 
int n,q;
  cin >> n >> q;
 
  vector<int> v(n+1);
 
  for(int i = 1; i <= n; i++)
  {
    cin >> v[i];
  }
 
  build(v);
 
  while(q--)  
  {
    int l,r;
    cin >> l >> r;
 
    cout << query(l,r) << endl;
  }
 
 
 
 
 
    return 0;
}
 