import java.util.*;
import java.io.*;

public class Main {
	private static long fly(long distance) {
		long cnt;
		long sum;
		long n = 1;
		
		while(true) {
			sum = n*n;
			if( distance <= n*n )break;
			n++;
		}
		
		if( ( sum - n + 1 ) <= distance ) cnt = 2 * n - 1;
		else cnt = 2 * ( n - 1 );
		
		return cnt;
	}
	public static void main(String[] args) throws IOException {
		int TestcaseCount=1;
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int testcase = Integer.parseInt(br.readLine());
		
		while(TestcaseCount<=testcase) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			long x = Long.parseLong(st.nextToken());
			long y = Long.parseLong(st.nextToken());
			
			System.out.println(fly(y-x));
            
			TestcaseCount++;
		}	
		br.close();
	}
}