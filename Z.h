#include "a.h"
#include "_Tools.h"
#define T true
#define F false
#define zgettime se=time(nullptr)
using namespace std;
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
static void Zif() {//

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