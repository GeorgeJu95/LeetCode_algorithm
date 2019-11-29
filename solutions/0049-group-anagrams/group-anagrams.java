// Given an array of strings, group anagrams together.
//
// Example:
//
//
// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
//
// Note:
//
//
// 	All inputs will be in lowercase.
// 	The order of your output does not matter.
//
//


class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        if(strs.length == 0 || strs == null) return new ArrayList<List<String>>();
        
        HashMap<String, ArrayList<String>> map = new HashMap<String, ArrayList<String>>();
        for(int i=0; i<strs.length; ++i) {
            char[] S = strs[i].toCharArray();
            // bubbleSort(S);
            Arrays.sort(S);
            String std = new String(S);
            if(!map.containsKey(std)) map.put(std, new ArrayList<String>());
            // HashMap<key,ArrayList<Values>>
            // map.get(key)获取到的是ArrayList<Values> 这个对象。
            map.get(std).add(strs[i]);
        }
        
        return new ArrayList<List<String>>(map.values());
    }
    
    public void bubbleSort(char[] S) {
        for(int i=0; i<S.length-1; ++i) {
            for(int j=0; j<S.length-i-1; ++j) {
                if(S[j] > S[j+1]) {
                    char tmp = S[j+1];
                    S[j+1] = S[j];
                    S[j] = tmp;
                }
            }
        }
    }
}

