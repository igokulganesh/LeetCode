
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class RandomizedSet {

    private final Map<Integer, Integer> map;
    private final List<Integer> list;

    public RandomizedSet() {
        this.map = new HashMap<>();
        this.list = new ArrayList<>();
    }

    public boolean insert(int val) {
        if (map.containsKey(val))
            return false;

        map.put(val, list.size());
        list.add(val);

        return true;
    }

    public boolean remove(int val) {
        if (!map.containsKey(val))
            return false;

        int index = map.get(val);
        int lastVal = list.getLast();

        list.set(index, lastVal);
        list.removeLast();

        map.put(lastVal, index);
        map.remove(val);

        return true;
    }

    public int getRandom() {
        int rand = ((int) Math.floor(Math.random() * 100)) % list.size();

        return list.get(rand);
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
