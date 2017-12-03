#include<iostream>
#include<string>

using namespace std;

string pre,in;
int f;

void dfs(int l,int r)
{
	if(r<=l)	return;

	int i;
	char tmp = pre[f];

	for( i = 0 ; tmp != in[i] ; ++i );

	++f;
	dfs(l,i);
	dfs(i+1,r);

	cout<<tmp;

}

int main()
{
	while(cin>>pre>>in)
	{
		dfs(0,pre.size());
		f=0;
		cout<<endl;
	}
}
