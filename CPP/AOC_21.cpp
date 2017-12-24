#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;


template<typename T>
ostream& operator << (ostream& lhs, vector<T>& rhs)
{

  for( auto& r: rhs)
    lhs << r << endl;

  return lhs;

}

template<typename T>
void Rotate( vector<T>& square)
{

  const int size = square.size();
  const int n = size -1;

  for(int i_X = 0; i_X < (size+1)/2; i_X++ )
  {
    for(int i_Y = 0; i_Y < size/2; i_Y++ )
    {
      auto tmp = move(square[i_Y][i_X]);
      square[ i_Y   ][ i_X   ] = move(square[ n-i_X ][ i_Y   ]);
      square[ n-i_X ][ i_Y   ] = move(square[ n-i_Y ][ n-i_X ]);
      square[ n-i_Y ][ n-i_X ] = move(square[ i_X   ][ n-i_Y ]);
      square[ i_X   ][ n-i_Y ] = move(tmp);
    }
  }
}


using Square = vector<string>;


void Flip( Square& square, int axis = 0)
{
  if (axis == 0)
  {
    for( auto& s: square)
      reverse(s.begin(), s.end());
  }
  else
  {

      reverse(square.begin(), square.end());
  }


}



class Rule{

public:

  vector<string> Input;
  vector<string> output;


  bool Enlarge( vector<string> small)
  {

    for( int r = 0; r < 4; r++)
    {
      if ( small == Input )
        return true;
       Flip(0);
       if ( small == Input )
         return true;
       Flip(0);
       Flip(1);
       if ( small == Input )
         return true;

       Flip(1);

       Rotate();
    }

    return false;
  }

private:



  void Rotate()
  {
    ::Rotate(Input);
    //::Rotate(output);
  }
  void Flip(int axis)
  {
    ::Flip(Input,  axis);
    //::Flip(output, axis);

  }





};



int main()
{




  vector<Rule> Rules;

  for (string line; getline(cin, line);)
  {
      Square Small{};
      Square Large{};

      string lhs = line.substr(0, line.find("=>") -1);
      string rhs = line.substr(line.find("=>")+3, line.size() - (line.find("=>")+2) );

      //      cout << line << endl << lhs << ":" << rhs << endl;

      auto it_l = lhs.begin();
      for( auto it_r = find(it_l, lhs.end(), '/');
                it_l < lhs.end();
                it_r = find(it_l, lhs.end(), '/') )
      {
        Small.push_back(string(it_l, it_r));
        it_l = it_r +1;
      }

      it_l = rhs.begin();
      for( auto it_r = find(it_l, rhs.end(), '/');
                it_l < rhs.end();
                it_r = find(it_l, rhs.end(), '/') )
      {
        Large.push_back(string(it_l, it_r));
        it_l = it_r +1;
      }


      Rule R;
      Rules.push_back(R);
      Rules.back().Input  = move(Small);
      Rules.back().output = move(Large);

  }


  Square Start = {{".#."},
                  {"..#"},
                  {"###"}};



  for ( int e = 0; e < 18; e++)
  {

      //cout << Start << endl;

      Square Enlarged;

      const int S =  Start.size();
      const int SS = (Start.size()%2)==0 ? 2 : 3;

      for ( int Y = 0; Y < S/SS; Y++)
      {

        vector<string> Row;
        for( int i = 0; i < SS; i++)
          Row.push_back(move(Start[SS*Y+i]));

        vector<string> EnlargedRow(SS+1, "");

        //cout << Row << endl;
        for ( int X = 0; X < S/SS; X++)
        {


            Square TmpSquare = Row;
            for( auto& r: TmpSquare)
              r = r.substr( SS*X, SS);

            for( auto &R: Rules)
            {
                if ( R.Enlarge(TmpSquare) )
                {
                  //cout << TmpSquare << endl <<  R.output << endl;
                  for( int i = 0; i < SS+1; i++)
                      EnlargedRow[i] += move(R.output[i]);

                  break;
                }
            }
        }
        for( auto &R: EnlargedRow)
          Enlarged.push_back(move(R));

      }


      Start = Enlarged;

  }

  //cout << Start << endl;

  int nhash = 0;
  for ( auto& l: Start)
    nhash += count(l.begin(), l.end(), '#');

  cout << nhash << endl;




  return EXIT_SUCCESS;
}
