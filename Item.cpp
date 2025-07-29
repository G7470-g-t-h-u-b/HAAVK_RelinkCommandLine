#include "Item.h"
using namespace std;
using namespace _Tl;
Item::Item( string name_, string id_, int max_number_,
	double weight_, bool gun_tf, bool sword_tf ){
	itemData.name[ ids ] = name_;
	itemData.id[ ids ] = id_;
	itemData.max_number[ ids ] = max_number_;
	itemData.weight[ ids ] = weight_;
	itemData.gunTF[ ids ] = gun_tf;
	itemData.swordTF[ ids ] = sword_tf;
	ids++;
}
void Item::setSwordData( string id, double attack_damage_ ){
	for (int i = 0; i < 10000; i++) {
		if (itemData.id[ i ] == id && itemData.swordTF[ i ] == true) {
			itemData.attack_damage[ i ] = attack_damage_;
			return;
		} else if(itemData.id[ i ] == id && itemData.swordTF[i] == false) {
			cout << "[ERROR] itemData.sword=false,This is not a sword!" << endl;
		}
	}
}