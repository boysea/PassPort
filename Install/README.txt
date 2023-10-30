*** How to build the MSI installatin database: ***

1. Make sure that the Framework .NET 2.0 is installed on the 
   machine. 
2. Install the Windows Installer XML v3 (you can try to get if
   from: http://wix.sourceforge.net/)
3. Make sure that the binaries of the WIXv3 (see 2.) are on the 
   PATH variable.
4. Run the build-msi.cmd in this directory. 

*** Content of the directory: ***

1. .\Licenses -- folder with licence files (only the GPL 2.0 present
   at the moment) in the .rtf format. The license text is included
   in the intallatino database. 
2. .\build-msi.cmd -- command file with instructions to  build the 
   PassPort.msi
3. .\PassPort.wxs -- The MSI database description in the WIX v.3 
   format. 
4. .\README.txt -- this readme file. 
