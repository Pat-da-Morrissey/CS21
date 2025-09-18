import java.util.Vector;
import java.util.Scanner;
import java.io.File;
import java.io.FileWriter;
import java.io.FileNotFoundException;
import java.io.IOException;

public class hash {
  Integer m;
  final double c = 0.618034;
  Vector<Vector<pair>> A = new Vector<Vector<pair>>();
  

  public hash(Integer size) {
    m = size;
    for (int i = 0; i < m; i++) { // resizes the hash table
      A.add(new Vector<pair>());
    }
  }

  public void hash_insert(Integer key, String value) {
    Integer hash_key = hash_generate(key);
    A.get(hash_key).add(new pair(key, value));
  }

  public String hash_delete(Integer key) {
    Integer hash_key = hash_generate(key);
    Integer index = find(key, hash_key);
    if(index != -1) {
      String value = A.get(hash_key).get(index).second();
      System.out.println("found index at: " + index);
      A.get(hash_key).removeElementAt(index);
      return value;
    }
    return "";
  }

  public String hash_search(Integer key) {
    Integer hash_key = hash_generate(key);
    Integer index = find(key, hash_key);
    if(index != -1) {
      return A.get(hash_key).get(index).second();
    }
    return "";
  }

  public void hash_load(String filename) {
    File fin = new File(filename);
    try {
      Scanner scanner = new Scanner(fin);
      while(scanner.hasNextLine()) {
        Integer key = scanner.nextInt();
        String value = scanner.nextLine().trim();
        hash_insert(key, value);
      }
      scanner.close();
    } catch (FileNotFoundException e) {
      System.out.println("File not found: " + filename);
    }
  }

  public void hash_save(String filename) {
    try {
      FileWriter fout = new FileWriter(filename);
      for(Integer i = 0; i < m; ++i){
        for(Integer index = 0; index < A.get(i).size(); ++i) {
          fout.write(String.format("%09d", A.get(i).get(index).first()) + " " + A.get(i).get(index).second() + "\n");
        }
      }
      fout.close();
    } catch (IOException e) {
      System.out.println("An error occurred!");
    }

  }

  public void hash_clear() {
    for(int i = 0; i < m; ++i) {
      A.get(i).clear();
    }
  }

  private Integer find(Integer key, Integer hash_key) {
    if(A.get(hash_key).size() > 0) {
      for(Integer i = 0; i < A.get(hash_key).size(); ++i) {
        if(A.get(hash_key).get(i).first() == key) {
          return i;
        }
      }
    }
    return -1;
  }

  private Integer hash_generate(Integer key) {
    return (int)(m*(key*c - (int)(key*c)));
  }
}
