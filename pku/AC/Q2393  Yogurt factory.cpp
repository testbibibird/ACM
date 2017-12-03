#include<iostream>

using namespace std;

class node
{
public:
	int price;
	int out;
};

int main()
{
	long long sum,s,n,min=2147483647,day;
	node arr[10000];

	while(cin>>n>>s)
	{
		sum=0;

		for(int i = 0 ; i < n ; ++i )
		{
			cin>>arr[i].price>>arr[i].out;
		}
		
		min = 2000000000;

		for(int i = 0 ; i < n ; ++i )
		{
			if( min > arr[i].price)	min = arr[i].price;	

			/*for(int j = 0 ; j <= i ; ++j )
			{
				if( ((i-j)*s + arr[j].price )* arr[i].out < min)	min =  ((i-j)*s + arr[j].price )* arr[i].out ;
			}*/

			sum += min*arr[i].out;
			min+=s;
		}

		cout<<sum<<endl;
	}
}