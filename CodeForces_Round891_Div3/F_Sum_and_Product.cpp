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
#define pb push_back
#define inf LLONG_MAX
#define ninf LLONG_MIN
#define yes "YES"
#define no "NO"  
#define mod 998244353     

//It was quite an awesome problem my mind was blown when i Saw that it used the simple concept of quadratic equations
//and took them to another level , just beautiful simply amazing

//as we are simply two numbers x and y where x = a + b and y = a * b
// (a + b)^2 = a^2 + b^2 + 2 * a * b
//  x^2 = a^2 + b^2 + 2 * y

// (a - b)^2 = a^2 + b^2 - 2* a * b
// (a - b)^2 = a^2 + b^2 - 2 * y

// (a - b)^2 = x^2 - 2 * y - 2 * y
// (a - b)^2 = x^2 - 4 * y
// sqrtl((a - b)^2) = sqrtl(x^2 - 4 * y)
// a - b = root(x^2 - 4 * y)

// now i know the value of a + b (given in ques as x) and a - b and i can find a + b + (a - b) which is equal
//2a and (2a)/2 = a as i found a i can find b by putting in any of the equations and after that my answer would
//simply be freq[a] * freq[b]
//now there is a case where if a == b then consider that array is 1 1 1 1 , now for 1st one it can piar with
//3 other ones and for second one it can piar with 2 other ones and so on so for n = 5 it will be 4 + 3 + 2 + 1
//because i have to be < j i.e  i < j  so for each duplicate element it will have choices to pair with as shown in the
//example and as we know that 4 + 3 + 2 + 1 == (n*(n - 1)) / 2 .So, if a==b then ans = (n*(n - 1)) / 2. 
//else ans = f[a] * f[b]

//few more conds in between were that (x^2 - 4 * y) this value of a - b , must be >= 0 otherwise we will hae complex
//roots after taking underoot and the value of underoot must be a perfect one and not floating one because of the 
//fact that if a - b = root(x^2 - 4 * y) , if a - b gives integer then aroot(x^2 - 4 * y) must also give an integer

//this was it and it was wondeful problem ... FOR SUCH PROBLEMS WHERE EQAUTIONS ARE GIVEN TRY TO MANIPULATE THEM
//AND THEN THE ANSWER WOULD BECOME QUITE SIMPLE.


void solve()
{
   ll n;
   cin >> n;
   ll a[n]{};
   inp(a, n);
   
   map<ll,ll> freq;
   for(ll i = 0; i < n; ++i){
        ++freq[a[i]];
   }
   
   ll q;
   cin >> q;
   while(q --){
      ll x , y;
      cin >> x >> y;
      
      ll eq = x * x - 4 * y;
      if(eq < 0){
        cout << 0 << ' ';
      }
      else{
        ll sqaure_rt = sqrtl(eq);
        
        if(sqaure_rt * sqaure_rt  != eq){
            cout << 0 << ' ';
        }
        else{
            ll a = (x + sqaure_rt) / 2 ;
            ll b = a - sqaure_rt; // also can be b = x - a as x is given to be x = a + b
            
            ll ans = 0;
            if(a == b){
                if(freq.count(a))
                    ans = (freq[a] * (freq[a] - 1)) / 2;
            }
            else{
                if(freq.count(a) && freq.count(b))
                    ans = freq[a] * freq[b];
            }
            
            cout << ans << ' ';
        }
      }
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
    os << p.first << ' ' << p.second;
    return os;
}