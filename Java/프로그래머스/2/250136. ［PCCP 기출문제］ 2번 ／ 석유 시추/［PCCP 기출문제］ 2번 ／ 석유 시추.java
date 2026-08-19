import java.util.*;
class Solution {
    
    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {1, -1, 0, 0};
    static boolean[][] visited;
    static int[] oil;
    
    static void bfs(int x, int y, int[][] map) {
        Queue<int[]> q = new ArrayDeque<>();
        q.offer(new int[]{x, y});
        visited[x][y] = true;
        
        Set<Integer> oils = new HashSet<>();
        int count = 0;
        
        while (!q.isEmpty()) {
            int[] c = q.poll();
            count++;              // 이번에 꺼낸 칸도 이 덩어리의 일부니까 개수 +1
            oils.add(c[1]);       // 이 칸의 열 번호를 기록
            
            for (int i = 0; i < 4; i++) {
                int nx = c[0] + dx[i];
                int ny = c[1] + dy[i];
                
                if (nx >= 0 && nx < map.length && ny >= 0 && ny < map[0].length) {
                    if (map[nx][ny] == 1 && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        q.offer(new int[]{nx, ny});
                    }
                }
            }
        }
        
        // 덩어리 탐색이 다 끝났으니, 이제 걸쳐있던 모든 열에 이 덩어리 크기를 더해줌
        for (int col : oils) {
            oil[col] += count;
        }
    }
    
    public int solution(int[][] land) {
        visited = new boolean[land.length][land[0].length];
        oil = new int[land[0].length];
        
        for (int j = 0; j < land[0].length; j++) {
            for (int i = 0; i < land.length; i++) {
                if (land[i][j] == 1 && !visited[i][j]) {
                    bfs(i, j, land);
                }
            }
        }
        
        return Arrays.stream(oil).max().getAsInt();
    }
}