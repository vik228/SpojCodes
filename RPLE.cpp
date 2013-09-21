#include <iostream>
#include <cstdio>
#include <set>
#define MAX 10000
using namespace std;
int main()
{
	
	int T,N,R,R1,R2;
	set < int > spy;
	set < int > person;
	set < int >::iterator it;
	set < int >::iterator it1;
	scanf ("%d",&T);
	int j = 1;
	while (T--)
	{
		scanf ("%d%d" ,&N,&R);
		for (int i = 0; i < R; i++)
		{
			scanf ("%d%d",&R1,&R2);
			//cout << R1 << R2 << "\n";
			spy.insert(R1);
			person.insert(R2);
			
		}
		#ifdef DEBUG
			for (it = spy.begin(); it != spy.end(); it++)
			{
				cout << *it << " ";
			}
			cout << "\n";
			for (it1 = person.begin(); it1 != person.end(); it1++)
				cout << *it1 << " ";
			cout << "\n";
		#endif
		bool found = false;
		for (it = spy.begin(); it != spy.end(); it++)
		{
			it1 = person.find(*it);
			if(it1 != person.end())
			{
				found = true;
				break;
			}
		}
		if(found)
		{
			printf("Scenario #%d: spied\n",j);
			j++;
		}
		else
		{
			printf("Scenario #%d: spying\n",j);
			j++;
		}
		spy.clear();
		person.clear();

		

	}
	
	return 0;

}
