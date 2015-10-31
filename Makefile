# Make file does not handle the libraries properly yet.
# Use:
# make clean; make; ./electrotest
# to run program after changes have been made to any files.

# Which compiler
CC = gcc

# Where to install
# The default GNU loader, ld.so, looks for libraries in the following order:
#   It looks in the DT_RPATH section of the executable, unless there is a DT_RUNPATH section.
#   It looks in LD_LIBRARY_PATH. This is skipped if the executable is setuid/setgid for security reasons.
#   It looks in the DT_RUNPATH section of the executable unless the setuid/setgid bits are set (for security reasons).
#   It looks in the cache file /etc/ld/so/cache (disabled with the ‘-z nodeflib’ linker option).
#   It looks in the default directories /lib then /usr/lib (disabled with the ‘-z nodeflib’ linker option).
INSTDIR = /usr/local/bin
LIBINSTDIR = /usr/lib

# Local Libraries
# MYLIB = 

# Where are include files kept
# INCLUDE =

# All the source files which electrotest depends on.
FILES = main.c libresistance.so libpower.so libcomponent.so

# Options for development
# -Wall enables all compiler's warning messages.
# CFLAGS = -g -Wall
CFLAGS = -fPIC -Wall
# Options for release
# CFLAGS = -O -Wall –ansi


all: electrotest


## LIBRARY
lib: libresistance.so libcomponent.so libpower.so

# Developers: add dependencies for the other tests when they are ready.
libtests: libresistance_test libpower_test

electrotest: $(FILES)
	$(CC) $(CFLAGS) main.c -L. -lpower -lresistance -lcomponent -o electrotest -Wl,-rpath,.



### LIBRESISTANCE
libresistance_test: libresistance.c libresistance.so
	$(CC) $(CFLAGS) libresistance_test.c -L. -lresistance -o libresistance_test

libresistance.so: libresistance.c
	$(CC) $(CFLAGS) -c libresistance.c -o libresistance.o;
	$(CC) -shared -o libresistance.so libresistance.o


### LIBPOWER
libpower_test: calc_power_r.c calc_power_i.c libpower.so
	$(CC) $(CFLAGS) libpower_test.c -L. -lpower -o libpower_test

libpower.so:  calc_power_r.c calc_power_i.c
	$(CC) $(CFLAGS) -c calc_power_r.c -o calc_power_r.o;
	$(CC) $(CFLAGS) -c calc_power_i.c -o calc_power_i.o;
	$(CC) -shared -o libpower.so calc_power_r.o calc_power_i.o


### LIBCOMPONENT
libcomponent_test: libcomponent.so
	$(CC) $(CFLAGS) libcomponent_test.c -L. -lcomponent -o libcomponent_test

libcomponent.so: libcomponent.c
	$(CC) $(CFLAGS) -c libcomponent.c -o libcomponent.o;
	$(CC) -shared -o libcomponent.so libcomponent.o



## Archiving - creating archives of several .c files (not needed for a small project like this)
libcomponent.a:
	ar rc libcomponent.a libcomponent.c

libpower.a:
	ar rc libpower.a libpower.c

libresistance.a:
	ar rc libresistance.a libresistance.c


## Clean
clean:
	@echo "\nCleaning up the leftovers... \n"
	-rm -f electrotest \
	*o \
	*a \
	*so \
	*_test;
	@echo "\nDone! :)\n"



## Install - use with sudo
install: electrotest
	@if [ -d $(LIBINSTDIR) ];\
		then \
		cp *.so $(LIBINSTDIR);\
		chmod 0755 $(LIBINSTDIR)/libpower.so;\
		chmod 0755 $(LIBINSTDIR)/libresistance.so;\
		chmod 0755 $(LIBINSTDIR)/libcomponent.so;\
		ldconfig;\
		echo "Installerade bibliotek i $(LIBINSTDIR)";\
	fi;
	@if [ -d $(INSTDIR) ]; \
		then \
		$(CC) -L$(LIBINSTDIR) -Wall -o electrotest main.c -lcomponent -lresistance -lpower;\
		cp electrotest $(INSTDIR);\
		chmod a+x $(INSTDIR)/electrotest;\
		chmod og-w $(INSTDIR)/electrotest;\
		echo "Installerade electrotest i $(INSTDIR)";\
	else \
		echo "Sorry, $(INSTDIR) finns inte";\
	fi;

	make clean;

## Uninstall - use with sudo
uninstall:
	@if [ -d $(INSTDIR) ]; \
		then \
		rm $(INSTDIR)/electrotest;\
		echo "Avinstallerade huvudprogramet.";\
	else \
		echo "Error: $(INSTDIR) är inte en katalog.";\
	fi;
	@if [ -d $(LIBINSTDIR) ];\
		then \
		rm $(LIBINSTDIR)/libpower.so;\
		rm $(LIBINSTDIR)/libresistance.so;\
		rm $(LIBINSTDIR)/libcomponent.so;\
		ldconfig;\
		echo "Electrotest bibliotek avinstallerades.";\
	fi;



# http://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html

# "all" för att bygga en exekverbar fil "program1" 
# "clean" för att ta bort samtliga objektfiler 
# "install" för att kopiera körbar fil till en lämplig katalog varifrån filen är enkelt körbar för en vanlig användare via anropet program1. Vilka kataloger är lämpliga på just ditt system och hur ser man det?  Miljövariabeln PATH är en ledtråd. 
# "uninstall" för att ta bort det som gjordes av "install" 

# GCC options and examples:
# Use the -c option to gcc to tell it just to create an object file (an .o file) rather than an executable:
# To create a .so (shared object) file use the -shared flag to gcc.
# The -L. piece tells gcc to look in the current directory in addition to the other library directories for finding libmylib.a.
# The compiler option -lNAME will attempt to link object files with a library file ‘libNAME.a’ i
# To link with a library not in the standard (usr/lib) path: -L/home/myUserName/lib -lmylib
# -I adds include directory of header files. Using -I flag .h files can be in another directory.
# $(CC) $(CFLAGS) -o libcomponent.o -c libcomponent.c;
# $(CC) $(CFLAGS) -shared -o libcomponent.so  libcomponent.o -lm;
# $(CC) $(CFLAGS) main.c -L. -lcomponent -lresistance -lpower -o main.o;

# Special macros and options for makefiles:
#$? List of prerequisites (files the target depends on) changed more recently than the current target
#$@ Name of the current target
#$< Name of the current prerequisite
#$* Name of the current prerequisite, without any suffix

#- tells make to ignore any errors. For example, if you wanted to make a directory but wished to
# ignore any errors, perhaps because the directory might already exist, you just precede mkdir
# with a minus sign.
#@ tells make not to print the command to standard output before executing it. This character is
# handy if you want to use echo to display some instructions.

