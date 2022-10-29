import javafx.util.Pair;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main implements Comparable<Main>{

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int vertex = scan.nextInt();
        int edge = scan.nextInt();
        ArrayList<Pair<Integer, Integer>>[] adjList = new ArrayList[vertex];
        boolean visited[] = new boolean[vertex];
        for (int i =0 ; i< vertex;i++){
            adjList[i] = new ArrayList<>();
        }
        for(int i = 0;i<edge;i++){
            int startVertex = scan.nextInt();
            int endVertex = scan.nextInt();
            int weight = scan.nextInt();
            adjList[startVertex].add(new Pair<>(weight,endVertex));
            adjList[endVertex].add(new Pair<>(weight,startVertex));
        }
        PriorityQueue<Pair<Integer,Integer>> pq = new PriorityQueue<>();
        for (Pair<Integer, Integer> p :adjList[0]){
            int w = p.getKey();
            int v = p.getValue();
            pq.add(new Pair<>(p.getKey(),p.getValue()));
        }
        int totalCost = 0;
        visited[0] = true;
        while (!pq.isEmpty()){
            Pair<Integer, Integer> top = pq.peek();
            int w = top.getKey();
            int v = top.getValue();
            pq.poll();
            totalCost+=w;
            visited[v] = true;
            for (Pair<Integer, Integer> p :adjList[v]){
                if (!visited[p.getValue()]){
                    pq.add(new Pair<>(p.getKey(),p.getValue()));
                }
            }
        }
        System.out.println(totalCost);
    }

    @Override
    public int compareTo(Main o) {
        return 0;
    }
}
/*
5 7
0 1 1
0 2 5
0 3 10
0 4 4
1 2 2
1 4 1
2 3 4
 */