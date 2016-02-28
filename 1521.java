import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.RoundingMode;

/**
 * Accepted.
 * 
 * 
 * @author hong
 * 
 */
public class Main {

 private static Node[] nodes = new Node[1000];

 private static boolean[] used = new boolean[1000];

 private static int count = 0;

 static int p = 0;

 private static int getIndex(char s) {
  for (int i = 0; i < p; i++) {
   if (nodes[i].c == s) {
    return i;
   }
  }

  return -1;
 }

 /**
     * Construct the Huffman Tree.
     * 
     * @return
     */
 private static void constructHuffmanTree() {

  for (int i = 0; i < p; i++) {
   used[i] = false;
  }

  while (true) {

   // first find the min occurence for unused node, there always be such one node.
   int min = Integer.MAX_VALUE;
   int min1_index = 0;

   for (int i = 0; i < p; i++) {
    if (!used[i] && nodes[i].occur < min) {
     min = nodes[i].occur;
     min1_index = i;
    }
   }

   // use the min1_index node.
   used[min1_index] = true;

   // try to find the second min node, if this node is not found, break the while.
   int min2 = Integer.MAX_VALUE;
   int min2_index = 0;

   for (int i = 0; i < p; i++) {
    if (!used[i] && nodes[i].occur < min2) {
     min2 = nodes[i].occur;
     min2_index = i;
    }
   }

   if (min2 == Integer.MAX_VALUE) {
    break;
   }

   used[min2_index] = true;

   // construct a new Node.
   Node newNode = new Node();
   newNode.occur = nodes[min1_index].occur + nodes[min2_index].occur;
   newNode.left = nodes[min1_index];
   newNode.right = nodes[min2_index];

   nodes[p] = newNode;
   used[p] = false;
   p++;
  }
 }

 private static void travTree(Node tree, int depth) {
  if (tree != null) {

   tree.depth = depth;

   if (tree.left == null && tree.right == null) {
    // find a leaf.
    count += tree.occur * depth;
   }

   if (tree.left != null) {
    travTree(tree.left, depth + 1);
   }

   if (tree.right != null) {

    travTree(tree.right, depth + 1);
   }
  }
 }

 /**
     * @param args
     */
 public static void main(String[] args) throws Exception {
  BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));

  while (true) {
   String line = stdin.readLine().trim();

   if ("END".equals(line)) {
    break;
   }

   p = 0;

   for (int i = 0; i < line.length(); i++) {

    int index = getIndex(line.charAt(i));

    if (index == -1) {
     Node node = new Node(line.charAt(i));
     node.occur = 1;

     nodes[p] = node;
     p++;
    } else {
     nodes[index].occur++;
    }
   }

   constructHuffmanTree();

   int current = 8 * line.length();

   if (p == 1) {
    count = line.length();

    System.out.println(current + " " + count + " "
      + new BigDecimal(current * 1.0 / count).setScale(1, RoundingMode.HALF_UP));

   } else {

    count = 0;

    travTree(nodes[p - 1], 0);

    System.out.println(current + " " + count + " "
      + new BigDecimal(current * 1.0 / count).setScale(1, RoundingMode.HALF_UP));
   }

  }

 }

 static class Node {
  char c;

  int depth = 0;

  int occur;

  Node left = null;

  Node right = null;

  public Node(char c) {
   this.c = c;
  }

  public Node() {
  }

 }

}
