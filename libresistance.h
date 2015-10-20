#ifndef _LIBRESISTANCE_H_
#define _LIBRESISTANCE_H_

    // Library header example from:
    // http://www.cs.swarthmore.edu/~newhall/unixhelp/howto_C_libraries.html


    // a constant definition exported by library:
    //#define MAX_FOO3  20

    // a type definition exported by library:
/*    struct foo_struct3 {  
        int x;
        float y;
    };
    typedef struct foo_struct3 foo_struct3;*/

    // a global variable exported by library
    // "extern" means that this is not a variable declaration, it 
    // just defines that a variable named total_foo of type int
    // exits and you can use it (its declaration is in some library source file)
    //extern int total_foo3; 	


/*    Function: calc_resistance

    count: Antal komponenter

    conn: Seriellt eller parallellt kopplade komponeter [ P | S ]

    *array: En pekare på en array av komponentvärden som är lika stor som count.
    
    Värdet 0 skall returneras om något motstånd är noll vid parallellkoppling, dvs R1||R2=0, om
    R1 eller R2 är 0Ohm.
    Biblioteket får inte krascha om en "nollpekare" skickas till funktioen, dvs om array=0.
    Om argumenten är felaktiga skall funktionen returnera -1.

    Returvärdet är den resulterande resistansen*/

    float calc_resistance(int count, char conn, float *array);

    // En liten funktion för att testa biblioteket.
    int add(int a, int b);

#endif
