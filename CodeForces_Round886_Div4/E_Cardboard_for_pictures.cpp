#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
void fastIO();
template<class T> void inp(T [],ll);
template<class T> void print(T [],ll);
#define mod 998244353
#define nl '\n'
#define pb push_back
#define inf LLONG_MAX
#define ninf LLONG_MIN
#define mxn (ll)10010001
#define u_map unordered_map

//This was a very intuitive and easy problem I didnt even read it during the contest but after getting hint of applying
//the binary search it was very very easy and after understanding the formula (s[i] + mid * 2) you solved it
//but still couldn't figure out why 2 is getting multiplied and the formula required
// --------------------- Note ---------------------
//Please figure out the overflow issues and initialization of low and high values which were causing issue
//when you revisist the problem IMP ............ Please  look into this

void solve()
{
    ull n,c;
    cin >> n >> c;
    
    ll s[n]{};
    inp(s,n);

    __int128 lo = 0, hi = 1e9;
        
    while(lo <= hi){
        __int128 mid = lo + (hi - lo) / 2;
            
         __int128 sum = 0;
        for(ll i = 0; i < n; ++i){
            sum += (s[i] + mid * 2) * (s[i] + mid * 2);
        }
        
        if(sum == c){
          cout << (ll)mid << nl ;
          break;  
        }    
        else if(sum > c)
            hi = mid + 1;
        else
            lo = mid - 1;
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
