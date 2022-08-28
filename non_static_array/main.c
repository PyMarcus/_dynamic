#include <stdio.h>
#include <stdlib.h>

#ifndef MIN
    #define MIN 0;
#endif

int size = 0;

//const int MAX = 3;

typedef struct ArrayList{
    int value;
    int store[3];
    int lenght;
    int first;
    int last;
}AL;

typedef int Integer;



int *dynamic_alloc(int vector[], int value)
 // ★ (INTEGER) receive the vector and the value
{
    size_t lenght = (sizeof(vector) / sizeof (int) + size);
    AL *pointer;
    int count = 0;
    pointer = (AL*)calloc(lenght , sizeof(int));
    if(pointer){
        for(int i = 0; i < lenght + 1;i++){
            pointer->store[i] =  vector[i];
            ++count;
        }
        pointer->store[count] = value;
        ++size;
        return pointer->store;
    }else{
        printf("There is not avaiable memory");
    }
    free(pointer);
    pointer = NULL;
    return vector;
}



int main()
{
    Integer zero = 0;
    AL *p;
    struct ArrayList array;

    p = &array;

    for(int i = 0; i < sizeof(array.store) / sizeof (int); i++)
    {
        p->store[i] = i;
        p->lenght++;
    }
    for(int i = 0; i < sizeof(array.store) / sizeof (int); i++)
    {
        printf("%d -> %d\n", i, p->store[i]);
    }
    int *vect = dynamic_alloc(p->store, 25);
    vect = dynamic_alloc(vect, 333);
    printf("Pos funcao: \n");
    for(int i = 0; i < 5; i++){
        printf("vect[%d] = %d\n", i, vect[i]);
    }
    printf("\n");
    return 0;
}
