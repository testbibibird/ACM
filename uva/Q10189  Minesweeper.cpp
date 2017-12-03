#include<iostream>
#include<string>

using namespace std;

int main()
{
	int m,n,rs[102][102]={},count=1;;
	string *arr;


	while(cin>>n>>m)
	{
		if(n==0 && m==0)	break;

		if(count!=1)	cout<<endl;

		arr = new string [n+1];

		memset(rs,0,102*102*4);

		getline( cin , arr[0] );


		for( int i = 0 ; i < n ; ++i ) getline(cin,arr[i]);
		
		for(int i = 0 ; i < n ; ++i )
		{
			for(int j = 0 ; j < m ; ++j )
			{
				if( arr[i][j] == '*' )
				{
					rs[i+1][j+1];
					++rs[i+1][j];
					++rs[i][j];
					++rs[i][j+1];
					++rs[i][j+2];
					++rs[i+1][j+2];
					++rs[i+2][j+2];
					++rs[i+2][j+1];
					++rs[i+2][j];
				}
			}
		}
		
		cout<<"Field #"<<count++<<":"<<endl;

		for( int i = 0 ; i < n ; ++i )
		{
			for(int j = 0 ; j < m ; ++j )
			{
				if( arr[i][j] == '*' )
				{
					cout<<'*';
				}
				else	cout<<rs[i+1][j+1];
			}
			cout<<endl;
		}

		delete [] arr;
	}
}