#include <bits/stdc++.h>
#include <iomanip>

//THis is the optimized logic for the code

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

ll power[7] = {1,10,100,1000,10000,100000,1000000} ;

void solve(int tc=0)
{
	while(tc--){
		int a,b,c ;
		ll k;
		cin >> a >> b >> c  >> k;
		
		bool good = false; 
		
		for(int i = power[a - 1] ; i < power[a]; ++i){
			int left = max(power[b - 1],power[c - 1] - i);	// and also as a + b = c so here we are checing by b = c - a i.e c - i in this way
			int right = min(power[b] - 1,power[c] - 1 - i);
			//a is subtracted so that if the range is valid we get the values which specifies the constraint that b remains B digit and a + b is c digits
			
			if(left <= right){	//meaning we have got valid range of equation for b where a + b = c
				ll have = right - left + 1; //because right most value is inclusive
				if(k <= have){
					cout << i << " + " << (left + k -1) << " = " << i + ( left + k - 1) << '\n';
					good = true;
					break;
				}
				k -= have;
			}
		}
		
		if(!good) cout << "-1" << '\n';
	}
}

int main()
{
    fastIO();	
	int tc = 0;
	cin >> tc;
	solve(tc);
}