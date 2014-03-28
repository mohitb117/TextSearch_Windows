# pragma once
# include "TextSearchComponent.h"

//# include "TextCompUtil.h"

class TextSearchFactory  //Object Factory to generate the Abstract text Search Client 
{

public:
	 static AbstractTextSearchComponentReferenceCounted* createTextSearchComponent();

};