import java.util.Scanner;
import java.util.Vector;

public class main {
  public static void main(String[] args) {
    Vector<Integer> data = new Vector<Integer>();
    Scanner scanner = new Scanner(System.in);
    
    while(scanner.hasNextInt()) {
        data.add(scanner.nextInt());
    }
    scanner.close();

    radixbucketsort sorter = new radixbucketsort();
    sorter.radixbucketsort(data);
    PrintVector(data);
  }
  public static void PrintVector(Vector<Integer> A) {
    for (Integer value : A) {
      System.out.println(String.format("%09d", value));
    }
  }
}