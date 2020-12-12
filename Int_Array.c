#include "Int_Array.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define ORIG_CAP 6
#define MAX_CAP 5000000

struct _Int_Array
{
    size_t size,
           capacity;
    int *raw;
};

Int_Array *make_empty_int_array()
{
    Int_Array *nia = (Int_Array *) malloc(sizeof(Int_Array));

    nia->size = 0;
    nia->capacity = ORIG_CAP;
    nia->raw = malloc(sizeof(int) * ORIG_CAP);
    return nia;
}

Int_Array *delete_int_array(Int_Array *ia)
{
    free(ia->raw);
    ia->raw = NULL;;
    return ia;
}

Int_Array *ia_push_back(Int_Array **ia, int n)
{
    Int_Array *temp1 = NULL;
    Int_Array *temp2 = *ia;

    if (temp2->size < temp2->capacity - 1) {
        temp2->raw[temp2->size++] = n;
    } else {
        size_t new_cap = temp2->capacity * 2;
        // let's limit the size of the array to 5 mill ints for now
        if (new_cap > MAX_CAP) {
            fprintf(stderr,
                    "ERR: Failed to push. Already at maximum capacity!");
            return *ia;
        }
        temp2->raw[temp2->size++] = n;
        temp2->capacity = new_cap;
        temp1 = realloc(temp2, new_cap * sizeof(int));
    }

    //DEBUG
    printf("\ntemp1: %p\n", temp1);
    printf("temp2: %p\n", temp2);
    printf("*ia: %p\n", *ia);
    printf("ia: %p\n\n", ia);
    //END DEBUG
   
    if (temp1) {
        *ia = temp1;
        free(temp1);
        temp1 = NULL;
    }

    return *ia;
}

int ia_pop_back(Int_Array *ia)
{
   if (ia->size > 0) {
       return ia->raw[--ia->size];
   }

   fprintf(stderr, "ERR: Empty array! Nothing to pop!\n");
   return INT_MIN;
}

int ia_back(Int_Array *ia)
{
    if (ia->size > 0) {
        return ia->raw[ia->size - 1];
    }

    fprintf(stderr, "ERR: Empty array! Add something!\n");
    return INT_MIN;
}

int ia_front(Int_Array *ia)
{
    if (ia->size > 0) {
        return ia->raw[0];
    }

    fprintf(stderr, "ERR: Empty array! Add something!\n");
    return INT_MIN;
}

int ia_at(Int_Array *ia, size_t idx)
{
    if (idx >= 0 && idx < ia->size) {
        return ia->raw[idx];
    }

    fprintf(stderr, "ERR: Out of bounds! Check your bounds!\n");
    return INT_MIN;
}

size_t ia_size(Int_Array *ia)
{
    return ia->size;
}

_bool_ ia_empty(Int_Array *ia)
{
    return ia->size == 0 ? _TRUE_ : _FALSE_;
}
