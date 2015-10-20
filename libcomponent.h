#ifndef _LIBCOMPONENT_H_
#define _LIBCOMPONENT_H_

    // Library header example from:
    // http://www.cs.swarthmore.edu/~newhall/unixhelp/howto_C_libraries.html

    // a constant definition exported by library:
    //#define MAX_FOO  20

    // a type definition exported by library:
/*    struct foo_struct {  
        int x;
        float y;
    };
    typedef struct foo_struct foo_struct;*/

    // a global variable exported by library
    // "extern" means that this is not a variable declaration, it 
    // just defines that a variable named total_foo of type int
    // exits and you can use it (its declaration is in some library source file)
    // extern int total_foo; 	



/*    En funktion som beräknar vilka tre seriekopplade resistorer i E12-serien som närmast ersätter den
    resistans som skickas med.
    
    orig_resistance är ersättningsresistansen.
    
    *res_array är en pekare till en array med 3 resistorer som ska fyllas med värden ur E12-
    serien.
    
    return är hur många resistorer ur E12-serien som behövdes för att ersätta orig_resistance Om
    inte alla 3 komponenterna behövs ska de som inte används fyllas med värdet 0. count kan
    anta värde mellan 0 och 3*/
    int e_resistance(float orig_resistance, float *res_array );





#endif
