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
    ia->raw = NULL;
    free(ia);
    ia = NULL;
    return ia;
}

void ia_push_back(Int_Array **ia, int n)
{
    Int_Array *new_ia = NULL;
    Int_Array *copy = *ia;

    if (copy->size < copy->capacity - 1) {
        copy->raw[copy->size++] = n;
    } else {
        size_t new_cap = copy->capacity * 2;
        // let's limit the size of the array to 5 mill ints for now
        if (new_cap > MAX_CAP) {
            fprintf(stderr,
                    "ERR: Failed to push. Already at maximum capacity!");
            return;
        }
        copy->raw[copy->size++] = n;
        copy->capacity = new_cap;
        new_ia = realloc(copy, new_cap * sizeof(int));
    }
   
    if (new_ia) {
        *ia = new_ia;
    }

    return;
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
