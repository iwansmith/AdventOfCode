#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <deque>
#include <algorithm>
#include <map>
#include <unordered_set>
using namespace std;

struct Pgam{
  int weight;
  vector<string> daughters;
};


int GetWeight( map<string, Pgam> &Programmes, string Name)
{
  Pgam& CP = Programmes.at(Name);

  if ( CP.daughters.empty() )
    return CP.weight;

  unordered_set<int> v_Weight;
  int Weight = 0;
  for ( auto& D : CP.daughters )
  {
    int w = GetWeight(Programmes, D);
    v_Weight.insert(w);
    Weight += w;
  }

  if( v_Weight.size() > 1 )
  {
    for ( auto& D : CP.daughters )
    {
      cout << D << "  " << GetWeight(Programmes, D) << "  " << Programmes[D].weight<< endl;
    }
    exit(0);
  }
  return Weight + CP.weight;
}



int main()
{

  deque<string> RemainingPrograms;
  deque<string> TopLayer;
  deque<string> SecondLayer;

  map<string, Pgam> Programmes;






  { // scope to avoid namespace pollution
    string line;
    while ( getline(cin, line))
    {
      if ( line.find("->") >=  line.size())
        TopLayer.push_back(string( line.begin(), line.begin()+line.find(' ')));
      else
        RemainingPrograms.push_back(line);

      {
        vector<string> data;
        istringstream ss(line);
        string datum;
        while( ss >> datum )
          data.push_back(datum);

        Pgam current_Pgam;
        current_Pgam.weight = atoi(string(data[1].begin()+1, data[1].end()-1).c_str());
        if ( data.size() > 3 )
          for_each(data.begin()+3, data.end(), [&current_Pgam](auto& s)
          {
              current_Pgam.daughters.push_back( string( s.begin(), find(s.begin(), s.end(), ',') ) );
          });


        Programmes[data[0]] = current_Pgam;
      }
    }
  }
  while ( RemainingPrograms.size() != 1)
  {
    for( auto& l: TopLayer)
    {
      auto FoundLine = find_if(RemainingPrograms.begin(), RemainingPrograms.end(), [&l](auto p_line)
      {
        return p_line.find(l) < p_line.size();
      });

      if ( FoundLine != RemainingPrograms.end() )
      {
        SecondLayer.push_back(string( FoundLine->begin(), FoundLine->begin()+FoundLine->find(' ')));
        RemainingPrograms.erase(FoundLine);
      }
    }

    TopLayer = move(SecondLayer);
  }

  cout << RemainingPrograms[0] << endl;

  cout << GetWeight(Programmes, "cyrupz")<< endl;


  return EXIT_SUCCESS;
}

