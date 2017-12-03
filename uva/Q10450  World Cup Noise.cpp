#include<iostream>

using namespace std;

int main()
{
	long long n,arr[51]={1,2,3};
	int num;

	for(int i = 3 ; i < 51 ; ++i )
	{
		arr[i] = arr[i-1] + arr[i-2];
	}

	cin>>num;

	for(int i = 0 ; i < num ; ++i )
	{
		cin>>n;

		cout<<"Scenario #"<<i+1<<':'<<endl;

		cout<<arr[n]<<endl<<endl;
	}

}