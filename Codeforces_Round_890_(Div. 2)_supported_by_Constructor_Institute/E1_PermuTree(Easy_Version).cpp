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

//Revise the question entirely when you visit later please so that you can get complete hold of it when you 
//practice it yourself

//THe overall crusk of the problem was clear and what it required the idea and how to do it but some of the dp
//part is maybe still unclear so its better to solve this problem again when you revisit it .

//OVERALL VERY VERY VERY BEAUTIFUL problem it also teached YOU about another problem , which you also solved on
//geeks for geeks to understand the concept although it was a little bit different but still the idea was the same
//so a problem which teached you a lot and the time was worth it but still I hope you revisit it when the conpets of
//dp and stuff are more clear to you and clear any confusion still left to date

//Recursice Dp Version
/*
ll find_pairs_helper(ll i,vector<ll>& v,ll curr_sum,ll& total_sum,vector<vector<ll>>& dp)
{
    if(i == v.size())
        return curr_sum * (total_sum - curr_sum);
    
    if(dp[i][curr_sum] != -1)
        return dp[i][curr_sum];
    
    ll take = find_pairs_helper(i + 1,v,curr_sum + v[i],total_sum,dp);
    ll not_take = find_pairs_helper(i + 1,v,curr_sum,total_sum,dp);
    return dp[i][curr_sum] = max(take,not_take);
}*/

//Video source Doc NITA

ll find_pairs(vector<ll>& v,ll total_sum)
{
    ll n = v.size();
    ll dp[n + 1][total_sum + 1]{};
   
    for(ll i = 0 ; i <= total_sum; ++i)
        dp[n][i] = i  * (total_sum - i);
    
    for(ll i = n - 1; i >= 0; --i){
        for(ll j = 0; j <= total_sum; ++j){
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + v[i]]);
        }
    }
    
    return dp[0][0]; // because you have taken into account all the elements and the you have worked your way from
    //bottom to the top (bottom up dp) and at this point as you have conisdered all the elements that what happens
    //if you take them or not take them, dp[0][0] would represent the case when no elements are considered and the 
    //total sum is zero it may not sound intutive but all the other values have been set up and anyways you are
    //taking max of taking or not taking even when you will reach dp[0][0] so help us find the answer in such a 
    //way that it considers that what would happen when no element is taken it would ask its subproblem i + 1
    //and also what would happen when the last element is considered so this will contain the result of al the 
    //possibilities. so the point where we take no eleemnts and no total sum will be our answer point because we
    //will ask our subproblem that what happened to all the pairs and store it in dp[0][0] variable along with possibility
    //that what happens when you include the last element of the child vector because only considering this when total 
    //sum is zero has not happened before
}

ll dfs(ll node,vector<ll> adj[],ll& ans)
{
    vector<ll> child_vector;
    ll child_cnt = 0;
    
    for(auto e : adj[node]){
        ll e_child = dfs(e,adj,ans);
        child_cnt += e_child;
        child_vector.pb(e_child);
    }
    
    ans += find_pairs(child_vector,child_cnt);
    return child_cnt + 1;
}

void solve()
{
    ll n = 0;
    cin >> n;
    vector<ll> adj[n];
    for(ll i = 0; i < n - 1; ++i){
        ll x;
        cin >> x;
        
        adj[x - 1].pb(i + 1);
    }
    
    ll ans = 0;
    dfs(0,adj,ans);
    cout << ans << nl;
}
    
int main()  
{
  fastIO();
  cout << fixed << setprecision(10);
  int tc = 0; 
  //cin >> tc;
  //while(tc --)
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