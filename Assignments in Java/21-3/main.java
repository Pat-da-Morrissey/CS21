
import java.util.Scanner;
import java.util.Vector;


public class main {
  public static void main (String[] args) {
    Scanner scanner = new Scanner(System.in);
    Vector<Integer> data = new Vector<>();
    
    while(scanner.hasNextInt()){
      data.add(scanner.nextInt());
    }
    scanner.close();

    quicksort List = new quicksort(data);
    List.printVector(data);
  }
}