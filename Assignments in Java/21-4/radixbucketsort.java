import java.util.Vector;

public class radixbucketsort {
  public void radixbucketsort(Vector<Integer> A) {
    Integer n = A.size();
    Integer d = 9;
    Integer k = 10;

    Vector<Vector<Integer>> Bay = new Vector<Vector<Integer>>();  // The buckets go into the bay
    for (int i = 0; i < k; i++) {
      Bay.add(new Vector<Integer>());
    }
    for(Integer i = 1; i <= d; i++) {
      for(Integer j = 0; j < n; j++) {
        Integer r = (A.get(j) / (int) Math.pow(10, i - 1)) % 10; // Get the digit at position i
        Bay.get(r).add(A.get(j));
      }
      A.clear();
      for(Integer b = 0; b < k; ++b) {
        for(Integer p = 0; p < Bay.get(b).size(); ++p) {
          A.add(Bay.get(b).get(p));
        }
        Bay.get(b).clear();
      }
    }
  }
}