import java.util.*;
import java.math.BigInteger;
public class Main
{
	public void sieve(int primes[])
	{
		int flags[] = new int[10001];
		for (int i = 0; i <= 10000; i++)
			flags[i] = 0;
		flags[0] = flags[1] = 1;
		for (int i = 2; i*i <= 10000; i++)
		{
			for (int j = i*i; j <= 10000; j+= i)
				flags[j] = 1;
		}
		int k = 0;
		for (int i = 0; i <= 10000; i++)
		{
			if (flags[i] == 0)
				primes[k++] = i;
		}
		
	}
	public static void main(String args[])
	{
		int primes[] = new int[1229];
		Main k1 = new Main();
		k1.sieve(primes);
		/*
		for (int i = 0; i < 1229; i++)
			System.out.println(primes[i] + "\n");
		*/
		int N;
		Scanner s = new Scanner(System.in);
		N = s.nextInt();
		while (true)
		{
			if (N == 0)
				break;
			if (N == 1)
			{
				System.out.println ("1");
				N = s.nextInt();
				continue;
			}
			SortedMap <Integer,Integer> map = new TreeMap <Integer,Integer>();
			int p = 0;
			int i = 0;
			while (i < 1229 && primes[i] <= N)
			{
				int k = N;
				int count = 0;
				while (k > 0)
				{
					k/= primes[i];
					count+= k;
				}
				map.put(primes[i],count);
				i++;
				
			}
			BigInteger b1 = new BigInteger("1");
			for (Map.Entry <Integer,Integer> entry : map.entrySet())
			{
				
				
				long a1 = 2*entry.getValue() + 1;
				BigInteger b2 = BigInteger.valueOf(a1);
				//System.out.println(a1);
				//System.exit(0);
				b1 = b1.multiply(b2);
			}
			/*
		
			for (Map.Entry <Integer,Integer> entry : map.entrySet())
			{
				System.out.println (entry.getKey() + "->" + entry.getValue() + "\n");
			}
			*/
			System.out.println(b1);
		
			N = s.nextInt();

		}

		
	}
}
