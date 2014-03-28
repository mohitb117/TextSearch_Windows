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

=========================HOW TO BUILD================================================

1 . Execute Batch file BuildSolution.bat


2. The powershell Build Scripts are in RootFolder\CPP_Client_Powershell_Script
    for the C++ Client Interaction with the COM Wrapper via dll.
(Outputs will be generated as seperate files within the scripts folder.)


3. The powershell Build Scripts are in RootFolder\CS_Client_Powershell_Script
    for the C# Client Interaction with the COM Wrapper via dll.
(Outputs will be generated as seperate files within the scripts folder.)


---------------------------------------------------------------------------------
Please Note the only reason why I had to split scripts 
was due to some situation due o threading constructs in the project acquiring locks 
while searching files and cascaded scripts would sometimes get stuck.
(Thats my working theory!)
---------------------------------------------------------------------------------


