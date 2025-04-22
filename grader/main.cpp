#include <climits>
#include <queue>
#include <unordered_map>
#ifdef MYDEBUG
#include "debug.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

typedef long long           ll;

typedef std::vector<bool>   vb;
typedef std::vector<int>    vi;
typedef std::vector<ll>     vll;
typedef std::vector<string> vs;

typedef std::vector<vb>     vvb;
typedef std::vector<vi>     vvi;
typedef std::vector<vll>    vvll;
typedef std::vector<vs>     vvs;

typedef std::pair<int, int> pii;
typedef std::pair<ll, ll>   pll;

typedef std::vector<pii> vpii;
typedef std::vector<pll> vpll;

typedef std::vector<vpii> vvpii;
typedef std::vector<vpll> vvpll;

#define ve    vector
#define pb    push_back
#define ppb   pop_back
#define ppf   pop_front
#define pf    push_front
#define sz(a) int((a).size())

#define mk    make_pair
#define F     first
#define S     second

const ll MOD = 1e9 + 7;

#define  all(v)  (v).begin(),  (v).end()
#define rall(v)  (v).rbegin(), (v).rend()

#define maxve(v) (*std::max_element(v))
#define minve(v) (*std::min_element(v))

#define FAST_IO  ios::sync_with_stdio(0)

#ifdef MYDEBUG
#define dbe(...) __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbe(...) 
#endif


//"L'elemento A deve precedere l'elemento B?". In pratica:
//"a deve precedere B". In pratica:
//
//Se restituisce true, allora gli elementi rimangono nell'ordine dato.
//Se restituisce false, gli elementi potrebbero essere scambiati.































/*
int fpow(int b, int e) {
  if(e <= 1) return e;

  int tmp = fpow(b, e / 2);

  tmp *= tmp;

  if(e % 2 == 1) tmp *= b;

  return tmp;
}

*/


/*
ll fpow(ll b, ll e) {
  if(e == 0) return 1;
  if(e == 1) return b;

  ll tmp = fpow(b, e / 2);

  tmp = ((tmp % MOD) * (tmp % MOD)) % MOD;

  if(e % 2 == 1) tmp = ((tmp % MOD) * (b % MOD)) % MOD;

  return tmp;
}
*/

map<pair<int, int>, int> m;

int find(int l, int r, int K, int S[]) {

  if(l > r) return 0;
  if(K < 0) return 0;

  if(m.count(mk(l, r))) return m[mk(l, r)];

  int a = find(l + 1, r, K - S[l], S);
  int b = find(l, r - 1, K - S[r], S);

  if(S[l]) a++;
  if(S[r]) b++;
  
  m[mk(l, r)] = max(a, b);

  return m[mk(l, r)];
   
}

int solve(int N, int K, int *S) {

  return find(0, N - 1, K, S);

}



#ifdef MYDEBUG

void tc() {
}

void _main() {
  int T = 1;
  // cin >> T;

  for(int t = 1; t <= T; t++) {
    tc();
    cout << endl;
  }

}












int main() {
  FAST_IO;

#ifdef MYDEBUG
  std::cerr << ("\033[3J\033[H\033[2J");  // Clear everything
  std::cerr << "\033[1;36m[DEBUG MODE]\033[0m \033[1;34m"
    << "\033[1;33mExecution started...\033[0m\n";
  auto start = std::chrono::high_resolution_clock::now();
#endif

  _main();

#ifdef MYDEBUG
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  double time_spent = duration.count() / 1000000.0;

  // Output più colorato e leggibile
  std::cerr << "\n\033[1;32m----------------------------------------\033[0m\n";
  std::cerr << "\033[1;32mTIME ELAPSED: \033[1;33m \033[1;35m" 
    << std::fixed << std::setprecision(3) << time_spent 
    << "s\033[0m\n";
  std::cerr << "\033[1;32m----------------------------------------\033[0m\n";
#endif

  return 0;
}



#endif
