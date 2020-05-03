import java.util.*;

/**
 *
 * @author Harrison Fang
 */
public class RobotTurtles {

    static class State {
        int x, y, d, dist;
        StringBuilder path;
        State(int x, int y, int d, int dist) {
            this.x = x; this.y = y; this.d = d; this.dist = dist;
            path = new StringBuilder();
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        // Reading input.
        char[][] board = new char[8][8];
        for (int i = 0; i < 8; i++)
            board[i] = in.next().toCharArray();

        // Data structures for Dijkstra's algorithm.
        PriorityQueue<State> queue = new PriorityQueue<>(new Comparator<State>() {
            @Override
            public int compare(State s1, State s2) {
                return Integer.compare(s1.dist, s2.dist);
            }
        });
        boolean[][][] visited = new boolean[8][8][4];

        // Starting state and state transitions.
        queue.offer(new State(7, 0, 0, 0));
        visited[7][0][0] = true;

        int[][] delta = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Dijkstra's algorithm for shortest path.
        while (!queue.isEmpty()) {
            State s = queue.poll();

            // Found the diamond.
            if (board[s.x][s.y] == 'D') {
                System.out.println(s.path.toString());
                System.exit(0);
            }

            {
                // Try moving forward.
                int x = s.x + delta[s.d][0], y = s.y + delta[s.d][1], d = s.d;
                if (checkBounds(x, y) && visited[x][y][d] == false) {
                    if (board[x][y] == 'I') {   // Ice castle.
                        State ns = new State(x, y, d, s.dist + 2);
                        ns.path.append(s.path.toString()).append('X').append('F');
                        queue.offer(ns);
                        visited[x][y][d] = true;
                    } else if (board[x][y] != 'C') {    // Not a castle.
                        State ns = new State(x, y, d, s.dist + 1);
                        ns.path.append(s.path.toString()).append('F');
                        queue.offer(ns);
                        visited[x][y][d] = true;
                    }
                }
            }

            {
                // Try turning left.
                int x = s.x, y = s.y, d = (s.d + 3) % 4;
                if (visited[x][y][d] == false) {
                    State ns = new State(x, y, d, s.dist + 1);
                    ns.path.append(s.path.toString()).append('L');
                    queue.offer(ns);
                    visited[x][y][d] = true;
                }
            }

            {
                // Try turning right.
                int x = s.x, y = s.y, d = (s.d + 1) % 4;
                if (visited[x][y][d] == false) {
                    State ns = new State(x, y, d, s.dist + 1);
                    ns.path.append(s.path.toString()).append('R');
                    queue.offer(ns);
                    visited[x][y][d] = true;
                }
            }
        }

        System.out.println("no solution");
    }

    static boolean checkBounds(int x, int y) {
        return 0 <= x && x < 8 && 0 <= y && y < 8;
    }
}