#include<iostream>
#include<string>


using namespace std;

int main()
{

	string a;

	while(cin>>a)
	{
		if(a[0]=='-')	break;

		if(a[0]=='0'&&a[1]=='x'&&a.size()>2)
		{
			int pow=1;
			int result=0;

			for(size_t i=a.size()-1 ; i>1 ; --i)
			{
				if(a[i]>64)
				{
					result+=pow*(a[i]-55);
				}
				else
				{
					result+=pow*(a[i]-'0');	
				//	cout<<result<<endl;
				}
				pow*=16;
			}

			cout<<result<<endl;
		}
		else
		{
			cout<<"0x"<<hex<<atoi(a.c_str())<<endl;
		}
	}
}