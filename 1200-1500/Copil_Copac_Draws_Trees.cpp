  #include <bits/stdc++.h>
  #include <iomanip>

  using namespace std;

  //This question explained to me how can i traverse the nodes when the specific order is mentioned and i have to retreverse the 
  //data again and again and 3 sec doesnt simply means n^2 will get an AC , check constraints fully and also
  //such questions where you have to retraverse the tree again and again you can create adjancancey list and call dfs on it
  //as you checked that if index is lower in the deeper node that means that another reading had to be done so you incremented
  //it using a cheeky boolean technique and it was a good and very easy question, I understand that you were not able to do
  //it because you haven't observed such patterns till now so you know what you have to do practice more and more.

  typedef long long ll;
  typedef long double ld;
  typedef unsigned long long ull;
  void fastIO();
  #define mod 998244353
  #define nl '\n'
  #define pb push_back
  #define inf LLONG_MAX
  #define ninf LLONG_MIN
  #define mxn (ll)105
  ll ans;

  void dfs(ll node,ll prev,ll node_index,ll reading,vector<pair<ll,ll>> adj[])
  {
    ans = max(ans,reading);
    
    for(auto it : adj[node]){
      if(it.first != prev){
        dfs(it.first, node,it.second,reading + (it.second < node_index), adj);
      }
    }
  }    
      
  void solve()
  {
      ll n;
      cin >> n;
      
      vector<pair<ll,ll>> adj[n + 1];
      
      for(ll i=0;i<n-1;++i){
        ll p,q;
        cin >> p >> q;
        
        adj[p].pb({q,i});
        adj[q].pb({p,i});
      }
      ans = 0;
      dfs(1,-1,n,0,adj);
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