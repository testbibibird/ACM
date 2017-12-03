#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	long long b1,b2,b3,g1,g2,g3,c1,c2,c3,t2[6],t[6],sum,k;

	while(cin>>b1>>g1>>c1>>b2>>g2>>c2>>b3>>g3>>c3)
	{
		sum=b1+b2+b3+g1+g2+g3+c1+c2+c3;

		t[0]=b1+g3+c2;
		t[1]=b1+g2+c3;
		t[2]=b2+g3+c1;
		t[3]=b3+g2+c1;
		t[4]=b2+g1+c3;
		t[5]=b3+g1+c2;


		for(int i = 0 ; i < 6 ; ++i )
		{
			t2[i]=t[i];
		}
		
		sort(t,t+6);

		for( k = 0 ; k < 6 ; ++k )
		{
			if(t2[k]==t[5])	break;
		}

		switch(k)
		{
		case 0:
			cout<<"BCG ";
			break;
		case 1:
			cout<<"BGC ";
			break;	
		case 2:
			cout<<"CBG ";
			break;
		case 3:
			cout<<"CGB ";
			break;
		case 4:
			cout<<"GBC ";
			break;
		case 5:
			cout<<"GCB ";
			break;
		}

		cout<<sum-t[5]<<endl;
		
	}
}