#include <stdio.h>
#include <math.h>
 
int main(){
    int n, i, j, c, i1, j1;
    scanf("%d", &n);
    int a[n][n];
    int count[n];
    int k = sqrt(n);
    int not_row, not_col, not_box, not_sudoku = 0;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for(i = 0; i < n; i++){
        for(c = 0; c < n; c++)
            count[c] = 0;
        not_row = 0;
        for(j = 0; j < n; j++){
            if((a[i][j] > n) || (a[i][j] < 1))
                not_row = 1;
            else
                count[a[i][j] - 1]++;
        }
        for(c = 0; c < n; c++)
            if (count[c] > 1 || count[c] == 0)
                not_row = 1;
        if(not_row){
            printf("Row %d is invalid\n", i+1);
            not_sudoku = 1;
        }
    }
    
    for(i = 0; i < n; i++){
        for(c = 0; c < n; c++)
            count[c] = 0;
        not_col = 0;
        for(j = 0; j < n; j++){
            if(a[j][i] > n || a[j][i] < 1)
                not_col = 1;
            else
                count[a[j][i]-1]++;
        }
        for(c = 0; c < n; c++)
            if(count[c] > 1 || count[c] == 0)
                not_col = 1;
        if(not_col){
            printf("Column %d is invalid\n", i+1);
            not_sudoku = 1;
        }
    }
    
    int box_number = 0;
    for(i = 0; i + k - 1 < n; i += k){
        for(j = 0; j + k - 1 < n; j += k){
            not_box = 0;
            box_number++;
            for(c = 0; c < n; c++)
                count[c] = 0;
            for(i1 = 0; i1 < k; i1++){
                for(j1 = 0; j1 < k; j1++){
                    if (a[i+i1][j+j1] > n || a[i+i1][j+j1] < 1)
                        not_box = 1;
                    count[a[i+i1][j+j1]-1]++;
                }
            }
            for(c = 0; c < n; c++)
                if(count[c] > 1 || count[c] == 0)
                    not_box = 1;
            if(not_box){
                printf("Box %d is invalid\n", box_number);
                not_sudoku = 1;
            }
        }
    }
    if(!not_sudoku)
        printf("Valid Sudoku");
    return 0;
}
