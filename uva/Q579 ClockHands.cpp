#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>

using namespace std;

int main()
{

	char a[6];
	char delims []=":";
	char *result;
	double hour,second;
	double angle,temp;

	while(cin>>a)
	{
		
		result=strtok(a,delims);
		hour=atof(result);
		result=strtok(NULL,delims);
		second=atof(result);

		if(hour==0&&second==0)	break;

		temp=hour*30+0.5*second;

		if(temp>=360)	temp-=360;

		angle=fabs(temp-second*6);

		cout<<setiosflags(ios::fixed);

		if(angle>=180)
		{
			cout<<setprecision(3)<<fabs(360-angle)<<endl;
		}
		else
		{
			cout<<setprecision(3)<<angle<<endl;
		}
	}
}
