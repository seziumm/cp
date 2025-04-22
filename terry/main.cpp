#ifdef MYDEBUG
#include "debug.h"
#define INC_MYDEBUG
#else
#include <bits/stdc++.h>
#endif

using namespace std;

namespace __DEBUG_UTIL__ { 

  void print(const char *x) { cerr << x; }
  void print(bool x) { cerr << x; }
  void print(char x) { cerr << '\'' << x << '\''; }
  void print(signed short int x) { cerr << x; }
  void print(unsigned short int x) { cerr << x; }
  void print(signed int x) { cerr << x; }
  void print(unsigned int x) { cerr << x; }
  void print(signed long int x) { cerr << x; }
  void print(unsigned long int x) { cerr << x; }
  void print(signed long long int x) { cerr << x; }
  void print(unsigned long long int x) { cerr << x; }
  void print(float x) { cerr << x; }
  void print(double x) { cerr << x; }
  void print(long double x) { cerr << x; }
  void print(string x) { cerr << '\"' << x << '\"'; }

  template <size_t N> void print(bitset<N> x) { cerr << x; }
  void print(vector<bool> &v) { /* Overloaded this because stl optimizes
                                   vector<bool> by using _Bit_reference instead of
                                   bool to conserve space. */
    int f = 0;
    cerr << '{';
    for (auto &&i : v)
      cerr << (f++ ? "," : "") << i;
    cerr << "}";
  }
  /* Templates Declarations to support nested datatypes */

  template <typename T> void print(T &&x);

  template <typename T> void print(vector<vector<T>> &mat);

  template <typename T, size_t N, size_t M> void print(T (&mat)[N][M]);

  template <typename F, typename S> void print(pair<F, S> x);

  template <typename... T> void print(priority_queue<T...> pq);

  template <typename T> void print(stack<T> st);

  template <typename T> void print(queue<T> q);

  /* Template Datatypes Definitions */

  template <typename T> void print(T &&x) {
    /*  This works for every container that supports range-based loop
        i.e. vector, set, map, oset, omap, dequeue */
    int f = 0;
    cerr << '{';
    for (auto &&i : x)
      cerr << (f++ ? "," : ""), print(i);
    cerr << "}";
  }
  template <typename T> void print(vector<vector<T>> &mat) {
    int f = 0;
    cerr << "\n~~~~~\n";
    for (auto &&i : mat) {
      cerr << setw(2) << left << f++, print(i), cerr << "\n";
    }
    cerr << "~~~~~\n";
  }
  template <typename T, size_t N, size_t M> void print(T (&mat)[N][M]) {
    int f = 0;
    cerr << "\n~~~~~\n";
    for (auto &&i : mat) {
      cerr << setw(2) << left << f++, print(i), cerr << "\n";
    }
    cerr << "~~~~~\n";
  }
  template <typename F, typename S> void print(pair<F, S> x) {
    cerr << '(';
    print(x.first);
    cerr << ',';
    print(x.second);
    cerr << ')';
  }
  template <typename... T> void print(priority_queue<T...> pq) {
    int f = 0;
    cerr << '{';
    while (!pq.empty())
      cerr << (f++ ? "," : ""), print(pq.top()), pq.pop();
    cerr << "}";
  }
  template <typename T> void print(stack<T> st) {
    int f = 0;
    cerr << '{';
    while (!st.empty()) {
      cerr << (f++ ? "," : ""), print(st.top()), st.pop();
    }
    cerr << "}";
  }
  template <typename T> void print(queue<T> q) {
    int f = 0;
    cerr << '{';
    while (!q.empty())
      cerr << (f++ ? "," : ""), print(q.front()), q.pop();
    cerr << "}";
  }
  /* Printer functions */
  void printer(const char *) {} /* Base Recursive */
  template <typename T, typename... V>
    void printer(const char *names, T &&head, V &&...tail) {
      /* Using && to capture both lvalues and rvalues */
      int i = 0;
      for (size_t bracket = 0;
          names[i] != '\0' and (names[i] != ',' or bracket != 0); i++)
        if (names[i] == '(' or names[i] == '<' or names[i] == '{')
          bracket++;
        else if (names[i] == ')' or names[i] == '>' or names[i] == '}')
          bracket--;
      cerr.write(names, i) << " = ";
      print(head);
      if (sizeof...(tail))
        cerr << " |", printer(names + i + 1, tail...);
      else
        cerr << "\n";
    }
} // namespace __DEBUG_UTIL__

typedef long long ll;

typedef vector<bool>   vb;
typedef vector<int>    vi;
typedef vector<ll>     vll;
typedef vector<string> vs;

typedef vector<vb>     vvb;
typedef vector<vi>     vvi;
typedef vector<vll>    vvll;
typedef vector<vs>     vvs;

typedef pair<int, int> pii;
typedef pair<ll, ll>   pll;

typedef vector<pii> vpii;
typedef vector<pll> vpll;


#define ve  vector
#define pb  push_back
#define ppb pop_back
#define ppf pop_front
#define pf  push_front
#define sz(a) int((a).size())

#define mk  make_pair
#define F   first
#define S   second
#define MOD 1000000007

#define  all(v) (v).begin(),  (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define maxve(v) (*std::max_element(v))
#define minve(v) (*std::min_element(v))

#define FAST_IO ios::sync_with_stdio(0)


bool palindrome(string &s) {
  for (int i = 0; i < (int)s.size() / 2; i++) {
    if (s[i] != s[s.size() - i - 1]) {
      return 0;
    }
  }

  return 1;
}

bool isPrime(int n) {
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

inline void yn(bool x) { cout << (x ? "YES" : "NO"); }

long long fast_pow(long long b, long long e) {
  if(e == 1) return b;
  if(e == 0) return 1;

  long long bb = fast_pow(b, e / 2);

  if(e % 2 == 0) {
    return (bb % MOD) * (bb % MOD) % MOD;
  }

  return ((bb % MOD) * (bb % MOD) % MOD) * (b % MOD) % MOD;
}


void xor_bit(long long &x, long long i)   { x ^= 1<<i; }
void set_bit_0(long long &x, long long i) { x &= 1<<i; }
bool check_bit(long long x, long long i)  { return (x&(1<<i)); }
bool ispow2(long long x)           { return x > 0 && (x & (x - 1)) == 0; }


#ifdef MYDEBUG
#define dbe(...) __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbe(...) 
#endif


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


