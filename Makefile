# Which compiler
CC = gcc

# Where to install
INSTDIR = /usr/local/bin

# Local Libraries
MYLIB = component

# Where are include files kept
# INCLUDE = .

# Options for development
CFLAGS = -g -Wall
# Options for release
# CFLAGS = -O -Wall –ansi


all: electrotest

# The -L. piece tells gcc to look in the current directory in addition to the other library directories for finding libmylib.a.
# The compiler option -lNAME will attempt to link object files with a library file ‘libNAME.a’ i
electrotest: main.o
	$(CC) $(CFLAGS) main.o -o electrotest;

main.o:
# Use the -c option to gcc to tell it just to create an object file (an .o file) rather than an executable:
# To create a .so file use the -shared flag to gcc (it will copy the lib to usr/lib).
# To link with a library not in the standard (usr/lib) path: -L/home/myUserName/lib -lmylib
	$(CC) -o libcomponent.o -c libcomponent.c;
	$(CC) -shared -o libcomponent.so  libcomponent.o -lm;

	$(CC) -o libpower.o -c libpower.c;
	$(CC) -shared -o libpower.so  libpower.o -lm;

	$(CC) -o libresistance.o -c libresistance.c;
	$(CC) -shared -o libresistance.so  libresistance.o -lm;
	$(CC) main.c -L. -lcomponent -lresistance -lpower -omain.o;

libcomponent.a:
	ar rc libcomponent.a libcomponent.c;

libpower.a:
	ar rc libpower.a libpower.c;

libresistance.a:
	ar rc libresistance.a libresistance.c;

clean:
	-rm electrotest \
	main.o \
	libresistance.a \
	libpower.a \
	libcomponent.a \
	libresistance.so \
	libpower.so \
	libcomponent.so \
	libresistance.o \
	libpower.o \
	libcomponent.o;

install: program1
	@if [ -d $(INSTDIR) ]; \
		then \
		cp program1 $(INSTDIR);\
		chmod a+x $(INSTDIR)/program1;\
		chmod og-w $(INSTDIR)/program1;\
		echo “Installed program1 in $(INSTDIR)“;\
	else \
		echo “Sorry, $(INSTDIR) does not exist”;\
	fi

# uninstall:

# "all" för att bygga en exekverbar fil "program1" 
# "clean" för att ta bort samtliga objektfiler 
# "install" för att kopiera körbar fil till en lämplig katalog varifrån filen är enkelt körbar för en vanlig användare via anropet program1. Vilka kataloger är lämpliga på just ditt system och hur ser man det?  Miljövariabeln PATH är en ledtråd. 
# "uninstall" för att ta bort det som gjordes av "install" 



# Special macros:
#$? List of prerequisites (files the target depends on) changed more recently than the current target
#$@ Name of the current target
#$< Name of the current prerequisite
#$* Name of the current prerequisite, without any suffix


#- tells make to ignore any errors. For example, if you wanted to make a directory but wished to
# ignore any errors, perhaps because the directory might already exist, you just precede mkdir
# with a minus sign.
#@ tells make not to print the command to standard output before executing it. This character is
# handy if you want to use echo to display some instructions.

