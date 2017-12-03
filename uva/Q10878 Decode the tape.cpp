#include<iostream>

using namespace std;

int main()
{
	char a[20];
	int count=1,j=0;
	char pow,result;

	while(cin.getline(a,20))
	{
		if(!strcmp(a,"___________")&&count==2)	break;

		if(!strcmp(a,"___________"))
		{
			count++;
			continue;
		}

		result=0;
		pow=64;

		for(int i=2; i < strlen(a)-1;++i)
		{
			if(a[i]=='.')	++i;

			if(a[i]=='o')
			{
				result+=pow;
			}

			pow/=2;

		}

		cout<<result;
		
	}

	

}
