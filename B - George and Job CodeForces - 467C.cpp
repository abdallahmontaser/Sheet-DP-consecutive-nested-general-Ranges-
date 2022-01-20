#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define clr(x,val)           memset((x),(val),sizeof(x))
int N, M, K;
ll dp[(int)5e3 + 3][(int)5e3 + 3];
vl ve;
ll sol(int i, int rem)
{
	if (i > N)
		return ((rem != 0) * -1e15);
	ll& ret = dp[i][rem];
	if (~ret)
		return ret;
	ret = sol(i + 1, rem);
	if (i + (M - 1) <= N)
		ret = max(ret, (ve[i + (M - 1)] - ve[i - 1]) + sol(i + M, rem - 1));
	return ret;
}
void solve()
{
	cin >> N >> M >> K;
	ve = vl(N + 5, 0);
	clr(dp, -1);
	for (int i = 1; i <= N; i++) cin >> ve[i], ve[i] += ve[i - 1];
	cout << sol(1, K);
}
int main()
{
	solve();
}
