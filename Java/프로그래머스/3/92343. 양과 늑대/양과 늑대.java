import java.util.*;

class Solution {
    /* 
        dfs로 가되, dfs의 true, false적용 원리가 달라져야할 듯 함. 
        양의 수와 늑대의 수를 이용하되, 그 값이 같아진다면 false. 
        바깥으로 빠져나왔을 때 그 수가 빠지고 다른 루트가 있다면 그 루트로의 검사 
    */
    
    static int[] info; // info 저장
    static boolean[] visited; // 방문 했는지 검사
    static List<List<Integer>> adj; // 인접한지 트리를 기억하기 위한 리스트
    static int ans;
    
    static void dfs(Set<Integer> candidates, int sheeps, int wolves) {
        ans = Math.max(ans, sheeps);
        
        for (int next : new ArrayList<>(candidates)) {
            Set<Integer> newCandidates = new HashSet<>(candidates);
            newCandidates.remove(next); // 지나가기 위한 현 지점 삭제
            
            visited[next] = true;
            for (int nb : adj.get(next)) { // 방문 가능 후보지들을 가져와
                if (!visited[nb]) { // 방문하지 않은 지점이라면
                    newCandidates.add(nb); // 새로운 원소 추가
                }
            }
            
            // 양인지 늑대인지에 따라 +1
            int ns = sheeps + (info[next] == 0 ? 1 : 0);
            int nw = wolves + (info[next] == 1 ? 1 : 0);
            
            if (ns > nw) { // 다음 레벨 탐색
                dfs(newCandidates, ns, nw);
            }
            
            visited[next] = false;  // 백트래킹
        }
    }
    
    public int solution(int[] infoArr, int[][] edges) {
        info = infoArr;
        visited = new boolean[info.length];
        adj = new ArrayList<>();
        for (int i = 0; i < info.length; i++) adj.add(new ArrayList<>());
        
        for (int[] e : edges) {
            adj.get(e[0]).add(e[1]);
            adj.get(e[1]).add(e[0]);
        }
        
        ans = 1;
        visited[0] = true;
        Set<Integer> initialCandidates = new HashSet<>(adj.get(0));
        dfs(initialCandidates, 1, 0);
        
        return ans;
    }
}