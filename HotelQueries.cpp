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
const int INF = (1LL << 62) - 1;
const int N = 200005;
 
int n,m;
 
vector<int> h(N),r(N);
vector<int> segmnt(4*N);
 
void build(int curr,int ss,int se,vector<int> &v)
{
 
  if(ss == se)
  {
    segmnt[curr] = v[se];
  }
  else
  {
    int left = 2*curr, right = 2*curr+1,mid = ss + (se-ss)/2;
    build(left,ss,mid,v);
    build(right,mid+1,se,v);
    segmnt[curr] = max(segmnt[left],segmnt[right]);
  }
}
 
int query(int curr,int ss,int se,int l,int r)
{
  if(l > r or l > se or r < ss)return 0;
  if(ss >= l and se <= r)return segmnt[curr];
  int left = 2*curr, right = 2*curr+1,mid = ss + (se-ss)/2;
  int leftanswer = query(left,ss,mid,l,min(r,mid));
  int rightanswer = query(right,mid+1,se,max(l,mid+1),r);
  return max(leftanswer,rightanswer);
}
 
void update(int curr,int ss,int se,int pos,int new_value)
{
  if(ss == se)
  {
    segmnt[curr] = new_value;
  }
  else
  {
    int left = 2*curr, right = 2*curr+1,mid = ss + (se-ss)/2;
    if(pos <= mid)update(left,ss,mid,pos,new_value);
    else update(right,mid+1,se,pos,new_value);
    segmnt[curr] = max(segmnt[left],segmnt[right]);
  }
}
 
int binarysearch(int x)
{
  int low = 1;
  int high = n;
 
  while(low <= high)
  {
    int mid = low + (high-low)/2;
    if(query(1,1,n,1,mid) >= x)
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
 
  return low;
}
 
int32_t main()
{
 
 
 
 
  cin >> n >> m;
 
  for(int i = 1; i <= n; i++)
  {
    cin >> h[i];
  }
 
  for(int i = 1; i <= m; i++)
  {
    cin >> r[i];
  }
 
  build(1,1,n,h);
 
 
  for(int i = 1; i <= m; i++)
  {
    int idx = binarysearch(r[i]);
    if(idx == n+1)idx = 0;
    cout << idx << " ";
    if(idx == 0)continue;
    int val = query(1,1,n,idx,idx);
    int new_val = val - r[i];
    update(1,1,n,idx,new_val);
  }
 
    return 0;
}
 