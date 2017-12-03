#include<iostream>
#include<string.h>

using namespace std;

int main()
{
	bool exist[20001]={},key;
	int n,arr[100],casenum=1;

	while(cin>>n)
	{
		key = true;
		memset(exist,0,20001);

		for(int i = 0 ; i < n ; ++i )	cin>>arr[i];

		if(arr[0]<1)	key =false; 

		for(int i = 1 ; i < n ; ++i )
		{
			if(arr[i] <= arr[i-1])	key = false;
		}

		for(int i = 0 ; i < n && key ; ++i )
		{

			for(int j = i ; j < n && key ; ++j )
			{
			///	cout<<arr[i]+arr[j]<<' '<<i<<' '<<j<<endl;
				if(exist[arr[i]+arr[j]])
				{
					key = false;
				}
				else	exist[arr[i]+arr[j]] = true;
			}
		}

		if(key)	cout<<"Case #"<<casenum++<<": It is a B2-Sequence."<<endl;
		else cout<<"Case #"<<casenum++<<": It is not a B2-Sequence."<<endl;
		cout<<endl;
	}

}