DFS-LineTextEditor
==================
DFS-LineTextEditor is a line-text-editor project.

Development Environment
-----------------------
* Operating System: Microsoft Windows 10
* Programming Language: C++
* Builder: Microsoft Visual Studio 2017

Usage
-----
`edit <filename>`

Commands
--------
* o  
	* Description: open a file
	* Usage: `o [(fileno)/-n] <filename>`
	* Option '-n': new file

* cl  
	* Description: close a file
	* Usage: `cl [fileno]`

* f  
	* Description: print list of files
	* Usage: `f`

* e  
	* Description: edit a line
	* Usage: `e [fileno] [lineno]`

* a  
	* Description: append a line
	* Usage: `a [fileno]`

* i  
	* Description: insert a line
	* Usage: `i [fileno] [lineno]`

* cp  
	* Description: copy a line
	* Usage: `cp [fileno] [from-lineno] [to-lineno]`

* w  
	* Description: write a file
	* Usage: `w [fileno]`

* as  
	* Description: append lines
	* Usage: `as [fileno]`

* r  
	* Description: remove a line
	* Usage: `r [fileno] [lineno]`

* l  
	* Description: print list of lines
	* Usages
		1. `l [fileno]`
			* Description: print all lines
		2. `l [fileno] [lineno]`
			* Description: print a line
		3. `l [fileno] [from-lineno] [to-lineno]`
			* Description: print lines

Files
-----
* Source file
	* File.cpp
	* CommandLine.cpp
	* Files.cpp
	* commands.cpp
	* CommandProcess.cpp
	* main.cpp

* Header file
	* Files.h
	* File.h
	* function.h
	* exception.h
	* wtokenizer.h

* Other
	* .gitignore
	* LICENSE

History
-------
* 1.0 (March 12th, 2018)
	* First version

* 1.1 (March 20th, 2018)
	* Modify designs

* 1.2 (March 20th, 2018)
	* Modify designs
