  #include <bits/stdc++.h>
  #include <iomanip>

  using namespace std;

  //Very very beautiful problem teaching how to analyze the problem and how to observe them using the constraints
  //initially and work your way up to optimization , as this problem had two parts they taught how according to
  //constraints you can make observations which would even help you understand the problem in the most cases
  //Also dont start just graph is written so it is a graph problem as this time it was a series problem ,
  //BEAUTIFUL ONE

  typedef long long ll;
  typedef long double ld;
  typedef unsigned long long ull;
  void fastIO();
  #define mod 998244353
  #define nl '\n'
  #define pb push_back
  #define inf LLONG_MAX
  #define ninf LLONG_MIN
  #define mxn (ll)1e6 + 9
    
  ll pos[mxn]{};  
    
  void solve()
  {
      ll n;
      cin >> n;
      
      ll k = 2;
      while(1){
        ll initial = 1 + k + k*1LL*k;
        ll deep = k*k;
        
        if(initial > n) break;
        
        while(initial <= n){
            pos[initial] = 1;
            deep *= k;
            initial += deep;
        }
        k++;
      }
      
      cout << ((pos[n]) ? "YES\n" : "NO\n"); 
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