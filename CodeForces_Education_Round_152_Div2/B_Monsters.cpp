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
#define yes "YES"
#define no "NO"
    
//INTERESTING LEARNING THINGY : If you want to sort the vectors in ascending order if the first becomes equal
//and you want to sort according to second in ascending order (when first becomes equal) then you can use clever 
//negation approach as chatgpt expalined : "In summary, the second code snippet uses a clever trick by negating the first
//elements of the pairs to achieve the desired sorting order without explicitly defining a comparer function. It's a neat
//optimization to avoid the need for an additional comparer function when sorting pairs ". where when I was not negating
//I had to make a comparer function to achieve the same thing. 

//Apart from that the question required observation that first robos with % k == 0 will die then k - 1 , k - 2 ans so on 
//This was very easy ques and you were not able to solve it during the contest ALAS !!!! maybe due to the observation which
//was required and you were unable to do it.
    
void solve()
{   
    ll n , k;
    cin >> n >> k;
    
    vector<pair<ll,ll>> p;
    for(ll i = 0; i < n; ++i){
        ll e; 
        cin >> e;
        
        e %= k;
        if(e == 0) e = k;
        p.pb({-e,i + 1});
    }
    
    sort(p.begin(),p.end());
   
    for(auto v : p) {
        cout << v.second << ' ';
    }
    cout << nl;
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
