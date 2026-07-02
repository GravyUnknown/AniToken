#include "Tokenizer.h"
#include "Identifier.h"
#include "Token.h"
#include "Keyword.h"
#include <iterator>
#include <algorithm>

using namespace Identifiers;

Tokenizer::Tokenizer(std::string_view file, std::shared_ptr<Items::token_container_t>tokens, std::shared_ptr<Keywords::item_container_t>items)
	:input(file), token_list(tokens), items_list(items)
{
	while(!input.empty())
	{
		token_list->emplace_back(Tokenize());
	}

}

Items::Item Tokenizer::Tokenize()
{
	auto current = peek();
	if (is_open_bracket(current))
	{
		next_token_enclosed = true;
		return Items::Item{
			.type = Tokens::TokenType::OpenBracket,
			.value = take()
		};
	};

	if (is_close_bracket(current))
	{
		next_token_enclosed = false;
		return Items::Item{
			.type = Tokens::TokenType::CloseBracket,
			.value = take()
		};
	};

	if(separator == '\0') {
		if (is_separator(current))
		{
			separator = current;
			/*	if (separator.empty())
				{
					find_separator(peek());
				}*/
		}
	}

	if (current == separator)
	{
		return Items::Item
		{
			.type = Tokens::TokenType::Separator,
			.value = take(),
			.is_enclosed = next_token_enclosed,
			.is_identified = true,

		};

	}

	if (const auto& [key, type] = find_keywords(); !key.empty())
	{
		return Items::Item
		{
			.type = static_cast<Tokens::TokenType>(type),
			.value = static_cast<std::string>(key),
			.is_enclosed = next_token_enclosed,
			.is_identified = true
		};
	}

	if (next_token_enclosed)
	{
		return Items::Item
		{
			.type = Tokens::TokenType::Text,
			.value = take_text(next_token_enclosed, true),
			.is_enclosed = true
		};

	};


	return Items::Item
	{
		.type = Tokens::TokenType::Text,
		.value = take_text(next_token_enclosed, true),
		
	};
	


}

char Tokenizer::peek()
{
	return input.front();
}


std::string Tokenizer::take()
{
	std::string view = static_cast<std::string>(input.substr(0, 1));
	input.remove_prefix(1);
	return (view);

}

bool Tokenizer::is_text(const char ch)
{
	return !is_open_bracket(ch) && !is_close_bracket(ch) && !is_separator(ch);
}


std::string Tokenizer::take_text(bool enclosed, bool remove_prefix)
{
	std::string_view::const_iterator boundary;
	if (enclosed)
	{
		boundary = std::find_if(input.begin(), input.end(), is_close_bracket);
	}
	else { boundary = std::find_if(input.begin(), input.end(), is_separator); }


	auto n = std::ranges::distance(input.begin(), boundary);

	std::string view = static_cast<std::string>(input.substr(0, n));
	if (remove_prefix) {
		input.remove_prefix(n);
	}
	return view;

}


Keywords::keyword_t Tokenizer::find_keywords()
{
	for (const auto& [key, iden] : Keywords::base_keywords)
	{
		if (key == take_text(next_token_enclosed, false)) {

			Tokenizer::items_list->emplace_back(std::pair{ key, iden });
			return std::pair{ key, iden };
		}

	
	}
	return {};
}
