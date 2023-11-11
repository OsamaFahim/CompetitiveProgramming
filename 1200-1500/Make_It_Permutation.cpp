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

//This was a easy problem you made bit of a logic correct then you went it io completely wrong and different way after the
//halfway it is that after sorting you have to either include or exclude an element and the formulas for that were quite easy 
//and intuitive that you have to include some elements on the left and delete elements to the right of it and also implemetation
//took time because there was an edge case that you can remove all elemets and add one element i.e (n * c) + d (remove n elements)
//and add one at the end it is possible that this provides the min cost). so that was it for this problem good one and was very
//intuitive indeed

void solve()
{
    ll n,c,d;
    cin >> n >> c >> d;
    
    ll a[n]{};
    ll index = 0;
    ll dup = 0;
    unordered_set<ll> cnt;
    for(ll i = 0; i < n; ++i){
        ll no;
        cin >> no;
        if(!cnt.count(no)){
            a[index++] = no;
            cnt.insert(no);
        }
        else
            dup ++;
    }
    
    ll m = n;
    n = index;
    sort(a,a + n);
    
    ll cost = inf ;
    for(ll  i = n -1 ; i >= 0; --i){
       ll left_cost = (a[i] - i  - 1) * d;
       ll right_cost = (n - 1 - i) * c;
       cost = min(cost,left_cost + right_cost);
    }
    
    cost += dup * c;
    cost = min(cost,m * c + d);
    cout << cost << nl;
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
