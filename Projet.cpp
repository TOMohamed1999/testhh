#include <iostream>
#include <string>
#include <iterator>
#include <vector>
    
using namespace std;

class Itemset {
 private:
    vector<string> items;
    int frequent;
    vector<string> fermeture;
    double support;
 public:
    Itemset(double s,int f){
      //  this->support=s;
      //  this->frequent=f;
    }
     
     void setSupport(double s){
        this->support=s;
     }
     double getSupport(){
         return this->support;
     }
    void afficher(){
      cout<<" \nItemset: "<<endl;
     for(int i=0;i<items.size();i++){
        cout<<" "<< items.at(i)<< " ";
      }

      cout <<"\nSupport:"<<this->support<<endl;

       cout<<"\n Fermeture: "<<endl;
     for(int i=0;i<fermeture.size();i++){
        cout<<" "<< fermeture.at(i)<< " ";
      }
        
}
    
};
class EnsItemsets{
  private:
  int num;
  vector<Itemset*> list;
 
  public:
     EnsItemsets(int n){
        num=n;
     }
     void add(Itemset* i){
         list.push_back(i);
     }
     void afficher(){
        cout <<"\nEnsemblesm des Itemsets_:"<<num<<" :"<<endl;

for(int i=0;i<list.size();i++){
        list.at(i)->afficher();
      }
        

      }

};
int main(){
    
  Itemset *i1=new Itemset(1,0);

     Itemset *i2=new Itemset(2,1);

     Itemset *i3=new Itemset(0.99,0);

i1.afficher();
i2.afficher();
    i3.afficher();
    return 0;
}
