#include <vector>
#include <string>
#include <unordered_map>
#include <optional>
#include <iostream>

namespace arguments
{
	inline constexpr std::string_view file_path	= "file";
	inline constexpr std::string_view verbose	= "verbose";
	inline constexpr std::string_view count		= "count";

	class ArgParser
	{

		public:
			using arg_map = std::unordered_map<std::string, std::string>;

		private:
			arg_map options;

		public:
			ArgParser(int argc, char** argv);
			~ArgParser();
			std::optional<std::string> get(const std::string& key) const;
	};
}
