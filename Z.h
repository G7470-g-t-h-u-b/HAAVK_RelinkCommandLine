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
extern fstream logs_;
_Tl::_Tools tools;
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
static void Zif() {//if Z( <varname> <type> <varname> )Z Z{ c }Z
	string string15, string16, string17, string18;
	Zin >> string15 >> string16 >> string17 >> string18;
	if(string15!="Z("){
		logs_ << '[' + se + ']' << "[Zrun ERROR] <Z.h> Zif() error:Z( not found" << endl;
		SetConsoleTextAttribute( GetStdHandle( STD_ERROR_HANDLE ), 4 );
		cout << "Error:Z( not found" << endl;
		SetConsoleTextAttribute( GetStdHandle( STD_ERROR_HANDLE ), 15 );
		return;
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
		else if (s1 == "EXIT") {
			break;
		}
	}
	printf( "‘À––Ω· ¯\n" );
	system( "pause" );
}
#undef T
#undef F