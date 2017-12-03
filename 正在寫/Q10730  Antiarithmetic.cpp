#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int arr[10001],key,m,ptr;
	char a[50000],delims[]=" ",*result=NULL;

	while(cin.getline(a,50000))
	{
		if(a[0]=='0' && a[1] == '\0' )	break;

		key=1;
		m=0;

		
		result= strtok(a,delims) ;

		while(result != NULL)
		{
			arr[m++] = atoi(result);
			result = strtok (NULL,delims);
			
		}


		for(int i = 1 ; i <= arr[0]-2 && key ; ++i)
			for(int j = i+1 ; j <= arr[0]-1 ; ++j)
			{
				ptr=*lower_bound(arr,arr+m, arr[j]- arr[i] + arr[j] );

				cout<<ptr<<endl;
			}
				/*for( int k = j+1 ; k <= arr[0] ; ++k)
				{if(arr[i]-arr[j]==arr[j]-arr[k])
					{
						cout<<"no"<<endl;
						goto l1;
					}

				}*/
		cout<<"yes"<<endl;

		
	}
}