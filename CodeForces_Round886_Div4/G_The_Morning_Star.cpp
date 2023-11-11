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

//it taught me amazingness man wondeful wondeful wondeful !!! how goood is it man
        
//This was a very interesting problem the problem statement was a bit tricky but it's solution was very nice, the main
//observations were : firstly there were four lines and we can break our problem into four independent problems ,
//we observed that for a straight vertical line x reamins constant and y changes only, for horizontal line y remains
//constant and x changes only, for a line from sw to ne we saw that if there is a point x1,y1 then the point just after
//this will be x1+1,y1+1,after that x1+2,y1+2 so even if there is a point after d distance i.e x1+d,y1+d the difference
//between them will be y1-x1 among lots all of the points on that line so if we found the distance to y1-x1 (y-x as below)
//it means we are on (sw to ne) line and same is the case with line from (nw to se) but in this case we notice that
//if their is a point x1,y1 then the point just after this will be x1+1,y1-1 , after that x1+2,y1-2 which means that if
//there is a line after distance d that x1 + d,y1 - d then the sum between them for this line will remain the same
//that x1 + y1 will be same for all the points on this line and the case with vertical and horizontal as described above
//that x will be constant for vertical and y will be for horizonal so if we found an x which we already founded it 
//mens that we are on vertical line as for vertical line x remains constant and if we found an y which we already founded it 
//mens that we are on horizonal line as for horizontal line y remains constant 

//read below eplanations too to clear specific conepts that why 4 maps required and why * 2 is done at every step if
//point is found   
        
void solve()
{  
    ll n;
    cin >> n;
    
    map <ll , ll> sw_ne,nw_se,ns,we;    //4 maps are required for 4 different lines and 1 map wont be enough because
    ll ans = 0;                         //it is possible that airthmetic result that x,x+y,y-x or y is same but the point
    for(ll i = 0; i < n; ++i){          //belongs to specific line and we count it more times or less times so we can make
        ll x,y;                         //different map for different line the , if it was one map it would just just airthmetic
        cin >> x >> y;                  //results and that could definitely lead to error not knowing to which line this
                                        //point belongs to as we dont know which line it belongs to and how many points
                                        //behind this line thats why diff map for each line.
                                        
    //there can be some intersections between the lines that we will check whether the points belong to any of the four lines
    //or not that is why we are doing if for all and not if else
        
    //basically we are finding all the points associated with the current line independently   
        
        if(sw_ne.count(y - x))
            ans += sw_ne[y - x] * 2;    //mutiplication by 2 is done because if a cordinate point x1,y1 can pair up
        if(nw_se.count(x + y))          //with x2,y2 then x2,y2 can also pair up with x1,y1 so at each step we are
            ans += nw_se[x + y] * 2;    //accomodating for both of the points meaning that if point xk,yk is found
        if(ns.count(x))                 //and there are k points behind x,y behind the current xk,yk point, so this 
            ans += ns[x] * 2;           //point can pair up with all the k points behind it that is why for each point
        if(we.count(y))                 //found now i have to accomodate it will all the previous points that is why 
            ans += we[y] * 2;           //we have maintained the count of points of each line and after finding a point
                                        //lets say there were 3 points behind it so now it can pair up with those 3 points
                                        //so count is 3, so this 4th point can now pair up with the three previous 
                                        //points found till not but the *2 is done because all the previous k points can now
                                        //pair up with the new 4th point find now so to accomodate them as well we are 
                                        //multiplying them by 2 as these 3 points can form pair up with the 4th point found
                                        //so 3 * 2 = 6 as we needed to tell the pairs for which compass wont break.
                                        
    //then we are updating frequiencies of points in all of the four lines according to some conditions 
    //then we are increasing the cnt in our respective lines
        
        sw_ne[y - x]++;
        nw_se[x + y]++;
        ns[x]++;
        we[y]++;
    }
    
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