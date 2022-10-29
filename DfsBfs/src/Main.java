import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int vertex = scan.nextInt();
        int edge = scan.nextInt();
        ArrayList<ArrayList<Integer>> adjList = new ArrayList<>();
        boolean visited[] = new boolean[vertex];
        for (int i = 0;i<vertex;i++){
            adjList.add(new ArrayList<Integer>());
        }
        for(int i = 0;i<edge;i++){
            int startVertex = scan.nextInt();
            int endVertex = scan.nextInt();
            adjList.get(startVertex).add(endVertex);
        }
        // dfs(2,adjList,visited);
        bfs(2,adjList,visited);
    }
    public static void dfs(int vertex, ArrayList<ArrayList<Integer>> adjList, boolean visited[]){
        visited[vertex] = true;
        System.out.print(vertex+" ");
        for (int i: adjList.get(vertex)){
            if(!visited[i]){
                dfs(i,adjList,visited);
            }
        }
    }
    public static void bfs(int vertex, ArrayList<ArrayList<Integer>> adjList, boolean visited[]){
        visited[vertex] = true;
        Queue<Integer> queue = new LinkedList<>();
        queue.add(vertex);
        while (queue.size() !=0){
            vertex = queue.poll();
            System.out.print(vertex+" ");
            Iterator<Integer> i = adjList.get(vertex).listIterator();
            while (i.hasNext()){
                int n = i.next();
                if (!visited[n]){
                    visited[n] = true;
                    queue.add(n);
                }
            }
        }
    }
}
