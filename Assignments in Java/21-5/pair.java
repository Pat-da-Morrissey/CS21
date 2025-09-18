

public class pair {
  Integer key;
  String value;

  public pair (Integer input_key, String input_value) {
    key = input_key;
    value = input_value;
  }

  public Integer first() {
    return key;
  }
  
  public String second() {
    return value;
  }

}
