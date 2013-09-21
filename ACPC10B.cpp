#include <iostream>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
long long find_sum_of_squares (long long a)
{
	int ans = 0;
	while (a > 0)
	{
		int t = a%10;
		a/= 10;
		ans+= t*t;
	}
	return ans;
}
int main()
{
	long long A,B;
	while (scanf ("%lld%lld",&A,&B))
	{
		if (A == 0 or B == 0)
			break;
		if (A == B)
		{
			printf("%lld %lld 2\n",A,B);
			continue;
		}
		vector < long long > s1;
		vector < long long > s2;
		vector < int > s3;
		s3.push_back(58);
		s3.push_back(89);
		s3.push_back(145);
		s3.push_back(42);
		s3.push_back(20);
		s3.push_back(4);
		s3.push_back(16);
		s3.push_back(37);
		vector < long long >::iterator it,it1;
		s1.push_back(A);
		s2.push_back(B);
		long long p,q;
		p = A;
		q = B;
		bool found = false;
		if(find(s3.begin(),s3.end(),p) != s3.end() and find(s3.begin(),s3.end(),q) == s3.end())
		{
			while(true)
			{
				q = find_sum_of_squares(q);
				//cout << q << "\n";
				s2.push_back(q);
				if (q == 58 or q == 89 or q == 4 or q == 16 or q == 37 or q == 145 or q == 20 or q == 42 or q == 1)
					break;
			}
		}
		else if(find(s3.begin(),s3.end(),q) != s3.end() and find(s3.begin(),s3.end(),p) == s3.end())
		{
			while(true)
			{
				p = find_sum_of_squares(p);
				s1.push_back(p);
				if (p == 58 or p == 89 or p == 4 or p == 16 or p == 37 or p == 145 or p == 20 or p == 42 or p == 1)
					break;
			}
		}
		else
		{
			//cout << "hii\n";
			if(find(s3.begin(),s3.end(),q) == s3.end() and find(s3.begin(),s3.end(),p) == s3.end())
			{
				//cout << "bye\n";
				while(true)
				{
					p = find_sum_of_squares(p);
					//cout << p << "\n";
					s1.push_back(p);
					if (p == 58 or p == 89 or p == 4 or p == 16 or p == 37 or p == 145 or p == 20 or p == 42 or p == 1)
						break;
				}
				//cout << "******\n";
				while(true)
				{
					q = find_sum_of_squares(q);
					//cout << q << "\n";
					s2.push_back(q);
					if (q == 58 or q == 89 or q == 4 or q == 16 or q == 37 or q == 145 or q == 20 or q == 42 or q == 1)
						break;
				}
			}
		}
		long long t1 = p;
		long long t2 = q;
		if (t1 == 1 and t2 == 1)
		{
			found = true;
		}
		else if ( t1 == 1 and t2 != 1)
			found = true;
		else if ( t1 != 1 and t2 == 1)
			found = true;
		else
		{
			int countt1 = 0,countt2 =  0;
			long long n1 = t1;
			long long n2 = t2;
			while(n1 != t2)
			{
				n1 = find_sum_of_squares(n1);
				countt1++;
			}
			while(n2 != t1)
			{
				n2 = find_sum_of_squares(n2);
				countt2++;

			}
			//cout << countt1 << ":" << countt2 << "\n";
			if (countt1 <= countt2)
			{
				while(true)
				{
					p = find_sum_of_squares(p);
					s1.push_back(p);
					if (p == q)
						break;

				}
			}
			else
			{
				while(true)
				{
					q = find_sum_of_squares(q);
					s2.push_back(q);
					if (q == p)
						break;
				}
			}
		}
		
		long long count = 0;
		for (it = s1.begin(); it != s1.end(); it++)
		{
			it1 = find (s2.begin(),s2.end(),*it);
			if (it1 != s2.end())
			{
				long long i1 = it1 - s2.begin() + 1;
				long long i2 = it - s1.begin() + 1;
				//cout << i1 << "\n" << i2 << "\n";
				count = i1 + i2;
				break;
			}

		}
		if (count == 0 and found)
			printf("%lld %lld %lld\n",A,B,count);
		else
			printf("%lld %lld %lld\n",A,B,count);


	}
	return 0;


}


