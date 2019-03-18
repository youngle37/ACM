class Solution {
    HashMap<Character, Character> parentheses;
    
    public Solution(){
        parentheses = new HashMap<Character, Character>();
        parentheses.put(')', '(');
        parentheses.put('}', '{');
        parentheses.put(']', '[');
    }
    
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<Character>();
        
        for(int i=0; i<s.length(); ++i){
            char c = s.charAt(i);
            if(parentheses.containsKey(c)){
                char top = stack.empty() ? '?' : stack.pop();
                if(top != parentheses.get(c))
                    return false;
            } else{
                stack.push(c);
            }
        }
        
        return stack.isEmpty();
    }
}
