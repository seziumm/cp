#ifdef MYDEBUG
  #include "debug.h"
  #define USE_IO()
#else
  #include <bits/stdc++.h>
  #define USE_IO() do { \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout); \
  } while (0)
#endif

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

#define maxve(v) (*std::max_element(all(v)))
#define minve(v) (*std::min_element(all(v)))

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0)

#ifdef MYDEBUG
  #define dbe(...) __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
  #define dbe(...) 
#endif


void find_root(vvi &adj2, int &node) {
  
  if(adj2[node].empty()) return;
  
  node = adj2[node].front();
  find_root(adj2, node);

}


void dfs(vvi &adj, int node, vi &dist, vi &citta, int g[]) {

  if(adj[node].empty()) {
    if(citta[node] == 0) {
      dist[node] = 0;
    }
    else {
      dist[node] = g[node];
    }
    return;
  }

  int cr = 0;

  for(auto child : adj[node]) {
    if(dist[child] == INT_MAX) {
      dfs(adj, child, dist, citta, g);
    }
    cr += dist[child];
    dbe(dist[child], node);

  }

  if(citta[node] > 0) {
    dist[node] = g[node];
    return;
  }
  dist[node] = min(cr, g[node]);
}


int pianifica(int n, int m, int da[], int a[], int c[], int g[]) {

  vi citta(n, 0), dist(n, INT_MAX);

  for(int i = 0; i < m; i++) {
    citta[c[i]]++;
  }

  vvi adj(n);
  vvi adj2(n);

  int root = -1;

  for(int i = 0; i < n - 1; i++) {
    int aa, b;

    aa = da[i];
    b = a[i];

    adj[aa].pb(b);
    adj2[b].pb(aa);

    root = aa;
  }

  find_root(adj2, root);

  dfs(adj, root, dist, citta, g);

  return dist[root];

}

void solve() {
  USE_IO();
  int n;
  cin >> n;

  vpii v(n);

  for(auto &i : v) cin >> i.F >> i.S;

  vi dp(366, 0);

  for(int i = 0; i < n; i++) {
    int end = v[i].S;
    int dur = v[i].F;

    int first = end - dur + 1;
    while(first > 0) {
      dp[end] = max(dp[end], dp[first - 1] + 1);
      first--;
      end--;
    }
  }
  dbe(dp);
  cout << maxve(dp);

}

int main() {
  FAST_IO;

#ifdef MYDEBUG
  std::cerr << ("\033[3J\033[H\033[2J");
  std::cerr << "\033[1;36m[DEBUG]\033[0m \033[1;33mExecution started...\033[0m\n";
  auto start = std::chrono::high_resolution_clock::now();
#endif

  int T = 1;
  // cin >> T;

  while (T--) solve();

#ifdef MYDEBUG
  auto end = std::chrono::high_resolution_clock::now();
  double time_spent = std::chrono::duration<double>(end - start).count();
  std::cerr << "\033[1;32mTIME ELAPSED: \033[1;33m"
            << std::fixed << std::setprecision(3) << time_spent << "s\033[0m\n";
#endif

  return 0;
}
