#include<iostream>
/* math.h header file is included for abs() function */
#include<math.h>
using namespace std;

int main()
{
    int i, j, k, n;

    cout << "\nEnter the no. of equations: ";
    cin >> n;

    /* if no of equations are n then size of augmented matrix will be n*n+1. So here we are declaring 2d array 'mat' of size n+n+1 */
    float mat[n][n + 1];

    /* for n equations there will be n unknowns which will be stored in array 'res' */
    float res[n];

    cout << "\nEnter the elements of the augmented matrix: ";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            cin >> mat[i][j];
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (abs(mat[i][i]) < abs(mat[j][i]))
            {
                for (k = 0; k < n + 1; k++)
                {
                    /* swapping mat[i][k] and mat[j][k] */
                    mat[i][k] = mat[i][k] + mat[j][k];
                    mat[j][k] = mat[i][k] - mat[j][k];
                    mat[i][k] = mat[i][k] - mat[j][k];
                }
            }
        }
    }

