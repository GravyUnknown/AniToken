#pragma once
#include <string>
#include <vector>
#include "Token.h"

class Items
{
public:
	struct Item
	{
		Tokens::TokenType type;
		std::string value;
		bool is_enclosed = false;
		bool is_identified = true;

	};
	
};