#include <stdio.h>
#include <string.h>

// Function to input matrices
void inputMatrixes(int mx1[][3], int mx2[][3])
{
  printf("Input first matrix (3 x 3)\n");
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      scanf("%d", &mx1[i][j]);
    }
  }

  printf("\nInput second matrix (3 x 3)\n");
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      scanf("%d", &mx2[i][j]);
    }
  }
}

// Function to multiple the two matrices
void Multiple(int mx1[][3], int mx2[][3], int mx3[][3])
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      mx3[i][j] = 0;
      for (int k = 0; k < 3; k++)
      {
        mx3[i][j] = mx3[i][j] + mx1[i][k] * mx2[k][j];
      }
    }
  }
}

// Funtion to add the two matrices
void Addition(int mx1[][3], int mx2[][3], int mx3[][3])
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      mx3[i][j] = mx1[i][j] + mx2[i][j];
    }
  }
}

// Function to transpose the two matrices
void Transpose(int mx3[][3], int mxT[][3])
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      mxT[i][j] = mx3[j][i];
    }
  }
}

// Function to print matrices
void printMatrix(int mx3[][3])
{
  printf("\n");
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("%d ", mx3[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  // Initialize variables
  int mx1[3][3], mx2[3][3], mx3[3][3], menu;
  fflush(stdin);

  inputMatrixes(mx1, mx2);

menu:
  printf("Welcome to simple matrix computation program!\n");
  printf("\n1. Multiplication of Two Matrices\n2. Addition of Two Matrices\n3. Transpose Two Matrices\n4. Exit\nChoice: ");
  scanf("%d", &menu);

  switch (menu)
  {
  case 1:
    Multiple(mx1, mx2, mx3);
    printMatrix(mx3);
    goto menu;
    break;
  case 2:
    Addition(mx1, mx2, mx3);
    printMatrix(mx3);
    goto menu;
    break;
  case 3:
    Transpose(mx1, mx3);
    printf("\nFirst matrix transpose\n");
    printMatrix(mx3);
    Transpose(mx2, mx3);
    printf("\nSecond matrix transpose\n");
    printMatrix(mx3);
    goto menu;
    break;
  default:
    printf("\nGoodbye.\nHave a Nice Day!!\n");
    sleep(1);
    break;
  }

  return 0;
}