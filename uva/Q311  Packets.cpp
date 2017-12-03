#include<iostream>

using namespace std;

int main()
{
	long long s1,s2,s3,s4,s5,s6,result,empty;

	while(cin>>s1>>s2>>s3>>s4>>s5>>s6)
	{
		if(s1==0 && s2==0 && s3==0 && s4==0 && s5==0 && s6==0 )	break;
		
		result=s4+s5+s6;
		empty=0;

		if(s1>=s5*11)  //5*5
		{
			s1 = s1 - s5 * 11 ;
		}
		else
		{
			//s1=0;
			empty+=s5*11;//-s1;
		}

		if( s2 >= s4*5 )//4*4
		{
			s2 = s2 - s4 * 5;
		}
		else
		{
			empty += (s4*5 - s2)*4;
			s2=0;
			
		}

		if(s3%4==0)      //3*3
		{
			result += s3/4;
		}
		else
		{
			result += s3 / 4;
			++result;

			if(s3 %4 ==1)
			{
				if( s2 >= 5 )
				{
					s2-=5;
					empty+=7;
				}
				else
				{
					empty += ( 5-s2 )*4+7;
					s2=0;
					
				}
			}

			if(s3 %4 ==2)
			{
				if( s2 >= 3)
				{
					s2-=3;
					empty += 6;
				}
				else
				{
					empty += (3-s2)*4+6;
					s2=0;
					
				}
			}
			if(s3 %4 ==3)
			{
				if( s2>=1 )
				{
					--s2;
					empty+=5;
				}
				else
				{
					empty+=9;
				}
			}
		}
		
		if(s2%9==0)	result+=s2/9;
			
		else
		{
			result+=s2/9;
			++result;
			empty+=(9-s2%9)*4;
		}
	//	cout<<result<<endl;

		if(s1 > empty)
		{
			s1-=empty;
			if(s1%36!=0)	++result;
			
			result+=s1/36;
		}

		cout<<result<<endl;
	}
}