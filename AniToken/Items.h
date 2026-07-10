#pragma once
#include <string>
#include <vector>
#include "Token.h"
#include "Keyword.h"

namespace Items
{
	struct Item
	{
		Tokens::TokenType type;
		Keywords::Descriptors elementtype = Keywords::Descriptors::Undefined;
		std::string value;
		bool is_enclosed = false;
		bool is_identified = true;

	};

	using token_container_t = std::vector<Items::Item>;
	
};