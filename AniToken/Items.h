#pragma once
#include <string>
#include <vector>
#include "Token.h"

namespace Items
{
	struct Item
	{
		Tokens::TokenType type;
		std::string_view value;
		bool is_enclosed = false;
		bool is_identified = true;

	};

	static inline std::vector<Keywords::keyword_t> item_list;
	
};