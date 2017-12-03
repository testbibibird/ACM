#include<iostream>
#include<cmath>

using namespace std;

int main()
{

	int n;
	int height;
	int num=1;
	int arr[100];
	//cin>>n;

	while(cin>>n)
	{
		if(n==0)	break;

		int sum=0;
		int move=0;
		int m;

		//int *arr=new int[n];

		for(int i=0;i<n;++i)
		{
			cin>>height;
			arr[i]=height;
			sum+=height;

		}

		m=sum/n;

		for(int i=0;i<n;++i)
		{
			move+=abs(arr[i]-m);
		}

		cout<<"Set #"<<num++<<endl;

		cout<<"The minimum number of moves is "<<move/2<<"."<<endl<<endl;

	//	delete [] arr;

	}
}