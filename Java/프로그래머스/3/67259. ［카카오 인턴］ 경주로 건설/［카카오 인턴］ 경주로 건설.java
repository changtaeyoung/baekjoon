import java.util.*;

class Solution {
    
    static int[][][] visited; // 좌표, 현재 위치로 들어온 방향 (0은 시작, 1~4가 상하좌우)
    static int[] dx = {0, 0, 0, 1, -1};
    static int[] dy = {0, 1, -1, 0, 0};
    
    static void ds (int x, int y, int[][] map) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[3] - b[3]);
        pq.offer(new int[]{x, y, 0, 0}); // x, y, dir, cost
        visited[x][y][0] = 0; // cost memory
        
        while(!pq.isEmpty()) {
            int[] c = pq.poll();
            
            // 기억하고 있는 비용이 더 작으면 이 길은 필요 없다..!
            if (visited[c[0]][c[1]][c[2]] < c[3]) continue;
            
            for (int i = 1; i < 5; i++) {
                int nx = c[0] + dx[i];
                int ny = c[1] + dy[i];

                if (c[2] == 0) { // 첫 시작일 때
                    if (nx >= 0 && nx < map.length && ny >= 0 && ny < map.length && map[nx][ny] != 1) {
                        visited[nx][ny][i] = 100;
                        pq.offer(new int[]{nx, ny, i, c[3] + 100});
                    }
                }
                else { // 시작이 아닐 때
                    if (nx >= 0 && nx < map.length && ny >= 0 && ny < map.length && map[nx][ny] != 1) {
                        int newCost = c[3] + 100 + (c[2] != 0 && c[2] != i ? 500 : 0);  
                        if (newCost < visited[nx][ny][i]) {
                            visited[nx][ny][i] = newCost;
                            pq.offer(new int[]{nx, ny, i, newCost});
                        }
                    }
                }
                
            }
        }
        
    }
    
    public int solution(int[][] board) {
        visited = new int[board.length][board.length][5];
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board.length; j++) {
                Arrays.fill(visited[i][j], Integer.MAX_VALUE);
            }
        }
        
        ds (0, 0, board);
        
        int answer = Integer.MAX_VALUE;
        for (int i = 0; i < 5; i++) {
            if (answer > visited[board.length - 1][board.length - 1][i]) {
                answer = visited[board.length - 1][board.length - 1][i];
            }
        }
        
        return answer;
    }
}