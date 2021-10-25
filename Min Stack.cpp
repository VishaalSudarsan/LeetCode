class MinStack {
    vector<int> MinStack_vec;
    int MinElem;
public:
    MinStack() 
    {
        MinElem = INT_MAX;
    }
    
    void push(int val) 
    {
        MinStack_vec.push_back(val);
        if(val < MinElem)
            MinElem = val;
    }
    
    void pop() 
    {
        if(MinStack_vec.back() == MinElem)
        {
            MinStack_vec.pop_back();
            MinElem = *min_element(MinStack_vec.begin(), MinStack_vec.end());
        }
        else
        {
            MinStack_vec.pop_back();
        }
        if(MinStack_vec.size() == 0)
            MinElem = INT_MAX;
    }
    
    int top() 
    {
        return MinStack_vec.back();     
    }
    
    int getMin() 
    {
        return MinElem;   
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
