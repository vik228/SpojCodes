import java.math.BigInteger;
import java.util.Scanner;
import java.io.*;
public class Main
{
	public static void main(String args[])
	{
		int T;
		Scanner s = new Scanner (System.in);
		T = s.nextInt();
		while (T > 0)
		{
			BigInteger N = new BigInteger ("0");
			BigInteger X = new BigInteger ("0");
			BigInteger X_copy = new BigInteger ("0");
			BigInteger b1 = new BigInteger ("0");
			BigInteger b2 = new BigInteger ("0");
			BigInteger b3 = new BigInteger ("0");
	
			X = s.nextBigInteger();
			N = s.nextBigInteger();
			X_copy = X;
			//System.out.println (X_copy);
			while (X.compareTo (N) == 1 || X.compareTo(N) == 0)
			{
				b1 = X.mod (N);
				X = X.divide (N);
				b3 = b3.add (X);
				X = X.add (b1);
				//System.out.println (X + ":" + N + ":" + X.compareTo(N));


			}
			//System.out.println (b3);
			System.out.println (X_copy.add (b3));
			T--;
		}
	}
}
