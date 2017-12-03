#include<iostream>

using namespace std;

unsigned long long arr[1000001]={};

int main()
{
	unsigned long long  rs=1;
	int n;
	
	arr[4]=1;

	for(int i = 5 ; i <= 1000000 ; ++i )
	{
		if(i%2==0)
		{
			arr[i] = arr[i-1]+rs*rs;
			
		}
		else
		{
			arr[i] = arr[i-1]+(rs*(rs+1));++rs;
		}
	}

	while(cin>>n)
	{
		if(n<3)	break;

		cout<<arr[n]<<endl;
	}
}