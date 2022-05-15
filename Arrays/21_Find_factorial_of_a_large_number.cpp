// Brute force O(n2) but giving TLE:

vector<int> factorial(int N){
        vector<int> ans;
        int p = N;
        while(p != 0){
            ans.push_back(p%10);
            p = p/10;
        }
        p=N-1;
        while(p!=1){
            int c = 0;
            for(int j=0; j<ans.size(); j++){
                int pro = ans[j] * p;
                pro += c;
                c = pro/10;
                ans[j] = pro%10;
            }
            while(c != 0){
                ans.push_back(c%10);
                c = c/10;
            }
            p--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
}


// when we start from 1 to N then we dont get TLE:

vector<int> factorial(int N){
        vector<int> ans;
        ans.push_back(1);
        int p=2;
        while(p <= N){
            int c = 0;
            for(int j=0; j<ans.size(); j++){
                int pro = ans[j] * p + c;
                c = pro/10;
                ans[j] = pro%10;
            }
            while(c != 0){
                ans.push_back(c%10);
                c = c/10;
            }
            p++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
}
