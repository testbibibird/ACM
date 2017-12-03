#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	int base_max,sum,ans;

	while(cin>>s)
	{
		if(s[0]=='+' || s[0] =='-' )
		{
			s.erase(0,1);
		}
		
		if((s[0] =='1' ||s[0] =='0') && s.size()==1)	
		{
			cout<<2<<endl;
			continue;
		}

		base_max = 0 ,sum = 0;

		for(int i = 0 ; i < s.size() ; ++i )
		{
			if(s[i] < 65)	s[i] -= 48;
			else if( s[i] < 97 ) 	s[i] -= 55;
			else s[i] -= 61;

			if( base_max < s[i] ) base_max = s[i];

			sum += s[i];
		}
		ans = 0;
		for(int i = base_max ; i < 63 ; ++i )
		{
			if(sum %i==0)
			{
				ans = i+1;
				break;
			}
		}

		if(ans)	cout<<ans<<endl;
		else	cout<<"such number is impossible!"<<endl;
	}
}
