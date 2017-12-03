#include<iostream>
#include<iomanip>

using namespace std;

int pos[9]={},arr[9][9]={},m,tmp,c;

bool check(int n)
{
	for(int i = 0 ; i < n ; ++i )
	{
		if(pos[i]==pos[n])	return false;
		if(n-i==pos[n]-pos[i])	return false;
		if(n-i==pos[i]-pos[n])	return false;
	}

	return true;
}

void queen(int n)
{
	if(n==8)
	{
		if( tmp > m ) m = tmp;
		
		return;
	}

	for(int i = 0 ; i < 8 ; ++i )
	{
		pos[n] = i;

		if(check(n))
		{
			tmp += arr[n][i] ;
			queen(n+1);	
			tmp -= arr[n][i] ;//cout<<1;
		}	
	}
}



int main()
{
	int n ;

	cin>>n;

	while(n--)
	{
		for(int i = 0 ; i < 8 ; ++i )
		{
			for(int j = 0 ; j < 8 ; ++j )
			{
				cin>>arr[i][j];
			}
		}
		m=0,tmp=0,c=0;

		//for(int i = 0 ; i < 8 ; ++i )
		{	
		//	pos[0] = i;
			queen(0);
		}
		cout<<setw(5)<<m<<endl;

	}


}