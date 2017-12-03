#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
	int num,casenum=0,c,r,q,tmp;
	vector<int> v;

	cin>>num;

	while(casenum++<num)
	{
		cin>>c>>r;

		cout<<"Case #"<<casenum<<":";

		q=c-r;

		if(q>=r)
		{
			//if(r!=0)	tmp=r;
			//else	tmp=1;

			for(int i = 1 ; i <= sqrt((double)q) ; ++i )
			{
				if(q%i==0)	
				{
					if(i > r )	v.push_back(i);
					if(q/i > r && i*i!=q )v.push_back(q/i);
				}
			}
			sort(v.begin(),v.end());

			for(int i = 0 ; i < v.size() ; ++i )	cout<<' '<<v[i];
			cout<<endl;
		}
		else if(q==0)
		{
			cout<<" 0"<<endl;
		}
		else
		{
			cout<<endl;
		}

		if(!v.empty())	v.clear();
	}
}