using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace TextSearchCompCSharpClient
{
    /*
		
	Schema of TextCompParsing :=

	<AppExec>.exe  /R(optional)   /O(optional)      -Path    _______    -Words  ______ ______   -Files ______ _______
				    recursion     strings patterns
    */

    class CSharpArgumentParser
    {
        private static List<String> TextPatterns;

        private static List<String> FilePatterns;

        private bool recursion = false;   //By Default false its not Recursion

        private bool allPatterns = true;  //By default true  ... Find Files which have all String Occurences

        private String dirPath = ".";

        private TextCompWrapperLib.ITextCompCOM textComp;

        public List<String> getTextPatterns()
        {
            return TextPatterns;
        }

        public List<String> getFilePatterns()
        {
            return FilePatterns;
        }

        public String getSearchDirectoryPath()
        {
            return dirPath;
        }

        public Boolean getRecursionFlag()
        {
            return recursion;
        }

        public Boolean getSearchAllPatternsFlag()
        {
            return allPatterns;
        }

        public CSharpArgumentParser(String[] args)
        { 
            TextPatterns = new List<String>();
            FilePatterns = new List<String>();
            recursion = false;
            allPatterns = true;
            dirPath = ".";
        }

        public Boolean parseCommandLineArgs2TextCompArguments(string[] args,TextCompWrapperLib.ITextCompCOM textComp)
        {
            this.textComp=textComp;

            scanDirectoryPath(args);

            scanTextCompFlags(args);
            
            scanTextCompTextSearchString(args);

            scanTextCompFileSearchString(args);

            if (!(dirPath != "" || dirPath != " " || dirPath!="\t" || dirPath!= "\n" || dirPath!="\b" ))
	        {
                dirPath = ".";
            }

            if (FilePatterns.Count() == 0)
            {
                FilePatterns.Add("*.*");
            }

            if (TextPatterns.Count() == 0)
            {
                return false;
            }

            textComp.InitializeComponent();

            textComp.SetSearchPath(getSearchDirectoryPath());

            textComp.SetTextPatterns(getTextPatterns().ToArray());

            textComp.SetFilePatterns(getFilePatterns().ToArray());

            textComp.SetSpecialSearchClause
                (
                getRecursionFlag().ToString(),
                getSearchAllPatternsFlag().ToString()
                );


            VerboseArgumentsPassed();

            return true;

        }

        private void scanTextCompFileSearchString(string[] args)
        {
            for (int i = 0; i < args.Length; i++)
	        {
		        if (args[i].Equals("-Files") && args.Length >= i + 1)
		        {
                    StoreAllPatterns(args, i, ref FilePatterns);

			        return;
		        }
	        }

        }

        private void scanTextCompTextSearchString(string[] args)
        {
            for (int i = 0; i < args.Length; i++)
	        {

		        if (args[i].Equals("-Words") && args.Length >= i + 1)
		        {
			        StoreAllPatterns(args, i, ref TextPatterns);

			        return;
		        }
	        }
        }


        private void StoreAllPatterns(String []args, int currPos,ref List<String> results)
        { 
                   for (int i = currPos + 1; i < args.Length; i++)
	                {
		                int pos = args[i].IndexOf("-");

		                int maxPos = args[i].Length;

		                if ( pos >= 0 && pos <maxPos)
		                {
			                return;
		                }

		                else
		                {
                            results.Add(args[i]);
		                }

	                }
        }

        void scanDirectoryPath(String [] args)
        {
            for(int i=0;i<args.Length;i++)
            {
                if(args[i].Equals("-Path") && args.Length>=i+1)
                {
                    dirPath = args[i + 1];
                }
            }
        }


            void scanTextCompFlags(String [] args)
            {
                for (int i = 0; i < args.Length; i++)
                {

                    //If no /R mentioned .. then recursion is false                   
                    if (args[i].Equals( "/R"))
                    {
	                    recursion = true;
                    }

                    //If no /O is mentioned find allPatterns
                    if (args[i].Equals("/O"))
                    {
	                    allPatterns = false;
                    }
                }
            }


            void VerboseArgumentsPassed()
            {
                
                Console.WriteLine("Arguments Scanned by the Parser");

                Console.WriteLine("Recursion Search Flag ==>"+boolean2String(recursion));

                Console.WriteLine("Search Files That contain Text Strings Flag ==>" + boolean2String(allPatterns));
 
                Console.WriteLine("Directory Path Provided for Searching==>"+dirPath);
                
                Console.Write("Text Patterns Needed for Searching==> ");

                printList(TextPatterns);

                Console.Write("File Patterns Needed for Searching==> ");
               
                printList(FilePatterns);
            
            }


            void printList(List<string> x)
            {
                foreach(string inst in x)
                {
                    Console.Write(inst+" , ");
                }
                Console.WriteLine();
            }


            string boolean2String(bool x)
            {
                if (x)
                    return "true";
                else
                    return "false";
            }

    }
}
