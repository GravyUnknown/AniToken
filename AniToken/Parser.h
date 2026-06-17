#pragma once
#include "Items.h"
#include "Tokenizer.h"
#include "Keyword.h"

class Parser
{
public:
	Parser(std::vector<Items::Item> token_list, std::vector<Keywords::keyword_t> items);
	
private:
	std::vector<Keywords::keyword_t> received_items;
	std::vector<Items::Item> received_tokens;
	Keywords::keyword_t ParseFileExtension();
	Keywords::keyword_t ParseEpisodeNumber();	
	void AddItem(Keywords::keyword_t returnValue);
	
};
