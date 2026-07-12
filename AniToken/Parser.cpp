#include "Parser.h"
#include <algorithm>


using namespace Keywords;

Parser::Parser(Keywords::item_container_t& items, Items::token_container_t& tokens)
	: received_tokens(tokens), 
	received_items(items)
{
	received_items.reserve(15);

	for (auto& i : received_tokens)
	{
		/*		if (parse_episode_number)
				{
					AddItem(ParseEpisodeNumber(i));

				}

				if (parse_episode_title)
				{
					AddItem(ParseEpisodeTitle(i));
				}

				if (parse_series_title)
				{
					AddItem(ParseSeriesTitle(i));
				}

				AddItem(ParseKeywords(i));
			}
		*/
		(void)i;
	}
	
	;
	AddItem(ParseFileExtension());
	AddItem(ParseReleaseGroup());
	AddItem(ParseReleaseYear());
	AddItem(ParseEpisodeNumber());
}


void Parser::AddItem(keyword_string_t returnValue)
{
	if (!returnValue.first.empty())
	{
		Parser::received_items.emplace_back(returnValue);
	}
}

keyword_string_t Parser::ParseFileExtension()
{

	Items::Item& item = received_tokens.back();
	item = {
		.type = item.type,
		.elementtype = Descriptors::FileExtension,
		.value = item.value,
		.is_identified = true
	};
	return { item.value.substr(1), Descriptors::FileExtension};

	
}

keyword_string_t Parser::ParseEpisodeNumber(Items::Item& i)
{
	(void)i;
	return {};
}

keyword_string_t Parser::ParseReleaseGroup()
{
	Items::Item& item = received_tokens[1];
	if (item.is_enclosed)
	{	
		item = {
			.type = item.type,
			.elementtype = Descriptors::ReleaseGroup,
			.value = item.value,
			.is_identified = true
		};
		return { item.value, Descriptors::ReleaseGroup };
	}

	return {};
}

keyword_string_t Parser::ParseReleaseYear()
{
	auto release_year_candidate = std::find_if(received_tokens.begin(), received_tokens.end(), [](const Items::Item& i) 
		{return i.is_enclosed &&
		i.value.length() == 4;});

	if (release_year_candidate == received_tokens.end())
	{
		return {};
	}

	const auto confirm_year = std::ranges::all_of(release_year_candidate->value.begin(), release_year_candidate->value.end(), 
		[](const char ch)
		{return ('0' <= ch && ch <= '9');});
	if (confirm_year)

	{
		*release_year_candidate = {
			.type = release_year_candidate->type,
			.elementtype = Descriptors::ReleaseYear,
			.value = release_year_candidate->value,
			.is_enclosed = true,
			.is_identified = true,

		};
		return { release_year_candidate->value, Descriptors::ReleaseYear };

	}

	return {};
}

keyword_string_t Parser::ParseEpisodeNumber()
{
	auto episode_number_probable = std::find_if(received_tokens.begin(), received_tokens.end(),
		[](const Items::Item& i)
		{return std::isdigit(i.value.front()) && !(i.is_enclosed); });

	if (episode_number_probable == received_tokens.end())
	{
		return {};
	}
	std::string retreived_episode_number = episode_number_probable->value.substr(0, episode_number_probable->value.find("v"));


	return { retreived_episode_number, Descriptors::EpisodeNumber };
		

}