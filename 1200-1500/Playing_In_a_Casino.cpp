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

//Importand learning propert : If you are computing absolute differences between to pairs abs(a[i] - a[j]) where a is
//array if n integers the order wont matter meaning you can change the order and still get the same aboslute difference
//between the values that were originally in let's say Set S !!! (fasicnating right ? ) , so if orders doesnt matter
//we can just sort the array and it wont have impact on the result but in this way we know that a[i] is smaller than 
//a[i + 1] and we can compute the sum after a[i]  (from a[i + 1] to a[n] , 1 based indexing) and we can count how
//many times a[i] would be subtracted and that would literally be the n - i as the elements after ith index.

//Final Winner points wont change because scenario is based on absolute difference and absolute difference is 
//commutative i.e abs(a-b) == abs(b-a)

//LEARNING OBSERVATION : for these question , whevever WHENEVER ORDER DOESN'T MATTER simply SORT the array BECAUSE
//in sorted arrays differentt techniques and stuff are efficient to apply (and also can be very easy)

void solve()
{
    ll n , m;
    cin >> n >> m;
    
    ll a[n][m]{};
    
    for(ll i = 0; i < n; ++i){
        for(ll j = 0; j < m; ++j)
            cin >> a[i][j];
    }   
    
    ll ans = 0;
    for(ll i = 0; i < m; ++i){
        vector<ll> v;
        for(ll j = 0; j < n; ++j){
            v.pb(a[j][i]);
        }
        sort(v.begin(),v.end());  //Sorting, beacuse we will then know that how many times a[i] needs to be sutracted from
                                  //the bigger elements and as all the elemts on right of a[i] will be larger and it will
                                  //will be subtracted from all the elements that is why we are multiplying from num 
                                  //elements i.e (n - i). and this is what we want we need to know how many times the 
                                  //the greater elements will be subtracted from a[i] and the values can be founded using 
                                  //precomputation of the sum (prefix concept).
        
        ll sum = 0;
        for(auto e : v) sum += e; //precomputing the sum for entire array and deleting after using each of the elemnt  
                                  //because we don't need the previous sum after each point
                                
        for(ll i = 0; i < n - 1; ++i){
            sum -= v[i]; //This part is necessary beacuse I need to consider the sum after that specific index                     //
                       //meaining if I am on index i and dont need sum of values from 0 to i - 1 i.e (a[0] .. a[i -1])
                  //so that is why we are subtracting that from the sum after we have calculated the ans for ith index
            
            ans += sum - (v[i] * (n - i - 1));               
        }               
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
