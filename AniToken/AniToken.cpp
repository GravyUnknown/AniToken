#include "AniToken.h"


AniToken::AniToken(std::string_view filename)
{
	Tokenizer tokenizer(filename, AniToken::tokens_list, AniToken::items_list);
	Parser parser(AniToken::items_list, AniToken::tokens_list);
}