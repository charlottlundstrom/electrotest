#ifndef _LIBPOWER_H_
#define _LIBPOWER_H_

    // a constant definition exported by library:
    //#define MAX_FOO2  20

    // a type definition exported by library:
/*    struct foo_struct2 {  
        int x;
        float y;
    };
    typedef struct foo_struct2 foo_struct2;*/

    // a global variable exported by library
    // "extern" means that this is not a variable declaration, it 
    // just defines that a variable named total_foo of type int
    // exits and you can use it (its declaration is in some library source file)
    // extern int total_foo2; 	

    // a function prototype for a function exported by library:
    extern int foo2(float y, float z);   // a very bad function name

#endif
