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
    
//This is one of those problems whih had very simple implementation but very very nice observation, the original 
//equation given in the way ai - aj >= bi - bj ... that if you take two indices and this conditions satisifies then
//their is an edge between i and j vertices if we observe carefully we can change the equation slightly i.e
//ai - bi >= aj - bj , now we can accomodate for all the edges and vertices in a single linear scan 
// for(ll i = 0; i < n; ++i){ diff.pb({a[i] - b[i], i + 1}); } we are bascially storing the differences in a vector
//because we know that there will be a highest value of diff (a[i] - b[i]) in the vector and as you see that 
//the highest value can form an edge with all of the pairs as its ai - bj value is going to be larger than any other
//combination so it can form an edge with all the vertices , and any other a[i] - b[i] whose value is equal to the maximum
//one can also form an edge with all other vertices so we can put them in a vector and sort them in descending order
//and then print all the vertices whose value is the same from the start as the greatest absolute values are sorted in 
//descending order and this was it the question was very easy but the nice observation was tricky and i was no way 
//closer to that
    
void solve()
{
    ll n;
    cin >> n;
    
    ll a[n]{},b[n]{};
    inp(a, n);
    inp(b, n);

    vector<pair<ll,ll>> diff;
    
    for(ll i = 0; i < n; ++i){
        diff.pb({a[i] - b[i], i + 1});   
    }

    sort(diff.begin(), diff.end(),greater<pair<ll,ll>>());
    
    vector<ll> ans;
    if(diff.size())
        ans.pb(diff[0].second);
    
    for(ll i = 1; i < n; ++i)
        if(diff[i].first == diff[i - 1].first)
            ans.pb(diff[i].second);
        else
            break;
        
    sort(ans.begin(),ans.end());
        
    cout << ans.size() << nl;
    print(ans);
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