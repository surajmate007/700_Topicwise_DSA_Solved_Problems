// very intuitive code

void insert(stack<int>& st, int a){
    if(st.empty() or st.top() <= a){
        st.push(a);
        return;
    }
    
    int b = st.top(); st.pop();
    insert(st, a);
    st.push(b);
}

void SortedStack :: sort(){
   if(s.empty()){
       return;
   }
   
   int a = s.top();
   s.pop();
   sort();
   insert(s, a);
   
}
