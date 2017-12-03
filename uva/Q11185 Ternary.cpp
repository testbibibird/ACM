#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n,carry;

	while(cin>>n)
	{
		string result;

		if(n<0) break;

		int i;

		if(n==0)
		{
			cout<<0;
		}
		else
		{
			for(i=0;n>0;++i)
			{
				result.push_back(n%3);

				n/=3;
			}

			for(int j=i-1;j>=0;--j)
			{
				cout<<static_cast<int>(result[j]);
			}
		}
		cout<<endl;
		

	}
}
