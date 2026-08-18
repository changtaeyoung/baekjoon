import java.util.*;

class Solution {
    /*
        (1,4)라면 2,3에서 요격해야한다는 거 같음. -> 자연수가 아니여도 되네. 그 사이기만 하면
        겹치는 곳들을 구해야하는데 어떻게 구해야할까?
        시작 지점으로 정렬한다? 아니면 끝지점? + 그리디 방식을 적용한다? 
        (1,4)
        (3,7)
        (4,5)
        (4,8) 
        (5,12)
        (10,14)
        (11,13)
        
        50만개의 입력이 있으니, 2중 반복은 절대 안될거 같고. n 또는 nlogn까지 가능할 거 같기도 함.
        그 감시카메라 문제처럼, 마지막 요격 지점을 고르고, 시작지점이 그보다 작은 것은 뛰어넘는거지.
        마지막 요격 지점은 마지막 시점에서 - 0.1하면 되지 않을까 싶음.
        
        틀렸다는디..근데 55 걸리는거 보니까 그리디 시간 초과 날수도 있겠다 싶은데 (로직이 틀린걸수도)
        DP인건가?
    */
    public int solution(int[][] targets) {
        int answer = 1;
        Arrays.sort(targets, (a, b) -> {
            if (a[1] == b[1]) {
                return Integer.compare(a[0], b[0]);
            }
            else {
                return Integer.compare(a[1], b[1]);
            }
        });
        
        double dest = targets[0][1] - 0.1;
        for (int i = 1; i < targets.length; i++) {
            if (dest > targets[i][0]) { // 다음 미사일 시작 지점이 얘보다 작으면
                continue; // 이 요격 시스템 1개로 충분하니까 다음으로 넘어가면 댐
            }
            else if (dest < targets[i][0]) { // 다음 미사일 시작 지점이 얘보다 크면
                // dest 갱신해야지
                dest = targets[i][1] - 0.1;
                answer++;
            }
        }
        return answer;
    }
}