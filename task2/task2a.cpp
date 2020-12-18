#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>

class validator
{
    private:
        int lower_bound;
        int upper_bound;
        char letter;
        std::string password;
    
    public:
        validator(std::string inp)
        {
            lower_bound = std::stoi(inp.substr(0, inp.find("-")));
            inp = inp.substr(inp.find("-") + 1);

            upper_bound = std::stoi(inp.substr(0, inp.find(" ")));
            inp = inp.substr(inp.find(" ") + 1);

            letter = inp[0];

            password = inp.substr(3);
        }

        bool validate()
        {
            int occurences = std::count(password.begin(), password.end(), letter);
            return lower_bound <= occurences && occurences <= upper_bound;
        }
};

std::vector<validator> get_all_passwords()
{
    std::ifstream fromFile("task2.txt");

    std::string fileLine;
    std::string fileSaved;

    std::vector<validator> pss;

    while(getline(fromFile, fileLine))
    { 
        pss.push_back(validator(fileLine));
    };

    return pss;
}

int passwords_correct(const std::vector<validator>& pss)
{
    return std::count_if(pss.begin(), pss.end(), [] (validator v) { return v.validate(); } );
}

int main()
{
    std::cout << passwords_correct(get_all_passwords()) << std::endl;
}