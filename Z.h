#include "a.h"
#include "Item.h"
#define T true
#define F false
#define zgettime se=time(nullptr)
using std::string; using std::cout; using std::cin; using std::time_t;
using std::fstream; using std::ofstream; using std::ifstream; using std::ios; using std::endl;
using namespace _Tl;
static ifstream Zin;
time_t se;
int intvarcnt = 0;
extern fstream logs_;
_Tl::_Tools tools;
class ZIntV {
public:
	int data;
	string name;
};
ZIntV zInt[ 32767 ];
static void Zprint( unsigned long long n, string s2 ) {
	zgettime;
	logs_ << '[' << se << ']' <<"[Zrun INFO] <Z.h> Zprint() n:" <<
		n << " data:" << s2 << endl;
	tools.out.print( s2, n );
}
static void Zprintln( unsigned long long n, string s2 ) {
	zgettime;
	logs_ << '[' + se + "][Zrun INFO] <Z.h> Zprintln() n:" <<
		n << " data" + s2 << endl;
	tools.out.println( s2, n );
}
/*
	class Class1 Z{
		int a;
	Z}
	Class1 class1
	class1 z> a=1
*/
inline void newintvar() {
	string name;
	Zin >> name;
	int data;
	Zin >> data;
	zInt[ intvarcnt ].name = name;
	zInt[ intvarcnt ].data = data;
	intvarcnt++;
}
static void Zif() {//if Z( <varname> <type> <varname> )Z Z{ c }Z    [< a == c >] && [< b <= d]
	string string15, string16, string17, string18, string19, string20, string21;
	int data1, data2;
	Zin >> string15 >> string16;
	if(string15!="Z("){//15: Z( 16:varname || [< 17( [< >] ):varname
		logs_ << '[' + se + ']' << "[Zrun ERROR] <Z.h> Zif() error:\"Z(\" not found" << endl;
		SetConsoleTextAttribute( GetStdHandle( STD_ERROR_HANDLE ), 4 );
		cout << "Error:\"Z(\" not found" << endl;
		SetConsoleTextAttribute( GetStdHandle( STD_ERROR_HANDLE ), 15 );
		return;
	}
	if (string16 == "[<") {
		Zin >> string17;//varname1
		for (int i = 0; i < 32767; i++) {
			if (string17 == zInt[ i ].name) {

			}
		}
	}
}
static void Z( string fileName ) {
	string s1, s2;
	long long n;
	Zin.open(fileName);
	while (Zin.end==F) {
		Zin >> s1;
		if (s1 == "print") {
			Zin >> n >> s2;
			Zprint( n, s2 );
		}
		else if (s1 == "int") {
			newintvar();
		}
		else if (s1 == "EXIT") {
			break;
		}
	}
	printf( "‘À––Ω· ¯\n" );
	system( "pause" );
}
#undef T
#undef F