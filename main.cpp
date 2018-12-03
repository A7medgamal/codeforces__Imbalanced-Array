/* In the function trace max we calculate sum of maximum of all subarrays by segment tree to avoid time limit the time will nlog(n)
and so in the function trace min*/
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef bitset<15>mask;
#define F first
#define S second
ll n,m,x,y,z,k,sol,sum,ans,l,r,xx,yy,a[1000000],b[1000000],max_arr[1000000],min_arr[1000000];
vector<ll>v1;
vector<ll>v2;
ll trace__max(ll no=1,ll l=1,ll r=n)
{
    if(l==r) return a[l];
    ll mid=(l+r)/2;
 ll   sum=0,ans=0,x=0;
    for(int i=mid+1;i<=r;i++)
    {
       x=max(x,a[i]);
        max_arr[i]=x;
        sum+=max_arr[i];
    }
    ll idx=mid+1,mixum=0;
    for(int i=mid;i>=l;i--)
    {
        mixum=max(a[i],mixum);
        while(idx<=r&&mixum>=max_arr[idx])
        {
            sum-=max_arr[idx];
            idx++;
        }
        ans+=sum+(idx-mid-1)*mixum;
    }
    return ans+trace__max(2*no,l,mid)+trace__max(2*no+1,mid+1,r);
}
ll trace__min(ll no=1,ll l=1,ll r=n)
{
    if(l==r) return a[l];
    ll mid=(l+r)/2;
  ll  sum=0,ans=0,x=1e13;
    for(int i=mid+1;i<=r;i++)
    {
        x=min(x,a[i]);
        min_arr[i]=x;
        sum+=min_arr[i];
    }
    ll idx=mid+1,minum=1e17;
    for(int i=mid;i>=l;i--)
    {
        minum=min(a[i],minum);
        while(idx<=r&&minum<min_arr[idx])
        {
            sum-=min_arr[idx];
            idx++;
        }
        ans+=sum+(idx-mid-1)*minum;
    }
    return ans+trace__min(2*no,l,mid)+trace__min(2*no+1,mid+1,r);
}

int main()
{
//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
      cout<<trace__max()-trace__min()<<endl;


    return 0;
}
