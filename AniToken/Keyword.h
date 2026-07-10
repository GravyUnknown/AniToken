#pragma once
#include <map>
#include <array>
#include <string>
namespace Keywords {
	enum class Descriptors
	{
		AudioCodec,
		VideoCodec,
		VideoResolution,
		SeriesName,
		EpisodeTitle,
		ReleaseGroup,
		FileExtension,
		ReleaseYear,
		Undefined

	};

	using keyword_t = std::pair<std::string_view, Descriptors>;
	using keyword_string_t = std::pair<std::string, Descriptors>;

	
	

// The ultimate clean setup
static constexpr std::array<keyword_t, 3> base_keywords = { {
	{"1080p", Descriptors::VideoResolution},
	{"H.264", Descriptors::VideoCodec},
	{"FLAC", Descriptors::AudioCodec}
} };


using item_container_t = std::vector<keyword_string_t>;



};




