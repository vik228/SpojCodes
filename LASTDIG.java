import java.math.*;
import java.util.*;
public class Main
{
	public static void main(String args[])
	{
		int t;
		Scanner s = new Scanner(System.in);
		t = s.nextInt();
		
		BigInteger b1 = new BigInteger("0");
		int b2;
		BigInteger b3 = new BigInteger("0");
		BigInteger b4 = new BigInteger("10");
		while(t>0)
		{
			b1 = s.nextBigInteger();
			b2 = s.nextInt();
			b3 = b1.pow(b2);
			System.out.println(b3.mod(b4));
			t--;
		}
		s.close();
	}
}

