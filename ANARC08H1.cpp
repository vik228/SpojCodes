#include <iostream>
using namespace std;
int main()
{
	int N,D;
	while(cin >> N >> D)
	{
		if(N == 0 or D == 0)
			break;
		else
		{
			int res = 1;
			for(int i = 2; i <= N; i++)
				res = ((res + D + -1 ) % i +1 );
			cout << N <<" " << D <<" " << res << "\n";
		}
		//cout << res << "\n";
	}
	return 0;
}
