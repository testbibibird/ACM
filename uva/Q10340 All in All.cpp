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

		int i,j;

		for(i=0,j=0;i<a.size()&&j<b.size();++j)
		{
			if(a[i]==b[j])
			{
					//c[k]=a[i];
				++i;	
			}

		}
		if(i<a.size())
		{
			cout<<"No"<<endl;
		}
		else
		{
			cout<<"Yes"<<endl;
		}

		/*c[k]='\0';

		cout<<c<<endl;

		if(strcmp(c,a.c_str())==0)
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}*/
	}
}
