import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] number = new int[9];
        int num, max = -1, cnt = 0;
        for(int i = 0; i < 9; i++){
            num = sc.nextInt();
            number[i] = num;
        }

        for(int i = 0; i < 9; i++){
            if(number[i] > max){
                max = number[i];
            }
        }

        for(int i = 0; i < 9; i++){
            if(number[i] == max){
                cnt = i;
            }
        }

        System.out.println(max);
        System.out.println(cnt + 1);
    }
}