import java.util.Vector;

public class BinarySearchTree {
  Integer size;
  Vector<Integer> list = new Vector<>();

  public void BinarySeardhTree() {
    size = 0;
    root = null;
  }

  public void insert(Integer key) {
    Node prev = null; // temporary value but determines the location
    Node temp = root;
    while(temp != null) {  // initalizes/sets the prev
      prev = temp;
      if(key < temp.value) {
        temp = temp.left;
      } else {
        temp = temp.right;
      }
    }
    size++;
    Node input = new Node(key); // create the Node;
    input.parent = prev;
    if(prev == null) {  // creates the root
      root = input;
      return;
    }
    if(input.value < prev.value) { // picks which side input goes L or R;
      prev.left = input;
    } else {
      prev.right = input;
    }
    return;
  }

  public Boolean search(Integer key) {
    Node x = nodeLookup(key);
    if(x == null) {
      return false;
    }
    return true;
  }

  public Boolean deleteNode(Integer key) {
    Node cur = nodeLookup(key);
    Node temp;
    Node x;
    if(cur == null) {
      return false;
    }
    if(cur.left == null || cur.right == null) { // setup temp
      temp = cur;
    } else {
      temp = nodeLookup(successor(cur.value));
    }
    if(temp.left != null) { // setup x to be swapped
      x = temp.left;
    } else {
      x = temp.right;
    }
    if(x != null) {
      x.parent = temp.parent;
    }
    if(temp.parent == null) { // link over cur with x
      root = x;
    } else if (temp == temp.parent.left) {
      temp.parent.left = x;
    } else {
      temp.parent.right = x;
    }
    if(temp != cur) {
      cur.value = temp.value;
    }
    temp = null;
    return true;
  }

  public Integer predecessor(Integer key) {
    Node x = nodeLookup(key);
    if(x == null) {
      return key + 1; // if not return something that wouldn't be a predecessor
    }
    if(x.left != null) { 
      return nextSubmax(x);
    }
    Node temp = x.parent;
    while(temp != null && x == temp.left) {
      x = temp;
      temp = temp.parent;
    }
    if(temp != null) {
      return temp.value;
    }
    return key; // no predecessor
  }
  
  public Integer successor(Integer key) {
    Node x = nodeLookup(key);
    if(x == null) {
      return key - 1; // if not return something that wouldn't be a successor
    }
    if(x.right != null) {
      return nextSubmin(x);
    }
    Node temp = x.parent;
    while(temp != null && x == temp.right) {
      x = temp;
      temp = temp.parent;
    }
    if(temp != null) {
      return temp.value;
    }
    return key; // no sucessor
  }

  public Vector<Integer> inorder() {
    list.clear();
    if(size == 0) {
      return list;
    }
    Node x = root;
    inTraversal(x);
    return list;
  }

  public Vector<Integer> preorder() {
    list.clear();
    if(size == 0)
      return list;
    Node x = root;
    preTraversal(x);
    return list;
  }

  public Vector<Integer> postorder() {
    list.clear();
    if(size == 0)
      return list;
    Node x = root;
    postTraversal(x);
    return list;
  }

  public Vector<Integer> returnMin() {
    Vector<Integer> minimum = new Vector<>();
    if(size == 0) {
      return minimum;
    }
    minimum.add(min());
    return minimum;
  }

  public Vector<Integer> returnMax() {
    Vector<Integer> maximum = new Vector<>();
    if(size == 0) {
      return maximum;
    }
    maximum.add(max());
    return maximum;
  }

  private class Node {
    Integer value = 0;
    Node left;
    Node right;
    Node parent;
    Node(Integer data) {
      value = data;
      left = null;
      right = null;
      parent = null;
    }
  }

  private Node root;

  private Node nodeLookup(Integer key) {
    Node x = root;
    while(x != null && x.value != key) {
      if(key < x.value) {
        x = x.left;
      } else {
        x = x.right;
      }
    }
    return x; // return null if doesn't exist
  }

  private Integer min() {
    Node x = root;
    while(x.left != null) {
      x = x.left;
    }
    return x.value;
  }

  private Integer max() {
    Node x = root;  // could be an issue?
    while(x.right != null) {
      x = x.right;
    }
    return x.value;
  }  

  private Integer nextSubmax(Node x) {
    x = x.left;
    while(x.right != null) {
      x = x.right;
    }
    return x.value;
  }

  private Integer nextSubmin(Node x) {
    x = x.right;
    while(x.left != null) {
      x = x.left;
    }
    return x.value;
  }

  private void inTraversal(Node x) {
    if(x == null) {
      return;
    }
    inTraversal(x.left);
    list.add(x.value);
    inTraversal(x.right);
  }

  private void preTraversal(Node x) {
    if(x == null) {
      return;
    }
    list.add(x.value);
    preTraversal(x.left);
    preTraversal(x.right);
  }

  private void postTraversal(Node x) {
    if(x == null) {
      return;
    }
    postTraversal(x.left);
    postTraversal(x.right);
    list.add(x.value);
  }

}
