#include<bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::string s;
    std::cin >> n >> m >> s;
    
    std::vector<std::vector<i64>> a(n, std::vector<i64>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> a[i][j];
        }
    }
    
    std::vector<i64> row_sums(n);
    for (int i = 0; i < n; ++i) {
        i64 sum = 0;
        for (int j = 0; j < m; ++j) {
            sum += a[i][j];
        }
        row_sums[i] = sum;
    }
    
    std::vector<i64> col_sums(m);
    for (int j = 0; j < m; ++j) {
        i64 sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i][j];
        }
        col_sums[j] = sum;
    }
    
    for (int k = 0, i = 0, j = 0; k < s.length(); ++k) {
        if (s[k] == 'D') {
            a[i][j] = -row_sums[i];
            row_sums[i] += a[i][j];
            col_sums[j] += a[i][j];
            ++i;
        } else {
            a[i][j] = -col_sums[j];
            col_sums[j] += a[i][j];
            row_sums[i] += a[i][j];
            ++j;
        }     
    }
    
    a[n - 1][m - 1] = -row_sums[n - 1];
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << a[i][j] << " \n"[j == m - 1];
        }
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