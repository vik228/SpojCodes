import java.math.*;
import java.util.*;
public class Main
{
	public static void main(String args[])
	{
		int t,n;
		Scanner s = new Scanner(System.in);
		t = s.nextInt();
		while(t>0)
		{
			n = s.nextInt();
			BigInteger res = BigInteger.ONE;
			for(int i=1;i<=n;i++)
			{
				res = res.multiply(BigInteger.valueOf(i));
			}
			System.out.println(res);
			t--;
		}
	}
}
				
			
