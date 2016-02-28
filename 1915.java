import java.io.BufferedInputStream;
import java.util.LinkedList;
import java.util.Scanner;
public class Main {

    private static int[][] directions = new int[][]{
        {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

    static void BreadthFirstSearch(int startX, int startY,
            chessNode[][] chessPanel, int size) {
        chessNode currentNode = null, nextNode = null;
        LinkedList queue = new LinkedList();
        currentNode = chessPanel[startY][startY] =
                new chessNode(startX, startY, true, 0, false);
        queue.addLast(currentNode);
        while (!queue.isEmpty()) {
            currentNode = queue.removeFirst();
            if (currentNode.isTarget()) {
                break;
            }
            for (int i = 0; i < 8; i++) {
                int x = currentNode.getX() + directions[i][0];
                int y = currentNode.getY() + directions[i][1];
                int step = currentNode.getStep();
                if (x >= 0 && x < size && y >= 0 && y < size) {
                    if (chessPanel[x][y] == null) {
                        chessPanel[x][y] = new chessNode(x, y, false, 0, false);
                    }
                    nextNode = chessPanel[x][y];
                    if (!nextNode.isVisited()) {
                        nextNode.setVisited(true);
                        nextNode.setStep(step + 1);
                        queue.addLast(nextNode);
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        int n = 0;
        int size = 0;
        int startX = 0, startY = 0, endX = 0, endY = 0;
        Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            size = scanner.nextInt();
            startX = scanner.nextInt();
            startY = scanner.nextInt();
            endX = scanner.nextInt();
            endY = scanner.nextInt();
            chessNode[][] chessPanel = new chessNode[size][size];
            chessPanel[endX][endY] = new chessNode(endX, endY, false, 0, true);
            BreadthFirstSearch(startX, startY, chessPanel, size);
            System.out.println(chessPanel[endX][endY].getStep());
        }
    }
}

class chessNode {

    private int x;
    private int y;
    private boolean visited;
    private int step;

    public int getX() {
        return x;
    }

    public chessNode(int x, int y, boolean visited, int step, boolean target) {
        this.x = x;
        this.y = y;
        this.visited = visited;
        this.step = step;
        this.target = target;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }
    private boolean target;

    public boolean isVisited() {
        return visited;
    }

    public void setVisited(boolean visited) {
        this.visited = visited;
    }

    public int getStep() {
        return step;
    }

    public void setStep(int step) {
        this.step = step;
    }

    public boolean isTarget() {
        return target;
    }

    public void setTarget(boolean target) {
        this.target = target;
    }
}


