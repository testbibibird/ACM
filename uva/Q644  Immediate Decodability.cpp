#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	vector<string> arr;
	string a;
	int count=1 , key ;

	while(cin>>a)
	{
		if(a=="9")
		{
			key = 1;

			for(int i = 0 ; i < arr.size() && key ; ++i )
			{
				for(int j = i+1 ; j < arr.size() && key ; ++j )
				{
					if( arr[i].size() > arr[j].size() )
					{
						if( arr[i].substr( 0 , arr[j].size() ) == arr[j] ){
							//cout<<arr[i].substr( 0 , arr[j].size() )<<" "<<arr[j]<<endl;
							key=0;}
					}
					else
					{
						if( arr[j].substr( 0 , arr[i].size() ) == arr[i] ) {
							//cout<<arr[i].substr( 0 , arr[j].size() )<<" "<<arr[j]<<endl;
							key=0;}
					}
				}
			}

			if(key)
			{
				cout<<"Set "<<count++<<" is immediately decodable"<<endl;
			}
			else
			{
				cout<<"Set "<<count++<<" is not immediately decodable"<<endl;
			}

			arr.clear();
		}
		else
		{
			arr.push_back(a);
		}

	}
}