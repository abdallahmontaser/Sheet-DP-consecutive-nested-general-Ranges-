#include<bits/stdc++.h>
using namespace std;
#define clr(x,val)           memset((x),(val),sizeof(x))
int V1, V2, T, D, dp[105][1000];
int sol(int second, int speed)
{
	if (second == T)
		return (abs(speed - V2) > D) * -1e5;
	int& ret = dp[second][speed];
	if (~ret)
		return ret;
	ret = speed + sol(second + 1, speed);
	for (int i = 1; i <= D; i++)
	{
		int tem1 = speed + i;
		int tem2 = max(1, (speed - i));
		ret = max(ret, tem1 + sol(second + 1, tem1));
		ret = max(ret, tem2 + sol(second + 1, tem2));
	}
	return ret;
}
void solve()
{
	cin >> V1 >> V2 >> T >> D;
	if (V1 > V2)
		swap(V1, V2);
	clr(dp, -1);
	cout << sol(2, V1) + V1 + V2;
}
int main()
{
	solve();
}
