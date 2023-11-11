  #include <bits/stdc++.h>
  #include <iomanip>

  using namespace std;
    
    // Mind blowing observation that how can at at max there be 2 colors the appraoch of stacks was intuitive but
    // the string logic was wow wow and my logic correlated to tha part of it 
    // If reverse of s or simply s is valid then 1 color can achieve it else 2 colors are definitely required
    // the half (len/2) would be opening and half would be closing because sum must be equla to len and diff
    // of them must be 0 , so for first half any opening '(' would be from 1 family and closing ')' would be 2
    // and vice versa for second half inuitively similar to maintaining two stacks and also always there would
    // exsist two colors only because there are 2 combinations for s or either s in reverse frorm
    
  typedef long long ll;
  typedef long double ld;
  typedef unsigned long long ull;
  void fastIO();
  #define mod 998244353
  #define nl '\n'
  #define pb push_back
  #define inf LLONG_MAX
  #define ninf LLONG_MIN
  #define mxn 105
    
   bool valid(string s)
   {
      stack<char> st;
      ll len = s.length();
      
      for(ll i=0;i<len;++i){
        if(s[i] == '(')
          st.push(s[i]);
        else if(s[i] == ')' && !st.empty() && st.top() == '(')
          st.pop();
        else
          return false;
      }
      return st.empty();
   } 
    
  void solve()
  {
      ll len;
      cin >> len;
      
      string s = "";
      ll open=0,close=0;
      
      for(ll i=0;i<len;++i){
        char ch;
        cin >> ch;
        if(ch == ')') close++;
        else open ++;
        s.pb(ch);
      }
      
      if(abs(open-close) != 0){
        cout << "-1\n";
      }
      else{
        string rev = s;
        reverse(rev.begin(),rev.end());
        
        if(valid(s) || valid(rev))
        {
          cout << 1 << nl;
          for(ll i=0;i<len;++i)
            cout << "1 ";
          cout << nl;
        } 
        else{
          cout << 2 << nl;
          for(ll i=0;i<len/2;++i){
            if(s[i] == '(')
              cout << "1 ";
            else
              cout << "2 ";
          }
          
          for(ll i=len/2;i<len;++i){
            if(s[i] == ')')
              cout << "1 ";
            else
              cout << "2 ";
          }
          cout << nl;
        }
      }
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
