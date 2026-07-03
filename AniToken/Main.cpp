#include "AniToken.h"

int main()
{
	const auto& something = AniToken("[TaigaSubs]_Toradora!_(2008)_-_01v2_-_Tiger_and_Dragon_[1080p_H.264_FLAC][BAD7A16A].mkv");

	const auto& sm = something.items_list;

	for (const auto s : sm)
	{
		continue;
	}

}