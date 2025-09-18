

public class pair {
  Integer[] arr;
  Integer size;

  public pair (Integer[] input_arr, Integer input_size) {
    arr = input_arr;
    size = input_size;
  }

  public Integer[] first() {
    return arr;
  }
  
  public Integer second() {
    return size;
  }

}
