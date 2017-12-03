#include<iostream>

using namespace std;




int main()
{
	int a,b;
	
	while(1){
	
	int temp=0;
	int count=0;

	cin>>a>>b;

	if(a==0&&b==0) break;

	for(int i=0;a>0||b>0;i++)
	{
		temp=a%10+b%10+temp/10;
		a/=10;
		b/=10;
		if(temp>=10)
		{
			++count;
		}
	}

	if(count==0)
	{
		cout<<"No carry operation.";
	}
	else
	{
		if(count>1)
		{
			cout<<count<<" carry operations.";
		}
		else
		{
			cout<<count<<" carry operation.";
		}
	}

	cout<<endl;
	}
}