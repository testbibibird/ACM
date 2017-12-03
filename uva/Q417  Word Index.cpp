#include<iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
	string in;
	int num = 1;
	map<string,int> word;

	for(in = "a" ; in[0] <= 'z'; ++in[0] )
	{
		word[in] = num++;
	}

	for(in = "ab" ; in[0] <= 'y' ; ++in[0] )
	{
		for( in[1] = in[0] +1 ; in[1] <= 'z' ; ++in[1] )
		{
			word[in] = num++;
		}
	}

	for(in = "abc" ; in[0] <= 'x' ; ++in[0] )
	{
		for( in[1] = in[0] + 1 ; in[1] <= 'y' ; ++in[1] )
		{
			for(in[2] = in[1]+1 ; in[2] <= 'z' ; ++in[2])
			{
				word[in] = num++;
			}
		}
	}

        for(in = "abcd" ; in[0] <= 'w' ; ++in[0] )
        {
                for( in[1] = in[0] + 1 ; in[1] <= 'x' ; ++in[1] )
                {
                        for(in[2] = in[1]+1 ; in[2] <= 'y' ; ++in[2])
                        {
                                for(in[3] = in[2]+1 ; in[3]<='z' ; ++in[3])
				{
					word[in] = num++;
				}
                        }
                }
        }

        for(in = "abcde" ; in[0] <= 'v' ; ++in[0] )
        {
                for( in[1] = in[0] + 1 ; in[1] <= 'w' ; ++in[1] )
                {
                        for(in[2] = in[1]+1 ; in[2] <= 'x' ; ++in[2])
                        {
                                for(in[3] = in[2]+1 ; in[3]<='y' ; ++in[3])
                                {
					for(in[4] = in[3]+1; in[4] <='z' ; ++in[4])
                                        word[in] = num++;
                                }
                        }
                }
        }


	while(cin>>in)
	{
		cout<<word[in]<<endl;
	}
}
