#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

ll n, m, k;
vvl A;
vvl S;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n >> m;

  A = vvl(n + 1, vl(m + 1));
  for (auto i = 1; i <= n; ++i) {
    for (auto j = 1; j <= m; ++j) {
      cin >> A[i][j];
    }
  }

  S = vvl(n + 1, vl(m + 1, 0));
  for (auto i = 1; i <= n; ++i) {
    for (auto j = 1; j <= m; ++j) {
      S[i][j] += S[i][j - 1] + A[i][j];
    }
  }

  for (auto j = 1; j <= m; ++j) {
    for (auto i = 1; i <= n; ++i) {
      S[i][j] += S[i - 1][j];
    }
  }

  cin >> k;
  while (0 < (k--)) {
    ll t, l, b, r;
    cin >> t >> l >> b >> r;

    --t;
    --l;

    cout << S[b][r] - S[t][r] - S[b][l] + S[t][l] << '\n';
  }

  return 0;
}