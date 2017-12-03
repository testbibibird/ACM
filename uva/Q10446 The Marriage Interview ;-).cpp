#include<iostream>

using namespace std;

int main()
{
	unsigned long long arr[63]={};

	int n,back,casenum=1;

	while(cin>>n>>back)
	{
		if(n>60)	break;

		if(n<2)	
		{
			cout<<"Case "<<casenum++<<": "<<1<<endl;
			continue;
		}

		memset(arr,0,63*8);

		arr[1] = 1 ; 
		arr[0] = 1 ;

		for(int i = 2 ; i <= n ; ++i )
		{
			for(int j = 1 ; j <= back ; ++j )
			{
				if(i-j>0)
				{
					arr[i] += arr[i-j] ;
				}
				else
				{
					arr[i] += 1;
				}
				
				//cout<<i<<' '<<i-j<<endl;
			}
			arr[i] += 1;
		}

		cout<<"Case "<<casenum++<<": "<<arr[n]<<endl;
	}
}