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
template<typename T1, typename T2> ostream& operator<<(ostream& os, const pair<T1, T2>& p);
#define nl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define inf LLONG_MAX
#define ninf LLONG_MIN
#define yes "YES"
#define no "NO"  
#define mod 998244353     

//This was actually C of the contest lol as C was 1000 rated and it was 1500 .  
    
//This was a fun problem during one of your lucky div 2 contests where you Allah Almighty helped you solve
//the second problem for the first time...

//The main missing part in your logic was that you said that if i am on i i can check whether removing
//this seller will be costly or not the thinking was correct but the way you were trying to approach this
//thinking was not leading you anywhere, you were thinking that you would see that whether removing this
//would decrease the cookies eaten or not , but this can't be determined or I was not able to determine it correctly 
//and intuitively as for different test cases my point always failed to prove so what you can do is
//imagine on ith seller you can always subtract (s[i + 1] - s[i] - 1) / k cookies eaten from right of i
// and (s[i] - s[i - 1] - 1) / k , cookies eaten from left of i  and then + 1 i.e left + right + 1 these 
//represent the cookies eaten when i was present and when we remove i , clearly then it will be 
//(s[i + 1] - s[i] - 1 )/ k (you were only trying to work with this and not thought about the left and right
//cookies eaten idea which is nice) but the point is that after removing this seller the cookies eaten
//should be lesser when it was not included i.e 
//(s[i + 1] - s[i] - 1 )/ k  < ((s[i + 1] - s[i] - 1) + (s[i] - s[i - 1] - 1) / k) + 1 , and this was the 
//entire point of the logic that you were missing although it was a pretty fun problem
    
    /*
         ll remove = 0;
    for(ll i = 1; i < m; ++i){
        ll removal_diff = (s[i + 1] - 1 - s[i - 1]) / d;
        ll half_one = (s[i] - 1 - s[i - 1]) / d;
        ll half_second = (s[i + 1] - 1 - s[i]) / d;
        
         // + 1 is added as we are removing the current seller and also the indices where he can eat
         // as we are removing the ith seller that it the ith seller is inclusive that is why we 
         // +1 to.
        if(removal_diff < (half_one + half_second + 1)){ //focus on the this as this think you didn't
            remove ++;                                   //exactly in this way
        }
    }
    
    this is the logic that you were missing from line 87 - 98
    
    */
    
void solve()
{   
    ll n , m , d;
    cin >> n >> m >> d;
    
    vector<ll> s;
    for(ll i = 0; i < m; ++i){
        ll a;
        cin >> a;
        if(i == 0 && a != 1)
            s.pb(1);
        
        s.pb(a);
    }
    
    ll prev_m = m;
    m = s.size();
    ll cnt = 1;
    for(ll i = 1; i < m; ++i){
        cnt += ((s[i] - 1 - s[i - 1]) / d) + 1;
    }
    cnt += (n - s[m - 1]) / d; //This line destroyed my brain heavily
    // cnt += (n - 1 - s[m - 1]) / d; -1 is not done here in the statement just above because we are also 
    //accomodating the nth bench if we do -1 that would mean that we are not conisdering the last nth bench
    //that is why test cases were being failed to pass after test case 1 
    
    s.pb(n + 1); // n + plus because n is included in the benches so to accomodate tha last nth bench as 
                 //well we use n + 1
    ll remove = 0;
    for(ll i = 1; i < m; ++i){
        ll removal_diff = (s[i + 1] - 1 - s[i - 1]) / d;
        ll half_one = (s[i] - 1 - s[i - 1]) / d;
        ll half_second = (s[i + 1] - 1 - s[i]) / d;
        
         // + 1 is added as we are removing the current seller and also the indices where he can eat
         // as we are removing the ith seller that it the ith seller is inclusive that is why we 
         // +1 to.
        if(removal_diff < (half_one + half_second + 1)){ //focus on the this as this think you didn't
            remove ++;                                   //exactly in this way
        }
    }
    
    cnt -= remove != 0;
    if(remove == 0)
        remove = prev_m;
    
    cout << cnt << ' ' << remove << nl;
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

template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    os << p.first << ' ' << p.second << nl;
    return os;
}