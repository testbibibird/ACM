#include<iostream>

using namespace std;

int main()
{
	int num=1;
	int arr[20];
	long long int n,result,product;



	while(cin>>n)
	{
			
		for(int i=0;i<n;++i)
		{
			cin>>arr[i];			
		}

		result=0;

		for(int i=0;i<n;++i)
		{
			product=1;

			for(int j=i;j<n;++j)
			{
				product*=arr[j];

				if(result<product)
				{
					result=product;
				}
			}
		}

		cout<<"Case #"<<num<<": The maximum product is "<<result<<"."<<endl;
	
		cout<<endl;
		
		++num;
	}

}
