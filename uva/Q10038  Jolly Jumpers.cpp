#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int n;
	int past,now;
	bool arr[3001];

	//for(int i=0;i<3001;++i)
	//{
//		arr[i]=0;
//	}

	while(cin>>n)
	{
		for(int i=1;i<=n;++i){	arr[i]=0;	}

		int tok=1;

		cin>>past;

		for(int i=1;i<n;++i)
		{
			cin>>now;

			if(abs(now-past)>=n)
			{
				tok=0;
				//arr[abs(now-past)]=1;
			}
			else
			{
				arr[abs(now-past)]=1;
			}
			past=now;
		}

		for(int i=1 ; i<n ;++i)
		{
			if(!arr[i])
			{
				tok=0;
			}
			else{}
		}

		if(tok==1)
		{
			cout<<"Jolly"<<endl;
		}
		else
		{
			cout<<"Not jolly"<<endl;
		}

	}
}