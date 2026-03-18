#include <iostream>
#include <iterator>
#include <regex>
#include <string>
 
int main()
{
    std::string s = "Some people, when confronted with a problem, think "
        "\"I know, I'll use regular expressions.\" "
        "Now they have two problems.";
 
    std::regex word_regex("(\\w+)");
    auto words_begin = 
        std::sregex_iterator(s.begin(), s.end(), word_regex);
    auto words_end = std::sregex_iterator();
 
    std::string result = "";
    for (std::sregex_iterator i = words_begin; i != words_end; ++i)
    {
        result += (*i).str() + " ";
    }

    std::cout << result << '\n';
}