/////////////////////////////////////////////////////////////////////
// CPPClient_TextFinder.cpp						                   //
//                                                                 //
// Mohit Bhalla CSE Syracuse University, Spring 2014	           //
/*
        This class just refers the COM Wrapper associated with the 
        TextSearchCompoent and invokes the functionality 
        through the metadata accesibility from the midl compiler
        generates for the COM object wrapper
*/
/////////////////////////////////////////////////////////////////////

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TextSearchCompCSharpClient
{
    class Program
    {

        static void Main(string[] args)
        {

            Console.WriteLine("===================================================================");
            Console.WriteLine("===================================================================");
            Console.WriteLine("              C# Client Interfacing with COM Object                ");
            Console.WriteLine("===================================================================");
            Console.WriteLine("===================================================================");
            TextCompWrapperLib.ITextCompCOM TextCompHandle = new TextCompWrapperLib.TextCompCOM();
        
            CSharpArgumentParser parser=new CSharpArgumentParser(args);

            if (parser.parseCommandLineArgs2TextCompArguments(args,TextCompHandle))
            {
                Array files;

                TextCompHandle.GetQualifyingFileList(out files);

                Console.WriteLine("===================================================================");
                Console.WriteLine("===================================================================");

                Console.WriteLine("The Qualifying Files from the Text Seacrh Component via C# COM interface");

                foreach (string file in files)

                    Console.WriteLine(" {0}", (string)file);

                Console.WriteLine("\n\n");

                Console.WriteLine("End of C# COM interface");
            }

            else 
            {
                Console.WriteLine("Error During Parsing of Arguments of the TextSearchComponent");
                Console.WriteLine("Arguments==> /R(opt)   /O(opt)   -Path ______  -Words __ ___   -Files ___ ___");
                Console.WriteLine("             recursion Condition  DirectoryPath TextPatterns     FilePatterns  ");
            }

            return ;
        }

    }
}
