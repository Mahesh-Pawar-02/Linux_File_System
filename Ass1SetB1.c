#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
        int pid;
        int n, num[20], i, j, temp,key;
        printf("Enter the length of the array: ");
        scanf("%d",&n);
        //num = (int*)malloc(sizeof(int)*n);
        printf("Enter the array:\n");
        for(i = 0 ; i < n ; i++)
                scanf("%d",&num[i]);
        pid = fork();
        if(pid == 0 )
        {
                printf("Child process exucuting by bubble sort\n");
                for(i = 0 ; i < n ; i++ )
                {
                        for(j = 0 ; j < n-i-1 ; j++)
                        {
                                if(num[j] > num[j+1])
                                {
                                        temp = num[j];
                                        num[j] = num[j+1];
                                        num[j+1] = temp;
                                }
                        }
                }
                printf("The sorted array is:\n");
                for(i = 0 ; i < n ; i++)
                {
                        printf("%d ",num[i]);
                }
                printf("\n");
        }
else
{
wait(NULL);
printf("Parent process exucuting by using insertion sort\n");
               for (i = 1; i < n; i++)
    {
        key = num[i];
        j = i - 1;
         /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && num[j] > key)
        {
            num[j + 1] = num[j];
            j = j - 1;
        }
        num[j + 1] = key;
    }
                printf("The sorted array is:\n");
                for(i = 0 ; i < n ; i++)
                {
                        printf("%d ",num[i]);
                }
                printf("\n");
        }

return 0;
}
