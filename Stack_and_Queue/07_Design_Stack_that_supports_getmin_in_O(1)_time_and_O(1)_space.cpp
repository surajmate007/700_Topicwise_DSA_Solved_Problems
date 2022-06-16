// This is thebrute force solution where we are using extra O(N) space. by using extra stack for storing the minimum elements.

stack<int> mn;

void push(stack<int>& s, int a){
    if(mn.size() == 0){
        mn.push(a);
    }
    else{
        if(a < mn.top()){
            mn.push(a);
        }
    }
	s.push(a);
}

bool isFull(stack<int>& s,int n){
	return (s.size() >= n);
}

bool isEmpty(stack<int>& s){
	return (s.size()==0);
}

int pop(stack<int>& s){
	int val = s.top();
	if(mn.top() == val){
	    mn.pop();
	}
	return val;
}

int getMin(stack<int>& s){
	return mn.top();
}


// The better approach is by storing the encrypted version of the value.
// Encryption : x = 2 * a - mn;
// Decryption : mn = 2 * mn - a;

int mn = 99999;

void push(stack<int>& s, int a){
    if(s.empty()){
        mn = a;
        s.push(a);
    }
    else{
        int x = a;
        if(a < mn){
            x = 2*a-mn;
            mn = a;
        }
        s.push(x);
    }
}

bool isFull(stack<int>& s,int n){
	return (s.size() >= n);
}

bool isEmpty(stack<int>& s){
	return (s.size()==0);
}

int pop(stack<int>& s){
	int val = s.top();
	if(val >= mn){
	    s.pop();
	}
	else{
	    int y = 2 * mn - val;
	    s.pop();
	    mn = y;
	}
	return val;
}

int getMin(stack<int>& s){
	return mn;
}
