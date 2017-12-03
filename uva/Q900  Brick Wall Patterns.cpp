#include<iostream>

using namespace std;

int main()
{
	long long int n,arr[50]={1,2};

	for(int i = 2 ; i < 50 ; ++i )
	{
		arr[i] = arr[i-1] + arr[i-2];
	}

	while(cin>>n)
	{
		if(n==0) break;

		cout<<arr[n-1]<<endl;
	}
}