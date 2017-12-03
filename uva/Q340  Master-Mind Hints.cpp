#include<iostream>

using namespace std;

int main()
{
	int n,arr[1000]={},ans[1000],a,b,casenum=1;
	bool used[1000],key;

	while(cin>>n)
	{
		if(n==0)	break;

		for(int i = 0 ; i < n ; ++i )	cin>>ans[i];

		cout<<"Game "<<casenum++<<':'<<endl;
		
		while(1)
		{
			key = true;
			a=b=0;

			for(int i = 0 ; i < n ; ++i )	
			{
				cin>>arr[i];
				if(arr[i]!=0)	key = false;
			}
			if(key)	break;
			
			memset(used,0,1000);

			for(int i = 0 ; i < n ; ++i )
			{
				if(arr[i]==ans[i])	
				{
					used[i]=true;
					++a;
				}
			}

			for(int i = 0 ; i < n ; ++i )
			{
				if(ans[i]==arr[i])	continue;

				for(int j = 0 ; j < n ; ++j )
				{
					if(ans[i]==arr[j] && !used[j] )
					{
						used[j] = true;
						++b;
						break;
					}
				}
			}

			

			cout<<"    ("<<a<<','<<b<<")"<<endl;
		}
	}
}