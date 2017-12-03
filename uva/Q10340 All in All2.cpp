#include<iostream>
#include<string>

using namespace std;

int main()
{
	string a,b;
	int count;

	while(cin>>a>>b)
	{
		char c[1000];

		int i,j,k;

		for(i=0,j=0,k=0;i<a.size()&&j<b.size();++i)
		{
			for(;j<b.size();++j)
			{
				if(a[i]==b[j])
				{
					c[k]=a[i];

					++k;
				
					break;
				}
			}
		}
		

		c[k]='\0';

		cout<<c<<endl;

		if(strcmp(c,a.c_str())==0)
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
}
