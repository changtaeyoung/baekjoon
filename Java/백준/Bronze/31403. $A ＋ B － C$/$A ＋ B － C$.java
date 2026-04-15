import java.util.*;

public class Main {
    public static void main(String[] args) {
        int a,b,c, sum;
        String s_a,s_b,s_sum;
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();

        s_a = Integer.toString(a);
        s_b = Integer.toString(b);
        s_sum = s_a + s_b;
        sum = Integer.parseInt(s_sum);
        sum = sum - c;
        s_sum = Integer.toString(sum);

        System.out.println(a+b-c);
        System.out.println(s_sum);

    }
}