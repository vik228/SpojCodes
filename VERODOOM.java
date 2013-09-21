import java.math.BigInteger;
import java.util.*;
import java.io.*;
public class VERODOOM
{
	public static void main(String args[])
	{
		int T;
		int  N;
		Scanner s = new Scanner (System.in);
		T = s.nextInt();
		while (T>0)
		{
			N = s.nextInt();
			Long a1 = (long)N*N;
			Integer a2 = 3*N;
			Integer a3 = N;
			BigInteger b1 = BigInteger.valueOf(a1.longValue());
			BigInteger b2 = BigInteger.valueOf(a2.intValue());
			BigInteger b3 = new BigInteger ("2");
			BigInteger b4 = BigInteger.valueOf(a3.intValue());
			System.out.println ((((b1.add(b2)).add(b3)).multiply(b4)).divide(b3));
			T--;
		}

	}

}
