// Brute force approach can be we will first store each row in set and then insert these set elements into the map.
// at last we will check whether the frequent elements in map are number of row times repeating.
// we can improve this solution by explicitely storing the element count to 1

void printCommonElements(int mat[M][N])
{
    unordered_map<int, int> mp;
 
    // initialize 1st row elements with value 1
    for (int j = 0; j < N; j++)
        mp[mat[0][j]] = 1;
 
    // traverse the matrix
    for (int i = 1; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // If element is present in the map and
            // is not duplicated in current row.
            if (mp[mat[i][j]] == i)
            {
               // we increment count of the element
               // in map by 1
                mp[mat[i][j]] = i++;
 
                // If this is last row
                if (i==M-1 && mp[mat[i][j]]==M)
                  cout << mat[i][j] << " ";
            }
        }
    }
}
