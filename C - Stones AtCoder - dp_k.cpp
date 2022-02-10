#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define all(x)                 x.begin(),x.end()
#define clr(x,val)           memset((x),(val),sizeof(x))
int N, K, dp[(int)1e5 + 3][2];
vi ve;
int sol(int rem, int flag)
{
	if (ve[0] > rem)
		return flag;
	int& ret = dp[rem][flag];
	if (~ret)
		return ret;
	ret = flag;
	for (int i = 0; i < N; i++)
	{
		if (!flag)
		{
			if (ve[i] <= rem)
				ret = max(ret, sol(rem - ve[i], !flag));
		}
		else
		{
			if (ve[i] <= rem)
				ret = min(ret, sol(rem - ve[i], !flag));
		}
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
	if (sol(K, 0))	
		cout << "First";
	else
		cout << "Second";
}
int main()
{
		solve();
}
