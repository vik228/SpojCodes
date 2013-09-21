import java.math.BigInteger;
import java.util.*;
public class RANJAN02
{
	public static void main(String args[])
	{
		int t,n;
		BigInteger b1 = new BigInteger("2");
		BigInteger b2 = new BigInteger("3");
		Scanner s = new Scanner(System.in);
		t = s.nextInt();
		while (t > 0)
		{
			ArrayList<BigInteger> a = new ArrayList<BigInteger>();
			n = s.nextInt();
			a.add(new BigInteger("2"));
			a.add(new BigInteger("2"));
			for (int i = 2; i <= n; i++)
			{
				a.add((a.get(i - 1).multiply(b2)).add(b1));
			}
			System.out.println(a.get(n));
			t--;
			
		}
		
	}
}

