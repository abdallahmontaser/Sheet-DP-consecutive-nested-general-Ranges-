#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define clr(x,val)           memset((x),(val),sizeof(x))
int N, M, K, X, Y;
ll dp[(int)2e3 + 2];
vl ve, save;
int get_sum(int l, int r)
{
	return ve[r] - ve[l - 1];
}
ll sol(int i)
{
	if (i == K + 1)
		return 0;
	ll& ret = dp[i];
	if (~ret)
		return ret;
	ret = 1e15;
	for (int j = 1; j <= (K + 1) - i; j++)
		ret = min(ret, get_sum(i + save[j], (i + j) - 1) + sol(i + j));
	return ret;
}
void solve()
{
	cin >> N >> M >> K;
	ve = save = vl(N + 1);
	clr(dp, -1);
	for (int i = 1; i <= N; i++)
		cin >> ve[i];
	for (int i = 0; i < M; i++)
		cin >> X >> Y, save[X] = max(save[X], (ll)Y);
	sort(ve.begin() + 1, ve.end());
	for (int i = 1; i <= N; i++)
		ve[i] += ve[i - 1];
	cout << sol(1);
}
int main()
{
	solve();
}
