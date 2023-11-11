#include<bits/stdc++.h>

using namespace std;

/* O(n^3) brute force, unoptimized solution
 int countSubstrings(string s) {
    int ans = 0;
	int len = s.length();
	
	for(int i = 0 ; i < len; ++i)
		for(int j = i; j < len; ++j){
			bool palindrome = true;
			for(int x = i , z = j; x < z; ++x,--z)
				if(s[x] != s[z]){
					palindrome = false;
					break;
				}
				
			if(palindrome)
				ans++;
		}
	
	
	return ans;
 }
*/

//O(n^2) optimized approach
int countSubstrings(string s){
	int ans = 0;
	int len = s.length();
	
	//For oddd length sub strings
	for(int i = 0;i < len; ++i){
		int l = i , r = i;
		while(l >= 0 && r < len){
			if(s[l] == s[r]){
				ans++;
				++r;
				--l;
			}
			else
				break;
		}
	}
	
	//For even length sub strings
	for(int i = 0;i < len; ++i){
		int l = i , r = i + 1;
		while(l >= 0 && r < len){
			if(s[l] == s[r]){
				ans++;
				++r;
				--l;
			}
			else
				break;
		}
	}
	
	return ans;
}

int main(){
	cout << countSubstrings("abc") << '\n';
}