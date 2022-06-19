// This is very intuitive code similar implementation of stack using 2 queues.

void StackQueue :: push(int x){
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    s2.push(x);
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop(){
    if(!s1.empty()){
        int val = s1.top();
        s1.pop();
        return val;
    }
    return -1;
}
