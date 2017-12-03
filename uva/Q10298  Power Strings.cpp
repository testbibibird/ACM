#include<iostream>
#include<string>

using namespace std;

int main()
{
	int failure[1000000]={};
	string t;

	while(cin>>t)
	{
		if(t==".")	break;

		failure[0] = -1;

		for(int i = 1 , j = -1 ; i < t.size() ; ++i )
		{
			while( j >= 0 && t[i] != t[j+1])	j = failure[j] ;

			if( t[i] == t[j+1] ) ++j;

			failure[i] = j;

		//	cout<<failure[i]<<' ';
		}
		
		//cout<<failure[t.size()-1]<<' ';

		cout<<t.size()/ ( t.size()-failure[t.size()-1] -1 )<<endl;

		
	}
}