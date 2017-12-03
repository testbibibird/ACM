#include<iostream>

using namespace std;

int main()
{
	unsigned int number;
	unsigned int count;
	unsigned int a;
	unsigned int temp;
	unsigned int reverse=0;

	cin>>number;

	
	
	for(int m=0;m<number;m++)
	{
		cin>>a;
		count=0;

	while(1)
	{
		reverse=0;
		
		temp=a;

		for(int i=0;temp>0;i++)
		{
			reverse=temp%10+reverse*10;
			temp/=10;
		}

		if(a==reverse)
		{
			break;
		}
		else
		{
			a=a+reverse;
			count++;
		}
	}
	cout<<count<<" "<<a<<endl;
	}
	

}