#include<iostream>

using namespace std;

int main()
{
	int n,num,arr[8],arr2[8]={2,3,4,5,6,7,8,9};//2 3 4 5 7 8

	cin>>num;

	while(num--)
	{
		cin>>n;
		memset(arr,0,8*4);

		if(n==1)	cout<<1;
		if(n==0)	{cout<<0<<endl;continue;}

		for( ; n%9 ==0 ; n/=9 , ++arr[7]) ;
		for( ; n%8 ==0 ; n/=8 , ++arr[6]) ;
		for( ; n%7 ==0 ; n/=7 , ++arr[5]) ;
		for( ; n%6 ==0 ; n/=6 , ++arr[4]) ;
		for( ; n%5 ==0 ; n/=5 , ++arr[3]) ;
		if(n%4==0) {arr[2]=1; n/=4;}
		for( ; n%3 ==0 ; n/=3 , ++arr[1]) ;
		if(n%2==0) {arr[0]=1; n/=2;}

		if(n==1)
		{
			for(int i = 0 ; i < 8 ; ++i )
			{
				for(int j = 0 ; j < arr[i] ; ++j )
				{
					cout<<arr2[i];
				}
			}
		}
		else
		{
			cout<<-1;
		}
		cout<<endl;
	}
}