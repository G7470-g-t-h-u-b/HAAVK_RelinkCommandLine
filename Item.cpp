#include "Item.h"
using std::string; using std::cout; using std::cin; using std::time_t; using std::to_string;
using std::fstream; using std::ofstream; using std::ifstream; using std::ios; using std::endl;
using namespace _Tl;
Item::Item( string name_, string id_, int max_number_,
	double weight_, bool gun_tf, bool sword_tf ){
	if (ids >= 10000) {
		cout << "[ERROR] ItemData is full!" << endl;
		logs_ << '[' + to_string( time( nullptr ) ) + ']' +
			"[Item ERROR] ItemData is full!" << endl;
		return;
	}
	itemData.name[ ids ] = name_;
	itemData.id[ ids ] = id_;
	itemData.max_number[ ids ] = max_number_;
	itemData.weight[ ids ] = weight_;
	itemData.gunTF[ ids ] = gun_tf;
	itemData.swordTF[ ids ] = sword_tf;
	ids++;
	logs_<< '[' + to_string( time( nullptr ) ) + ']' +
		"[Item INFO] ItemData.id[" + to_string( ids - 1 ) + "]:" +
		id_ + " name:" + name_ + " max_number:" +
		to_string( max_number_ ) + " weight:" +
		to_string( weight_ ) + " gunTF:" +
		to_string( gun_tf ) + " swordTF:" +
		to_string( sword_tf ) << endl;
}
void Item::setSwordData( string id, double attack_damage_ ){
	for (int i = 0; i < 10000; i++) {
		if (itemData.id[ i ] == id && itemData.swordTF[ i ] == true) {
			itemData.attack_damage[ i ] = attack_damage_;
			return;
		} else if(itemData.id[ i ] == id && itemData.swordTF[i] == false) {
			cout << "[ERROR] itemData.sword=false,This is not a \"sword!\"" << endl;
		}
	}
}