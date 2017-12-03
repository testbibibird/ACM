#include<iostream>

using namespace std;

int main()
{
	int n,num,day,*h,count;
	bool arr[3651];

	cin>>n;

	while(n--)
	{
		cin>>day>>num;

		h = new int [num];
		memset(arr,0,3651);
		count=0;

		for(int i = 0 ; i < num ; ++i )	cin>>h[i];

		for(int i = 0 ; i < num ; ++i )
		{
			for(int j = h[i] ; j <= day ; j+=h[i] )
			{
				arr[j] = true;
			}
		}

		for(int i = 1 ; i <= day ; ++i )
		{
			if( arr[i] && i%7!=6 && i%7!=0)	++count;
		}

		cout<<count<<endl;

		delete [] h;
	}
}