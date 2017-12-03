#include<iostream>
#include<stack>
#include<string>
#include<cmath>

using namespace std;

int main()
{
	unsigned long long  n,a1,a3,a2,a4,tmp,tmp2,b1,b2,num,g;
	int m;
	string a;


	while(cin>>n>>m)
	{	
		a.clear();

		g=(unsigned long long)pow(2.0,m);

		for(  ;   n>0 ; n/=2  )
		{
			a.insert(0,1,'0'+n%2);
		}
		//cout<<a<<' '<<a.size()<<endl;

		int bin[100]={};
		unsigned long long arr[6] = {0,1,1,1,0,1};

		for(int i = 0 ; i < a.size() ; ++i )
		{
				bin[i] = a[a.size()-i-1]-'0';
		}a1=0;
		for(int i = 0 ; i < a.size() ; ++i )
		{
			if(bin[i]==1)
			{
				tmp=arr[4];
				tmp2=arr[5];
				arr[4] = arr[0]*tmp+arr[1]*tmp2;
				 arr[5] = arr[2]*tmp+arr[3]*tmp2;
				arr[4]%=g;//10000000000;
				 arr[5]%=g;//10000000000;

			}
			//cout<<arr[1]<<' ';
			a1 = arr[0]*arr[0] + arr[1]*arr[1];
			a2 = arr[0]*arr[2] + arr[1]*arr[3];
			a4 = arr[2]*arr[2] + arr[3]*arr[3];
//	cout<<arr[1]*arr[1]<<'x'<<endl;
			arr[0] = a1%g;//10000000000;
			arr[1] = arr[2] = (a2%g);//10000000000);
			arr[3] = (a4%g);//10000000000);
			//cout<<bin[a.size()-i-1];
		}
	//	cout<<(unsigned long long)pow(2.0,m)<<endl;

		cout<<arr[4]%(unsigned long long)pow(2.0,m)<<endl;

		/*switch(m)
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
		}*/
	}
}
