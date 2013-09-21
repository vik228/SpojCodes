import java.math.BigInteger;
import java.util.*;
public class IWGBS 
{
	public static void main(String args[])
	{
		int n;
		Scanner s1 = new Scanner (System.in);
		while (s1.hasNextLine())
		{
			n = s1.nextInt();
			BigInteger b1 = new BigInteger("0");
			ArrayList<BigInteger> array = new ArrayList<BigInteger>();

			array.add(new BigInteger("2"));
			array.add(new BigInteger("3"));
			for (int i = 2; i <= n; i++)
			{
				b1 = (array.get(i - 1)).add(array.get(i - 2));
				array.add(b1);
			}
			System.out.println(array.get(n - 1));
		}
	}
}
