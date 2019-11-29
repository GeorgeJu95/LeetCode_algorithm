// Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
// Example:
//
//
// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]
//
//


class Solution {
    public List<List<Integer>> permuteUnique(int[] nums){
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if(nums==null || nums.length==0) return res;
        boolean[] used = new boolean[nums.length];
        List<Integer> list = new ArrayList<Integer>();
        // 排序为了更好去重
        Arrays.sort(nums);
        dfs(nums, used, list, res);
        return res;
    }

    public void dfs(int[] nums, boolean[] used, List<Integer> list, List<List<Integer>> res){
        if(list.size() == nums.length) {
            res.add(new ArrayList<Integer>(list));
            return;
        }
        
        for(int i=0; i<nums.length; i++) {
            // 使用过跳过
            if(used[i]) continue;
            // 和前一个元素一样，但前一个未使用过，跳过（也就是前一个元素回溯了）
            if(i>0 && nums[i-1] == nums[i] && !used[i-1]) continue;
            
            used[i] = true;
            list.add(nums[i]);
            dfs(nums, used, list, res);
            used[i] = false;
            list.remove(list.size()-1);
        }
    }
}
