#include<bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m, x;
    std::cin >> n >> m >> x;
    
    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i].first;
        a[i].second = i;
    }
    
    std::set<std::pair<int, int>> st;
    for (int i = 0; i < m; ++i) {
        st.insert({0, i});
    }
    
    std::sort(a.begin(), a.end());
    
    std::vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        auto [min, tower] = *st.begin();
        st.erase(st.begin());
        st.insert({min + a[i].first, tower});
        ans[a[i].second] = tower + 1;
    }
    
    std::cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(nullptr);
   
   int t;
   std::cin >> t;
   
   while (t--) {
       solve();
   }
   
   return 0;
}