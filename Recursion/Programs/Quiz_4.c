#include <stdio.h>
int count = 0;
fun(int n)

{

    int x = 1, k;
    count++;
    
    if (n == 1)
        return x;

    for (k = 1; k < n; ++k)

        x = x + fun(k) * fun(n - k);
        
        
    printf("%d ", x);
    return x;
}

int main()
{

    int result = fun(5);
    printf("%d ", result);
    printf("%d ", count);
}