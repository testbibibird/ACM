#include<iostream>

using namespace std;

int main()
{
	int n,arr[10],num,sum;

	cin>>num;

	while(num--)
	{
		cin>>n;

		sum=0;

		for(int i = 0 ; i < n ; ++i )
		{
			cin>>arr[i];

			sum+=arr[i];
		}

		cout<<sum-n+1<<endl;
	}
}