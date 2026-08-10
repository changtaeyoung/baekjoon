import java.util.*;

class Solution {
    /*
        전체 0으로 map을 초기화 시킨 뒤에
        겉 라인 부분을 제외한 내부쪽만 +1씩 시키는 것은 어떤지?
        map 현재 부분이 1인지 아닌지를 판단하고, 
        1일 경우는 그냥 그대로 냅두고, 0일 경우는 +1해주는거지.
        
        그리고 기본 map 크기로 하게 된다면 이동한 거리를 제대로 측정하지 못하기 때문에 *2씩 하고
        마지막 계산에서 /2해주어야함
    */
    static boolean[][] visited;
    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {1, -1, 0, 0};
    
    static int bfs (int x, int y, int tx, int ty, int[][] map) {
        Queue<int[]> q = new ArrayDeque<>();
        q.offer(new int[]{x, y, 0});
        visited[x][y] = true;
        
        while (!q.isEmpty()) {
            int[] c = q.poll();
            
            if (c[0] == tx && c[1] == ty) return c[2];
            
            for (int i = 0; i < 4; i++) {
                int nx = c[0] + dx[i];
                int ny = c[1] + dy[i];
                
                if (nx >= 0 && nx < map.length && ny >= 0 && ny < map[0].length) {
                    if (map[nx][ny] == 1 && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        q.offer(new int[]{nx, ny, c[2] + 1});
                    }
                }
            }
        }
        return -1;
    }
    
    public int solution(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) {
        int[][] map = new int[101][101];
        visited = new boolean[101][101];
        
        for (int i = 0; i < rectangle.length; i++) {
            int sx = 2 * rectangle[i][0], sy = 2 * rectangle[i][1];
            int ex = 2 * rectangle[i][2], ey = 2 * rectangle[i][3];
            
            // 내부 사각형을 채운다
            for (int x = sx; x <= ex; x++) {
                for (int y = sy; y <= ey; y++) {
                    // 테두리일 경우 map이 이미 채워져있다면 채우지 않는 방향으로
                    // 이 생각의 근거 -> 테두리와 테두리가 만나는 부분이라면 1이어야 이동이 가능할 테니까.
                    if (x > sx && x < ex && y > sy && y < ey) {
                        map[x][y] = 2;
                    }
                    else {
                        if (map[x][y] != 2) {
                            map[x][y] = 1;
                        }
                    }
                }
            }    
        }
        
        return bfs(2*characterX, 2*characterY, 2*itemX, 2*itemY, map) / 2;
    }
}