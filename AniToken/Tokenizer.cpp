#include "Tokenizer.h"
#include "Identifier.h"
#include "Token.h"
#include <iterator>
#include <algorithm>

using namespace Identifiers;

Tokenizer::Tokenizer(std::string_view filename)
	:input(filename)
{
	for (int i = 0; i < filename.size(); i++)
	{
		item_list.emplace_back(Tokenize());
	}
}

Items::Item Tokenizer::Tokenize()
{
	bool next_token_enclosed = false;

	if (is_open_bracket(peek()))
	{
		next_token_enclosed = true;
		return Items::Item{
			.type = Tokens::TokenType::OpenBracket,
			.value = take()
		};
	};

	if (is_close_bracket(peek()))
	{
		next_token_enclosed = false;
		return Items::Item{
			.type = Tokens::TokenType::CloseBracket,
			.value = take()
		};
	};


	if (is_separator(peek()))
	{
		/*	if (separator.empty())
			{
				find_separator(peek());
			}*/

		return Items::Item{
			.type = Tokens::TokenType::Separator,
			.value = take()
		};


	};

	if (next_token_enclosed)
	{
		return Items::Item
		{
			.type = Tokens::TokenType::Text,
			.value = take_text(next_token_enclosed),
			.is_enclosed = true
		};
	};

	return Items::Item
	{
		.type = Tokens::TokenType::Separator,
		.value = take_text(next_token_enclosed),
		
	};
	


}

char Tokenizer::peek()
{
	return input.front();
}


std::string Tokenizer::take(size_t n = 1)
{
	std::string_view view = input.substr(0, 1);
	input.remove_prefix(n);
	return static_cast<std::string>(view);

}

bool Tokenizer::is_text(const char ch)
{
	return !is_open_bracket(ch) && !is_close_bracket(ch) && !is_separator(ch);
}


std::string Tokenizer::take_text(bool enclosed)
{
	std::string_view::const_iterator boundary;
	if (enclosed)
	{
		auto boundary = std::find_if(input.begin(), input.end(), is_close_bracket);
	}
	else { auto boundary = std::find_if(input.begin(), input.end(), is_close_bracket); }


	int n = std::ranges::distance(input.begin(), boundary);

	std::string_view view = input.substr(0, n);
	input.remove_prefix(n);
	return static_cast<std::string>(view);

}


