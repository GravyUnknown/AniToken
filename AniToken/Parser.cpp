#include "Parser.h"


using namespace Keywords;

Parser::Parser(std::vector<Items::Item> token_list, std::vector<keyword_t>items)
	: received_tokens(token_list), 
	received_items(items)
{
	AddItem(ParseFileExtension());
	AddItem(ParseEpisodeNumber());
	
}


void Parser::AddItem(keyword_t returnValue)
{
	if (!returnValue.first.empty())
	{
		Items::item_list.push_back(returnValue);
	}
}

keyword_t Parser::ParseFileExtension()
{

	Items::Item& item = received_tokens.back();
	item.value.remove_prefix(1);
	return { item.value, Descriptors::FileExtension };

	
}

keyword_t Parser::ParseEpisodeNumber()
{
	return {};
}