# pragma once

# include "TextSearchFactory.h"

//# include "TextCompUtil.h"

AbstractTextSearchComponentReferenceCounted* TextSearchFactory::createTextSearchComponent()
{
	return new TextSearchComponent();
}
