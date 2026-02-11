#include <stdio.h>
#define MAX 100
int QUICK(int a[], int BEG, int END)
{
  int LEFT = BEG;
  int RIGHT = END;
  int LOC = BEG;
  int temp;
  while (1)
  {
    while (a[LOC] <= a[RIGHT] && LOC != RIGHT)
      RIGHT--;

    if (LOC == RIGHT)
      return LOC;
    if (a[LOC] > a[RIGHT])
    {
      temp = a[LOC];
      a[LOC] = a[RIGHT];
      a[RIGHT] = temp;
      LOC = RIGHT;
    }
    while (a[LEFT] <= a[LOC] && LEFT != LOC)
      LEFT++;
    if (LOC == LEFT)
      return LOC;

    if (a[LEFT] > a[LOC])
    {
      temp = a[LOC];
      a[LOC] = a[LEFT];
      a[LEFT] = temp;
      LOC = LEFT;
    }
  }
}

int main()
{

  int a[MAX], LOWER[MAX], UPPER[MAX];
  int i, n;
  int BEG, END, LOC;
  int top = -1;
  printf("Enter the number of Elements ");
  scanf("%d",&n);
  printf("Enter array element : ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }

    for(i = 0; i < n; i++)
  {
    printf("%d ",a[i]);
  }
  if (n > 1)
  {

    top++;
    LOWER[top] = 0;
    UPPER[top] = n - 1;
  }
  while (top != -1)
  {
    BEG = LOWER[top];
    END = UPPER[top];
    top--;

    LOC = QUICK(a, BEG, END);
    if (BEG < LOC - 1)
    {
      top++;
      LOWER[top] = BEG;
      UPPER[top] = LOC - 1;
    }
    if (LOC + 1 < END)
    {
      top++;
      LOWER[top] = LOC + 1;
      UPPER[top] = END;
    }
  }
  printf("\nsorted array:\n");
  for(i = 0; i < n; i++)
  {
    printf("%d ",a[i]);
  }
  return 0;
}
