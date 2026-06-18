#include "Parser.h"


using namespace Keywords;

Parser::Parser(std::shared_ptr<Keywords::item_container_t> items, std::shared_ptr<Items::token_container_t> tokens)
	: received_tokens(tokens), 
	received_items(items)
{
	AddItem(ParseFileExtension());
	AddItem(ParseEpisodeNumber());
	
}


void Parser::AddItem(keyword_t returnValue)
{
	if (!returnValue.first.empty())
	{
		Parser::received_items->push_back(returnValue);
	}
}

keyword_t Parser::ParseFileExtension()
{

	Items::Item& item = received_tokens->back();
	item.value.remove_prefix(1);
	return { item.value, Descriptors::FileExtension };

	
}

keyword_t Parser::ParseEpisodeNumber()
{
	return {};
}