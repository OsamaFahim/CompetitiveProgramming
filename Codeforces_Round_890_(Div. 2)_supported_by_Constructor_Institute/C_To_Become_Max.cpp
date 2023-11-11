#include <bits/stdc++.h>    
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
void fastIO();
template<class T> void inp(T [],ll);
template<class T> void print(T [],ll);
template<class T> void inp(vector<T>&);
template<class T> void print(vector<T>&);
#define mod 998244353
#define nl '\n'
#define pb push_back
#define inf LLONG_MAX
#define ninf LLONG_MIN
#define yes "YES" 
#define no "NO"       

//Was not a difficult problem but there were few good observations that one had to make and the rest of the solution
//and binary searching was very very intuitive , I was very sad at this point that I should have thought about this
//and reached to this solution one way or another as the solution was very very nice and intuitive and when you
//want to revise this problem see cpwithcpp to revise at this point everything is clear as the approach explained
//by him is very nice 

//https://www.youtube.com/watch?v=zCfVs8GrVus&t=1083s --> link to get perfect explanation

//invariance tencique can alos be learned where one is always considered to be true and other false (lo , hi)
//was easy question should have given more thought for me not that intuitive as i have not solved problems
//this way but later InshAllah i will try to think about the problems in such a way

//Also very lo value of n was a hint that the solution can be done in n^2 so we could just do
//O(n ^ 2 * log(1e15)) which would also be working for provided that constraints for n are very less strict
void solve()
{   
    ll n,k;
    cin >> n >> k;
    ll a[n]{};
    inp(a, n);
    
    ll maxi = ninf;
    for(ll i = 0; i < n; ++i) maxi = max(maxi, a[i]);
        
    ll lo = maxi, hi = 1e15;
    ll ans = maxi;
    
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        
        auto check = [&]() -> bool {
            for(ll i = 0; i < n; ++i){
                ll need = mid;
                ll oprs = 0;
                
                for(ll j = i; j < n; ++j){
                    ll required = need - a[j];
                    if(required < 1){
                        if(oprs <= k)
                            return 1;
                        else
                            break;
                    }
                    oprs += required;
                    --need;
                    need = max(need,1LL);
                }
            }    
            return 0;       
        };
        
        if(check()){
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    
    cout << ans << nl;
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

template<class T>
void inp(vector<T>& arr)
{
    for(auto &e : arr)
         cin >> e;
}

template<class T>
void print(vector<T>& arr)
{
    for(auto &e : arr)
        cout << e << ' ';
    cout << nl;
}