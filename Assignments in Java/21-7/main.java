import java.util.Scanner;
import java.util.Vector;

public class main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    BinarySearchTree myTree = new BinarySearchTree();
    
    while(scanner.hasNextLine()) {
      String input = scanner.nextLine();
      if(!input.startsWith("#")) {
        if(input == "min") {
          Vector<Integer> isMin = myTree.returnMin();
          if(isMin.isEmpty()) {
            System.out.println("tree isEmpty");
          } else {
            System.out.println("min is " + isMin.get(0) + ".");
          }
        } else if(input == "max") {
          Vector<Integer> isMax = myTree.returnMax();
          if(isMax.isEmpty()) {
            System.out.println("tree isEmpty");
          } else {
            System.out.println("max is " + isMax.get(0) + ".");
          }
        } else if(input == "inorder") {
          System.out.println("inorder traversal:");
          Vector<Integer> order = myTree.inorder();
          for(Integer i = 0; i < order.size(); ++i) {
            System.out.print(order.get(i));
            if(i < order.size() - 1) {
              System.out.print(" ");
            }
          }
        } else if(input == "postorder") {
          System.out.println("postorder traversal:");
          Vector<Integer> order = myTree.postorder();
          for(Integer i = 0; i < order.size(); ++i) {
            System.out.print(order.get(i));
            if(i < order.size() - 1) {
              System.out.print(" ");
            }
          }
        } else if(input == "preorder") {
          System.out.println("preorder traversal:");
          Vector<Integer> order = myTree.preorder();
          for(Integer i = 0; i < order.size(); ++i) {
            System.out.print(order.get(i));
            if(i < order.size() - 1) {
              System.out.print(" ");
            }
          }
        }
        String temp = "";
        for(int i = input.indexOf(' ') + 1; i < input.length(); ++i) {
          temp += input.charAt(i);
        }
        Integer key = Integer.valueOf(temp);
        if(input.startsWith("insert")) {
          myTree.insert(key);
          System.out.println("inserted " + key + ".");
        } else if(input.startsWith("delete")) {
          Boolean is_removed = myTree.deleteNode(key);
          if(is_removed) { // returns true if deleted
            System.out.println("deleted " + key + ".");
          } else {
            System.out.println("delete " + key + " - not found.");
          }
        } else if(input.startsWith("successor")) {
          if(myTree.successor(key) == key) { // no successor
            System.out.println("no successor for " + key + ".");
          } else if (myTree.successor(key) == key - 1) { // not in tree
            System.out.println(key + " not in tree.");

          } else { // in tree
            System.out.println(key + " successor is " + myTree.successor(key) + ".");
          }
        } else if(input.startsWith("predecessor")) {
          if(myTree.predecessor(key) == key) { // no predecessor
            System.out.println("no predecessor for " + key + ".");
          } else if (myTree.predecessor(key) == key + 1) { // not in tree
            System.out.println(key + " not in tree.");
          } else { // in tree
            System.out.println(key + " predecessor is " + myTree.predecessor(key) + ".");
          }
        }
      }
    }
  }
}
