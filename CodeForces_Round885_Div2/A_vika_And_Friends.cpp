#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

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
  
/*
if ((abs(x-ax[i]) + abs(y-ay[i])) & 1 ) == 0 THis checks that the either of the friend is present in the same color
this problem also seems to be passing the test cases for this problem so can we conclude that as in chess the same 
colors are diagonal to each other and if any of the friends is at the same color then vika would move to a different color 
and at the same time friend would try to move to the same color reducing the manhatan distance and at sometime the distance 
swould beome zero and vika would get caught , so thats why we check the even odd thing that if manhatan distance is even that
means they are on the same colors and she would get caught else she would not get caught.
Very important takeaway from the problem is that such problems where rid like stucture is there and movemoent to 
neighbours is allowed in such a way that u should avoid gettin caught then chess like structure can be modeleld
chat gpt: In chess, the board is a grid-like structure where each cell has specific relationships with its neighboring cells. Similarly, if your problem
involves movement and relationships between neighboring cells, you can draw inspiration from chess to model the problem.
By assigning different colors or attributes to the cells in a regular pattern, like the alternating black and white squares
on a chessboard, you can create a chess-like coloring or a similar pattern to represent different characteristics or conditions.
chess concept is used because diagonal means more chance of getting caught as one can only move to adjacen cells.
*/  
  
void solve()
{
    ll  n,m,k;
    
    cin >> n >> m >> k;
    
    ll x,y;
    cin >> x >> y;
    
    ll ax[k],ay[k];
    
    for(ll i=0;i<k;++i){
      cin >> ax[i] >> ay[i];
    }
    
    bool caught = false;
    for(ll i=0;i<k;++i){
      if(((abs(x-ax[i]) + abs(y-ay[i])) & 1 ) == 0){
        caught = true;
        cout << "NO\n";
        break;
      }
    }
    
    if(!caught) cout << "YES\n";
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