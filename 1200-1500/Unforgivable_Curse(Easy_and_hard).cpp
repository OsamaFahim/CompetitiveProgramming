#include <bits/stdc++.h>    
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
        
//Maan what a beautiful problem dammmm!! it was very very good and its intuition and thought process was simple yet so 
//beautiful and dificult to come up wih (imo) at the same time. This problem taught me a lot and blowed my mind phuffff
//the only thing was to figure out that can you somehow swap the adjacent characters or not and if you can you can swap
//any character you want as we do in bubble sort by using a sort of a temporary variable as consider the example below
//         i-k   i   i+1  if i  use one of the place as a swapping variable i can swap two adjacent variables easiy
// step 1: s[i]    s[i-k]  s[i+1]
// step 2: s[i+1]  s[i-k]  s[i]
// step 3: s[i-k]  s[i+1]  s[i]
//so we can clearly see that we can swap two adjacent characters with the help of a variable which is before k-1 steps 
//or this would have been even possible if the variable was present after ith index that after i + k or i + k + 1 indexes
//so if i can swap adjacent character then it is somehow always possible that i can swap the characters and place 
//desired character in its place but one codition is necessary that there must be k characters present behind i (iterating
//index) or k characters are present after i , i.e (i - k >= 0 || k + i < n) ---> one of these conditions must be 
//satisfied for that purpose i have used the condition that if both of them are false means that there is no way for us
//to use a swapping variable as we must use a swapping variable whose |i -j| = k or k + 1 , so if k characters are not 
//present before or after ith index then we cannot swap the character and we print no at that point simply
//that if s[i] != t[i] we wanna swap, so we check if(s[i] != t[i] && (i - k < 0 && i + k >= n)) and if it becomes true
//meaning no variable with absolute difference k si we print no and break out
        
void solve()
{  
    ll n , k;
    cin >> n >> k;
    
    string s,t;
    cin >> s >> t;
    vector<ll> cnt(26,0);
    
    for(ll i = 0; i < n; ++i){
        cnt[s[i] - 'a'] ++;
    }
    
    for(ll i = 0; i < n; ++i){
        cnt[t[i] - 'a'] --;
    }
    
    for(auto e : cnt){
        if(e != 0){
            cout << no << nl;
            return;
        }
    }
    
    bool ans = true;
    for(ll i = 0; i < n; ++i){
        if(s[i] != t[i] && (i - k < 0 && i + k >= n)){ //because if i + k >= n then there is no way we can reach 
            ans = false;                                                                             //i + k + 1
            cout << no << nl;
            break;
        }
    }
    
    if(ans)
        cout << yes << nl;
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