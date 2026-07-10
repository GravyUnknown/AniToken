#pragma once
#include "Items.h"
#include "Tokenizer.h"
#include "Keyword.h"
#include <memory>


class Parser
{
public:
	Parser(Keywords::item_container_t& items, Items::token_container_t& tokens);
	
private:
	bool parse_episode_number = true;
	bool parse_episode_title = true;
	bool parse_series_title = true;
	Keywords::item_container_t& received_items;
	Items::token_container_t& received_tokens;
	Keywords::keyword_string_t ParseFileExtension();
	Keywords::keyword_string_t ParseEpisodeNumber(Items::Item& i);	
	Keywords::keyword_string_t ParseEpisodeNumber();
	Keywords::keyword_string_t ParseEpisodeTitle(Items::Item& i);
	Keywords::keyword_string_t ParseSeriesTitle(Items::Item& i);
	Keywords::keyword_string_t ParseReleaseYear();
	Keywords::keyword_string_t ParseKeywords(Items::Item& i);
	Keywords::keyword_string_t ParseReleaseGroup();
	void AddItem(Keywords::keyword_string_t returnValue);
	
};
