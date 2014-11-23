Description
===========

Small clock


Install ncurses lib
=========================

Ubuntu:
sudo apt-get install build-essentials
sudo apt-get install libncurses5-dev

RaspberryPi:
sudo apt-get install libncurses5-dev

Link ncurses lib
================

compile and link: 
	gcc <program file> -lncurses

Eclipse: 
	Open Project Properties>C/C++ Build>Setting>GCC C++ Linker>Libraries
	Add "ncurses" as library		