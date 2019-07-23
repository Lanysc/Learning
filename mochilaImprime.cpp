#include <bits/stdc++.h>

using namespace std;

#define inf 123456789

int memo[10000][10000], n = 3;
int p[3] = {10,20,30};
int v[3] = {60,100,120};

int bag(int i, int disp)
{
	if (i == n || disp == 0) return 0;
	int &pd = memo[i][disp];
	if (pd != -1) return pd;
	if (p[i] > disp)
		return pd = bag(i+1,disp);
	return pd = max(bag(i+1,disp),v[i] + bag(i+1,disp - p[i]));
}

void rec(int j, int disp)
{
	if(j == n || disp == 0)
		return;
	if(p[j] > disp)
		return rec(j+1,disp);
	int pd = memo[j][disp];
	if (pd == bag(j+1,disp))
		return rec(j+1,disp);
	cout << j << endl;
	rec(j + 1, disp - p[j]);
}

int main()
{
	memset(memo,-1,sizeof memo);
	int peso;
	scanf("%d",&peso);
	rec(0,peso);
	cout << bag(0,peso) << endl;
	
}
