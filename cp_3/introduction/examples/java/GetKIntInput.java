package cp_3.introduction.java;

import java.util.*;


public class GetKIntInput {

    public static void main(String[] args) 
    {
        int k, ans=0, v;
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextLine()) {
            v = sc.nextInt();
            ans += v;
        }
        System.out.printf("%d\n", ans);
    }
}