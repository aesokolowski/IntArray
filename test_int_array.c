#include "Int_Array.h"
#include <limits.h>
#include <stdio.h>

int main()
{
    printf("Let's try to make a bounded array of integers!\n");

    Int_Array *my_ia = make_empty_int_array();

    printf("...my_ia created, now let's try to see it's address.\n");

    printf("my_ia: ");
    if (my_ia) {
        printf("%p\n", my_ia);
    } else {
        printf("NULL\n");
    }

    printf("Just for fun let's see what happens if we try to peek at the back of an empty\narray: ");
    fflush(stdout);
    
    int int_0 = ia_back(my_ia);

    // consider this a hacky try/catch, INT_MIN signifies error:
    if (int_0 != INT_MIN) {
        printf("ia_back(my_ia): %d\n", int_0);
    } // else do nothing, error was already printed to stderr within back()

    printf("Same with the front: ");
    fflush(stdout);

    int_0 = ia_front(my_ia);

    if (int_0 != INT_MIN) {
        printf("ia_front(my_ia): %d\n", int_0);
    } // else do nothing -- from now on I'm going to use ia_empty to make sure
      // I'm not doing anything crazy

    printf("Let's make sure ia_empty returns true (really 0 or 1 with a conditional\nto print true or false but I digress):\n%s\n",
            ia_empty(my_ia) ? "true" : "false");

    printf("Cool beans, now let's add six values {1, 200, 3000, -4, -50, -60000}\n");

    ia_push_back(&my_ia, 1);
    ia_push_back(&my_ia, 200);
    ia_push_back(&my_ia, 3000);
    ia_push_back(&my_ia, -4);
    ia_push_back(&my_ia, -50);
    ia_push_back(&my_ia, -6000);

    printf("Hit a snag here with the pointers so let's take a peek: %p\n",
            my_ia);

    printf("Let's take another look at the back:\n");

    if (!(ia_empty(my_ia))) {
        printf("ia_back(my_ia): %d\n", ia_back(my_ia));
    }

    printf("...and anther look at the front:\n");

    if (!(ia_empty(my_ia))) {
        printf("ia_front(my_ia): %d\n", ia_front(my_ia));
    }

    printf("What's the size?: %zu\n", ia_size(my_ia));
    printf("Is it empty?: %s\n", ia_empty(my_ia) == _TRUE_ ? "true" :
            "false");

    printf("Now let's pop the back off:\n");

    if (!(ia_empty(my_ia))) {
        printf("ia_pop_back(my_ia): %d\n", ia_pop_back(&my_ia));
    }

    printf("Nice, nice, now let's get the back and size again:\n");

    if (!(ia_empty(my_ia))) {
        printf("ia_back(my_ia): %d\n", ia_back(my_ia));
    }
 
    printf("ia_size(my_ia): %zu\n", ia_size(my_ia));

    printf("now let's loop and print every single element using ia_at(my_ia, i):\n");

    for (size_t i = 0; i < ia_size(my_ia); i++) {
        printf("%d   ", ia_at(my_ia, i));
        if (i == ia_size(my_ia) - 1) {
            printf("\n");
        }
    }

    printf("just for fun let's see what happens when we try to peek at something out of\nbounds: ");
    fflush(stdout);
    
    int_0 = ia_at(my_ia, -1);
    if (int_0 != INT_MIN) {
        // currently unreachable
        printf("%d\n", int_0);
    }

    printf("let's add another umm... 100 items to see if it still works...\n");

    for (int i = 0; i < 100; i++) {
        ia_push_back(&my_ia, i * 117);
        printf("%zu ", ia_size(my_ia));
    }

    printf("\nsize: %zu\n", ia_size(my_ia));

    printf("...now let's try deleting it...\n");
    printf("address before delete: %p\n", my_ia);
    my_ia = delete_int_array(my_ia);

    if (!my_ia) {
        printf("Deletion succesful\n");
    } else {
        printf("Deletion failed\n");
    }

    return 0;
}
