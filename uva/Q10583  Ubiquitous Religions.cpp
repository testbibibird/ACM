#include<iostream>

using namespace std;

int arr[50001],group,m,n,tmp,tmp2;

void uni(int x,int y)
{
	if(arr[x]==arr[y])	return;

	group--;

	int amax=max(arr[x],arr[y]);
	int amin=min(arr[x],arr[y]);

	for(int i = 1 ; i <= n ; ++i )
	{
		if(arr[i]==amin)
		{
			arr[i]=amax;
		}
	}
}

int main()
{
	int count=1;

	while(cin>>n>>m)
	{
		if(n==0&&m==0)	break;
		
		group=n;

		for(int i = 0 ; i <= n ; ++i )
		{
			arr[i]=i;
		}

		for(int i = 0 ; i < m ; ++i )
		{
			cin>>tmp>>tmp2;

			uni(tmp,tmp2);
		}

		cout<<"Case "<<count++<<": "<<group<<endl;
	}

}