//Justin Y.
//Matrix library
//GNU License

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

struct Relations{


    int **cells;

};

void setRelations()
{

}

int cmpEqual(int A, int B)
{
    return (A == B);
}

int cmpGreaterThan(int A, int B)
{
    return (A >= B);
}


int cmpLessThan(int A, int B)
{
    return (A <= B);
}
//    char buffer[1000];
//    int count = 0;
//    double sum = 0;
//    int num;
//    fgets(buffer, sizeof buffer, stdin);
//    const char *p = buffer;
//    int n;
//    while (sscanf(p, "%d%n", &num, &n) == 1) {
//      p += n;
//      ; // do something with `num`
//      sum += num;
//      count++;
//    }
//    printf("Average %f\n", sum/count);

void getUserInput(int **A, int **B)
{


    int num1,num2;
    printf("Enter the number of elements in set A: ");
    scanf("%d",&num1);

    *A = (int*)malloc(num1 * sizeof(int));

    printf("Enter %d elements in set A: ",num1);
    for(int i=0;i<num1;i++)
    {
    scanf("%d",&(*A)[i]);
    }

    printf("Enter the number of elements in set B: ");
    scanf("%d",&num2);

    *B = (int*)malloc(num1 * sizeof(int));

    printf("Enter %d elements in set B: ",num2);
    for(int i=0; i<num2; i++)
    {
        scanf("%d",&(*B)[i]);
    }

    char *input = (char*)malloc(256);
    printf("Enter type of relation (==,<=,>=): ");
    scanf("%s",input);

    printf("debug: %s\n",input);

    if(strcmp(input,"==") == 0){
        printf("yesh!\n"); //set function pointer here monica.
    }

//    for(int i=0; i<num1;i++)
//        printf("%d",A[i]);


}

void toBinaryMatrix(int ***x, int *A, int *B, int(*cmp)(int A,int B), int **result){


    //int A[] = {1,2,3};
    //int B[] = {1,2,3};
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++){

            //use function pointer for relations

            if(cmp(A[i],B[j]))
                (*x)[i][j] = 1;

//            if(A[i] == A[j]){
//                (*x)[i][j] = 1;
//            }
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
    int *A;
    int *B;
    int (*relation)(int A,int B);

    getUserInput(&A,&B);

    for(int i=0; i<3;i++)
        printf("%d",A[i]);

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
    relation = cmpLessThan; //Get user input here monica.
    toBinaryMatrix(&x,A,B,relation,z);

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


