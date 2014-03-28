/////////////////////////////////////////////////////////////////////
// TextSearchComponent.h								           //
//                                                                 //
//   Mohit Bhalla CSE Syracuse University, Spring 2014	           //

		/*
		The declarations for a specialzied TextSearchComponent
		which is wrapped as a Abstract reference counted  instance.
		*/

/////////////////////////////////////////////////////////////////////

#pragma once
# include "AbstractReferenceCount.h"
# include "ITextSearchComponent.h"
# include "FileSystem.h"
# include "OS_SLASH.h"

using Result = std::vector<std::string>;
using DirectoryPath = std::string;
using Patterns = std::vector<std::string>;

using AbstractTextSearchComponent = ITextSearchComponent<Result, const DirectoryPath&, const Patterns &,const Patterns &>;

using AbstractTextSearchComponentReferenceCounted = AbstractReferenceCount<AbstractTextSearchComponent>;

//# include "TextCompUtil.h"

class TextSearchComponent : public AbstractTextSearchComponentReferenceCounted
{

	private:
	FileSystemSearch fss;
	bool findFilesRecursive;
	bool FileMustContainAllPatterns;

	public:
	TextSearchComponent() : AbstractTextSearchComponentReferenceCounted()
	{

	}

	~TextSearchComponent()
	{

	}

	Result search(const DirectoryPath & path, const Patterns & filePatterns,const Patterns &textPatterns);

	void searchFilesRecursive(bool flag)
	{
		findFilesRecursive = flag;
	}

	void searchAllPatterns(bool flag)
	{
		FileMustContainAllPatterns = flag;
	}

	bool getRecursionFlag()
	{
		return findFilesRecursive;
	}

	bool getTextPatternSearchCondition()
	{
		return FileMustContainAllPatterns;
	}

	void verbose(bool pred=true)
	{
		_verbose = pred;
	} 

};
