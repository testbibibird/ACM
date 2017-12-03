#include<iostream>

using namespace std;

int main()
{
	bool arr[101],key;
	int n,count,rs,i,m,j,k;

	while(cin>>n)
	{
		if(n==0)	break;

		if(n==13)	{cout<<1<<endl;continue;}

		key = false;

		for(m = 5 ; m <= n && !key ; ++m )
		{	
			count=1,rs=1;
			
			memset(arr,0,n+1);
			
			for(i = 0 ; i < n && !arr[13] ; ++i )
			{
				/*while( arr[count%n] )
				{
					++count;
					count%=n;
				}

				cout<<count<<endl;

				arr[count] = true;
				
				count+=m;
				count%=n;*/

				arr[count] = true;
				
				//cout<<count<<" ";
				if(count==13)	{++i;break;}
				for( j = 1 , k = 1; j <= m  ; ++k )
				{
					if( !arr[ (count+k)%n ] )	++j;


				}
				
				count += k-1;
				count %= n;
			}//cout<<endl;

			if( i >= n )//&& arr[13] )	
			{
				rs=m;
				key = true;
				break;
			}
		}

		if(key)	cout<<rs<<endl;
		else	cout<<0<<endl;
	}
}