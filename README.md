DFS-LineTextEditor
==================
DFS-LineTextEditor is a line-text-editor project.

Development Environment
-----------------------
* Operating System: Microsoft Windows 10
* Programming Language: C++
* Builder: Microsoft Visual Studio 2017
* Makefile: Microsoft nmake

Usage
-----
`edit <filename>`

Commands
--------
* o  
	* Description: Open a file
	* Usage: `o [(fileno)/-n] <filename>`
	* Option '-n': new file

* cl  
	* Description: Close a file
	* Usage: `cl [fileno]`

* f  
	* Description: Print list of files
	* Usage: `f`

* e  
	1.
		* Description: Edit a line
		* Usage: `e [fileno] [lineno]`
	2.
		* Description: Paste a text from copy-buffer to a line
		* Usage: `e -c [fileno] [lineno] [copy-buffer-no]`

* a  
	1.
		* Description: Append a line
		* Usage: `a [fileno]`
	2.
		* Description: Append a text from copy-buffer
		* Usage: `a -c [fileno] [copy-buffer-no]`

* i  
	1.
		* Description: Insert a line
		* Usage: `i [fileno] [lineno]`

	2.
		* Description: Insert a text from copy-buffer
		* Usage: `i -c [fileno] [lineno] [copy-buffer-no]`

* cp  
	* Description: Copy a line to a copy-buffer
	* Usage: `cp [fileno] [lineno] [(copy-buffer-no)/-n]`
	* Option '-n': Copy to new copy-buffer

* w  
	* Description: Write a file
	* Usage: `w [fileno]`

* as  
	* Description: Append lines
	* Usage: `as [fileno]`

* r  
	* Description: Remove a line
	* Usage: `r [fileno] [lineno]`

* l  
	* Description: Print list of lines
	* Usages
		1. `l [fileno]`
			* Description: print all lines
		2. `l [fileno] [lineno]`
			* Description: print a line
		3. `l [fileno] [from-lineno] [to-lineno]`
			* Description: print lines

* q  
	* Description: Quit DFS-LineTextEditor
	* Usage: `q`

* fcl  
	* Description: Force close a file
	* Usage: `fcl [fileno]`

* fq  
	* Description: Force quit DFS-LineTextEditor
	* Usage: `fq`

Files
-----
* Source file
	* File.cpp
	* CommandLine.cpp
	* commands.cpp
	* CommandProcess.cpp
	* main.cpp

* Header file
	* File.h
	* function.h
	* exception.h
	* wtokenizer.h

* Other
	* .gitignore
	* LICENSE
	* boost/
	* makefile

History
-------
* 1.0 (March 12th, 2018)
	* First version

* 1.1 (March 20th, 2018)
	* Modify designs

* 1.2 (March 20th, 2018)
	* Modify designs

* 2.0 (March 30th, 2018)
	* Addition fq command and fcl command
	* Modify cp command and e command and a command and i command

* 2.1 (March 31st, 2018)
	* Modify designs

License
-------
Copyright 2018 Daiki Yoshida. All rights reserved.  
This program and its source files and header files are licensed by GNU-GPL v3.0.  
You can see document of GNU-GPL v3.0 in "LICENSE" file or GNU official website(https://www.gnu.org/licenses/gpl-3.0.en.html).  
