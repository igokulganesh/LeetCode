
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        List<List<Integer>> graph = new ArrayList<>(numCourses);
        int[] incomming = new int[numCourses];

        for (int i = 0; i < numCourses; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] req : prerequisites) {
            graph.get(req[1]).add(req[0]);
            incomming[req[0]]++;
        }

        Queue<Integer> queue = new LinkedList<>();

        for (int i = 0; i < numCourses; i++) {
            if (incomming[i] == 0)
                queue.add(i);
        }

        while (!queue.isEmpty()) {
            int preCourse = queue.poll();

            for (int course : graph.get(preCourse)) {
                if (--incomming[course] == 0)
                    queue.add(course);
            }
        }

        for (int course : incomming)
            if (course > 0)
                return false;

        return true;
    }
}