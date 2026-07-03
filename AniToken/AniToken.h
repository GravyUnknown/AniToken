#pragma once

#include "Parser.h"
#include "Tokenizer.h"
#include <memory>

using namespace Keywords;
using namespace Items;

class AniToken
{
public:
	AniToken(std::string_view filename);

	token_container_t tokens_list;
	item_container_t items_list;
};