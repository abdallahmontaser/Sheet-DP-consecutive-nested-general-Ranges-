#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define clr(x,val)           memset((x),(val),sizeof(x))
int N;
vl ve;
ll dp[401][401];
ll get_sum(int l, int r)
{
	return ve[r] - ve[l - 1];
}
ll sol(int i, int j)
{
	if (i == j)
		return 0;
	if (j - i == 1)
		return get_sum(i,j);
	ll& ret = dp[i][j];
	if (~ret)
		return ret;
	ret = 1e18;
	for (int x = i; x < j; x++)
		ret = min(ret, get_sum(i, j) + sol(i, x) + sol(x + 1, j));
	return ret;
}
void solve()
{
	cin >> N;
	ve = vl(N + 3);
	clr(dp, -1);
	for (int i = 1; i <= N; i++)
		cin >> ve[i], ve[i] += ve[i - 1];
	cout << sol(1, N);
}
int main()
{
		solve();
}
