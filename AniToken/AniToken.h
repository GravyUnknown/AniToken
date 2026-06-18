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

	std::shared_ptr<token_container_t> tokens_list = std::make_shared<token_container_t>();
	std::shared_ptr<item_container_t> items_list = std::make_shared<item_container_t>();
};