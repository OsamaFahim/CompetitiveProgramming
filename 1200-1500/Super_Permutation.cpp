#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

//You almost thought of the correct pattern but you thought in reverse order and also in such kind of problems you must observe
//the pattern and try to fix some elements out hopefully your brain would be able to solve such problems in the future

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
void fastIO();
template<class T>
void inp(T [],ll);
template<class T>
void print(T [],ll);
#define mod 998244353
#define nl '\n'
#define pb push_back
#define inf LLONG_MAX
#define ninf LLONG_MIN
#define mxn (ll)10010001
#define u_map unordered_map

void solve()
{
    ll n;
    cin >> n;
    
    if(n == 1){
        cout << "1\n";
    }
    else{
        
        if(n & 1){
            cout << "-1\n";
        }
        else{
        
            ll a[n]{};
            
            a[0] = n;
            a[1] = n - 1;
            
            for(ll i=2;i<n;i+=2){
                a[i] = i;
            }
            
            ll put = 1;
            for(ll i = n - 1; i >2; i-=2){
                a[i] = put;
                put += 2;
            }
            
            print(a,n);
        }
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

template<class T>
void inp(T arr[],ll n)
{
    for(ll i = 0; i < n; ++i){
        cin >> arr[i];
    }
}

template<class T>
void print(T arr[],ll n)
{
    for(ll i = 0; i < n; ++i){
        cout << arr[i] << ' ';
    }
    cout << nl;
}
