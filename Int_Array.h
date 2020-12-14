#ifndef INT_ARRAY_H
#define INT_ARRAY_H

#include <stdlib.h>

// NOTE: most of the comments in this header file are strictly temporary and
// will either be deleted or replaced with usage notes.

// type definitions:
typedef struct _Int_Array Int_Array;
#  ifndef CUSTOM_BOOL
#  define CUSTOM_BOOL
typedef enum { _FALSE_, _TRUE_ } _bool_;
#  endif //CUSTOM_BOOL

// creation/release:
Int_Array *make_empty_int_array();
Int_Array *delete_int_array(Int_Array *);

// modifiers:
void ia_push_back(Int_Array **, int /* value to push */);
int ia_pop_back(Int_Array **);

// access:
/* All return MIN_INT on failure. My logic being that the absolute value of
   MIN_INT is MAX_INT + 1 because of 2's complement (I guess some systems might
   have double zero in 2020? Screw 'em), so we'll just steal that extra
   negative value to use as a flag to signal the value returned is not
   actually stored in the array (magic number).
   This is probably a temporary fix, I think I'm going to want to change this
   to printing a message to stderr, flushing it and exiting abnormally with
   with the message saying to use after checking with ia_size or ia_empty.
   Or even better yet create a hidden file with a single int in it that gets
   incremented every time this failure occurs and if it happens over 5000 times
   or whatever tell the user to go back to JavaScript as an Easter Egg.

   Oh yeah, pop_back, pop_front and extract also act/will act the same way
*/
int ia_back(Int_Array *);
int ia_front(Int_Array *);
int ia_at(Int_Array *, size_t /* index */);

// meta:
/* an Int_Array pointer seems to be unable to directly access the fields of
   _Int_Array from outside files, which is nice, but I want to test it
   further */
size_t ia_size(Int_Array *);
_bool_ ia_empty(Int_Array *);

// algos?:

/* roadmap:
ia_push_front
ia_pop_front
ia_insert (this and the next one can probably call push and pop for front and
           back and have special implementations for within the structure)
ia_extract (this, ia_insert and ia_push_front will be extremely expensive,
           use sparingly)
ia_begin -- return a pointer to the beginning of array
ia_end -- return a pointer to the end of the array

possible algos, ideally these would take :
ia_stable_sort
ia_unstable_sort
ia_make_set

*/

#endif // INT_ARRAY_H
