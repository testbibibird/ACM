#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int N;
	long long num,sum,last,now,i,tmp;

	cin>>N;

	while(N--)
	{
		cin>>num;

		sum = 0;
		last = num;
		tmp = sqrt(double(num));

		for(i = 1 ; i <= tmp ; ++i )
		{
			if((num/i)==num/(num/i))
			{
				sum += (num/i);

				//cout<<i<<'x'<<endl;
			}
			else
			{
				now = num / (i+1) ;

				sum += (num / i)  + (last - now)*(i) ;

				last = now;			
			}
		}

		//sum += tmp;

		cout<<sum<<endl;

		/*for(int i = 1 ; i <= num ; ++i )
			cout<<num/i<<' '<<i<<endl;
		cout<<endl;*/
	}
}