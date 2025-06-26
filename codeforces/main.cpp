#ifdef MYDEBUG
#include "debug.h"
#define USE_IO()
#define dbe(...) __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#include <bits/stdc++.h>
#define dbe(...) 
#define USE_IO() do { \
  freopen("input.txt", "r", stdin); \
  freopen("output.txt", "w", stdout); \
} while (0)
#endif

#define F     first
#define S     second

using namespace std;

typedef long long ll;
#define ve vector

typedef ve<bool>    vb;
typedef ve<int>     vi;
typedef ve<ll>      vll;
typedef ve<string>  vs;

typedef ve<vb>      vvb;
typedef ve<vi>      vvi;
typedef ve<vll>     vvll;
typedef ve<vs>      vvs;

typedef pair<bool, bool>       pbb;
typedef pair<bool, int>        pbi;
typedef pair<bool, ll>         pbll;
typedef pair<bool, string>     pbs;

typedef pair<int, bool>        pib;
typedef pair<int, int>         pii;
typedef pair<int, ll>          pill;
typedef pair<int, string>      pis;

typedef pair<ll, bool>         pllb;
typedef pair<ll, int>          plli;
typedef pair<ll, ll>           pll;
typedef pair<ll, string>       plls;

typedef pair<string, bool>     psb;
typedef pair<string, int>      psi;
typedef pair<string, ll>       psll;
typedef pair<string, string>   pss;

typedef ve<pbb>    vpbb;
typedef ve<pbi>    vpbi;
typedef ve<pbll>   vpbll;
typedef ve<pbs>    vpbs;

typedef ve<pib>    vpib;
typedef ve<pii>    vpii;
typedef ve<pill>   vpill;
typedef ve<pis>    vpis;

typedef ve<pllb>   vpllb;
typedef ve<plli>   vplli;
typedef ve<pll>    vpll;
typedef ve<plls>   vplls;

typedef ve<psb>    vpsb;
typedef ve<psi>    vpsi;
typedef ve<psll>   vpsll;
typedef ve<pss>    vpss;

typedef ve<vpbb>   vvpbb;
typedef ve<vpbi>   vvpbi;
typedef ve<vpbll>  vvpbll;
typedef ve<vpbs>   vvpbs;

typedef ve<vpib>   vvpib;
typedef ve<vpii>   vvpii;
typedef ve<vpill>  vvpill;
typedef ve<vpis>   vvpiss;

typedef ve<vpllb>  vvpllb;
typedef ve<vplli>  vvplli;
typedef ve<vpll>   vvpll;
typedef ve<vplls>  vvplls;

typedef ve<vpsb>   vvpsb;
typedef ve<vpsi>   vvpsi;
typedef ve<vpsll>  vvpsll;
typedef ve<vpss>   vvpss;

#define pb    push_back
#define ppb   pop_back
#define ppf   pop_front
#define pf    push_front
#define sz(a) int((a).size())

#define mk    make_pair
#define F     first
#define S     second
#define MOD   1000000007

#define all(v)    (v).begin(),  (v).end()
#define rall(v)   (v).rbegin(), (v).rend()

#define maxve(v) (*std::max_element(all(v))
#define minve(v) (*std::min_element(all(v))

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0)


void solve(int ntc) {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> a(n, vector<int> (m));
  int mx = 0, cnt_mx = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] > mx) {
        mx = a[i][j], cnt_mx = 1;
      } else if (a[i][j] == mx) {
        cnt_mx++;
      }
    }
  }
  vector<int> r(n), c(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == mx) {
        r[i]++;
        c[j]++;
      }
    }
  }
  int flag = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (r[i] + c[j] - (a[i][j] == mx) == cnt_mx) {
        flag = 1;
      }
    }
  }
  cout << mx - flag;
}

int main() {
  FAST_IO;

#ifdef MYDEBUG
  std::cerr << ("\033[3J\033[H\033[2J");
  std::cerr << "\033[1;36m[DEBUG]\033[0m \033[1;33mExecution started...\033[0m\n";
  auto start = std::chrono::high_resolution_clock::now();
#endif

  int T = 1;
  cin >> T;

  for(int t = 1; t <= T; t++) {
    solve(t);
    cout << endl;
  }

#ifdef MYDEBUG
  auto end = std::chrono::high_resolution_clock::now();
  double time_spent = std::chrono::duration<double>(end - start).count();
  std::cerr << "\033[1;32mTIME ELAPSED: \033[1;33m"
    << std::fixed << std::setprecision(3) << time_spent << "s\033[0m\n";
#endif

  return 0;
}
