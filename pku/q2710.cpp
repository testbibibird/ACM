#include<iostream>
#include<cmath>
#include<string>

using namespace std;

int main()
{
	double n,d,tmp;
	int e,b,num,count=1,i;
	string rs;

	cin>>num;

	while(num--)
	{
		cin>>n>>d>>b>>e;

		tmp = n/d;

		for( i = 0 ; i < b ; ++i)	
		{
		//	
			tmp*=7;
			tmp-=floor(tmp);
		}

		for( ; i <= e ; ++i )
		{
			cout<<tmp<<endl;
			tmp*=7;
			rs.push_back(floor(tmp)+'0');
			//rs.push_back(fmod(tmp,10.0)+'0');
			tmp-=floor(tmp);
		}

		cout<<"Problem set "<<count++<<": "<<n<<" / "<<d<<", base 7 digits "<<b<<" through "<<e<<": "<<rs<<endl;
		
		rs.clear();
	}
}