#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define clr(x,val)           memset((x),(val),sizeof(x))
int N;
vl ve;
ll dp[(int)3e3][(int)3e3][2];
ll sol(int i, int j, int ok)
{
	if (i > j)
		return 0;
	ll& ret = dp[i][j][ok];
	if (~ret)
		return ret;
	if (ok)
		ret = min(-ve[i] + sol(i + 1, j, !ok), -ve[j] + sol(i, j - 1, !ok));
	else
		ret = max(ve[i] + sol(i + 1, j, !ok), ve[j] + sol(i, j - 1, !ok));
	return ret;
}
void solve()
{
	cin >> N;
	ve = vl(N);
	clr(dp, -1);
	for (auto& it : ve) cin >> it;
	cout << sol(0, N - 1, 0);
}
int main()
{
	solve();
}
