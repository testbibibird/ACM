#include<iostream>

using namespace std;

int arr[92][9]={},pos[9]={},c=0;

bool check(int n)
{
	for(int i = 1 ; i < n ; ++i )
	{
		if(pos[i] == pos[n] )	return false;
		if(n-i == pos[n]-pos[i] )	return false;
		if(n-i == pos[i]-pos[n] )	return false;
	}
	return true;
}

void queen(int n)
{
	if(n==9)
	{
		for(int i = 1 ; i < 9 ; ++i )
		{
			arr[c][i] = pos[i] ;
		}

		
		++c;
		return;
	}

	for(int i = 1 ; i < 9 ; ++i )
	{
		pos[n] = i ;

		if(check(n))
		{
			queen(n+1);
		}
	}
}


int main()
{
	int n,x,y,count=0;

	queen(1);

	cin>>n;

	while(n--)
	{
		if(count!=0)	cout<<endl;

		cin>>x>>y;

		cout<<"SOLN       COLUMN"<<endl;
		cout<<" #      1 2 3 4 5 6 7 8"<<endl<<endl;
		for(int i = 0 ,k=1; i < 92 ; ++i )
		{
			if(arr[i][y]==x)
			{
				if(k<10)
				cout<<" "<<k<<"     ";
				else
					cout<<k<<"     ";
				for(int j = 1 ; j < 9 ; ++j )	cout<<' '<<arr[i][j];
				cout<<endl;
				++k;
			}
		}
	
	
		++count;
	}
}