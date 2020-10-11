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
 
 
vector<int> segmnt(4*N);
      int n;
 
void build(int curr,int ss,int se,vector<int>&v)
{
  if(ss == se)
  {
    segmnt[curr] = v[se];
  }
  else
  {
    int left = 2*curr,right = 2*curr+1,mid = ss + (se-ss)/2;
    build(left,ss,mid,v);
    build(right,mid+1,se,v);
    segmnt[curr] = segmnt[left] + segmnt[right];
  }
}
void update(int curr,int ss,int se,int pos, int new_val)
{ 
  if(pos > n or pos < 1)return;
  if(ss == se)
  {
    segmnt[curr] = new_val;
  }
  else
  {
    int left = 2*curr,right = 2*curr+1,mid = ss + (se-ss)/2;
    if(pos <= mid)update(left,ss,mid,pos,new_val);
    else update(right,mid+1,se,pos,new_val);
    segmnt[curr] = segmnt[left] + segmnt[right];
  }
}
 
int query(int curr,int ss,int se,int l,int r)
{
 
  if(l > r or l > se or r < ss)return 0;
  if(ss >= l and se <= r)return segmnt[curr];
  int left = 2*curr,right = 2*curr+1,mid = ss + (se-ss)/2;
  int leftanswer = query(left,ss,mid,l,min(mid,r));
  int rightanswer = query(right,mid+1,se,max(l,mid+1),r);
  return leftanswer + rightanswer;
}
 
int binarysearch(int x)
{
  int low = 1, high = n;
 
  while(low <= high)
  {
    int mid = low + (high-low)/2;
 
    int y = query(1,1,n,1,mid);
 
    if(y == x)
      {
        if(mid == 1 or query(1,1,n,1,mid-1) < y)return mid;
        else high = mid-1;
      }
 
    else if(y < x)low = mid + 1;
    else high = mid - 1;
  }
 
  return low;
 
}
 
int32_t main()
{
 
 
 
 
      cin >> n;
 
      vector<int> v(n+1,1);
      v[0] = 0;
 
      vector<int> arr(n+1),q(n+1);
 
 
      for(int i = 1; i <= n; i++)cin >> arr[i];
 
      for(int i = 1; i <= n; i++)cin >> q[i];
 
 
 
        build(1,1,n,v);
      // cout << query(1,1,n,1,5) << endl;
 
      // update(1,1,n,3,0);
      // cout << query(1,1,n,1,5) << endl;
      for(int i = 1; i <= n; i++)
      {
        int idx = binarysearch(q[i]);
        cout << arr[idx] << " ";
        update(1,1,n,idx,0);
      }
 
 
 
 
 
 
 
 
 
    return 0;
}