/////////////////////////////////////////////////////////////////////
// AbstractReferenceCount.cpp							           //
//                                                                 //
// Mohit Bhalla CSE Syracuse University, Spring 2014	           //
// Abstract Reference Count Class Wrapper which can be included in //
// Class and make it behave as a Reference COunted Class		   //
/////////////////////////////////////////////////////////////////////

# include <atomic>
# include <iostream>

template <class T>
class AbstractReferenceCount : public T
{
protected:
	bool _verbose;
private:
	std::atomic<size_t> referenceCount = 0;

public:
	AbstractReferenceCount(bool verbose = true)
	{
		referenceCount = 1;
		_verbose = verbose;

		if (_verbose)
			std::cout << "\n Creating Object Reference of class obeyeing AbstractReferenceCount Interface" << "\n Count is " << referenceCount << std::endl;
	}

	~AbstractReferenceCount()
	{
		if (_verbose)
		{
			std::cout << "\n Destroying Reference of class obeyeing AbstractReferenceCount Interface"<<std::endl;
		}
	}


	T* AddRef()
	{
		++referenceCount;
		if (_verbose)
		{
			std::cout << "\n Incrementing Reference of class obeyeing AbstractReferenceCount Interface" << "\n Count is " << referenceCount << std::endl;
		}

		return this;
	}

	void Release()
	{
		if (--referenceCount == 0)
		{
			delete this;
			return;
		}

		if (_verbose)
		{
			std::cout << "\n Decrementing Reference of class obeyeing AbstractReferenceCount Interface" << "\n Count is " << referenceCount <<std::endl;
		}

	}

};
