#include<iostream>
#include<string>

using namespace std;

int main()
{
	string a;
	int rs,pow;

	while(cin>>a)
	{
		if(a=="0")	break;

		if( a.size()==31 )
		{	
			cout<<"2147483647"<<endl;
			continue;
		}

		if( a.size()==30 && a[0] =='2' )	
		{
			cout<<"2147483646"<<endl;
			continue;
		}

		pow = 2,rs=0;

		for(int i = a.size()-1 ; i>=0 ; --i , pow*=2 )
		{
			if( a[i]=='0' )	
			{

			}
			else if(a[i]=='1')
			{
				rs += pow -1;
			}
			else	if(a[i] =='2')
			{
				rs += 2*pow-2;
			}
		}

		cout<<rs<<endl;
	}
}