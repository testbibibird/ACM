#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string a,b;
	int pos;
	bool key1,key2;

	while(cin>>a)
	{
		if(a==".")	break;

		key1 = key2 = false;

		pos = a.find('.');

		b = a;

		swap( b[b.size()-1] , b[pos] );

		key2 = next_permutation(b.begin() , b.end()-1 );

		swap( b[b.size()-1] , b[pos] );

		for(int i = a.size()-1 ; i >= 0 && !key1  ; --i )		
		{
			if(a[i] =='6') 
			{
				a[i]='9';
				key1=true;
			}
			if(a[i] =='2')
			{
				a[i] = '5';
				key1 = true;
			}
		}

		if( key1 && key2 )
		{
			bool big=false;

			for(int i = 0 ; i < a.size() && !big; ++i)
			{
				if(a[i]=='.')	continue;

				if( a[i] > b[i] )	big = true;
			}

			if(big)	cout<<b;

			else	cout<<a;

		}
		else if( !key1 && key2 )
		{
			cout<<b;
		}
		else if( key1 && !key2)
		{
			cout<<a;
		}
		else
		{
			cout<<"The price cannot be raised.";
		}
		cout<<endl;
	}
}