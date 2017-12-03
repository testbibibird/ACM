#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n,groupnum,p;
	string a;

	while(cin>>groupnum)
	{
		if(groupnum==0)	break;

		cin>>a;

		n = a.size() / groupnum;
		p = n;

		for(int i = 0 ; i < groupnum ; ++i , p += n )
		{
			for(int j = 1 ; j <= n ; ++j )
			{
				cout<<a[p-j];
			}
		}
		cout<<endl;
	}
}