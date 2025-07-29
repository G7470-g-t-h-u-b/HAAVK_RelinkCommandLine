#include "_Tools.h"
using namespace std;
using namespace _Tl;
static int ids = 1;
class ItemData {
public:
	string id[ 10000 ];
	string name[ 10000 ];
	int max_number[ 10000 ];
	double weight[ 10000 ];
	bool gunTF[ 10000 ];
	bool swordTF[ 10000 ];
	double attack_damage[ 10000 ];
};
static ItemData itemData;
class Item {
public:
	Item( string name_,string id_,int max_number_,double weight_,bool gun_tf_,bool sword_tf_);
	void setSwordData( string id, double attack_damage_ );
};