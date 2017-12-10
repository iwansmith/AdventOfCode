#include <iostream>
#include <cstdlib>
#include <iterator>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <algorithm>

int main()
{

  std::string line;

  int ValidPhrases = 0;

  while ( getline( std::cin, line ) ) {


    std::unordered_set<std::string> words;

    std::istringstream iss(line);
    std::string word;

    bool isValid = true;
    while ( iss >> word )
    {
        sort(word.begin(), word.end());

        isValid = words.find(word) == words.end();

        if ( not isValid )
          break;

        words.insert(word);
    }

    ValidPhrases += isValid;

  }

  std::cout << "Valid Phrases: " << ValidPhrases << std::endl;
  return EXIT_SUCCESS;
}
