#include<iostream>
#include<list>

using namespace std;

int main()
{
	int n,parity;
	

	while(cin>>n)
	{
		if(n==0)	break;

		list<char> rs;

		parity=0;
		cout<<"The parity of ";

		for( ; n > 0 ; n/=2 )
		{
			if((n&1)==1)	
			{
				++parity;
				rs.push_front('1');
			}
			else	rs.push_front('0');
		}
		for(list<char>::iterator it=rs.begin() ; it != rs.end() ; ++it )
			cout<<*it;
		cout<<" is "<<parity<<" (mod 2)."<<endl;
	}
}