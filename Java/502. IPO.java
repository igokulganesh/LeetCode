import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

class Solution {
    public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        List<Project> projects = new ArrayList<>();

        for (int i = 0; i < profits.length; i++)
            projects.add(new Project(profits[i], capital[i]));

        projects.sort((a, b) -> a.capital - b.capital);

        PriorityQueue<Integer> maxProfitHeap = new PriorityQueue<>((a, b) -> b - a);

        int i = 0;
        while (k-- > 0) {
            while (i < profits.length && projects.get(i).capital <= w) {
                maxProfitHeap.add(projects.get(i).profit);
                i++;
            }

            if (maxProfitHeap.isEmpty())
                break;

            w += maxProfitHeap.poll();
        }

        return w;
    }

    public class Project {

        public int profit;
        public int capital;

        public Project(int profit, int capital) {
            this.profit = profit;
            this.capital = capital;
        }
    }
}