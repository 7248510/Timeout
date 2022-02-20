# Timeout
# Goals:
  * Learn pointers
  * Practice secure programming
  * Interact with operating systems

# Windows terms: 
Shutdown's [MSDN page](https://docs.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-initiatesystemshutdowna). "The function does not require an error return function because it is<br>returns a LSTATUS/Long value. The error code is in the return result, therefore it is not necessary to use another function.
A DWORD is an unsigned 32 bit integer"(W10 System Programming)<br>[Windows Library file names](https://en.wikipedia.org/wiki/Microsoft_Windows_library_files)
# MSVC Flags
* /TC = make sure C is compiled
* /W4 = Max warning levels
* /sdl = Security checks
* /EHsc = exception handling model

# Things learned:
 * Windows security tokens
 * Windows libraries
 * [Example](https://docs.microsoft.com/en-us/windows/win32/shutdown/how-to-shut-down-the-system)
 * C++ 20's Spaceship operator, Cmake and toolchains.
