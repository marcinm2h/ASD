import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {
        String inputline = null;
        int readChars = 0;

        Tree tree = new Tree();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = null;
        try {
            while ((str = br.readLine()) != null) {
                inputline = str.trim();
                String [] inputArr = inputline.split(" ");
                if(inputline.length() > 0) {
                    if (inputArr.length == 1) { //root
                        tree.addNode(inputArr[0].charAt(0), null);
                        readChars += 1;
                    } else if (inputArr.length == 2){
                        tree.addNode(inputArr[0].charAt(0), inputArr[1]);
                        readChars += 1;
                        readChars += inputArr[1].length();
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.print(tree.getLongestWord() + "\n" + readChars);
    }
}

class Node {
    Node left;
    Node right;
    char val;

    Node(Node left, Node right, char val) {
        this.left = left;
        this.right = right;
        this.val = val;
    }
}

class Tree {
    public String longestWord = "";
    public Node Root;
    public Tree() {
        this.Root = new Node(null, null, ' ');
    }
    public void addNode(char val, String pathString) {
        if (pathString == null) {
            Root.val = val;
            return;
        }

        int idx;
        int pathStringLength = pathString.length();

        Node currentNode = Root;
        for (idx = 0; idx < pathStringLength; idx++) {
            char key = pathString.charAt(idx);
            boolean isLeftKey = key == 'L';

            if (isLeftKey ? (currentNode.left == null) : (currentNode.right == null)) {
                Node node = new Node(null, null, ' ');
                if (isLeftKey) {
                    currentNode.left = node;
                } else {
                    currentNode.right = node;
                }
            }
            if (isLeftKey) {
                currentNode = currentNode.left;
            } else {
                currentNode = currentNode.right;
            }
            if (idx == (pathStringLength - 1 )) {
                currentNode.val = val;
            }
        }
    }
    private void countLongestWord(Node node, String word) {
        if (node.left != null) {
            String newWord = "";
            if (node.left.val != ' ') {
                newWord = "" + node.left.val;
            }
            newWord += word;
            countLongestWord(node.left, newWord);
        }
        if (node.right != null) {
            String newWord = "";
            if (node.right.val != ' ') {
                newWord = "" + node.right.val;
            }
            newWord += word;
            countLongestWord(node.right, newWord);
        }
        //leaf
        if (node.left == null && node.right == null) {
            if (word.compareTo(longestWord) > 0) {
                longestWord = word;
            }
        }
    }

    public String getLongestWord() {
        countLongestWord(Root, ("" + Root.val));
        return longestWord;
    }
}
