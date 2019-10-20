# Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
#
#
# 	push(x) -- Push element x onto stack.
# 	pop() -- Removes the element on top of the stack.
# 	top() -- Get the top element.
# 	getMin() -- Retrieve the minimum element in the stack.
#
#
#  
#
# Example:
#
#
# MinStack minStack = new MinStack();
# minStack.push(-2);
# minStack.push(0);
# minStack.push(-3);
# minStack.getMin();   --> Returns -3.
# minStack.pop();
# minStack.top();      --> Returns 0.
# minStack.getMin();   --> Returns -2.
#
#
#  
#


class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.min = float('inf')     # 正无穷大
        self.stack = []             

    def push(self, x: int) -> None:
        self.stack.append(x - self.min)    # 用该方式记录下前一个最小值
        if x < self.min:
            self.min = x

    def pop(self) -> None:
        if not self.stack:
            return
        tmp = self.stack.pop()
        if tmp < 0:               # 小于0，肯定是最小值
            self.min -= tmp       # 更新最小值为“上一个最小值”

    def top(self) -> int:
        if not self.stack:
            return
        tmp = self.stack[-1]
        if tmp < 0:
            return self.min        # 小于0肯定是最小值，直接返回
        else:                      
            return self.min + tmp  # 还原

    def getMin(self) -> int:
        return self.min

        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
