#include<iostream>
#include<algorithm>

using namespace std;

int m,n;

bool cmp(int a,int b)
{

	if( a%m == b%m )
	{
		if( abs(a%2) == 0 && abs(b%2) ==1 )	return false;

		if( abs(a%2) == 1 && abs(b%2) ==0 )	return true;

		if( abs(a%2) == 1 && abs(b%2) ==1 )
		{
			return a>b;
		}
		if( abs(a%2) == 0 && abs(b%2) ==0 )
		{
			return a<b;
		}
	}

	return 	(a%m) < (b%m);
	/*else if( a%m == 0 && b%m == 0 )
	{

	}*/
}

int main()
{
	int *arr;

	while(cin>>n>>m)
	{
		cout<<n<<' '<<m<<endl;
		
		if(n==0 && m==0)	break;

		arr = new int[n];
	
		for(int i = 0 ; i < n ; ++i )	cin>>arr[i];

		sort(arr,arr+n,cmp);

		

		for(int i = 0 ; i < n ; ++i )	cout<<arr[i]<<endl;

		delete [] arr;
	}
}