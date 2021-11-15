import java.io.*;
import java.util.ArrayList;
import java.util.Hashtable;
import java.util.List;
import java.util.Scanner;

/**
 * Twosum
 */
public class Twosum {
    public static void main(String[] args) throws IOException {
        Scanner inFile = new Scanner(new File("integers.txt"));

        List<Long> ints = new ArrayList<Long>();

        while (inFile.hasNextLine()) {
            ints.add(Long.parseLong(inFile.nextLine()));
        }
        inFile.close();


        Hashtable<Long, Long> table = new Hashtable<>(ints.size());

        long nT = 0;

        for (long x: ints) 
            table.put(x, 0l);

        System.out.println("STARTING EXECUTTTTION");

        for (int t = -10000; t < 10000; t++) {
            // System.out.println("Doing t: " + t);
            // for (long x: ints) { // need to assign x: t - x
            //     table.put(x, t-x);
            // }

            // System.out.println("Done finishing putting the elements in the table");
            // System.out.println("Checking the Ts...");
            // for (long x: table.keySet()) {
            //     if (table.containsKey(table.get(x))) {
            //         nT++;
            //     }
            // }
            // System.out.println("Doneee");
            // System.out.println();
            // System.out.println();

            // table.clear();
            System.out.println("T IS " + t);
            for (long x: ints) {
                if (table.containsKey(t - x)) {
                    System.out.println("YEES");
                    nT++;
                }
            }

            System.out.println();
            System.out.println();
            System.out.println();

        }

    
        System.out.println(nT);
    }
}