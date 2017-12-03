#include<iostream>
#include<string>
#include<stack>

using namespace std;

int *pos;

void ret(stack<int> *stk , int k)  //from to¬°¤è¶ô½s¸¹
{
	int tmp;
	int q=pos[k];

	for( ; !stk[ q ] .empty() && stk[ q ].top() != k ; )
	{
		tmp = stk[q].top();
		stk[q].pop();

		stk[tmp].push(tmp);

		pos[tmp] = tmp;
	}

}

void pile( stack<int> *stk , int from , int to )
{
	stack<int> tmp;
	int p = pos[from],q = pos[to];


	for( ; stk[p].top() != from  ; )
	{
		tmp.push( stk[p].top() );
		stk[p].pop();
	}

	tmp.push( stk[p].top() );
	stk[p].pop();

	for( ; !tmp.empty() ; )
	{
		stk[q].push( tmp.top() );
		pos[tmp.top()] = q;
		tmp.pop();
	}
}

int main()
{
	int n,from,to;
	stack<int> *stk;
	stack<int> tmp;
	string mv,tp;

	while(cin>>n)
	{
		stk = new stack<int>[n];
		pos = new int [n];

		for(int i = 0 ; i < n ; ++i )
		{
			stk[i].push(i);
			pos[i] = i ;
		}

		while(cin>>mv)
		{
			if(mv=="quit")	break;

			cin>>from>>tp>>to;

			if(from==to||pos[from]==pos[to])	continue;
		
			//key = key2 = false;
			if(mv=="move")
			{
				if(tp=="onto")
				{
					ret(stk,from);
					ret(stk,to);

					stk[ pos[to] ].push( stk[ pos[from] ].top() );
					stk[ pos[from] ].pop();

					pos[from] = pos[to];

				}
				if(tp=="over")
				{
					ret(stk,from);

					stk[ pos[to] ].push( stk[ pos[from] ].top() );
					stk[ pos[from] ].pop();

					pos[from] = pos[to];
				}
			}
			else	if(mv=="pile")
			{
				if(tp=="onto")
				{
					ret(stk,to);
					pile(stk,from,to);

					pos[from] = pos[to];
				}
				if(tp=="over")
				{
					pile(stk,from,to);

					pos[from] = pos[to];
				}				
			}


		}	
		for(int i = 0 ; i < n ; ++i )
		{
			cout<<i<<":";
			for( ;!stk[i].empty() ; )
			{
				tmp.push(stk[i].top());
				//cout<<" "<<stk[i].top();
				stk[i].pop();
			}

			for( ; !tmp.empty();)
			{
				cout<<" "<<tmp.top();
				tmp.pop();
			}
			cout<<endl;
		}

	/*	for(int i = 0 ; i < n ; ++i )
		{
			cout<<stk[i].top();
		}*/
		delete [] pos;

		delete [] stk;
	}
}