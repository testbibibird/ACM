#include<iostream>
#include<cmath>

using namespace std;

bool use[17]={};
int arr[16],n;

bool prime(int a,int b)
{
	bool key = true;

	for( int i = 2 ; i <= sqrt(double(a+b)) ; ++i )
	{
		if( (a+b)%i == 0 ) key = false;
	}
	return key;
}

void DFS(int c)
{
	if(c==n)
	{
		bool key = true;;


		if(!prime (arr[0],arr[n-1]))	key = false;
		/*for(int i = 0 ; i < n && key ; ++i )
		{
			if( !prime( arr[ i%n ], arr[ (i+1)%n] ) )	key = false;
		}*/

		if(key)
		{	
			cout<<arr[0];	
			
			for(int i = 1 ; i < n ; ++i )
				cout<<" "<<arr[i];

			cout<<endl;
		}
	}
	else
	{
		for(int i = 2 ; i <= n ; ++i)
		{
			if( !use[i] && prime(i,arr[c-1]) )
			{
				use[i] = true;
				arr[c] = i ;
				DFS(c+1);
				use[i] = false;
			}
		}
	}
}

int main()
{
	int count=1;

	while(cin>>n)
	{
		if( count != 1)	cout<<endl;

		cout<<"Case "<<count++<<":"<<endl;

		use[1] = true;arr[0]=1;
		DFS(1);
		//cout<<endl;
	}
}