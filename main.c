#include <stdio.h>

struct Relations{


    int **cells;

};

void setRelations()
{

}

void toBinaryMatrix(int ***x, int **result){


    int A[] = {1,2,3};
    int B[] = {1,2,3};
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++){

            //use function pointer for relations
            if(A[i] == A[j]){
                (*x)[i][j] = 1;
            }
            else{
                printf("A: %d %d\n",A[i],A[j]);
                (*x)[i][j] = 0;
            }
        }
     }

}

int reflexive(int **matrix, int matrixOrder) {
    int i;

    for (i = 0; i < matrixOrder; i++) {
        if (matrix[i][i] == 0) {
            break;
        }
    }

    if (i < matrixOrder) {
        return 0;
    }
    return 1;
}


int main(void)
{
    int A[] = {1,2,3};
    int B[] = {1,2,3};

    int **x;
    int dim = 3;
    int dim2 = 3;
    x = (int **)malloc(dim*sizeof(int*));
    for(int i=0; i<dim; i++){
        x[i] = (int*)malloc(dim2 * sizeof(int));
    }
    //{(1,1),(1,2),(1,3)}
//    x[0][0] = 1;
//    x[0][1] = 1;
//    x[1][0] = 1;
//    x[1][1] = 2;
//    x[2][0] = 1;
//    x[2][1] = 3;


//   for(int i=0; i<3; i++)
//   {
//       for(int j=0; j<3; j++){

//           //use function pointer for relations
//           if(A[i] <= A[j]){
//               x[i][j] = 1;
//           }
//           else{
//               printf("A: %d %d\n",A[i],A[j]);
//               x[i][j] = 0;
//           }
//       }
//    }
    int **z;
    toBinaryMatrix(&x,z);

   for(int i=0; i<3; i++){
       for(int j=0; j<3; j++)
           printf("%d ", x[i][j]);
       printf("\n");
   }

   printf("%d\n", reflexive(x,3));

    int y[] = {1,1,1,2,1,3};
//    for(int i=0; i<3; i++)
//    {
//        printf("(");
//        for(int j=0; j<2; j++)
//        {
//            if(j%2 == 2-1)
//                printf(",");
//            printf("%d",x[i][j]);
//        }

//        printf(")");
//    }

    for(int i=0; i<3;){
        for(int j=0; j<2; j++){
            printf("(%d,%d)",y[i],y[i++]);
        }
    }



    return 0;
}


