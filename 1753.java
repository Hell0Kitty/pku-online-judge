import java.io.BufferedInputStream;   
import java.util.LinkedList;   
import java.util.Scanner;   
  
  
/*  
 * To change this template, choose Tools | Templates  
 * and open the template in the editor.  
 */  
/**  
 * poj1753  
 * 以输入的棋盘的状态做为根结点进行广搜，当找到的时候，其深度就是所求的最小步数  
 * 这个与之前做的poj1915一样。  
 * 但我刚开始，只是简单用二维数组去存储，果然效率超低，还在IDE里out of memmory  
 * 后来看到了网上的高手，为了提高搜索效率,采用位运算，把棋盘状态转换为一个16位的二进制数  
 * 于是便拿来参考参考。  
 * 在翻转的时候，  
 * 将整数的二进制某一位翻转可采用id^=(1<<x)(x代表要翻转的位置)  
 * 这个太巧妙了，还有把棋盘状态转换为ID那部分也很巧妙  
 * 第一次使用java中的位移运算，才发现位运算厉害了，不过技巧性比较强。  
 * 用得好，程序的效率会很高的。  
 * @author NC  
 */  
public class Main {   
    //用于标志是否访问过，提高效率的。   
    static boolean[] isVisited = new boolean[65536];//不能65535，小心一点   
  
    public static void main(String[] args) {   
        Scanner scan = new Scanner(new BufferedInputStream(System.in));   
        if (scan.hasNext()) {   
            int[][] chessBoard = new int[4][4];   
            for (int i = 0; i < 4; i++) {   
                String ss = scan.nextLine().trim();   
                char[] cs = ss.toCharArray();   
                for (int j = 0; j < 4; j++) {   
                    if (cs[j] == 'b') {   
                        chessBoard[i][j] = 1;//black 1   
                    } else if (cs[j] == 'w') {   
                        chessBoard[i][j] = 0;//white 0   
                    }   
                }   
            }   
            int result = bfs(chessBoard);   
            if (result == -1) {   
                System.out.println("Impossible");   
            } else {   
                System.out.println(result);   
            }   
        }   
    }   
//广搜，分16个方向   
    static int bfs(int[][] chessBoard) {   
        LinkedList<Node> queue = new LinkedList();   
        int id = chessBoardToId(chessBoard);   
        Node node = new Node(id,0);//建立根结点   
        if (isWhite(id) || isBlack(id)) {   
            return 0;   
        }   
        isVisited[id] = true;   
        queue.addLast(node);   
        while (!queue.isEmpty()) {   
            node = queue.removeFirst();   
            for (int i = 0; i < 16; i++) {   
                //16 childNode   
                Node nextNode = nextNode(node, i);   
                nextNode.addDepth();//记录深度，深度加1   
                int idid = nextNode.getChessBoardId();   
                if (!isVisited[idid]) {//没有访问过的   
                    isVisited[idid] = true;   
                    queue.addLast(nextNode);   
                }   
                if (isWhite(idid) || isBlack(idid)) {   
                    int d = nextNode.getDepth();   
                    return d;   
                }   
            }   
        }   
        return -1;   
    }   
  
    static int chessBoardToId(int[][] chessBoard) {   
        int id = 0;   
        for (int i = 0; i < chessBoard.length; i++) {   
            for (int j = 0; j < chessBoard[i].length; j++) {   
                if (chessBoard[i][j] == 1) {   
                    id++;   
                }   
                id <<= 1;//左移一位，右边自动补零   
            }   
        }   
        id >>= 1;//左移一位，只需移动15位就够了   
        return id;   
    }   
  
    //位移运算时，比如左移，左移后，低位会补零   
    static Node nextNode(Node node, int i) {   
        int id = node.getChessBoardId();   
        int depth = node.getDepth();   
        //对1左移到要翻转的位置，再按位异或就实现，目标位的翻转   
        //打印出来时，id的位数可能不够16位，因为高位为0，不过不影响   
        id ^= (1 << (15 - i));//本位翻转   
        if (i >= 4) {//如果不是在第一行，上位翻转   
            id ^= (1 << (15 - i + 4));   
        }   
        if (i <= 11) {//如果不是在最后一行，下位翻转   
            id ^= (1 << (15 - i - 4));   
        }   
        if (i % 4 > 0) {//如果不是在第一列，左位翻转   
            id ^= (1 << (15 - i + 1));   
        }   
        if ((i + 1) % 4 > 0) {//如果不是在最后一列，右位翻转   
            id ^= (1 << (15 - i - 1));   
        }   
        node = new Node(id,depth);   
        //node.setChessBoardId(id);不能这样，要重新new一个才行   
        return node;   
    }   
  
    static boolean isWhite(int chessBoardId) {   
        if (chessBoardId == 0) {   
            return true;   
        }   
        return false;   
    }   
  
    static boolean isBlack(int chessBoardId) {   
        if (chessBoardId == 0xFFFF) {//十六进制数等于65535   
            return true;   
        }   
        return false;   
    }   
}   
  
class Node {   
  
    private int chessBoardId;   
    private int depth;   
  
    public Node(int chessBoardId,int depth) {   
        this.chessBoardId = chessBoardId;   
        this.depth = depth;   
    }   
  
    public int getChessBoardId() {   
        return chessBoardId;   
    }   
  
    public void setChessBoardId(int chessBoardId) {   
        this.chessBoardId = chessBoardId;   
    }   
  
    public int getDepth() {   
        return depth;   
    }   
  
    public void addDepth() {   
        this.depth++;   
    }   
}  
