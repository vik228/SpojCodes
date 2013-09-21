import java.math.BigInteger;
import java.util.*;
public class Main
{
	static BigInteger[] b1 = new BigInteger[152];
	static BigInteger cmp = new BigInteger ("-1");
	static BigInteger findAns (BigInteger n)
	{
		int n1 = n.intValue();
		if (!b1[n1].equals (cmp))
			return b1[n1];
		BigInteger b2 = new BigInteger ("0");
		BigInteger b3 = new BigInteger ("0");
		BigInteger sum = new BigInteger ("0");
		if (n.equals(BigInteger.ZERO))
			return BigInteger.ONE;
		for (int i = 1; i <= n1; i++)
		{
			b2 = findAns (BigInteger.valueOf (i - 1));
			b3 = findAns (n.subtract (BigInteger.valueOf (i)));
			sum = sum.add (b2.multiply(b3));

		}
		return (b1[n1] = sum);
	}
	public static void main (String args[])
	{
		//a1 = new ArrayList <BigInteger>();
		BigInteger n = new BigInteger ("0");
		//BigInteger cmp = new BigInteger ("-1");
		Scanner s = new Scanner (System.in);
		while (true)
		{
			for (int i = 0; i <= 150; i++)
			{
				b1[i] = cmp;
			}
			n = s.nextBigInteger();
			if (n.equals (cmp))
				break;
			System.out.println (findAns (n));
		}
	}
}
