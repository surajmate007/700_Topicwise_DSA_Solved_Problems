// Easiest approach is storing mapping for every character and then appending that mapping to the resultant string.


string printSequence(string s){
    unordered_map<char, string> mp;
    mp[' '] = "0";
    mp['A'] = "2"; mp['B'] = "22"; mp['C'] = "222";
    mp['D'] = "3"; mp['E'] = "33"; mp['F'] = "333";
    mp['G'] = "4"; mp['H'] = "44"; mp['I'] = "444";
    mp['J'] = "5"; mp['K'] = "55"; mp['L'] = "555";
    mp['M'] = "6"; mp['N'] = "66"; mp['O'] = "666";
    mp['P'] = "7"; mp['Q'] = "77"; mp['R'] = "777"; mp['S'] = "7777";
    mp['T'] = "8"; mp['U'] = "88"; mp['V'] = "888";
    mp['W'] = "9"; mp['X'] = "99"; mp['Y'] = "999"; mp['Z'] = "9999";
    
    string ans = "";
    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        ans += mp[ch];
    }
    
    return ans;
}

// code from reference github profile.

string printSequence(string input)
{
    string arr[] = { "2","22","222",
                    "3","33","333",
                    "4","44","444",
                    "5","55","555",
                    "6","66","666",
                    "7","77","777","7777",
                    "8","88","888",
                    "9","99","999","9999"
    };

    string output = "";

    // length of input string
    int n = input.length();
    for (int i = 0; i < n; i++)
    {
        // Checking for space
        if (input[i] == ' ')
            output = output + "0";

        else
        {
            // Calculating index for each
            // character
            int position = input[i] - 'A';
            output = output + arr[position];
        }
    }

    // Output sequence
    return output;
}

