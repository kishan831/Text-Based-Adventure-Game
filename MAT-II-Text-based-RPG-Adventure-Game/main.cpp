#include <iostream>
using namespace std;

//Player We Are Using In The Game
enum PlayerType {
  Hero,
  Goblin,
  DemonMurloc,
};

// Interface for Player classes
class BasePlayer {

protected:           //Used For Every Child Classes Can Use It.
  int PlayerHealth;
  int MeleeDamage;
  int SpecialAbilitiesDamage;
  PlayerType player;

//Using Setter And Getter For Every Player
public:
  virtual PlayerType const GetPlayerType() = 0;
  virtual int const GetPlayerHealth() = 0;
  virtual void SetPlayerHealth(int value) = 0;
  virtual int const GetPlayerDamage() = 0;
  virtual void SetPlayerDamage(int value) = 0;
  virtual int const GetSpecialAbilitiesDamage() = 0;
  virtual void SetSpecialAbilitiesDamage(int value) = 0;

  virtual void TakeDamage(int damage) = 0;
  virtual int const GetTotalDamage() = 0;

  virtual void RandomizeAttackDamage() = 0;

  virtual void ApplyDamage(BasePlayer *otherPlayer) = 0;

  virtual ~BasePlayer() = 0;
};

BasePlayer:: ~BasePlayer(){}  //

// Implementation of Interface Base for different player class
class Player : public BasePlayer {
public:
  Player(int PlayerHealth, int MeleeDamage, int SpecialAbilitiesDamage, PlayerType Player) {

    this->PlayerHealth = PlayerHealth;
    this->MeleeDamage = MeleeDamage;
    this->SpecialAbilitiesDamage = SpecialAbilitiesDamage;
    this->player = Player;
  }

  PlayerType const GetPlayerType() {
    return player;
  }

  int const GetPlayerHealth() {
    return PlayerHealth;
  }

  void SetPlayerHealth(int value) {
    PlayerHealth = value;
  }

  int const GetPlayerDamage() {
    return MeleeDamage;
  }

  void SetPlayerDamage(int value) {
    MeleeDamage = value;
  }

  int const GetSpecialAbilitiesDamage() {
    return SpecialAbilitiesDamage;
  }

  void SetSpecialAbilitiesDamage(int value) {
    SpecialAbilitiesDamage = value;
  }

  void TakeDamage(int damage)  {
    PlayerHealth -= damage;
  }

  int const GetTotalDamage() {
    return MeleeDamage + SpecialAbilitiesDamage;
  }

  virtual void RandomizeAttackDamage() {
    SetSpecialAbilitiesDamage(5 + (rand() % 10));
  }

  void ApplyDamage(BasePlayer *otherPlayer);

};

// Creating player types by inheriting properties from player class 
class Hero1 : public Player {
public:
  Hero1(int PlayerHealth, int MeleeDamage, int SpecialAbilitiesDamage) : Player(PlayerHealth, MeleeDamage, SpecialAbilitiesDamage, PlayerType::Hero){}

  void RandomizeAttackDamage() {             //Random Damage And Healing For Pubg1Player
    SetSpecialAbilitiesDamage(4 + (rand() % 10));
  }

};

class Goblin1 : public Player {
public:
  Goblin1(int PlayerHealth, int MeleeDamage, int SpecialAbilitiesDamage) : Player(PlayerHealth, MeleeDamage, SpecialAbilitiesDamage, PlayerType::Goblin) {}

  void RandomizeAdditionalDamage() {              //Random Damage And Healing For Enemy1Player
    SetSpecialAbilitiesDamage(6 + (rand() % 10));
  }

};

class DemonMurloc1 : public Player {
public:
  DemonMurloc1(int PlayerHealth, int PlayerDamage, int SpecialAbilitiesDamage) : Player(PlayerHealth, PlayerDamage, SpecialAbilitiesDamage,PlayerType::DemonMurloc) {}

  void RandomizeAdditionalDamage() {               //Random Damage And Healing For Zombie1Player
    SetSpecialAbilitiesDamage(8 + (rand() % 10));
  }

};

//Instructions Of The Battle-Adventure Game
void ShowGameInstruction() {
  cout << endl << endl;
  cout << "!! Welcome To Text Based RPG Game !!" << endl << endl<< endl;

  cout << "Instructions :" << endl;
  cout << "This Is The Messege From The King Of Asgard ! " << endl;
  cout << "Hero We Are In Great In Danger Our City Is Captured By DemonMurloc. " << endl;
  cout << "Thanks For Your Kindness For Having You Here To Save Ourselves from The rage Of Goblin " << endl;
  cout << "Your Job Is To Defeat DemonMurloc And Save Our City. " << endl;
  cout << "Our City Will  Always Be Debt Of Your Superiority " << endl;
  cout << "There Are 4 Types Of Special Items You will Gain To Defeat DemonMurloc Try To Collect All Of Them. " << endl;
  

  cout << endl << endl;
} 


//Intitial Stats Of Players
void ShowInitialStats(BasePlayer* player, int index) {
  switch(index) {
    case 1:
      cout << "Pubg Player - Whatever Tt Takes !" << endl;
      break;

  }

  cout << "Player health : " << player->GetPlayerHealth() << endl;
  cout << "Melee Damage : " << player->GetPlayerDamage() << endl;

}

//Health Of Two Player Who Will Fight
void ShowPlayerStats(BasePlayer* player1, BasePlayer* player2) {
  cout << "Hero : Health = " << player1->GetPlayerHealth() << endl;
  cout << "Goblin : Health = " << player2->GetPlayerHealth() << endl << endl << endl;
}


//Creation Of Players 
BasePlayer* CreatePlayerOfType(int value) {

  switch(value) {
    case 1: {
        BasePlayer* powerPlayer = new Hero1(200, 25, 0);
        ShowInitialStats(powerPlayer, 1);
        return powerPlayer;
      }
      break;
  
    case 2: {
        BasePlayer* skilledPlayer = new Goblin1(80, 10, 0);
        ShowInitialStats(skilledPlayer, 2);
        return skilledPlayer;
      }
      break;

    case 3: {
        BasePlayer* ragedPlayer = new DemonMurloc1(150, 30, 10);
        ShowInitialStats(ragedPlayer, 3);
        return ragedPlayer;
      }
      break;

    Default:
    return nullptr;
    break;
  } 
  return nullptr;
}


//Applying Action Of Players Taking Input From User
void LevelOne(BasePlayer* player1, BasePlayer* player2) {
  char playerAction;

  cin >> playerAction;

  if(playerAction == 'a' || playerAction == 'A') {

        player2->ApplyDamage(player1);
        player1->ApplyDamage(player2);
      }

}

void LevelTwo(BasePlayer* player1, BasePlayer* player2,BasePlayer* player3) {
  char playerAction;

  cin >> playerAction;

  if(playerAction == 'a' || playerAction == 'A') {

        player1->ApplyDamage(player2);
        player2->ApplyDamage(player1);
        player3->ApplyDamage(player1);
      }

}

//Player Selection From User
BasePlayer* LevelOneFight(int value) {
  int playerChoice = 0;

  cout << endl;
  cout << "Player " << value << " : Select player for first Level (1.Hero, 2.Goblin )" << endl;
  cout << "Player Selected : " ;


  while(true) {
    cin >> playerChoice;
    cout << endl ;


    if(!cin || !(playerChoice == 1 || playerChoice == 2 )) {
      cin.clear();
      
      cout << "Player Type : " ;
      continue;
    }
    else  {     
      break;
    }
  
  }
  return CreatePlayerOfType(playerChoice);  
}


BasePlayer* LevelTwoFight(int value,int value1) {
  int playerChoice = 0;

  cout << endl;
  cout << "Player " << value << " : Select player for first Level (1.Hero, 2.Goblin )" << endl;
  cout << "Player Selected : " ;


  while(true) {
    cin >> playerChoice;
    cout << endl ;


    if(!cin || !(playerChoice == 1 || playerChoice == 2 )) {
      cin.clear();
      
      cout << "Player Type : " ;
      cout << "Player Type : " ;
      continue;
    }
    else  {     
      break;
    }
  
  }
  return CreatePlayerOfType(playerChoice);  
}


//Battle Begin With Two Player
void BattleForLevelOne(BasePlayer* player1, BasePlayer* player2) {
  int playerAction = 1;
  cout << endl << endl;
  cout << "! Battle Started !" << endl;

  while(true) {

    if( player1->GetPlayerHealth() <= 0 ) {
      cout << "!! Player 2 won !!" << endl << endl;
      break;
    }
    else if(player2->GetPlayerHealth() <= 0) {
      cout << "!! Player 1 won !!" << endl << endl;
      break;
    }

    cout << "Player " << playerAction << " : Enter 'A' To Attack " << endl;
    cout << "Player " << playerAction << " : ";

    if(playerAction == 1) {
      LevelOne(player1, player2);
      ShowPlayerStats(player1, player2);
      playerAction++;
    }

    else {   
      LevelOne(player2, player1);
      ShowPlayerStats(player1, player2);
      playerAction--;
    }    
  }

}

//Battle Begin With Two Player
void BattleForLevelTwo(BasePlayer* player1, BasePlayer* player2,BasePlayer* player3) {
  int playerAction = 1;
  cout << endl << endl;
  cout << "! Battle Started !" << endl;

  while(true) {

    if( player1->GetPlayerHealth() <= 0 ) {
      cout << "!! Player 2 won !!" << endl << endl;
      break;
    }
    else if( player2->GetPlayerHealth() <= 0 && player3->GetPlayerHealth() <= 0 ) {
      cout << "!! Player 1 won !!" << endl << endl;
      break;
    }

    cout << "Player " << playerAction << " : Enter 'A' To Attack " << endl;
    cout << "Player " << playerAction << " : ";

    if(playerAction == 1) {
      LevelTwo(player1,player2,player3);
      ShowPlayerStats(player1, player2);
      playerAction++;
    }

    else {   
      LevelTwo(player2, player1,player3);
      ShowPlayerStats(player1, player2);
      playerAction--;
    }    
  }
}

//Apply Damage On otherPlayer And Apply Some Special Abilities Of Every Player ( We Have Given In The Program ).... 
void Player::ApplyDamage(BasePlayer *otherPlayer) {
  otherPlayer->RandomizeAttackDamage();   // To Randomize Attack Damage

  switch(otherPlayer->GetPlayerType()) {

    case Hero:
      if( (GetPlayerType() == Goblin) && (rand() % 4 == 0)) {
        cout << "Special Ability Used By Hero - Attack Blocker" << endl;
        cout << "Damage given = 0" << endl;
        break;
      }

      if(rand() % 4 == 0) {
        otherPlayer->SetSpecialAbilitiesDamage( 2 * otherPlayer->GetSpecialAbilitiesDamage());
        otherPlayer->SetPlayerDamage( 2 * otherPlayer->GetPlayerDamage());
        TakeDamage(otherPlayer->GetTotalDamage());

        cout << "Special Ability Used by Hero - Double Attack" << endl;
        cout << "Damage given by Hero = " << otherPlayer->GetTotalDamage() << endl;

        otherPlayer->SetPlayerDamage(otherPlayer->GetPlayerDamage() / 2);
        break;
      }
      else {
        TakeDamage(otherPlayer->GetTotalDamage());
        cout << "Damage given by Hero = " << otherPlayer->GetTotalDamage() << endl;
      }
      break;

    case Goblin:
      if(rand() % 4 == 0) {
        cout << "Special Ability Used - Heal + Damage" << endl;

        TakeDamage(otherPlayer->GetTotalDamage());
        cout << "Damage given by Goblin= " << otherPlayer->GetTotalDamage() << endl;

      }

      else {
        TakeDamage(otherPlayer->GetTotalDamage());
        cout << "Damage given by Goblin = " << otherPlayer->GetTotalDamage() << endl;
      }
      break;


    case DemonMurloc:
      if( (GetPlayerType() == Hero) && (rand() % 4 == 0)) {
        cout << "Special Ability Used By Hero - Attack Blocker" << endl;
        cout << "Damage given by Murloc = 0" << endl;
        break;
      }

      if( (GetPlayerHealth() <= 0.3 * 100)) {
        otherPlayer->SetPlayerDamage( (otherPlayer->GetPlayerDamage() + 100/(otherPlayer->GetPlayerHealth())) );
        cout << "Special Ability Used - Ground Slash" << endl;

          if((rand() % 4 == 0)) {
            otherPlayer->SetSpecialAbilitiesDamage( 1.5 * otherPlayer->GetSpecialAbilitiesDamage());
            otherPlayer->SetPlayerDamage( 1.5 * otherPlayer->GetPlayerDamage());
            TakeDamage(otherPlayer->GetTotalDamage());

            cout << "Special Ability Used by DemonMurloc - Speed Dash" << endl;
            cout << "Damage given = " << otherPlayer->GetTotalDamage() << endl;

            otherPlayer->SetPlayerDamage(otherPlayer-> GetPlayerDamage() / 2);
            break;
          }

          else {
            TakeDamage(otherPlayer->GetTotalDamage());
            cout << "Damage given by Murloc = " << otherPlayer->GetTotalDamage() << endl;
          }   
      }

      else {
        TakeDamage(otherPlayer->GetTotalDamage());
        cout << "Damage given by Murloc= " << otherPlayer->GetTotalDamage() << endl;
      }
      break;
  }

}


int main() {

  char restart; // Used Restarting Of Game  

  while(true) {

    ShowGameInstruction();
   
    BasePlayer *player1  = LevelOneFight(1);
    BasePlayer *player2  = LevelOneFight(2);

    BattleForLevelOne(player1,player2);

    cout << endl << endl;

    cout << "----------Level Two Started----------- " << endl << endl;

    BasePlayer *player3  = LevelTwoFight(1,2);
    BasePlayer *player4  = LevelTwoFight(2,3);

    BattleForLevelTwo(player1,player2,player3);

    cout << endl << endl;


    cout << "Press 'E' To Play Again" << endl;
    cin >> restart;

    if(!(restart == 'e' || restart == 'E')) {
      cout << "I Will Try To Improvise This Game For You See You Next Time !" << endl;
      break;
    }
  }
  return 0;
}