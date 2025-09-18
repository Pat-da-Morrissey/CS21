import java.util.Scanner;

public class main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    heap myHeap = new heap(2400000);
    
    while(scanner.hasNextInt()){
      Integer input = scanner.nextInt();
      if(input == 0) {
        System.out.println(myHeap.toString());
      } else if (input == -1) {
        System.out.println("extract min: " + myHeap.extractMin());
      } else if (input == -2) {
        pair sorted = myHeap.heapSort();
        System.out.print("sorted array: [");
        Integer[] arr = sorted.first();
        for(int i = 0; i < sorted.second(); ++i) {
          System.out.print(arr[i]);
          if(i < sorted.second() - 1) {
            System.out.print(", ");
          }
        }
        System.out.println("]");
      } else {
        System.out.println("insert: " + input);
        myHeap.heapInsert(input);
      }
    }
    scanner.close();
  }
}
