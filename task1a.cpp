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
    for(int x : inp)
    {
        if(std::binary_search(inp.begin(), inp.end(), 2020 - x))
        {
            std::cout << "Values are: " << x << " and " << 2020 - x << std::endl;
            return x * (2020 - x);
        }
    }
}

int main()
{
    std::vector<int> numbers(get_entries());
    std::sort(numbers.begin(), numbers.end());

    std::cout << find_result(numbers) << std::endl;
}