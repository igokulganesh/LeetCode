import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<List<Integer>> graph = new ArrayList<>(numCourses);
        for (int i = 0; i < numCourses; i++)
            graph.add(new ArrayList<>());

        int[] incomming = new int[numCourses];

        for (int[] req : prerequisites) {
            graph.get(req[1]).add(req[0]);
            incomming[req[0]]++;
        }

        Queue<Integer> queue = new LinkedList<>();

        for (int i = 0; i < numCourses; i++) {
            if (incomming[i] == 0)
                queue.add(i);
        }

        int[] result = new int[numCourses];
        int i = 0;
        while (!queue.isEmpty()) {
            int preCourse = queue.poll();
            result[i++] = preCourse;

            for (int course : graph.get(preCourse)) {
                if (--incomming[course] == 0)
                    queue.add(course);
            }
        }

        return numCourses == i ? result : new int[0];
    }
}