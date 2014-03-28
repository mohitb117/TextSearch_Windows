/////////////////////////////////////////////////////////////////////
// ITextSearchComponent.h								           //
//                                                                 //
// Mohit Bhalla CSE Syracuse University, Spring 2014	           //
// Interface for the Skeleton TextSearchComponent                  //
/////////////////////////////////////////////////////////////////////


# include <vector>
# include <string>

template <typename R,typename ... A>

struct ITextSearchComponent
{
	virtual ~ITextSearchComponent()	{};

	virtual R search(A...) = 0;

	virtual ITextSearchComponent* AddRef()=0;

	virtual void Release()=0;

	virtual void verbose(bool pred = true) = 0;
};





