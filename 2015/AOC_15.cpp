#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <tuple>
#include "CommonTools.h"


using namespace std;


struct Ingredient
{
  string name;
  int    capacity;
  int    durability;
  int    flavour;
  int    texture;
  int    calorie;

  int nSpoon = 0;

};

template<typename T>
int GetMaxScore( vector<Ingredient>& VI, const int nSpoon, T It_VI)
{

  int MaxScore = 0;

  if ( It_VI != VI.end()-1 )
  {
      for ( int spoon = 0; spoon <= nSpoon; spoon++)
      {

          It_VI->nSpoon = spoon;
          int Score;
          Score =  GetMaxScore(VI, nSpoon - spoon, It_VI+1);

          if (Score > MaxScore)
            MaxScore = Score;
      }
  }

  else if ( It_VI == VI.end()-1 )
  {
      It_VI->nSpoon = nSpoon;

      int Capacity = 0;
      int Durability = 0;
      int Flavour = 0;
      int Texture = 0;
      int Calorie = 0;

      for(auto& I:VI)
      {

        Capacity   += I.nSpoon * I.capacity;
        Durability += I.nSpoon * I.durability;
        Flavour    += I.nSpoon * I.flavour;
        Texture    += I.nSpoon * I.texture;
        Calorie    += I.nSpoon * I.calorie;
      }


      Capacity   = max( 0, Capacity   );
      Durability = max( 0, Durability );
      Flavour    = max( 0, Flavour    );
      Texture    = max( 0, Texture    );

      MaxScore = Capacity * Durability * Flavour * Texture;

      if (Calorie != 500)
        return 0;
  }

  return MaxScore;

}



int main()
{



  vector<Ingredient> Ings;
  for( string line; getline(cin, line);)
  {
      vector<string> Input = SplitString<string>(line);

      Ingredient I;
      I.name       = Input[0];
      I.capacity   = stoi(Input[2]);
      I.durability = stoi(Input[4]);
      I.flavour    = stoi(Input[6]);
      I.texture    = stoi(Input[8]);
      I.calorie    = stoi(Input[10]);

      Ings.push_back(I);

  }

  sort(Ings.begin(), Ings.end(), [](Ingredient& lhs, Ingredient& rhs)
       {

          return lhs.calorie > rhs.calorie;

       });


  cout << GetMaxScore(Ings, 100, Ings.begin()) << endl;

  return EXIT_SUCCESS;
}
