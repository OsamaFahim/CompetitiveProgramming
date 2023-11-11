  #include <bits/stdc++.h>
  #include <iomanip>

  using namespace std;

  //This problem was not that difficult but ot required beautiful observation of the fact that you can group algorithms
  //into the number of smaller divisors which n can have if its smallest divisor is greater than m then then we cant partition
  //the algorithms equally and thus infinity would never happen and we would print YES and vice versa.

  typedef long long ll;
  typedef long double ld;
  typedef unsigned long long ull;
  void fastIO();
  #define mod 998244353
  #define nl '\n'
  #define pb push_back
  #define inf LLONG_MAX
  #define ninf LLONG_MIN
  #define mxn (ll)10010001
    
  void solve(vector<ll>& Prime)
  {
      ll n,m;
      
      cin >> n >> m;
      
      if(n == 1 || m == 1){
        cout << "YES\n";
      }
      else{
        if(Prime[n] > m){
          cout << "YES\n";
        }
        else
          cout << "NO\n";
      }
  }  
            
  int main()
  {
    fastIO();
    cout << fixed << setprecision(10);
    int tc = 0; 
    cin >> tc;
    
    vector<ll> Prime(mxn,0);  
    Prime[1] = 1;
    
    for(ll i=2;i<=mxn;++i){
      if(Prime[i] == 0){
        Prime[i] = i;
        for(ll j = i*i;j<=mxn;j+=i){
          if(Prime[j] == 0)
             Prime[j] = i;
        }
      }
    }
    
    while(tc --)
      solve(Prime);
  }
            
  void fastIO()   
  {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
  }