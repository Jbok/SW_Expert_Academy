import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Solution_2805 {
	static class Ptr{
		int r;
		int c;
		int cnt;
		
		public Ptr(int r, int c, int cnt) {
			super();
			this.r = r;
			this.c = c;
			this.cnt = cnt;
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int T = Integer.parseInt(br.readLine());
		
		for (int tc = 1; tc <= T; tc++) {
			int N = Integer.parseInt(br.readLine());
			
			int[] dR = {0, 0, 1, -1};
			int[] dC = {1, -1, 0, 0}; 
			
			String[] strs = new String[N];
			boolean[][] visit = new boolean[N][N];
			
			for (int i = 0; i < N; i++) {
				strs[i] = br.readLine();
			}
			
			int mid = N/2;
			
			Ptr start = new Ptr(mid, mid, 1);
			visit[mid][mid] = true;
			
			Queue<Ptr> q = new LinkedList<>();
			q.add(start);
			
			
			while (!q.isEmpty()) {
				Ptr now = q.poll();
				
				if (now.cnt < mid+1) {
					for (int i = 0; i < 4; i++) {
						int nextR = now.r + dR[i];
						int nextC = now.c + dC[i];
						
						if (nextR < N && nextC < N && nextR >= 0 && nextC >= 0 && !visit[nextR][nextC]) {
							visit[nextR][nextC] = true;
							q.add(new Ptr(nextR, nextC, now.cnt+1));
						}
					}
				}
			}
			
			int sum = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (visit[i][j]) {
						sum += strs[i].charAt(j)-'0';
					}
				}
			}
			System.out.printf("#%d %d\n", tc, sum);
		}
		
		
	}
}
 