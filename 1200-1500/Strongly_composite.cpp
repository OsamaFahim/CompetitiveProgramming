#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

//I liked this question a lot it used conept for prime factorization !!! In this question the main crusk was knowing that
//multiplying two same prime numbers are always going to give you a strongly composite numbers and two different prime numbers
//will give you a composite number but not strongly composite numbers so once you get a composite number you multiply the 
//it with another prime number you get a strongly composite number i.e multiplying three distinct prime numbers 
//and also that multiplying a prime number with a composite number always gives you a strongly composite number which is similar
//to the point mentioned above and with these points we can simply compute prime factors of all the values or the product
//and maintain their frequency using a hashmap and we can make strongly composite numbers out of the pairs which are twice
//for eg 2 -> 4 and 3 -> 2 and 5 -> 6 we can for each of them i.e 2 3 5 do their respective counts/2 as it would tell us that
//how many strongly composite numbers can be formed using prime numbers of same type as 2 same prime numbers always gives strongly
//composite numbers and remaing would be their counts % 2 (counts & 1) and we can make an extra variable if these three distinct
//primes are there, we can make another composite number and thats it. the remaining can't be used to make more prime numbers unless they
//are not divisible by three the remaining would be left as they are i.e extra % 3 cant be used  

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
   
   ll a[n];
   inp(a,n);
   
   unordered_map<ll,ll> freq;
   for(ll i = 0; i < n; ++i){
     ll val = a[i];
        for(ll j = 2; j * j <= val; ++j){
            while(val % j == 0){
                val /= j;
                ++freq[j];
            }
            
            if(val == 1) break;
        }
        
        if(val > 1) ++freq[val];
   }
   
   ll ans = 0;
   ll extra = 0;
   for(auto it : freq){
    ans += it.second / 2;
    extra += it.second & 1; //the distinct prime numbers which can't form a pair are added to extra variable
   }
   
   ans += extra / 3;  //and as we need three distinct prime numbers to make stronglt composite number as two distinct primes
                      //gives us a composite number (not strongly) and multiplying a prime number by a composite number
                      //gives strongly composite number as mentioned above in the notes 
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
