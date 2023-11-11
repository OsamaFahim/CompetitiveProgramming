#include <bits/stdc++.h>
#include <iomanip>

//This was the logic given by me however it gave TLE .

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define mod 998244353

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

ll numDigits[7] = {1,10,100,1000,10000,100000,1000000} ;

void solve(int tc = 0)
{
	while(tc--){
		ll a , b ,c, k ;
		cin >> a >> b >> c >> k;
		
		 if(c - max(a,b) > 1 || c - max(a,b) < 0 ||
           (numDigits[a] - 1) * (numDigits[b] - 1) < k)
           cout << "-1\n" ;
        else{
            ll start_a = 0 , start_b = 0;
            if(c - max(a,b) == 1){
                if(a > b)
                    start_a = numDigits[a] - 1 , start_b = numDigits[b - 1];
                else if(a < b)
                    start_b = numDigits[b] - 1 , start_a = numDigits[a - 1];
                else if(a == b)
                    start_a = numDigits[a - 1]  , start_b = numDigits[b] - start_a;
            }
            else{
                start_a = numDigits[a - 1];
                start_b = numDigits[b - 1];
            }
            
            
            ll k_cntr = 0 , temp_b = start_b,  res = 0 ;
            bool brk = false;
            while(start_a < numDigits[a]){
                temp_b = start_b;
                res = start_a + temp_b;
                while(temp_b < numDigits[b] && res < numDigits[c]){
                    k_cntr++;
                    if(k_cntr == k){
                        brk = true;
                        break;
                    }
                    temp_b ++;
                    res = start_a + temp_b;
                }
                if(brk) break;
                start_a ++;
                if(temp_b == numDigits[b]) start_b --;
            }	
			
		   cout << start_a << " + " << temp_b << " = " << res << '\n'; 
	    }
    }  
}

int main()
{
    fastIO();	
	int tc = 0;
	cin >> tc;
	solve(tc);
}