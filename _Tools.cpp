#include "_Tools.h"
#define setcolorred SetConsoleTextAttribute( GetStdHandle( STD_ERROR_HANDLE ), 4 )
#define setcolorwhite SetConsoleTextAttribute( GetStdHandle( STD_ERROR_HANDLE ), 15 )
#define gettime sec = time( nullptr )
using namespace _Tl;
extern std::fstream logs_;
time_t sec;
void _Tools::Out::print( std::string data, const unsigned int n ) {
	for (unsigned int i = 1; i <= n; i++) { gettime; std::cout << data; }
	logs_ << '[' << sec << ']' << "_Tl::_Tools::Out::print() data:"
		<< data << " n:" << n << std::endl;
}
void _Tools::Out::print( std::string data ) {
	gettime;
	std::cout << data;
	logs_ << '[' << sec << ']' << "[_Tools INFO]" <<
		"_Tl::_Tools::Out::print()  data:" << data << std::endl;
}
void _Tools::Out::println( std::string data, const unsigned long long n ) {
	gettime;
	for (unsigned int i = 1; i <= n; i++) {std::cout << data << std::endl;}
	logs_ << '[' + sec + "][_Tools INFO] _Tl::_Tools::Out::println()  data:\"" +
		data << "\"n:" << n << std::endl;
}
void _Tools::Out::println( std::string data ) {
	gettime;
	std::cout << data << std::endl;
	logs_ << '[' + sec + "][_Tools INFO] _Tl_::_Tools::Out::println()  data:" + data;
}
void _Tools::Out::ln() { printf( "\n" ); outlogs( "_Tools INFO", "use _Tools::Out::ln()" ); }
void _Tl::_Tools::Out::info( const unsigned short n, std::string data ) {
	time_t t = time( nullptr );
	switch (n) {
	case 0: 
		gettime;
		std::cout << '[' << t << ']' << "[main INFO] " << data << std::endl;
		logs_ << '[' + sec + "][_Tl::_Tools::Out::info()] n(type):"
			<< n << " data:" + data << std::endl;
	case 1: 
		gettime;
		logs_ << '[' + sec + "][_Tl::Tools::Out::info()] n(type):"
			<< n << " data:" + data << std::endl;
		SetConsoleTextAttribute( GetStdHandle( STD_ERROR_HANDLE ), 4 );
		std::cout << '[' << t << ']' << "[main ERROR]" << data << std::endl;
		SetConsoleTextAttribute( GetStdHandle( STD_ERROR_HANDLE ), 15 );
	
	default:
		gettime;
		logs_ << '[' + sec + "][_Tl::Tools::Out::info() n(type):"
			<< n << "(ERROR type) data:" << data << std::endl;
		break;
	}
}
void _Tl::_Tools::Out::outlogs( std::string type, std::string data ) {
	gettime;
	logs_ << '[' + sec + "][" << type << ']' + data << std::endl;
}
void _Tl::_Tools::Out::outText( std::string text ){
	for (int i = 0; i < text.size(); i++) {
		Sleep( 20 );
		std::cout << text[ i ];
	}
	std::cout << std::endl;
	//gettime;
	//logs_ << '[' + sec + "][_Tl::_Tools::Out::outText()] text:" + text << std::endl;
}
void _Tools::ln() { printf( "\n" ); }
void _Tl::_Tools::pause() {
	gettime;
	//logs_ << '[' + sec + ']' + "[tools] pause" << std::endl;
	system( "pause" );
	gettime;
	//logs_ << '[' + sec + ']' + "[tools] pause end" << std::endl;
}
void _Tl::_Tools::setcolor(unsigned short color){
	SetConsoleTextAttribute( GetStdHandle( STD_ERROR_HANDLE ), color );
}
static void ln() { printf( "\n" ); }
#undef gettime