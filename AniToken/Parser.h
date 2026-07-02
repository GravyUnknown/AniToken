#pragma once
#include "Items.h"
#include "Tokenizer.h"
#include "Keyword.h"
#include <memory>


class Parser
{
public:
	Parser(std::shared_ptr<Keywords::item_container_t> items, std::shared_ptr<Items::token_container_t> tokens);
	
private:
	std::shared_ptr<Keywords::item_container_t> received_items;
	std::shared_ptr<Items::token_container_t> received_tokens;
	Keywords::keyword_string_t ParseFileExtension();
	Keywords::keyword_string_t ParseEpisodeNumber();	
	void AddItem(Keywords::keyword_string_t returnValue);
	
};
