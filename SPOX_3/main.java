package pl.edu.pjatk;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) {
//        String inputline = null;
//        int readChars = 0;
//
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        String str = null;
//        try {
//            while ((str = br.readLine()) != null) {
//                inputline = str.trim();
//                String [] inputArr = inputline.split(" ");
//            }
//        } catch (IOException e) {
//            e.printStackTrace();
//        }
//        System.out.print("ANSWER");
        PriorityQueue pq = new PriorityQueue<>();
        pq.add("TEST");
        pq.add("DRUGI");
        pq.add("TRZECI");
        System.out.println(
                pq.toString()
        );
    }
}

class Graph {
    public LinkedList<Vertex> vertices; //id == nr na liście stąd trzeba je dodawać w kolejności

    public Graph() {
        this.vertices.add(new Vertex(1));
        this.vertices.get(1);
    }

}

class Vertex {
    private int id;
    private HashSet<Vertex> edges; //particular Vertex edges

    public Vertex(int id) {
        this.id = id;
    }
}
