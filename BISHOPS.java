import java.math.*;
import java.util.*;
public class Main
{
	public static void main (String args[])
	{
		Scanner s1 = new Scanner(System.in);
		BigInteger b1 = new BigInteger("0");
		BigInteger b2 = new BigInteger("2");
		BigInteger b3 = new BigInteger("1");
		BigInteger result = new BigInteger("0");
		while(s1.hasNext())
		{
			b1 = s1.nextBigInteger();
			if(b1.equals(b3))
				System.out.println("1\n");
			else
			{
				System.out.println((b1.multiply(b2)).subtract(b2) + "\n");
			}
		}
	}
}
