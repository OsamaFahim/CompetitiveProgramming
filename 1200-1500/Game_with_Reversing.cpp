#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
void fastIO();
#define mod 998244353
#define nl '\n'
#define pb push_back
#define inf LLONG_MAX
#define ninf LLONG_MIN
#define mxn (ll)105
   
void solve()
{
    ll n;
    cin >> n;
    
    string s1,s2;
    cin >> s1 >> s2;
    
    if(s1 == s2){
        cout << 0 << nl;
    }
    else{
        ll cnt = 0 , ans = 0;
        for(ll i=0;i<n;++i){
            if(s1[i] != s2[i])
                cnt++;
        }
        
        if((cnt & 1) == 0){
            ans = 2 * cnt;
        }
        else{
            ans = 2 * cnt - 1;
        }
        
        string rev_s2 = s2;
        reverse(rev_s2.begin(),rev_s2.end());
        
        cnt = 0;
        
        for(ll i=0;i<n;++i){
            if(s1[i] != rev_s2[i])
                cnt ++;
        }
        
        
        if(cnt==0){
            ans = min(ans,2*1LL);
        }
        else if((cnt & 1) != 0){
            ans = min(ans,2*cnt);
        }
        else{
            ans = min(ans,2*cnt-1);
        }
        
        cout << ans << nl;
    }
}
        
int main()
{
  fastIO();
  cout << fixed << setprecision(10);
  int tc = 0; 
  cin >> tc;
  while(tc --)
  solve();
}
        
void fastIO()   
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
}