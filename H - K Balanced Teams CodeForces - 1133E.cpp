#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define all(x)                 x.begin(),x.end()
#define clr(x,val)           memset((x),(val),sizeof(x))
void fast()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
}
int N, K, dp[(int)5e3 + 5][(int)5e3 + 5];
vi ve;
int sol(int i, int teams)
{
	if (i == N)
		return 0;
	int& ret = dp[i][teams];
	if (~ret)
		return ret;
	ret = sol(i + 1, teams);
	if (teams)
	{
		int tem = upper_bound(all(ve), ve[i] + 5) - ve.begin();
		ret = max(ret, (tem - i) + sol(tem, teams - 1));
	}
	return ret;

}
void solve()
{
	cin >> N >> K;
	ve = vi(N);
	clr(dp, -1);
	for (auto& it : ve) cin >> it;
	sort(all(ve));
	cout << sol(0, K);
}
int main()
{
	solve();
}
