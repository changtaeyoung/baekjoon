import java.util.*;

class Solution {
    static List<List<int[]>> courses;
    static int[] dist;
    static PriorityQueue<int[]> pq;
    static boolean[] isSummit;
    
    static void ds() {
        while(!pq.isEmpty()) {
            int[] c = pq.poll();
            
            if (dist[c[0]] < c[1]) continue;
            if (isSummit[c[0]]) continue;
            
            for (int[] next : courses.get(c[0])) {
                int nextCost = Math.max(c[1], next[1]);
                if (dist[next[0]] > nextCost) {
                    dist[next[0]] = nextCost;
                    pq.offer(new int[]{next[0], nextCost});
                }
            }
        }
    }
    
    public int[] solution(int n, int[][] paths, int[] gates, int[] summits) {
        courses = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            courses.add(new ArrayList<>());
        }
    
        for (int i = 0; i < paths.length; i++) {
            courses.get(paths[i][0]).add(new int[]{paths[i][1], paths[i][2]});
            courses.get(paths[i][1]).add(new int[]{paths[i][0], paths[i][2]});
        }
        
        dist = new int[n + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        
        pq = new PriorityQueue<>((a, b) -> Integer.compare(a[1], b[1]));
        for (int i = 0; i < gates.length; i++) {
            pq.offer(new int[]{gates[i], 0});
            dist[gates[i]] = 0;
        }
        
        isSummit = new boolean[n + 1];
        for (int i = 0; i < summits.length; i++) {
            isSummit[summits[i]] = true;
        }
        
        ds();
        
        int[] answer = {Integer.MAX_VALUE, Integer.MAX_VALUE};
        Arrays.sort(summits);
        for (int s : summits) {
            if (dist[s] < answer[1]) {
                answer[0] = s;
                answer[1] = dist[s];
            }
        }
        
        return answer;
    }
}