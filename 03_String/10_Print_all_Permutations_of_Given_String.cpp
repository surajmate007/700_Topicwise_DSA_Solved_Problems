// This is simple approach using c++ stl function : next_permutation(str.begin(), str.end()) 

vector<string>find_permutation(string S){
		   sort(S.begin(), S.end());
		   vector<string> ans; 
		   do{
		       ans.push_back(S);
		   }while(next_permutation(S.begin(), S.end()));
		   
		   return ans;
}

