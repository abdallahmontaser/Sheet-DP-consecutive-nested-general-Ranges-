#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define clr(x,val)           memset((x),(val),sizeof(x))
int N, K, X, ans = 0, dp[505][5005];
vi  level;
int sol(int i, int rem)
{
	if (i == 0)
		return 0;
	int& ret = dp[i][rem];
	if (~ret)
		return ret;
	ret = 0;
	for (int x = 1; x <= K; x++)
		if (rem >= x)
			ret = max(ret, sol(i - 1, rem - x) + level[x]);
	return ret;
}
void solve()
{
	cin >> N >> K;
	map<int, int>freq_favorite, freq_Cards;
	level = vi(K + 1);
	clr(dp, -1);
	for (int i = 0; i < N * K; i++)
		cin >> X, freq_Cards[X]++;
	for (int i = 0; i < N; i++)
		cin >> X, freq_favorite[X]++;
	for (int i = 1; i <= K; i++)
		cin >> level[i];
	for (auto& it : freq_favorite)
		ans += sol(it.second, freq_Cards[it.first]);
	cout << ans;
}
int main()
{
	solve();
}
