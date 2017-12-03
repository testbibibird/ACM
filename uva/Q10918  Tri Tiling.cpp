#include<iostream>

using namespace std;

int main()
{
	int n;
	long long arr[40]={1,0,3,0,11};

	for(int i = 6 ; i <36 ; i+=2)
	{
		arr[i] += arr[i-2]*3;

		for(int j = i-4 ; j >= 0 ; j-=2)
		{
			arr[i] += 2*arr[j];//*3 + arr[i-4] * 2;
		}
	}

	while(cin>>n)
	{	
		if(n==-1)	break;
		cout<<arr[n]<<endl;
	}
}