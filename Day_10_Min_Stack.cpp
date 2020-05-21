/* Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

Methods pop, top and getMin operations will always be called on non-empty stacks. */


/* Approach - keep two stack one for numbers and another for minimum number */

// Time Complexity - O(1)
// Space Complexity - O(n), where n is total number pushed on stack.

class MinStack {
public:
    stack<int> numbers, minNumber;
    MinStack() {
        numbers = stack<int> ();
        minNumber = stack<int> ();
    }
    
    void push(int x) {
        numbers.push(x);
        if (minNumber.empty() || x < minNumber.top()) {
            minNumber.push(x);
        }
        else {
            minNumber.push(minNumber.top());
        }
    }
    
    void pop() {
        if (numbers.size()) {
            numbers.pop();
            minNumber.pop();
        }
    }
    
    int top() {
        return numbers.top();
    }
    
    int getMin() {
        return minNumber.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */