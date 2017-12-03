#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int n1,n2,cs=0;
	double sfive = sqrt(5.0);
	int f1=1,tmp,f2=1,arr[15001]={1,1};


	for(int i = 2 ; i <= 15000 ; ++i )
	{
		arr[i]=(arr[i-1]+arr[i-2])%10000;
	}

	while(	cin>>n1>>n2)
	{
		if(n1==0 &&n2==0)	break;

		cout <<"Case "<< ++cs <<": "<<n1<<" "<<n2<<" "<<(2*arr[n1%15000]-1)%n2<< endl; 
	
	}
}


