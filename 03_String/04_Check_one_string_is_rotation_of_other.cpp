// the simple approach will be to concatenate 1st string with itself and then serach for the 2nd string in this combined bigger string.

bool areRotations(string str1, string str2)
{
   /* Check if sizes of two strings are same */
   if (str1.length() != str2.length()){
        return false;
   }
   string temp = str1 + str1;
   bool ans = temp.find(str2) != string::npos;
   return ans;
}

// the 2nd approach is using queues:

// 1. If the size of both the strings is not equal, then it can never be possible.

// 2. Push the original string into a queue q1.

// 3. Push the string to be checked inside another queue q2.

//  4. Keep popping q2‘s and pushing it back into it till the number of such operations are less than the size of the string.

// 5. If q2 becomes equal to q1 at any point during these operations, it is possible. Else not.

bool check_rotation(string s, string goal)
{
    if (s.size() != goal.size())
        return false;
    queue<char> q1;
    for (int i = 0; i < s.size(); i++) {
        q1.push(s[i]);
    }
    queue<char> q2;
    for (int i = 0; i < goal.size(); i++) {
        q2.push(goal[i]);
    }
    int k = goal.size();
    while (k) {
        char ch = q2.front();
        q2.pop();
        q2.push(ch);
        if (q2 == q1){
            return true;
        }
        k--;
    }
    return false;
}

// The 3rd approach will be using char indexes

// 1.Find all the positions of first character of original string in the string to be checked.

// 2.For every position found, consider it to be the starting index of the string to be checked.

// 3.Beginning from the new starting index, compare both strings and check whether they are equal or not.

// (Suppose original string to be s1,string to be checked be s2,n is length of strings and j is the position of first character of s1 in s2,

// then for i < (length of original string) ,check if s1[i]==s2[(j+1)%n). Return false if any character mismatch is found, else return true.

// 4.Repeat 3rd step for all positions found.

bool checkString(string &s1, string &s2, int indexFound, int Size)
{
    for(int i=0;i<Size;i++){
       //check whether the character is equal or not
        if(s1[i]!=s2[(indexFound+i)%Size])return false;
      // %Size keeps (indexFound+i) in bounds, since it ensures it's value is always less than Size
    }
   
     return true;
}

int main() {
     
  string s1="abcd";
  string s2="cdab";
   
  if(s1.length()!=s2.length()){
      cout<<"s2 is not a rotation on s1"<<endl;
  }
  else{
     
      vector<int> indexes; //store occurences of the first character of s1
       
      int Size = s1.length();
       
      char firstChar = s1[0];
     
     
      for(int i=0;i<Size;i++)
      {
          if(s2[i]==firstChar)
          {
            indexes.push_back(i);
          }
      }
     
 
      bool isRotation=false;
 
     // check if the strings are rotation of each other for every occurence of firstChar in s2 
      for(int idx: indexes)
      {
          isRotation = checkString( s1, s2, idx, Size);
 
          if(isRotation)
            break;
      }
 
      if(isRotation)cout<<"s2 is rotation of s1"<<endl;
      else cout<<"s2 is not a rotation of s1"<<endl;
     
    }
   
   
    return 0;
}
