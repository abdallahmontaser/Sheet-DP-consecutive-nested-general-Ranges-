#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define clr(x,val)           memset((x),(val),sizeof(x))
int A, N, M, L, R, x, p, ans, dp[(int)2e3 + 2][(int)2e3 + 2];
vi umbrella(2e3 + 2), raining(2e3 + 2);
int sol(int i, int j)
{
	if (i == A)
		return 0;
	int& ret = dp[i][j + 1];
	if (~ret)
		return ret;
	ret = 1e9;
	if (j != -1 || !raining[i])
		ret = umbrella[j] + sol(i + 1, j);            // continue with current umbrella
	if (!raining[i])
		ret = min(ret, sol(i + 1, -1));              // throw it
	if (umbrella[i])
		ret = min(ret, sol(i + 1, i) + umbrella[i]);   // pick one if available
	return ret;
}
void solve()
{
	cin >> A >> N >> M;
	clr(dp, -1);
	for (int i = 0; i < N; i++)
	{
		cin >> L >> R;
		for (; L < R; L++)
			raining[L] = true;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> x >> p;
		umbrella[x] = (umbrella[x] == 0 ? p : min(umbrella[x], p));
	}
	ans = sol(0, -1);
	if (ans >= 1e9)
		ans = -1;
	cout << ans;
}
int main()
{
	solve();
}
