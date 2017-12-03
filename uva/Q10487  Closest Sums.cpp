#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	int n,*arr,num,sum,rs,count=1,tmp,sub,low;

	while(cin>>n)
	{
		if(n==0)	break;

		arr = new int [n];

		for(int i = 0 ; i < n ; ++i )	cin>>arr[i];

		sort(arr,arr+n);

	//	for(int i = 0 ; i < n; ++i )	cout<<arr[i];

		cout<<"Case "<<count++<<':'<<endl;

		cin>>num;

		while(num--)
		{
			sub=100000000;

			cin>>sum;

			rs=0;

			for(int i = 0 ; i < n ; ++i )
			{
				tmp = sum - arr[i];
				//cout<<lower_bound(arr,arr+n,tmp)-arr<<'x'<<*lower_bound(arr,arr+n,tmp)<<endl;
				low = lower_bound(arr,arr+n,tmp) - arr;
				//up  = upper_bound(arr,arr+n,tmp) - arr;

				//cout<<low<<'x'<<endl;

				if( arr[low] != arr[i] && low < n && abs( arr[low] + arr[i]  - sum 	) < sub )	
				{
					sub = abs( arr[low] + arr[i]  - sum 	);

					rs = arr[low] + arr[i];
				}

				if( arr[low-1] != arr[i] && low >= 1  && abs( arr[low-1] + arr[i]  - sum 	) < sub )	
				{
					sub = abs( arr[low-1] + arr[i]  - sum 	);

					rs = arr[low-1] + arr[i];
				}
			/*	if( up != i && up < n && abs( arr[up] + arr[i]  - sum 	) < sub )	
				{
					sub = abs( arr[up] + arr[i]  - sum 	);

					rs = arr[up] + arr[i];
				}*/
			}

			cout<<"Closest sum to "<<sum<<" is "<<rs<<"."<<endl;
		}
		
		delete [] arr;
	}
}