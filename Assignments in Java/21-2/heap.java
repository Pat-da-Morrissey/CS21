
public class heap {
  Integer[] A;
  Integer capacity;
  Integer size; // current size

  public heap(Integer init_capacity){
    capacity = init_capacity;
    A = new Integer[capacity];
    size = 0;
  }

  public pair heapSort() { // returns a pair
    Integer backup_size = size;
    Integer[] A_copy = new Integer[size];
    for(Integer i = 0; i < size; ++i) {
      A_copy[i] = A[i];
    }
    

    for(Integer i = size - 1; i >= 0; --i) {
      Integer temp = A[0];
      A[0] = A[i];
      A[i] = temp;
      size--;
      heapify(0);
    }
    Integer[] A_temp = A;
    A = A_copy;
    A_copy = A_temp;
    size = backup_size;
    pair sorted = new pair(A_copy, size);
    return sorted;
  }

  public String toString() {
    String output = "heap size ";
    output += Integer.toString(size);
    output += ": ";
    for(Integer i = 0; i < size; ++i) {
      output += Integer.toString(A[i]);
      if(i != size -1) {
        output += ", ";
      }
    }
    return output;
  }

  public Boolean heapInsert(Integer value) {
    if(!isFull()) {
      size++;
      A[size-1] = value+1;
      decreaseKey(size-1, value);
      return true;
    }
    return false;
  }

  public Boolean isEmpty() {return size == 0;}

  public Boolean isFull() {return capacity == size;}

  public Integer minimum() {
    if(isEmpty()) {
      return 0;
    }
    return A[0];
  }

  public Integer extractMin() {
    if(isEmpty()) {
      return 0;
    }
    int min = A[0];
    A[0] = A[size-1];
    size--;
    heapify(0);
    return min;
  }

  public void decreaseKey(Integer i, Integer k) {
    if(A[i] <= k || i < 0 || i > size) {
      return;
    }
    A[i] = k;
    while(i > 0 && A[parent(i)] > A[i]) {
      Integer temp = A[i];
      A[i] = A[parent(i)];
      A[parent(i)] = temp;
      i = parent(i);
    }
  }

  private Integer minOf3(Integer curr, Integer p, Integer r) {
    Integer min = curr;
    if(p < size && A[p] < A[min]) { // checks left bound
      min = p;
    }
    if(r < size && A[r] < A[min]) {
      min =  r;
    }
    return min;
  }

  private Integer left(Integer i) {return (i * 2) + 1;}
  private Integer right(Integer i) {return (i * 2) + 2;}
  private Integer parent(Integer i) {return (i - 1) / 2;}

  private void buildheap() {
    for(int i = size/2 -1; i >= 0; i--) {
      heapify(i);
    }
  }

  private void heapify(Integer i) {
    Integer n = minOf3(i, left(i), right(i));
    if(n != i) {
      Integer temp = A[i];
      A[i] = A[n];
      A[n] = temp;
      heapify(n);
    }
  }

}
