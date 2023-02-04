EXECUTABLE_NAME = main
DLL_NAME = add

# Build application(Default).
build:
 @echo Build application...
 cl /EHsc /Fe$(EXECUTABLE_NAME) /D__NODLLEXPORT add.c main.c
 @echo OK

# Build static load dll application.
build2:
 @echo Build static load dll application...
 cl /EHsc /Fe$(EXECUTABLE_NAME) add.lib main.c
 @echo OK

# Build dyncmaic load dll application.
build3:
 @echo Build dyncmaic load dll application...
 cl /EHsc /Fe$(EXECUTABLE_NAME) /D__DYNAMICLOADDLL main.c
 @echo OK

# Build dynamic-link library and dllmain.c isn't necessary. There is no dllmin code MSVC will auto complie the dllmain into the dynamic-link library.
dll:
 @echo Build dynamic-link library...
 cl /LD /Fe$(DLL_NAME) /Iadd.h dllmain.c add.c
 @echo OK

dll2:
 @echo Build dynamic-link library...
 cl /LD /Fe$(DLL_NAME) /Iadd.h add.c
 @echo OK
# Clean
clean:
 @echo Clean...
 @if exist *.obj del *.obj
 @if exist *.lib del *.lib
 @if exist *.exe del *.exe
 @if exist *.exp del *.exp
 @if exist *.dll del *.dll
 @echo OK