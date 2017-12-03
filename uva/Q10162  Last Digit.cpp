#include<iostream>
#include<cmath>
#include<string>

using namespace std;

int main()
{
	long long sum=0,arr[101],result;
	string a;
	char rs[3];
	
	for(int i = 1 ; i <= 100 ; ++i)
	{
		switch(i%10)
		{
			case 1:	sum+=1;
				break;
			case 2:	
				if(i%4==1)	sum+=2;
				else if(i%4==2)	sum+=4;
				else if(i%4==3)	sum+=8;
				else sum+=6;
				break;
			case 3:
				if(i%4==1)	sum+=3;
				else if(i%4==2)	sum+=9;
				else if(i%4==3)	sum+=7;
				else sum+=1;
				break;
			case 4:	
				if(i%2==1)	sum+=4;
				else	sum+=6;
				break;
			case 5:	sum+=5;
				break;
			case 6:	sum+=6;
				break;
			case 7:	
				if(i%4==1)	sum+=7;
				else if(i%4==2)	sum+=9;
				else if(i%4==3)	sum+=3;
				else sum+=1;
				break;
			case 8:	
				if(i%4==1)	sum+=8;
				else if(i%4==2)	sum+=4;
				else if(i%4==3)	sum+=2;
				else sum+=6;
				break;
			case 9:	
				if(i%2==1)	sum+=9;
				else	sum+=1;
				break;
			case 0:	
				break;

			
		}
		//cout<<i<<" "<<sum%10<<endl;
		
		arr[i]=sum%10;
	}	

	arr[0]=arr[100];//=arr[109];
	
	while(cin>>a)
	{
		
		if(a=="0")	break;


		if(a.size()>1)
		{
			rs[0] = a [a.size() -2];
			rs[1] = a [a.size() -1];
			rs[2] = 0;			
		}
		else
		{
			rs[0] = a[0];
			rs[1] = 0;
		}
		result = atoi(rs);

		cout<<arr[result%100]<<endl;
	
		//cout<<arr[n%20]<<endl;
	}
}