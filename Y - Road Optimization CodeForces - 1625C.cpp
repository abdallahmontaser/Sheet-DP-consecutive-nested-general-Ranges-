#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define all(x)                 x.begin(),x.end()
#define clr(x,val)           memset((x),(val),sizeof(x))
void fast()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
}
int N, L, K;
vl d, ve;
ll dp[505][505];
ll sol(int i, int rem)
{
	if (i == N)
		return 0;
	ll& ret = dp[i][rem];
	if (~ret)
		return ret;
	ret = 1e18;
	for (int j = i + 1; j <= N; j++)
	{
		if (rem + ((j -i) 1)) > K)
			break;
		ret = min(ret, ((d[j] - d[i]) * ve[i]) + sol(j, rem + (j - (i + 1))));
	}
	return ret;
}
void solve()
{
	cin >> N >> L >> K;
	d = ve = vl(N + 1);
	clr(dp, -1);
	for (int i = 0; i < N; i++) cin >> d[i];
	for (int i = 0; i < N; i++) cin >> ve[i];
	d[N] = L;
	cout << sol(0, 0);
}
int main()
{
	solve();
}
