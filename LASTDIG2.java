import java.math.BigInteger;
import java.util.*;
public class LASTDIG2
{
	public static void main(String args[])
	{
		int t;
		BigInteger a = new BigInteger("0");
		BigInteger b = new BigInteger("0");
		BigInteger m = new BigInteger("10");
		BigInteger ans = new BigInteger("0");
		Scanner s1 = new Scanner (System.in);
		t = s1.nextInt();
		while (t > 0)
		{
			a = s1.nextBigInteger();
			b = s1.nextBigInteger();
			ans = a.modPow(b,m);
			System.out.println(ans);
			t--;

		}

	}
}
