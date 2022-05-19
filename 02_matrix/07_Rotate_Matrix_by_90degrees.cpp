// First Approach is inplace:

// Let size of row and column be 3. 
// During first iteration – 
// a[i][j] = Element at first index (leftmost corner top)= 1.
// a[j][n-1-i]= Rightmost corner top Element = 3.
// a[n-1-i][n-1-j] = Rightmost corner bottom element = 9.
// a[n-1-j][i] = Leftmost corner bottom element = 7.
// Move these elements in the clockwise direction. 
// During second iteration – 
// a[i][j] = 2.
// a[j][n-1-i] = 6.
// a[n-1-i][n-1-j] = 8.
// a[n-1-j][i] = 4. 
// Similarly, move these elements in the clockwise direction. 

void rotate90Clockwise(int a[N][N]){
 
    // Traverse each cycle
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
 
            // Swap elements of each cycle
            // in clockwise direction
            int temp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = temp;
        }
    }
}

// This approach is not changing the array into 90 degrees but it is just printing the array elements such that they are shifted 90 degrees.

void rotate90Clockwise(int arr[N][N])
{
    // printing the matrix on the basis of
    // observations made on indices.
    for (int j = 0; j < N; j++)
    {
        for (int i = N - 1; i >= 0; i--)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
}

// This approach is very elegent
// we first take transpose of given matrix and then reverse all the rows in the matrix

void rotate(int arr[N][N]){
     
    // First rotation
    // with respect to main diagonal
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < i; ++j){
            swap(arr[i][j], arr[j][i]);
        }
    }
     
    // Second rotation
    // with respect to middle column
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N / 2; ++j){
            int temp = arr[i][j];
            arr[i][j] = arr[i][N - j - 1];
            arr[i][N - j - 1] = temp;
        }
    }
}


// we can also rotate matrix by first taking transpose along secondary axis and then reversing the columns in the matrix:

void rotate(int arr[N][N]){
     
    // First rotation
    // with respect to Secondary diagonal
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N - i; j++){
            int temp = arr[i][j];
            arr[i][j] = arr[N - 1 - j][N - 1 - i];
            arr[N - 1 - j][N - 1 - i] = temp;
        }
    }
     
    // Second rotation
    // with respect to middle row
    for(int i = 0; i < N / 2; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[N - 1 - i][j];
            arr[N - 1 - i][j] = temp;
        }
    }
}
