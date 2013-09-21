import java.util.*;
import java.math.BigInteger;
public class Main
{
	public static void main(String args[])
	{
		BigInteger b1 = new BigInteger("0");
		BigInteger b2 = new BigInteger("0");
		BigInteger b3 = new BigInteger("0");
		BigInteger b4 = new BigInteger("0");
		BigInteger b5 = new BigInteger("0");
		BigInteger b6 = new BigInteger("2");
		int t = 10;
		Scanner in = new Scanner(System.in);
		while(t>0)
		{
			b1 = in.nextBigInteger();
			b2 =  in.nextBigInteger();
			b3 = b1.subtract(b2);
			b3 = b3.divide(b6);
			System.out.println(b3.add(b2) + "\n" + b3);
			t--;
		}
	}
}

			
