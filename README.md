Forth Virtual Machine for Arduino
=================================

FVM is a very simple virtual machine wich runs a restrict set of Forth language

Compiling
---------

At this moment, FVM isn't yet running in Arduino, but as a interpreter in your computer (I started the project just now, give me a time :).

For compilind just go to src folder and run:

	$ make

For running a example:

	$ ./fvm sourcetest.fth

For running as a console:

	$ ./fvm -c

Word Set
________

For a while FVM supports a very limited words set. I didn't make a list with all those words, but you can easily see them in builtin.h

