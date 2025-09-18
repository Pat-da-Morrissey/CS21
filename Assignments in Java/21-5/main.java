import java.util.Scanner;

public class main {
  public static void main(String[] args) {
    Integer input = -1;
    Scanner scanner = new Scanner(System.in);
    Integer hash_size = 178000; // assigned value
    hash hashTable = new hash(hash_size); 

    while(input != 7) {
      System.out.print("(1)load (2)insert (3)delete (4)search (5)clear (6)save (7)quit -- Your choice? ");
      input = scanner.nextInt();
      scanner.nextLine(); // consume the newline character
      
      if(input == 1) { // load
        System.out.print("read hash table - filename? ");
        String filename = scanner.nextLine();
        hashTable.hash_load(filename);
      }
      if(input == 2) { // insert        
        System.out.println("input new record:");
        Integer key = scanner.nextInt();
        String value = scanner.nextLine().trim();
        hashTable.hash_insert(key, value);
      }     
      if(input == 3) { // delete
        System.out.print("delete record - key? ");
        Integer key = scanner.nextInt();
        scanner.nextLine();
        String value = hashTable.hash_delete(key);
        if(value == ""){
          System.out.println("Delete not found:");
        } else {
          System.out.println("Delete: " + key + " " + value);
        }
      }
      if(input == 4) { // search
        System.out.print("Search for a record - key? ");
        Integer key = scanner.nextInt();
        scanner.nextLine();
        String value = hashTable.hash_search(key);
        if(value == "") {
          System.out.println("Search not found: " + key);
        } else {
          System.out.println("Found: " + key + " " + value);
        }
      }
      if(input == 5) { // clear
        System.out.println("clearing the hash table.");
        hashTable.hash_clear();
      }
      if(input == 6) { // save
        System.out.print("write hash table - filename? ");
        String filename = scanner.nextLine();
        hashTable.hash_save(filename);
      }
    }
    scanner.close();
  }
}
