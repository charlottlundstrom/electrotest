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



--- E12 Resistors ---
E12 - series resistor values. Scale this by powers of 10.
10 	12 	15 	18 	22 	27
33 	39 	47 	56 	68 	82

Basically each subsequent resistor has 1.21 times greater resistance than the last.



### Installation & Running
Use the included Makefile:

To run the program:
make clean; make; ./electrotest

The library tests can be run by building "make libtests". The resulting libLIBNAME_test executable should return a value other than -1 if successful.

Check the dependencies of any executable with the command: ldd ./executableName

On Ubuntu system the shared object files (.so) of the three libraries seem to only work if copying to usr/lib with root privilege.  

Manually setting LD_LIBRARY_PATH to the working dir of electrotest seems to not work in Ubuntu, the dynamic shared libraries are not found. I think this is a security feature of Ubuntu. Maybe we just have to live with using sudo for this.
[Using LD_LIBRARY_PATH](http://wiredrevolution.com/system-administration/how-to-correctly-use-ld_library_path)
[LinuxForums](http://www.linuxforums.org/forum/ubuntu-linux/176983-solved-cannot-set-ld_library_path-profile-etc-profile.html)

The solution is here [cusom library paths](http://www.cyberciti.biz/faq/linux-setting-changing-library-path/)
Basically add a custom .conf file i.e: /etc/ld.so.conf.d/myapp.conf and include the full path to the directory where the shared objects reside. You'll need root privileges to write to the .conf file. Once that is done reload the linking by entering ldconfig on the command line, again root privileges are required. Now the executable should find the shared object files.

### Bugs, known Issues and missing Features

* Make file does not handle the libraries properly. Use make clean; make; ./electrotest to run program after changes have been made to any files.
* Move library header .h files to sub-directory. Use -I flag in compiler,
* .so (shared object) files are not found when in the project directory. Even if the LD_LIBRARY_PATH variable is set in the shell the library will not be found by the OS linker. The solution seems to be to cp to /usr/lib/ with root priviledges (may be an Ubuntu specific problem). "make install" will solve the problem in the production environment, but for the development version of electrotest it's better to have all files under the project directory. (see Installing & Running for more info).



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

http://www.rapidtables.com/code/linux/gcc/gcc-i.htm

http://www.resistorguide.com/resistor-values/

http://www.thegeekstuff.com/2011/12/c-arrays/

http://randu.org/tutorials/c/libraries.php

http://www.cs.swarthmore.edu/~newhall/unixhelp/howto_C_libraries.html