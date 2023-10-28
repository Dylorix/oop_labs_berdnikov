#include "keyboard.h"

namespace laba4
{
	Keyboard::Keyboard() {}
	Keyboard::~Keyboard() {}

	void Keyboard::addCommand(const std::string& key, const std::string& cmd)
	{
		_commands.insert({key, cmd});
	}

	void Keyboard::parse(std::string keys)
	{
		std::stringstream keyssStringstream(keys);
		std::string str;

		for (int i = 0; i < keys.length(); i++)
		{
			if (getline(keyssStringstream, str, '>'))
			{
				_keysV.push_back(str);
			}
		}
	}

	void Keyboard::workflow(const std::string& strKey)
	{
		parse(strKey);
		for (const auto& i : _keysV)
		{
			std::cout << _commands[i] << std::endl;
		}
		std::cout << std::endl;
	}

	void Keyboard::undo() //Ctrl+Z
	{
		_keysV.erase(_keysV.end() - 1);
		for (const auto& i : _keysV)
		{
			std::cout << _commands[i] << std::endl;
		}
		std::cout << std::endl;
	}

	void Keyboard::copy() //Ctrl+C Ctrl+V
	{
		_keysV.insert(_keysV.end(), _keysV.end()-1, _keysV.end());
		for (const auto& i : _keysV)
		{
			std::cout << _commands[i] << std::endl;
		}
		std::cout << std::endl;
	}
}