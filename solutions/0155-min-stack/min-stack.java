// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//
// 	push(x) -- Push element x onto stack.
// 	pop() -- Removes the element on top of the stack.
// 	top() -- Get the top element.
// 	getMin() -- Retrieve the minimum element in the stack.
//
//
//  
//
// Example:
//
//
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> Returns -3.
// minStack.pop();
// minStack.top();      --> Returns 0.
// minStack.getMin();   --> Returns -2.
//
//
//  
//


class MinStack {
    int min = Integer.MAX_VALUE;
    Stack<Integer> S = new Stack<Integer> ();
    /** initialize your data structure here. */
    public MinStack() {
        S.clear();
        min = Integer.MAX_VALUE;
    }
    
    public void push(int x) {
        if(x <= min) {
            S.push(min);
            min = x;
        }
        S.push(x);
    }
    
    public void pop() {
        if(S.pop() == min) min = S.pop();  // 注意if中的pop()无论如何会执行一次
    }
    
    public int top() {
        return S.peek();
    }
    
    public int getMin() {
        return min;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
