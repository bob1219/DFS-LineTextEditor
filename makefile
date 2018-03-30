# macro
COMP = cl
LINK = link
OPTIONS = /EHsc /I.
EXE = edit.exe

# suffix rule
.cpp.obj:
	$(COMP) /Fe$@ /c $< $(OPTIONS)

$(EXE): main.obj File.obj commands.obj CommandProcess.obj Files.obj CommandLine.obj
	$(LINK) /out:$@ $** /LIBPATH:.\boost

main.obj: main.cpp exception.h File.h function.h
File.obj: File.cpp File.h exception.h
commands.obj: commands.cpp function.h File.h
CommandProcess.obj: CommandProcess.cpp function.h wtokenizer.h
CommandLine.obj: CommandLine.cpp function.h
