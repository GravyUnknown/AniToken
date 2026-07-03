#include "Parser.h"


using namespace Keywords;

Parser::Parser(Keywords::item_container_t& items, const Items::token_container_t& tokens)
	: received_tokens(tokens), 
	received_items(items)
{
	AddItem(ParseFileExtension());
	AddItem(ParseEpisodeNumber());
	
}


void Parser::AddItem(keyword_string_t returnValue)
{
	if (!returnValue.first.empty())
	{
		Parser::received_items.emplace_back(returnValue);
	}
}

keyword_string_t Parser::ParseFileExtension()
{

	const Items::Item& item = received_tokens.back();
	return { item.value.substr(1), Descriptors::FileExtension};

	
}

keyword_string_t Parser::ParseEpisodeNumber()
{
	return {};
}