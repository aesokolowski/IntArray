#include "Int_Array.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define ORIG_CAP 5

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

void ia_push_back(Int_Array *ia, int n)
{
    if (ia->size < ia->capacity) {
        ia->raw[ia->size++] = n;
    } else {
        fprintf(stderr,
                "ERR: Capacity reached! Somebody call the programmer!\n");
        return;
    }

    // TODO: write grow helper function and plug in above else block.
    // forward declaraction should be in this .c, not in the .h,
    // and use some fancy preprocessor mangling to simulate private
    // helper functions of a C++/Java class
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

size_t ia_size(Int_Array *ia)
{
    return ia->size;
}

_bool_ ia_empty(Int_Array *ia)
{
    return ia->size == 0 ? _TRUE_ : _FALSE_;
}
