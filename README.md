Electrotest linUM_06_projekt



### Versions
v0.0.1 (current)

(Note to author: version specified in readme.md, changelog.md, and in commit tag.)



### Requirements



### Overview
The program will ask for a voltage rating, circuit type and number of components and the resistance of each component. The program then returns the resulting resistance of the circuit, power, and also the closest a set of resistors from the E12-series to match the required resistance.

Programmet kan tex fråga efter spänningskälla, kopplinssätt, antal
komponenter samt värdet på varje komponent och returnera resulterande resistans, effektutveckling
samt ersättningsresistanser från E12-serien av resistorer.

#### Bibliotek 1, libresistance.so
Funktioner för att beräkna den totala resistansen för olika kopplade resistanser. 
Resistanserna kan kopplas parallellt eller i serie. 
Räknar inte på blandade kopplingar.

#### Bibliotek 2, libpower.so
P = U * I (Spänning gånger strömmen)
P = U^2 / R (Spänning i kvadrat delat i resistansen)
Funktioner för att beräkna den totala effektutvecklingen i en krets med en spänningskälla kopplad i serie med en resistans.

#### Bibliotek 3, libcomponent.so
Funktion som beräknar vilka tre seriekopplade resistorer i E12-serien som närmast ersätter den
resistans som skickas till funktionen.



#### Exempel på huvudprogram

%./electrotest
Ange spänningskälla i V: 50
Ange koppling[S | P]: S
Antal komponenter: 3
Komponent 1 i ohm: 300
Komponent 2 i ohm: 500
Komponent 3 i ohm: 598
Ersättningsresistans: 1398 ohm
Effekt: 1.78 W
Ersättningsresistanser i E12-serien kopplade i serie: 1200, 180, 18

E12 - series resistor values. Scale this by powers of 10.
10 	12 	15 	18 	22 	27
33 	39 	47 	56 	68 	82

Basically each subsequent resistor has 1.21 times greater resistance than the last.



### Installation & Running
Use the included Makefile:

make clean; make; ./electrotest



### Bugs, known Issues and missing Features

Make file does not handle the libraries properly. Use make clean; make; ./electrotest to run program after changes have been made to any files.



### Contributing

If you'd like to contribute to Electrotests's development, start by forking the GitHub repo:

https://github.com/weleoka/electrotest.git

Have a look at the known issues and missing features and take a pick or find something else that needs doing.

The best way to get your changes merged is as follows:

1. Clone your fork
2. Hack away
3. If you are adding significant new functionality, document it in the README
4. Do not change the version number, I will do that on my end
5. Push the repo up to GitHub
6. Send a pull request to [weleoka/electrotest](https://github.com/weleoka/electrotest)



### Licence
The MIT License (MIT)

Copyright (c) 2015 Group 113 at UMU linUM HT 2015



### Sources, inspiration and notes

http://www.resistorguide.com/resistor-values/

http://www.thegeekstuff.com/2011/12/c-arrays/

http://randu.org/tutorials/c/libraries.php

http://www.cs.swarthmore.edu/~newhall/unixhelp/howto_C_libraries.html