#include "arg_parser.h"
namespace arguments{
	ArgParser::ArgParser(int argc, char** argv)
	{
		std::vector<std::string> args(argv + 1, argv + argc);

		for(const auto& arg : args)
		{
			if(arg.starts_with("--"))
			{
				auto pos = arg.find('=');
				if(pos != std::string::npos)
				{
					std::string key = arg.substr(2, pos -2);
					std::string value = arg.substr(pos + 1);
					options[key] = value;
				}
				else
				{
					options[arg.substr(2)] = "true";
				}
			}
		}
	}

	std::optional<std::string> ArgParser::get(const std::string& key) const
	{
		if(arg_map::const_iterator  it = options.find(key); it != options.cend())
			return it->second;

		return std::nullopt;
	}

	ArgParser::~ArgParser()
	{
		std::cout << "ArgParser::~ArgParser()" << std::endl;
	}
}
