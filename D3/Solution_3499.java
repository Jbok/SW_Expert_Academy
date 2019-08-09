import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;

public class Solution_3499 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		for (int tc = 1; tc <= T; tc++) {
			int N = Integer.parseInt(br.readLine());
			
			String[] strs = br.readLine().split(" ");
			
			int mid = N%2 == 0 ? N/2 : N/2+1;
			
			
			List<String> ll = new LinkedList<String>();
			for (int i = 0; i < mid; i++) {
				ll.add(strs[i]);
			}
			
			List<String> lR = new LinkedList<String>();
			for (int i = mid; i < N; i++) {
				lR.add(strs[i]);
			}
			
			List<String> list = new LinkedList<>();
			
			if (N%2 == 0) {
				for (int i = 0; i < mid; i++) {
					list.add(ll.get(i));
					list.add(lR.get(i));
				}
			}else {
				for (int i = 0; i < mid-1; i++) {
					list.add(ll.get(i));
					list.add(lR.get(i));
				}
				list.add(ll.get(mid-1));
			}
			
			
			System.out.printf("#%d ", tc);
			for (int i = 0; i < N; i++) {
				System.out.printf("%s ", list.get(i));
			}
			System.out.println();
			
		}
	}
}
