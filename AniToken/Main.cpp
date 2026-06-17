#include "Tokenizer.h"
#include "Parser.h"
#include <iostream>
#include <string>

int main()
{
	const auto& something = Tokenizer("[TaigaSubs]_Toradora!_(2008)_-_01v2_-_Tiger_and_Dragon_[1080p_H.264_FLAC][BAD7A16A].mkv");
	const auto& sm = Parser(something.token_list);
	const auto& s = sm.item_list;
	for (auto s : s)
	{
		continue;
	}

}