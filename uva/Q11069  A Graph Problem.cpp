#include<iostream>

using namespace std;

int arr[100]={};

int main()
{
	int n;
	arr[1]=1;
	arr[2]=2;
	arr[3]=2;

	for(int i = 4 ; i < 77 ; ++i )
	{
		arr[i] = arr[i-2]+arr[i-3];
	}

	while(cin>>n)
	{
		cout<<arr[n]<<endl;
	}
}