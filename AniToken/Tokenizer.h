#pragma once
#include <string>
#include "Items.h"


class Tokenizer
{
	Tokenizer(std::string_view file);
	Items::Item Tokenize();

private:
	std::string_view input;
	std::string_view separator;
	std::vector<Items> item_list;
	auto TokenizeKeywords();
	auto TokenizeText(std::string_view string);
	char peek();
	std::string take(size_t n = 1);
	std::string take_text(bool enclosed);
	void find_separator(char s);
	bool is_text(const char ch);
};