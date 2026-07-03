#pragma once
#include <string>
#include <memory>
#include "Items.h"
#include "Parser.h"



class Tokenizer
{
public:
	Tokenizer(std::string_view file, Items::token_container_t& tokens, Keywords::item_container_t& items);
	Items::Item Tokenize();	
private:
	std::string_view input{};
	Items::token_container_t& token_list;
	Keywords::item_container_t& items_list;
	char separator = '\0';
	bool next_token_enclosed = false;
	auto TokenizeKeywords();
	auto TokenizeText(std::string_view string);
	char peek();
	std::string take();
	std::string take_text(bool enclosed, bool remove_prefix);
	void find_separator(char s);
	bool is_text(const char ch);
	Keywords::keyword_t find_keywords();
};