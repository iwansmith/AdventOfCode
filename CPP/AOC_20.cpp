#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;


class Particle
{

public:
  Particle()
  {

    P = {0,0,0};
    V = {0,0,0};
    a = {0,0,0};

    id = 0;

  }
  Particle(int ID, int p_X, int p_Y, int p_Z, int v_X, int v_Y, int v_Z, int a_X, int a_Y, int a_Z)
  {
    id = ID;
    P = {p_X, p_Y, p_Z};
    V = {v_X, v_Y, v_Z};
    a = {a_X, a_Y, a_Z};

  }


  void next()
  {
    for ( int i = 0; i < 3; i++)
    {
        V[i] += a[i];
        P[i] += V[i];
    }

  }


  int Distance()
  {
    return abs(P[0]) + abs(P[1]) + abs(P[2]);
  }


  bool operator==( Particle& rhs)
  {
    return P[0] == rhs.P[0] && P[1] == rhs.P[1] && P[2] == rhs.P[2];
  }


  int id;

private:

  vector<int> P;
  vector<int> V;
  vector<int> a;


};


int main()
{


  vector<Particle> Particles;

  int count(0);
  for( string line; getline(cin, line); count++)
  {
    size_t pos(0);

    line.erase(0, line.find("p=<")+3);
    int p1 = stoi(line, &pos);
    line.erase(0, pos+1);
    int p2 = stoi(line, &pos);
    line.erase(0, pos+1);
    int p3 = stoi(line, &pos);

    line.erase(0, line.find("v=<")+3);
    int v1 = stoi(line, &pos);
    line.erase(0, pos+1);
    int v2 = stoi(line, &pos);
    line.erase(0, pos+1);
    int v3 = stoi(line, &pos);

    line.erase(0, line.find("a=<")+3);
    int a1 = stoi(line, &pos);
    line.erase(0, pos+1);
    int a2 = stoi(line, &pos);
    line.erase(0, pos+1);
    int a3 = stoi(line, &pos);

    Particle P( count, p1, p2, p3, v1, v2, v3, a1, a2, a3);

    Particles.push_back(P);
  }



  for ( int i = 0; i < 100000; i++)
  {

    for( int p1 = 0; p1 < Particles.size(); p1++ )
    {
      bool del_flag = false;
      for( int p2 = p1 +1; p2 < Particles.size(); p2++ )
      {
        if ( Particles[p1] == Particles[p2] )
        {
            del_flag = true;
            Particles.erase(Particles.begin() + p2);
            p2--;
        }
      }
      if ( del_flag )
      {
          Particles.erase(Particles.begin() + p1);
          p1--;
      }
    }

    for ( auto& P: Particles)
      P.next();

    if ( i%100 == 0)
      cout << Particles.size() << endl;


  }



  return EXIT_SUCCESS;
}
