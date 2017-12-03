#include<iostream>

using namespace std;

int ** arr,* mm,k,n,fac,* rem;

void DFS(int a,int count)
{
	if(count==n)
	{
		int tmp[10]={};
		int l=0;

		for(int i = 0 ; i < n ; ++i ,++l)
		{
			for(int j = 0 ; j < n ; ++j )
			tmp[l] += arr[j][ ( i + rem[j] ) % n ];
		}

		int max  = 0 ;

		for(int i = 0 ; i < l ; ++i )
		{ 
			if( max < tmp[i] )	max = tmp[i];
		}

		mm[k++] = max;

		return;
	}

	for(int i = 0 ; i < n ; ++i )
	{
		rem[count] = i; 
		DFS(i , count+1);
	}

	
}



int main()
{
	

	while(cin>>n)
	{
		if(n==-1)	break;
		
		int min=2147483647;
		
		arr = new int*[n];
		rem = new int [n];

		fac=n,k=0;

		for(int i = 0 ; i < n ; ++i )	arr[i] = new int [n];

		for(int i = 2 ; i <= n ; ++i )	fac *= n;

		mm = new int [fac];

		for(int i = 0 ; i < n ; ++i )
		{
			for(int j = 0 ; j < n ; ++j )
				cin>>arr[i][j];
		}

		//for(int i = 0 ; i < n ; ++i )
		{
			DFS(0,0);
		}



		for(int i = 0 ; i < k ; ++i )
		{
			if(min > mm[i] )	min = mm[i];
		}

		cout<<min<<endl;//<<'x'<<endl;


	/*	for(int i = 0 ; i < n ; ++i )
		{
			for(int j = 0 ; j < n ; ++j )
				cout<<arr[i][j];
			cout<<endl;
		}*/

		for(int i = 0 ; i < n ; ++i )	
		{
		//	cout<<i<<endl;
			delete [] arr[i];
		}
		delete [] arr;
		delete [] mm;

		
	}
}