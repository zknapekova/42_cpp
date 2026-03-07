#include <string>
#include <iostream>
#include <fstream>


void	replace(std::string &s1, std::string &s2, std::string &content)
{
	size_t ind = content.find(s1);
	while (ind != std::string::npos)
	{
		content.erase(ind, s1.size());
    	content.insert(ind, s2);
    	ind = content.find(s1, ind + s2.size());
	}
}



int main(int argc, char *argv[])
{
	std::string s1, s2;
	const char* input_file;
	std::string line;
	
	if (argc != 4)
	{
		std::cerr << "One or more input parameter are missing" << std::endl;
		return 1;
	}
	s1 = argv[2];
	if (s1.size() == 0)
	{
		std::cerr << "s1 cannot be empty\n";
		return 1;	
	}
	s2 = argv[3];
		
	input_file = argv[1];
	std::ifstream input(input_file);
	if (!input)
	{
		std::cerr << "Opening input file failed\n";
		return 1;
	}
	
	std::string temp = std::string(input_file) + ".replace";
	const char* output_file = temp.c_str();
	
	std::ofstream output(output_file);
	if (!output)
	{
		std::cerr << "Opening output file failed\n";
		return 1;
	}
	
	while (std::getline(input, line))
    {
        if (!input.eof())
		{
        	line.append("\n");
		}
        replace(s1, s2, line);
        output << line;
    }
	output.close();
	
	return 0;
}
