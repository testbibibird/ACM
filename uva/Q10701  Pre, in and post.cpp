#include<iostream>
#include<string>

using namespace std;

string pre,in;
int s_size,f;

void dfs(int l,int r)
{
	if(r<=l)	return;
	
	int i;
	char tmp = pre[f];

	for( i = l ; pre[f]!=in[i] ; ++i);
	
	++f;
	dfs(l,i);
	dfs(i+1,r);

	cout<<tmp;
}

int main()
{
	int case_num;

	cin>>case_num;

	while(case_num--)	
	{
		cin>>s_size>>pre>>in;
		f = 0;

		dfs(0,s_size);
		cout<<endl;
	}
}
