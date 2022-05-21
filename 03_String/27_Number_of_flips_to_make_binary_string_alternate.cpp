// simple approach

int minFlips (string s){
    int cnt1 = 0; int cnt2 = 0; int n = s.length();
    for(int i=0; i<n; i++){
        if(i%2==1 and s[i]=='0'){
            cnt1++;
        }
        else if(i%2==0 and s[i]=='1'){
            cnt1++;
        }
        else if(i%2==1 and s[i]=='1'){
            cnt2++;
        }
        else if(i%2==0 and s[i]=='0'){
            cnt2++;
        }
    }
    
    return min(cnt1, cnt2);
}
