#include "arg_parser.h"
#include <fstream>
#include <ranges>
#include <string>

int main(int argc, char** argv)
{
	arguments::ArgParser args(argc, argv);
	auto  verbose = (args.get(std::string(arguments::verbose)) != std::nullopt);

	if(auto filePath = args.get(std::string(arguments::file_path)); filePath != std::nullopt)
	{
		std::ifstream file(filePath.value());
		std::unordered_map<std::string, uint32_t> word_map;

		if(!file)
		{
			std::cerr << "Cannot open " << filePath.value() << '\n';
			return 1;
		}

		auto words = std::ranges::istream_view<std::string>(file);

		for(const auto& w : words)
		{
			if(word_map.contains(w))
				++word_map[w];
			else
				word_map[w] = 0;
		}
		
		auto cntStr = args.get(std::string(arguments::count));

		uint32_t top_word_list_len = DEFAULT_TOP_WORDS_COUNT;
		if (cntStr.has_value())
		{
			auto [ptr, ec] = std::from_chars(cntStr.value().data(), cntStr.value().data() + cntStr.value().size(), top_word_list_len);
			if (ec != std::errc())
			{
				std::cout << "std::from_chars() failed, invalid --count parameter!\n";
				return static_cast<int>(ec);
			}
		}
		else if (verbose)
		{
			std::cout << "No --" << arguments::count << " argument used, falling back to default: " << DEFAULT_TOP_WORDS_COUNT << ".\n";
		}
	}
	return 0;
}
