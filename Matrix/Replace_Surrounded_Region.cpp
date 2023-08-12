#include<iostream>
#include<vector>
using namespace std;

void change(vector<vector<char>> &matrix, int x, int y){
    matrix[x][y] = '*';
    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};

    for (int i = 0; i < 4; i++){
        int cx = dx[i] + x;
        int cy = dy[i] + y;

        if(cx>=0 && cx<matrix.size() and cy>=0 && cy<matrix[0].size() and matrix[cx][cy] == 'O')
            change(matrix, cx, cy);
    }
    

}

int main(){
    int row, col;
    cout<<"Enter no. of rows & col : ";
    cin>>row>>col;
    
    // creating matrix
    vector<vector<char>> matrix(row, vector<char>(col));
    for (int i = 0; i < row; i++)
        for(int j=0; j<col; j++)
            cin>>matrix[i][j];
    
    cout<<endl;
    

    for (int i = 0; i < row; i++)
        for(int j=0; j<col; j++)
            if(i==0 || i==row-1 || j==0 || j==col-1)
                if(matrix[i][j] == 'O'){
                    // matrix[i][j] = '*'; // convert
                    change(matrix, i, j);  // IT ALSO WORKS SAME AS ABOVE STATEMENT
                }

    for (int i = 0; i < row; i++)
        for(int j=0; j<col; j++)
            if(matrix[i][j] == 'O')
                matrix[i][j] = 'X';  // actual replacing surrounding region
    
    for (int i = 0; i < row; i++)
        for(int j=0; j<col; j++)
            if(matrix[i][j] == '*')
                matrix[i][j] = 'O';  // converting back to non surroundinng region

    for (int i = 0; i < row; i++){
        for(int j=0; j<col; j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}