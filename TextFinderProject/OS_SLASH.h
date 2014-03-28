/////////////////////////////////////////////////////////////////////
// OS_SLASH.h								                       //
//                                                                 //
// Mohit Bhalla CSE Syracuse University, Spring 2014	           //
// Just defines the SLash FOrmat in windows and linux , for cross  //
// platform compilation on top the already provided FileSystem     // 
//Namespace by Professor Fawcett.								   //			
/////////////////////////////////////////////////////////////////////


# include<string>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
static const std::string slash = "\\";
#else
static const std::string slash = "/";
#endif

# define Verbose 0