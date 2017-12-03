#include<iostream>
#include<string>
#include<cmath>

using namespace std;

bool prime(int);

int main()
{	
	char a[2001];
	int n,count;
	char key;

	cin>>n;

	for(int i=0;i<n;++i)
	{
		char arr[2001];
		int k=0;
		count = 0 ;


		cin>>a;

		sort(a,a+strlen(a));
	
		key=a[0];
		count++;

		for(size_t j=1;j<strlen(a);++j)
		{
			if(key==a[j])
			{
				count++;
			}
			else
			{
				if(prime(count))
				{
					arr[k++]=key;
				}
				key=a[j];
				count=1;
			}
		}

		if(prime(count))	arr[k++]=key;
	
		if(k==0)	
		{
			cout<<"Case "<<i+1<<": empty";
		}
		else
		{
			cout<<"Case "<<i+1<<": ";

			for(int j=0;j<k;++j)
			{
				cout<<arr[j];
			}
		}
		cout<<endl;

	}
}

bool prime(int x)
{

	if(x==1)	return false;

	for(int i=2;i<=sqrt(x);++i)
	{
		if(x%i==0)	return false;
	}

	return true;
}
