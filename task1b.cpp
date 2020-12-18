#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>

std::vector<int> get_entries()
{
    std::ifstream fromFile("task1.txt");

    std::string fileLine;
    std::string fileSaved;

    std::vector<int> numbers;

    while(getline(fromFile, fileLine))
    { 
        numbers.push_back(std::stoi(fileLine));
    };

    return numbers;
}

int find_result(const std::vector<int>& inp)
{
    for(int i = 0; i < inp.size(); i++)
    {
        for(int j = i; j < inp.size(); j++)
        {
            if(std::binary_search(inp.begin(), inp.end(), 2020 - inp[i] - inp[j]))
            {
                std::cout << "Values are: " << inp[i] << " and " << inp[j] << " and " << 2020 - inp[i] - inp[j] << std::endl;
                return inp[i] * inp[j] * (2020 - inp[i] - inp[j]);
            }
        }
    }
}

int main()
{
    std::vector<int> numbers(get_entries());
    std::sort(numbers.begin(), numbers.end());

    std::cout << find_result(numbers) << std::endl;
}