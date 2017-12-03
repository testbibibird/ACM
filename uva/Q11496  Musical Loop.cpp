#include<iostream>

using namespace std;

int main()
{
	int n,*arr,count;

	while(cin>>n)
	{
		if(n==0)	break;

		arr = new int [n+2];

		count=0;

		for(int i = 0 ; i < n ; ++i )	cin>>arr[i];
		
		arr[n] = arr[0] ;
		arr[n+1] = arr[1] ;

		for(int i = 1 ; i <= n ; ++i )
		{
			if( arr[i] > arr[i-1] && arr[i] > arr[i+1] )	
			{
				count++;
			}
			else if( arr[i] < arr[i-1] && arr[i] < arr[i+1] )
			{
				count++;
			}
		}

		cout<<count<<endl;

		delete [] arr;
	}
}