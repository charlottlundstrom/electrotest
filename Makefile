# Make file does not handle the libraries properly yet.
# Use:
# make clean; make; ./electrotest
# to run program after changes have been made to any files.

# Which compiler
CC = gcc

# Where to install
INSTDIR = /usr/local/bin
LIBINSTDIR = /usr/local/lib
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

##LIBRARY
lib: libresistance libcomponent libpower

# Developers: add dependencies for the other tests when they are ready.
libtests: libresistance_test libpower_test component_test

electrotest: $(FILES)
	$(CC) $(CFLAGS) main.c -L. -lpower -lresistance -lcomponent -o electrotest -Wl,-rpath,.


### LIBRESISTANCE
libresistance_test: libresistance.c libresistance.so
	$(CC) $(CFLAGS) libresistance_test.c -L. -lresistance -o libresistance_test

libresistance.so: libresistance.c libresistance.o
	ld -shared -soname libresistance.so -o libresistance.so -lc libresistance.o

libresistance.o: libresistance.c


### LIBPOWER
libpower_test: calc_power_r.c calc_power_i.c libpower.so
	$(CC) $(CFLAGS) libpower_test.c -L. -lpower -o libpower_test

libpower.so:  calc_power_r.o calc_power_i.o
	ld -shared -soname libpower.so -o libpower.so -lc calc_power_r.o calc_power_i.o

calc_power_r.o: calc_power_r.c

calc_power_i.o: calc_power_i.c


### LIBCOMPONENT
libcomponent_test: libcomponent.so
	$(CC) $(CFLAGS) libcomponent_test.c -L. -lcomponent -o libcomponent_test

libcomponent.so: libcomponent.o
	ld -shared -soname libcomponent.so -o libcomponent.so -lc libcomponent.o

libcomponent.o: libcomponent.c


# For creating archives of several .c files (not needed for a small project like this)
libcomponent.a:
	ar rc libcomponent.a libcomponent.c

libpower.a:
	ar rc libpower.a libpower.c

libresistance.a:
	ar rc libresistance.a libresistance.c


clean:
	@echo "Cleaning up the mess :)"
	-rm -f electrotest \
	*o \
	*a \
	*so \
	*_test

## INSTALL use with sudo
install: electrotest
	@if [ -d /usr/local/bin ]; \
		then \
		cp electrotest /usr/local/bin;\
		chmod a+x /usr/local/bin/electrotest;\
		chmod og-w /usr/local/bin/electrotest;\
		echo "Installerad i /usr/local/bin";\
	else \
		echo "Sorry, mappen du valde finns inte";\
	fi;
	@if [ -d $(LIBINSTDIR) ];\
		then \
		cp *.so $(LIBINSTDIR);\
		chmod 0755 $(LIBINSTDIR)/libpower.so;\
		chmod 0755 $(LIBINSTDIR)/libresistance.so;\
		chmod 0755 $(LIBINSTDIR)/libcomponent.so;\
		ldconfig;\
		$(CC) -L$(LIBINSTDIR) -Wall -o electrotest main.c -lcomponent -lresistance -lpower;\
		echo "Installerat i $(LIBINSTDIR)";\
	fi;

#install: electrotest
#	@if [ -d $(INSTDIR) ]; \
#		then \
#		cp program1 $(INSTDIR);\
#		chmod a+x $(INSTDIR)/electrotest;\
#		chmod og-w $(INSTDIR)/electrotest;\
#		echo “Installed electrotest in $(INSTDIR)“;\
#	else \
#		echo “Sorry, $(INSTDIR) does not exist”;\
#	fi

# uninstall:

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

