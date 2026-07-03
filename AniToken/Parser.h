#pragma once
#include "Items.h"
#include "Tokenizer.h"
#include "Keyword.h"
#include <memory>


class Parser
{
public:
	Parser(Keywords::item_container_t& items, const Items::token_container_t& tokens);
	
private:
	Keywords::item_container_t& received_items;
	const Items::token_container_t& received_tokens;
	Keywords::keyword_string_t ParseFileExtension();
	Keywords::keyword_string_t ParseEpisodeNumber();	
	void AddItem(Keywords::keyword_string_t returnValue);
	
};
