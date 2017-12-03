#include<iostream>
#include<string>

using namespace std;

int main()
{
	string t,r;
	int failure[100000]={},max;

	while(cin>>t)
	{
		failure[0] = -1; 
		max = 0;

		r.assign(t.rbegin(),t.rend());


		for(int i = 1 , j = -1 ; i < r.size() ; ++i )
		{
			while( j >= 0 && r[i] != r[j+1] )	j = failure[j] ;

			if( r[i] == r[j+1] ) ++j;

			failure[i] = j;
		}

		for(int i = 0 , j = -1 ; i < t.size() ; ++i )
		{
			while( j >= 0 && t[i] != r[j+1] )	j = failure[j] ;

			if( t[i] == r[j+1] )	++j;

			if( i == t.size() - 1  )	max = j+1; 
		}

		for(int i = 0 ; i < t.size() - max ; ++i )
			cout<<t[i];

		cout<<r<<endl;;

	}
}