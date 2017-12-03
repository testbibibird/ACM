#include<iostream>
#include<string>

using namespace std;

int main()
{
	string a(""),tmp;
	int count,num,n=0;

	while(getline(cin,tmp))
	{
		for(int i = 0 ; i < tmp.size() && tmp[i]!='#' ; ++i )
		{
			n=((n<<1) + tmp[i]-'0')%131071;
		}

		if(tmp[tmp.size()-1]=='#')
		{
			if(n%131071==0)	cout<<"YES"<<endl;
			else	cout<<"NO"<<endl;

			n=0;
		}
		
		/*if( tmp[tmp.size()-1]!='#')
		{
			a.append(tmp);
		}
		else
		{
			a.append(tmp);

			//cout<<a<<endl;

			num=count=0;

			for(int i = a.size()-1 ; i>=0 && num < 17 ; --i )
			{
				if(a[i]=='1')	++count;
				if(a[i]=='1'||a[i]=='0')	++num;
			}	
			if(count==17||count==0)	cout<<"YES"<<endl;
			else	cout<<"NO"<<endl;

			a.clear();
		}*/
	}
}