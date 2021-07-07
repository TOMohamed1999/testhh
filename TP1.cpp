#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;
class Stratigie{
    public:
    string name;
    int player;
    Stratigie(string s,int p){
      name=s;
      player=p;
    };
    void afficher(){

         cout << "Player : " << player << " , Str  :  " << name <<endl;

    }
};
class Player {
    public:
    int numP;
    vector <Stratigie*> player_stratigies;
    Player(int p){
      numP=p;
    };

    void add(Stratigie *s){
       player_stratigies.insert(player_stratigies.end(), s);

    }
    void afficher(){
         cout << "Player : " << numP << " , nbST: " <<player_stratigies.size() <<endl;
        for(int i=0;i<player_stratigies.size();i++){
            player_stratigies.at(i)->afficher();
        }
    }

};
class Profil{
  public:
  vector<Stratigie*> profil;
  vector<double> gain;
  Profil(){

  }

  void add(Stratigie*s,double g){
    profil.insert(profil.end(),s);
    gain.insert(gain.end(),g);

  }
void afficher(){
        for(int i=0;i<profil.size();i++){
           cout << "Gain: " << gain.at(i) << "  ";
            profil.at(i)->afficher();
        }
}
};

class Game{
public:
vector<Profil*> issueJeu;
vector<Player*> listplayers;
int nbplayers;
Game(int nb){
  nbplayers=nb;
}

void addPlayer(Player *p){
    listplayers.insert(listplayers.end(),p);
}
int calculerTotalNbStratigies(int deb){
  int s=1;
  for(int i=deb;i<listplayers.size();i++)
         s=s*listplayers.at(i)->player_stratigies.size();
   return s;
}

void PossiblesProfiles(int k){ 
  int t=calculerTotalNbStratigies(k+1);
  int max=calculerTotalNbStratigies(0);
  int cpt=0;
  int n=listplayers.at(k)->player_stratigies.size();
  Profil *p;
  
  while(cpt<max){
    for(int i=0;i<n;i++){
      for(int j=0;j<t;j++){
        if(k!=0){
          issueJeu.at(cpt)->add(listplayers.at(k)->player_stratigies.at(i),cpt);
        } 
        else{ 
          p=new Profil();
          p->add(listplayers.at(k)->player_stratigies.at(i),cpt);
          issueJeu.insert(issueJeu.end(),p);
        }
        cpt++;
      }
    }
  }
}
void createFinaleProfilsList(){
  for(int i=0;i<nbplayers;i++){
    PossiblesProfiles(i);
  }
} 
void afficher(){
         cout << "NBProfils: " << issueJeu.size() << "   ,  NBSt: " << calculerTotalNbStratigies(0)<<endl;
        for(int i=0;i<issueJeu.size();i++){
            issueJeu.at(i)->afficher();
               cout <<endl;
        }

}



};
int main(){
int nbplayers=3;
Game *g=new Game(nbplayers);

Player *p1=new Player(1);
Profil *f1=new Profil();
Stratigie *st1=new Stratigie("A",1);
Stratigie *st2=new Stratigie("B",1);
Stratigie *st3=new Stratigie("C",1);
p1->add(st1);f1->add(st1,10);
p1->add(st2);f1->add(st2,20);
p1->add(st3);f1->add(st3,30);
g->addPlayer(p1);

p1=new Player(2);
st1=new Stratigie("F",2);
st2=new Stratigie("G",2);
st3=new Stratigie("H",2);

p1->add(st1);f1->add(st1,40);
p1->add(st2);f1->add(st2,50);
p1->add(st3);f1->add(st3,60);
g->addPlayer(p1);

p1=new Player(3);
st1=new Stratigie("I",3);
st2=new Stratigie("J",3);
st3=new Stratigie("K",3);

p1->add(st1);f1->add(st1,70);
p1->add(st2);f1->add(st2,80);
p1->add(st3);f1->add(st3,90);
g->addPlayer(p1);



g->afficher();
g->createFinaleProfilsList();
g->afficher();
return 0;
}
