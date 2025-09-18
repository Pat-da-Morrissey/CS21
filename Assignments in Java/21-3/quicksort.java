import java.util.Collections;
import java.util.Vector;

public class quicksort {
  
  private Integer mo3MinConst = 15; // Determined through experimenting
  private Integer size;

  public quicksort(Vector<Integer> A) {
    Integer p = 0;
    size = A.size();
    sort(A, p, size - 1);
  }

  public void sort(Vector<Integer> A, Integer p, Integer r) {
    if(p < r){
      Integer q = partition(A, p, r);
      sort(A, p, q - 1);
      sort(A, q + 1, r);
    }
  }

  public Integer medOf3(Vector<Integer> A, Integer front, Integer middle, Integer end) {
    if(A.get(front) >= A.get(middle) && A.get(front) <= A.get(end)) { // for the off chance that they're equal
      return front;
    }
    if(A.get(front) <= A.get(middle) && A.get(front) >= A.get(end)) {
      return front;
    }
    if(A.get(middle) >= A.get(front) && A.get(middle) <= A.get(end)) {
      return middle;
    }
    if(A.get(middle) <= A.get(front) && A.get(middle) >= A.get(end)) {
      return middle;
    }
    if(A.get(end) >= A.get(front) && A.get(end) <= A.get(middle)) {
      return end;
    }
    if(A.get(end) <= A.get(front) && A.get(end) >= A.get(middle)) {
      return end;
    }
    return 0;
  }

  public Integer partition(Vector<Integer> A, Integer left, Integer right) {
    if(right - left > mo3MinConst) {
      Integer medium = medOf3(A, left, (right+left)/2, right);
      Collections.swap(A, medium, right - 1);
    }
    Integer pivot = A.get(right);
    Integer index = left - 1;
    for(Integer scanner = left; scanner < right; ++scanner) {
      if(A.get(scanner) <= pivot) {
        index++;
        Collections.swap(A, index, scanner);
      }
    }
    Collections.swap(A, index+1, right);
    return index+1;
  }

  public void printVector(Vector<Integer> A) {
    for(Integer data : A) {
      System.out.println(String.format("%09d", data));
    }
  }

}
