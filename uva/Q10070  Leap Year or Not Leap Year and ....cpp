#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main()
{
	int n ,count=0,sum1,sum2;
	bool key,key2;
	string a;

	while(cin>>a)
	{
		if(count!=0)	cout<<endl;

		key = true;
		key2 = false;
		n=0;

		if( a.size() > 4 )
		{
			for(int i = a.size() - 1 ,k = 0 ,ten =1; k < 5 ; ++k ,--i,ten*=10)
			{
				n += (a[i]-'0')*ten;
			}
		//	cout<<n;
		}
		else	n = atoi( a.c_str() );

		if( ( n%4==0 && n%100!=0 ) || n%400==0)
		{
			cout<<"This is leap year."<<endl;
			key =false;
			key2=true;
		}

		n=0;

		for(int i = 0 ; i < a.size() ; ++i )
		{
			n += a[i]-'0';
		}

		if(n%3==0 && ( a[a.size()-1]=='0' || a[a.size()-1] =='5' ) )
		{
			cout<<"This is huluculu festival year."<<endl;
			key = false;
		}

		n=0,sum1=0,sum2=0;

		for(int i = 0 ; i < a.size() ; i+=2 )
		{
			sum1 += a[i]-'0';
		}
		for(int i = 1 ; i < a.size() ; i+=2 )
		{
			sum2 += a[i]-'0';
		}

		if(((abs(sum1-sum2)%11)==0)&&( a[a.size()-1]=='0' || a[a.size()-1] =='5' ) && key2)
		{
			cout<<"This is bulukulu festival year."<<endl;
			key = false;
		}
		if(key)	cout<<"This is an ordinary year."<<endl;


		++count;
	}
}