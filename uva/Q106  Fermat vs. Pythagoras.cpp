#include<iostream>

using namespace std;

bool prime(int a,int b)
{
	if(b)
	{
		while((a%=b)&&(b%=a));
	}

	if(a+b==1)	return true;

	else	return false;
}

int main()
{
	int a,x,y,z,count,remain;
	bool arr[1000000]={};

	while(cin>>a)
	{
		count=0;
		remain=0;

		memset(arr,0,1000000);

		for(int i = 2 ; i*i <= a ; ++i )
		{
			for(int j = 1 ; i*i + j*j <= a && j < i ; ++j )
			{
			
				
					x = 2*i*j;
					y = i*i - j*j ;
					z = i*i + j*j ;

					for(int k = 1 ; z*k <= a ; ++k )
					{
						arr[x*k] = arr[y*k] = arr[z*k] = true;
					}

					if( prime(x,y) && prime(x,z) && prime(y,z) )	++count;
				
			}
		}

		//cout<<endl;

	/*	for(int i = 5 ; i <= a ; ++i )
		{
			for(int j = 4 ; j <= i ; ++j )
			{
				for(int k = 3 ; k <= j ; ++k )
					if(j*j+k*k==i*i)	{}//cout<<k<<' '<<j<<' '<<i<<endl;
			}
		}*/

		for(int i = 1 ; i <= a ; ++i)
		{
			if(!arr[i])	
			{	
				++remain;
				//cout<<' '<<i;
			}
		}

		cout<<count<<' '<<remain<<endl;
	}
}

