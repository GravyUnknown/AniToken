#pragma once
#include <map>
#include <vector>
#include <string>
class Keywords {
	enum Descriptors
	{
		AudioCodec,
		VideoCodec,
		VideoResulution,
		SeriesName,
		EpisodeTitle,
		ReleaseGroup,

	};

	using keyword_t = std::vector<std::pair<std::string, Descriptors>>;

	static const keyword_t base_keywords{
		{"1080p", VideoResulution},
		{"H.264", VideoCodec},
		{"FLAC", AudioCodec}
	};


};




