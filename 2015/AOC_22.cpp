#include <iostream>
#include <cstdlib>
#include <algorithm>

#include "CommonTools.h"

using namespace std;


struct Spell
{

  const int cost;
  const int Damage;
  const int Healing;

  const int EffectDuration;

  const int EffectArmour;
  const int EffectDamage;
  const int EffectMana;

  int EffectCounter = 0;



};

struct Player
{
  int Mana;
  int HP;
  int Damage;
  int Armour = 0;
};



pair<int, int> PlayRound( Player& Henry, Player& Boss, vector<Spell>& Spells, Spell& S)
{
  /**
   * return 1  if Henry Wins
   * return 0  if NoOne Wins
   * return -1 if Boss Wins or move isn't valid
   */

  Henry.HP -= 1;
  if (Henry.HP <= 0 ) return {-1, 0};

  int Cost = 0;

  // Run over spells and apply
  Henry.Armour = 0;
  for( auto& Sp :Spells)
  {
    // Player casts a spell
    if ( Sp.EffectCounter > 0)
    {
      Sp.EffectCounter--;

      Boss.HP      -= Sp.EffectDamage;
      Henry.Armour += Sp.EffectArmour;
      Henry.Mana   += Sp.EffectMana;
    }
  }

  if ( Boss.HP <= 0 ) return {1, Cost};



  // Henry Attacks

  if ( S.EffectCounter > 0 or S.cost > Henry.Mana)
    return {-1, Cost};


  Cost = S.cost;
  Henry.Mana      -= S.cost;
  Boss .HP        -= S.Damage;
  Henry.HP        += S.Healing;
  S.EffectCounter  = S.EffectDuration;



  if ( Boss.HP <= 0 ) return {1, Cost};

  // Run over spells and apply
  Henry.Armour = 0;
  for( auto& Sp :Spells)
  {
    // Player casts a spell
    if ( Sp.EffectCounter > 0)
    {
      Sp.EffectCounter--;

      Boss.HP      -= Sp.EffectDamage;
      Henry.Armour += Sp.EffectArmour;
      Henry.Mana   += Sp.EffectMana;
    }
  }

  if ( Boss.HP <= 0 ) return {1, Cost};

  // Boss Attacks
  Henry.HP -= max(Boss.Damage - Henry.Armour, 1);

  if ( Henry.HP <= 0 ) return {-1, Cost};


  return {0, Cost};


}


int PlayGame( Player Henry, Player Boss, vector<Spell> Spells, int depth = 0, int maxdepth = 20)
{
  if ( depth == maxdepth )
    return 999999;

  int MinCost = 999999;

  for(int S = 0; S < Spells.size(); S++)
  {

    Player H       = Henry;
    Player B       = Boss;
    auto NewSpells = Spells;

    auto RoundOutcome = PlayRound(H, B, NewSpells, NewSpells[S]);

    int CostRound = RoundOutcome.second;
    if (RoundOutcome.first == -1 )
      continue;

    if ( RoundOutcome.first == 1 )
      return CostRound;

    if ( RoundOutcome.first == 0 )
    {

        int CostGame = PlayGame(H, B, NewSpells, depth+1, maxdepth);
        MinCost = min( CostGame + CostRound, MinCost );
    }

  }




  return MinCost;
}


int main()
{


  Spell MagicMissile {53,  4, 0, 0, 0, 0, 0  };
  Spell Drain        {73,  2, 2, 0, 0, 0, 0  };
  Spell Shield       {113, 0, 0, 6, 7, 0, 0  };
  Spell Poision      {173, 0, 0, 6, 0, 3, 0  };
  Spell Recharge     {229, 0, 0, 5, 0, 0, 101};

  vector<Spell> Spells;

  Spells.push_back( MagicMissile );
  Spells.push_back( Drain        );
  Spells.push_back( Shield       );
  Spells.push_back( Poision      );
  Spells.push_back( Recharge     );

  Player Henry{500, 50,  0};
  Player Boss {0  , 51,  9};

  cout << PlayGame(Henry, Boss, Spells) << endl;

  return EXIT_SUCCESS;
}
