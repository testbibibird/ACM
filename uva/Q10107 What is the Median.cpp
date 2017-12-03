#include<iostream>

using namespace std;

int main()
{
	int arr[10000];
	int n;
	int i=0,j=0;

	while(cin>>n)
	{
		for(j=i-1;j>=0;--j)
		{
			if(n>arr[j])	break;

			else	arr[j+1]=arr[j];
		}
		arr[j+1]=n;
		
		if(i%2==0)
		{
			cout<<arr[i/2]<<endl;
		}

		else
		{
			cout<<(arr[i/2]+arr[i/2+1])/2<<endl;
		}

		++i;
	}
	
}
