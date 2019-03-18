class Solution {
    public int romanToInt(String s) {
        HashMap<Character, Integer> romanTable = new HashMap<Character, Integer>();
        
        romanTable.put('I', 1);
        romanTable.put('V', 5);
        romanTable.put('X', 10);
        romanTable.put('L', 50);
        romanTable.put('C', 100);
        romanTable.put('D', 500);
        romanTable.put('M', 1000);
        
        int sum = romanTable.get(s.charAt(s.length()-1));
        
        for(int i=s.length()-2; i>=0; --i){
            int cur = romanTable.get(s.charAt(i));
            int nextToCur = romanTable.get(s.charAt(i+1));
            sum += cur < nextToCur ? -cur : cur;
        }
        
        return sum;
    }
}
