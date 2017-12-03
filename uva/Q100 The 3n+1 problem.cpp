#include <iostream>
using namespace std;
 
int f(int );

void main()
{
	int m,n;
	
	cout<<"Enter two integers\n";
	
	while(cin>>m>>n){
		int times=1;
	if(m>n)
	{
		for(int i=m;i>=n;i--)
	
		{
		
			int temp=i;

			for(int j=1;temp>1;)
	
			{
			
				j++;
			
				//cout<<j<<endl;
			
				if((temp%2)==1)
			
				{
				
					temp=3*temp+1;
			
				}
			
				else
			
				{
				
					temp=temp/2;
			
				}

			if(j>times)
				
				times=j;	
		
			}
	
		}

	}	
	
	if(m<n)
	
	{
	
		for(int i=m;i<=n;i++)
	
		{
				
			int temp=i;
		
			for(int j=1;temp>1;)
	
			{
			
				j++;
			
				if((temp%2)==1)
				
				{
				
					temp=3*temp+1;
			
				}
			
				else
			
				{
		
					temp=temp/2;
			
				}
			
				if(j>times)
							
				times=j;
		
			}

		}
	
	}
	
	cout<<times<<endl;
	}
}

