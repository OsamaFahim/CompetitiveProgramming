
    #include <bits/stdc++.h>
    #include <iomanip>
    using namespace std;
    typedef long long ll;
    typedef long double ld;
    typedef unsigned long long ull;
    void fastIO();
    template<class T> void inp(T[], ll);
    template<class T> void print(T[], ll);
    #define mod 998244353
    #define nl '\n'
    #define pb push_back
    #define inf LLONG_MAX
    #define ninf LLONG_MIN
    #define mxn (ll)10010001
    #define u_map unordered_map
     
    //This was a very easy and beautiful problem , although i was not able to reach it on my own it's intutition and approach
    //was very simple and basic and it teached me regarding how cheeky observations can be made... Nice one overall
    //How odd even lengths can also have an huge importance while you are thinking about a certain problem
    //You can always make the next two numbers equal to the first number by increasing or decreasing values 
    //according to the absolute difference that they have and after these steps after the last number is greater than second
    //last number then YES else you won't be able to make anything else possible hence NO and that is the case for even
    //lengths (i.e value of n) for odd there is always a way to make the array non decreasing!!
     
    void solve() 
    {
        ll n;
        cin >> n;
        
        ll a[n]{};
        inp(a,n);
        
        if(n & 1)
            cout << "YES\n";
        else{
            for(ll i = 1; i < n - 1; ++i){
                ll diff = a[i - 1] - a[i];
                a[i] += diff;
                a[i + 1] += diff;
            }
            
            if(a[n - 1] >= a[n - 2])
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    int main() {
        fastIO();
        cout << fixed << setprecision(10);
        int tc = 0; 
        cin >> tc;
        while(tc --)
           solve();
    }

    void fastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
    }

    template<class T>
    void inp(T arr[], ll n) {
        for (ll i = 0; i < n; ++i) {
            cin >> arr[i];
        }
    }

    template<class T>
    void print(T arr[], ll n) {
        for (ll i = 0; i < n; ++i) {
            cout << arr[i] << ' ';
        }
        cout << nl;
    }
