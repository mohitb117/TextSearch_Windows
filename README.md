CSE775 Distributed Objects                        Spring 2014 
 
Project #1 Text Search Component 
Version 1.2                          
   
Purpose: 
For this project we will develop recursive text finder components that can run on Windows and Linux.  
The purpose of the finder is to identify all files in some directory tree that contain one or more specified strings 

In this project you will develop a program that searches a directory subtree and reports any files
that contain a string passed to the command line.   
 
The Windows component will be developed using Microsoft�s Component Object Model (COM) technology.  
For Linux, which does not support COM we will build a C++ library that exposes its functionality 
through an interface and object factory and uses reference counted life-time management.  
We will see that COM does that too, and more.  These components will be 
used through scripts, a C++ client on both platforms, and also a C# client on Windows. 
 
You will then design and implement applications that search a path specified on the command line 
and report any files that contain a string, also specified on the command line. 

Requirements: 
Your NewFiles project:   
 
1.  shall  use  standard  C++  and  the  standard  library,  compile  and  link  from  the  command  line, 
 using    g++  within  the NetBeans or Eclipse IDE and Visual C++ in the Visual Studio 2013 IDE.   

 ==>DONE
   
2.  shall add code to the C++ FileSystem package for the Windows and Linux environments, as needed to support your 
project.  The external interfaces of these packages shall be identical on both platforms.   
 
 ==>DONE

3.  shall  provide  a  console  application  that  analyzes  all  of  the  files  and  directories  found  on  a  path  
specified  on  the program�s command line, and reports any files that contain one or more strings specified on the command line.
Please implement a /R option for recursive search and a /O option indicating that a match is found if any one of the strings are 
discovered.  Absence of the /O option indicates that all strings must be found.   
 
 ==> DONE

4.  shall  build  the  searching  functionality  on  Windows  using  the  COM  technology,  via  ATL  facilities 
provided  by  Visual Studio 2013.  This results in a dynamic link library configured with the COM protocols.  
 
 ==DONE

5.  shall build the searching functionality on Linux using native C++, providing an interface, implementation, and object 
factory, built as a dynamic link library.  This component shall implement reference counting and functions AddRef() and 
Release() to support that.   
 
 ==>DONE

6.  shall provide native C++ library clients that provide user access to the search facilities for both platforms, and shall also 
provide a C# client for Windows.   
 
 ==> DONE

7.  shall provide a PowerShell script on Windows and a Bash script on Linux for testing and to demonstrate that you met 
each of the requirements specified here.  
 
 ==> DONE

You will find it helpful to look at the Man pages for System Calls on your Linux system.  Those describe the semantics of each 
call and the header files you will need to include. 
 
A ten point bonus will be awarded for successful implementation of the search functionality so that each file is analyzed on 
its own thread.  You may use C++11 threads and locks, or, on the Windows platform you may use I/O completion ports.  
The bonus will depend on you executing performance demonstrations for single and multiple thread operation. 
 ==>DONE
                     
TextSearch_Windows
==================

C# & CPP interface to Native CPP code wrapped in COM Object  


Mohit Bhalla 919718909
This Solution has Three Projects

TextFinderProject ==> Native C++ COde which has the Responsibility for 
		      Finding the words you need to find.

		This Gets Built into a *.lib ==> a Static Library


TextComWrapper ==> As the name suggests  A COM Wrapper over the native 
	           class which allows to be wrapped. 


		This gets compiled into a dynamic Linked Library 
		==> *.dll



TextSearchCompCSharpClient ==> The CS project that hooks onto the *.dll 
			file and invokes the exposed functionality of the
			TextSearchComponent via the COM Wrapper.

			Generates==>TextSearchCompCSharpClient.exe

CPLUSPLUSCLIENT ==> This project interfaces with the COM wrapper generated 
	             DLL in order to invoke the packaged functionality 
		     of the TextSearchComponent.

		    Generates==>	CPLUSPLUSCLIENT.exe

=========================HOW TO BUILD====================================

1 . Execute Batch file BuildSolution.bat


2. The powershell Build Scripts are in RootFolder\CPP_Client_Powershell_Script
    for the C++ Client Interaction with the COM Wrapper via dll.
(Outputs will be generated as seperate files within the scripts folder.)


3. The powershell Build Scripts are in RootFolder\CS_Client_Powershell_Script
    for the C# Client Interaction with the COM Wrapper via dll.
(Outputs will be generated as seperate files within the scripts folder.)


------------------------------------------------------------------------
Please Note the only reason why I had to split scripts 
was due to some situation due to threading constructs in the project acquiring locks 
while searching files and cascaded scripts would sometimes get stuck.
(Thats my working theory!)
---------------------------------------------------------------------------------


