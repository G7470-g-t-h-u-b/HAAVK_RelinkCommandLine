#include "a.h"
//using namespace std;
namespace _Tl {
	class _Tools {
	public:
		class Out {
		public:
			void print( std::string data, const unsigned long long n );
			void print( std::string data );
			void println( std::string data, const unsigned long long n );
			void println( std::string data );
			void ln();
			void info(const unsigned short n,std::string data);
		};
		Out out;
		void ln();
	};
	void ln();
}