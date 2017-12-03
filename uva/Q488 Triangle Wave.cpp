#include<iostream>

using namespace std;


int main()
{
	int f;
	int a;
	int number;
	int i=0;
	int count,c=0;

	cin>>number;

	while(number>0)
	{
		if(c!=0)	cout<<"\n";
		
		cin>>a;
		cin>>f;	
		
		i=0;

		for(int i=0;i<f;i++)//¶]F
		{	
			if(i!=0)	cout<<"\n";

			count=a;
			for(int j=0;j<2*a-1;j++)
			{
				for(int k=0;k<=j&&j<a;k++)	
				{			
					cout<<j+1;
				}
			
				for(int k=count-1;k>0&&j>=a;k--)	
				{	
					cout<<count-1;
				}
			
				if(j>=a)	
				{
					count--;	
				}
		
				cout<<"\n";
			}

			//cout<<"\n";
		}
	++c;
	number--;
	}

}

