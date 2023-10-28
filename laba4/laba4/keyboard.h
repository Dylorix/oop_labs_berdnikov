#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

namespace laba4
{
	class Keyboard
	{
	public:
		Keyboard();
		~Keyboard();

		void addCommand(const std::string& key, const std::string& cmd);

		void workflow(const std::string& strKey);

		void copy();

		void undo();

	private:
		std::map<std::string, std::string> _commands;
		std::vector<std::string> _keysV;

		void parse(std::string keys);
	};
}