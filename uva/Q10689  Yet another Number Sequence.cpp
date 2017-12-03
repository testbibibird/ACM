#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main()
{
	long long int n,a1,a3,a2,a4,tmp,tmp2,b1,b2,num,m;
	string a;

	cin>>n;

	while(n--)
	{
		cin>>b1>>b2>>num>>m;
		//cin>>num;
		
		a.clear();

		for( ; num>0 ; num/=2)
		{
			a.insert(0,1,'0'+num%2);
		}
		//cout<<a<<endl;

		int bin[100]={};
		long long arr[6] = {0,1,1,1,0,1};

		arr[4]=b1;
		arr[5]=b2;

		for(int i = 0 ; i < a.size() ; ++i )
		{
				bin[i] = a[a.size()-i-1]-'0';
		}
		for(int i = 0 ; i < a.size() ; ++i )
		{
			if(bin[i]==1)
			{
			tmp=arr[4];
			 tmp2=arr[5];
			  arr[4] = arr[0]*tmp+arr[1]*tmp2;
			  arr[5] = arr[2]*tmp+arr[3]*tmp2;
			 arr[4]%=100000;
			 arr[5]%=100000;

			}

			a1 = arr[0]*arr[0] + arr[1]*arr[1];
			a2 = arr[0]*arr[2] + arr[1]*arr[3];
			a4 = arr[2]*arr[2] + arr[3]*arr[3];
	
			arr[0] = a1%100000;
			arr[1] = arr[2] = (a2%100000);
			arr[3] = (a4%100000);
			//cout<<bin[a.size()-i-1];
		}

		//cout<<arr[4]%100000;
		//cout<<endl;
		/*if(n==1||n==0)	
		{
			cout<<1<<endl;
			continue;
		}
		a[0]=0;
		a[1]=1;
		a[2]=1;
		a[3]=1;
		
		for( int i = 0 ; i < (n-3)  ; ++i )
		{
			a1 = a[1];
			a2 = a[0] + a[1];
			a3 = a[3];
			a4 = a[2] + a[3];

			a[0] = a1;
			a[1] = a2;
			a[2] = a3;
			a[3] = a4;
			
		//	cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
	//		cout<<a[0] + a[1] + a[2] +a[3]<<endl;
		}

		cout<<a[0] + a[1] + a[2] +a[3]<<endl;
*/		
		switch(m)
		{
			case 1:
				cout<<arr[4]%10<<endl;
				break;
			case 2:
				cout<<arr[4]%100<<endl;
				break;
			case 3:
				cout<<arr[4]%1000<<endl;
				break;
			case 4:
				cout<<arr[4]%10000<<endl;
				break;
		}
	}
}
