// This is the simple approach for this problem.

long long  multiplyTwoLists (Node* l1, Node* l2){
  long long a = 1000000007;
  long long ans = 0;
  long long num1 = 0 , num2 = 0;
  Node* t1 = l1, *t2=l2;
  while(t1 != NULL){
      num1 = (num1*10)%a + (long long)t1->data;
      t1 = t1->next;
  }
  
  while(t2 != NULL){
      num2 = (num2*10)%a + (long long)t2->data;
      t2 = t2->next;
  }
  
  ans = num1 * num2;
  return ans%a;
  
}
