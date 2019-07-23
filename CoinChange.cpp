#include <bits/stdc++.h>

using namespace std;

#define inf 123456789

int memo[10000000], Coin;
int m[100000];

int f(int n)
{
	if (n == 0) return 0;
	if (n < 0) return inf;
	int pd = memo[n];
	if(pd != -1) return pd;
	pd = inf;
	
	for (int i = 0; i < Coin; i++)
	{
		pd = min(pd,1+f(n-m[i]));
	}
	return memo[n] = pd; 
}

int main()
{
	int Moeda;
	for (int i = 0; i < 10000000; i++)
	{
		memo[i] = -1;
	}
	scanf("%d",&Coin);
	for (int i = 0; i < Coin; i++)
	{
		cin >> m[i];
	}
	scanf("%d",&Moeda);
	cout << f(Moeda) << endl;
	
}
