#pragma once
#include <string>
#include "Items.h"
#include "Parser.h"


class Tokenizer
{
public:
	Tokenizer(std::string_view file, std::vector<Items::Item>tokens);
	Items::Item Tokenize();
	static inline std::vector<Items::Item> token_list;
private:
	std::string_view input;
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