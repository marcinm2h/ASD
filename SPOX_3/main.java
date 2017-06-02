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

        int verticesNumber = 3; //from stdinput
        Graph graph = new Graph(verticesNumber);
        graph.addEdge(0, 1);
        graph.addEdge(1, 2);
        graph.addEdge(0, 2);

        System.out.println(graph.toString());

    }
}

class Graph {
    public LinkedList<Vertex> vertices; //in order - id == position

    public Graph(int verticesNumber) {
        this.vertices = new LinkedList<>();
        for (int vertexId = 0; vertexId < verticesNumber; vertexId++) {
            addVertex(vertexId);
        }
    }

    public void addVertex(int vertexId) {
        Vertex vertex = new Vertex(vertexId);
        this.vertices.add(vertexId, vertex);
    }

    public void addEdge(int vertexId1, int vertexId2) {
        Vertex vertex1 = this.vertices.get(vertexId1);
        Vertex vertex2 = this.vertices.get(vertexId2);
        vertex1.addEdge(vertex2);
        vertex2.addEdge(vertex1);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Vertex vertex : this.vertices) {
            sb.append(vertex.toString() + " | ");
        }
        return sb.toString();
    }

}

class Vertex {
    private int id;
    private HashSet<Vertex> edges; //not in order

    public Vertex(int id) {
        this.edges = new HashSet<>();
        this.id = id;
    }

    public void addEdge(Vertex vertex) {
        this.edges.add(vertex);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("[" + this.id + "] -> ");
        for (Vertex vertex : this.edges) {
            sb.append(vertex.id + ", ");
        }
        return sb.toString();
    }
}
