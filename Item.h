#include "_Tools.h"
using namespace std;
using namespace _Tl;
int ids = 1;
class ItemData {
public:
	string id[ 10000 ];
	string name[ 10000 ];
	int max_number[ 10000 ];
	int weight_[ 10000 ];
	bool gunTF[ 10000 ];
	bool swordTF[ 10000 ];
};
ItemData itemData;
class Item {
public:
	Item( string name_,string id_,int max_number_,int weight_,bool gun_tf_,bool sword_tf_);
};