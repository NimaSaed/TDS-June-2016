#include <iostream>
using namespace std;
class animal
{
protected:

public:
   virtual string getSound()
   {
      return "woooooo";
   }

   string  getMovingType()
   {
      return "walk";
   }
};

class bird: public animal
{
public:
   string getSound()
   {
      return "tweet-tweet";
   }
   string  getMovingType()
   {
      return "fly";
   }
};

class dog: public animal
{
public:
   string getSound()
   {
      return "bark";
   }
   string  getMovingType()
   {
      return "run";
   }
};


int main ()
{
   dog milo;
   bird woodpicker;
   animal lola;

   cout <<"Dog "<<milo.getMovingType() << endl;
   cout <<"Bird "<<woodpicker.getMovingType() << endl;
   cout <<"Unknown Animal "<<lola.getMovingType() << endl<< endl;


   animal *animal1 = &milo;
   animal *animal2 = &woodpicker;
   animal *animal3 = &lola;

   cout << animal1->getMovingType() << endl;
   cout << animal2->getMovingType() << endl;
   cout << animal3->getMovingType() << endl<< endl;


   cout <<"Dog "<<animal1->getSound() <<" and "<< animal1->getMovingType() << endl;
   cout <<"Bird "<<animal2->getSound() <<" and "<< animal2->getMovingType() << endl;
   cout <<"Unknown Animal "<<animal3->getSound() <<" and "<< animal3->getMovingType() << endl;



   //system( "PAUSE" );
   return 0;
}
