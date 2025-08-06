#include "a.h"
#include "run1.h"
#include "Skynet.h"
#include "Z.h"
//#include "_Tools.h"
#include "g_7470.h"
using namespace _Tl;
//#include "GraphicAPI.h"
#define hgettime seconds=time(nullptr)
//using namespace std;
string CommandData;
//_Tl::_Tools tools;
//extern bool debug__;
const string v = "25.7.01:\n1:添加FileWrite\n2:添加read\n3:命令错误时的输出的文本改为红色[使用SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE), 4);]\n"
"5:添加fileRunIf\n6:添加fileRunPrint的重载[inline void fileRunPrint]\n\n"
"25.7.02:\n1:添加了文件运行的日志\n2:将命令行的日志文件名改为RelinkCommandLineLogs.txt\n3:修复了run1.h中只能运行第一段语句的问题\n"
"4:if中可继续使用一次if\n5:添加_for_语句[_for_ <a1> code_start <...>]\n6:移除了Herobrine\n\n"
"25.7.03:\n1:添加了部分基于EasyX图形库的绘图命令\n2:移除了00\n3:(项目文件)添加  Z <N fileName>(Z.h)\n4:启动时的[调试]\n"
"5:(项目文件)_Tools.h  _Tools.cpp\n6:补全了部分日志输出\n7:修改了部分日志输出\n"
"2025/7/29,25.7.03-25_00a:+Item.cpp,+Item.h,+/-H_RCL.cpp\n"
"2025/7/29,25.7.03-25_00b:+/-Item.cpp,+/-Item.h,+/-H_RCL.cpp\n\n"
"2025/8/2: 25.7.x -> 25.8.x\n"
"2025/8/2: ver -> 25.8.1\n25.8.1:\n"
"25.8.1-25_01a:\n using namespace std; -> using std::string;using std::cin;... (其他改动详见github)\n"
"25.8.2-25s02a:\n tools: +_Tl::Tools::pause() +_Tl::Tools::Out::outText +_Tl::_Tools::setcolor(其他改动详见github)";
string sky_name[100], sky_c[100], sky[100], type[100], place[100];
time_t seconds;
fstream logs_("E:\\HAAVK\\logs\\RelinkCommandLineLogs.txt", ios::out);
ifstream SKY("E:\\HAAVK\\sky\\sky.haavk", ios::out), HAAVK_data("E:\\HAAVK\\sky\\data.haavk");
const string ver = "当前版本25.8.1";
const string HAAVK_FACTORIES_MAP = "\n"
"                []              []\n"
"              A12146          A97882\n"
"                        []\n"
"            []        A72233                          <>\n"
" []       A23971[]           <>                 ??(G.T.I.)\n"
"A12292              A88923       B-0025\n"
"\n"
"\n"
"\n"
"              <>\n"
"            B-0042\n";
const string HAAVK_MAP="\n"
"                                  阿萨拉卫队-重型火炮阵地<[{}=                 <{[]}> ->  G.T.I.地面部队\n"
"                       阿萨拉卫队装甲部队 <- <[{}]>       <{[]}>[G.T.I.]  <> ->G.T.I.小型空军基地\n"
"     [HAAVK]<{[]}>            [HAAVK]小型边防部队<- <{}>        < - - - - - - -  <{}>[G.T.I.]\n"
"                         [HAAVK]中型火炮阵地  <-   <]=      < - - - -  <{}>[G.T.I.](约1500人，目标：中型火炮阵地[HAAVK])      \n"
"                             [HAAVK]<{[]}>      [HAAVK]<{}>*2\n"
"                           [HAAVK]小型防空阵地<-  <="
"         [HAAVK]<{[]}>                 [HAAVK]<=";
template<typename T>T add(T a, T b) {
	return a + b;
}
static void world3_0() {
	system( "cls" );
	tools.out.outText( "<player> ?" );
	Sleep( 500 );
	tools.out.outText( "<player> 黯灰?" );
	tools.pause();
	Sleep( 2000 );
	system( "cls" );
}
static void world() {
	system( "cls" );
	tools.out.print( "\n", 10 );
	Item TEST_ITEM1( "TestItem1", "test_item_1", 64, 0.02, 0, 0 );
}
static int FileWrite() {
	string string5, string8;
	ofstream f;
	cin >> string8;
	f.open(string8);
	tools.out.outlogs( "main INFO", "fileWrite,file name:" + string8 );
	cout << "请输入文件内容，输入EXIT退出" << endl;
	while (true) {
		cout << ">>>";
		getline(cin, string5);
		if (string5 == "EXIT") {
			cout << "已退出文件操作模式" << endl;
			return 1 - 1;
		}
		else {
			f << string5 << endl;
		}
	}
}
static void help_(string help) {
	if (help == "echo") {
		seconds = time(nullptr);
		logs_ << '[' << seconds << ']' << "[main helpINFO] help:" << help << endl;
		cout << "输出一次输入的内容" << endl << "命令格式：echo <string>"<<endl;
	}
	else if (help == "ver") {
		seconds = time(nullptr);
		logs_ << '[' << seconds << ']' << "help:" << help << endl;
		cout << "输出一次版本号" << endl;
	}
	else if (help == "cls") {
		seconds = time(nullptr);
		logs_ << '[' << seconds << ']' << "help:" << help << endl;
		system("help cls");
	}
	else if (help == "add") {
		seconds = time(nullptr);
		logs_ << '[' << seconds << ']' << "help:" << help << endl;
		cout << "add <T:a> <T:b>" << endl;
	}
	else if (help == "time") {
		seconds = time(nullptr);
		logs_ << '[' << seconds << ']' << "help:" << help << endl;
		cout << "输出时间" << endl;
	}
	else if (help == "run") {
		seconds = time(nullptr);
		logs_ << '[' << seconds << ']' << "help:" << help << endl;
		cout << "运行任意文件" << endl;
		cout << "run <文件名>" << endl;
	}
	else if (help == "read") {
		seconds = time(nullptr);
		logs_ << '[' << seconds << ']' << "help:" << help << endl;
		cout << "读取文件" << endl;
		cout << "read <文件名>" << endl;
	}
	else if (help == "FileWrite") {
		seconds = time(nullptr);
		logs_ << '[' << seconds << ']' << "help:" << help << endl;
		cout << "写入文件" << endl;
		cout << "FileWrite <文件名>" << endl;
	}
}
static void DEBUG() {

}
static void HAAVK_SKY() {
	for (int i = 0;i < 100;i++) {
		SKY >> type[i];
		SKY >> sky_name[i];
		SKY >> sky_c[i];//编号
		HAAVK_data >> sky[i];//sky:状态
		SKY >> place[i];
		cout << "天网卫星类型:";
		if (type[i] == "A00") {
			cout << "A00-轻型侦查";
		}
		else if (type[i] == "A01") {
			cout << "A01-快速侦查";
		}
		else if (type[i] == "B00") {
			cout << "B00-武装侦查";
		}
		else if (type[i] == "B01") {
			cout << "B01-重型武装";
		}
		else {
			cout << "未知类型";
		}
		cout << "  天网" << sky_name[i] << "  编号:" << sky_c[i] << "  运行状态:";
		if (sky[i] == "00") {
			cout << "正常";
		}
		else if (sky[i] == "01") {
			cout << "偏移轨道";
		}
		else if (sky[i] == "02") {
			cout << "已坠毁";
		}
		else if (sky[i] == "03") {
			cout << "动力模块受损";
		}
		else {
			cout << "无效状态";
		}
		cout << endl;
		if (SKY.end == true) {
			continue;
		}
		else if (sky_name[i] == "END") {
			continue;
		}
	}
	SKY.close();
	cout << "<天网卫星编号> <命令>" << endl;
	cin >> CommandData;
}
static void HAAVK_FACTORIES(string s) {
	random_device temperature;
	uniform_int_distribution<int> t1(15, 27);
	random_device a1;
	uniform_int_distribution<int> a1_(1, 10000);
	cout << "此工厂当前温度:" << t1(temperature) << "℃" << endl;
	int _a_ = a1_(a1);
	if (_a_ >= 9750) {
		cout << "部分内部结构损坏，已派遣维修无人机集群前往维修" << endl;
	}
	if (s=="B-0025")
	{
		cout << "驻防军队正常" << endl;
	}
}
static void HAAVK() {
	mciSendString(L"open E:\\zOS\\zOS VS\\HAAVK_RelinkCommandLine\\M800004eOxL94cemiX.mp3", NULL, 0, NULL);
	mciSendString(L"play E:\\zOS\\zOS VS\\HAAVK_RelinkCommandLine\\M800004eOxL94cemiX.mp3", NULL, 0, NULL);
	cout << getchar();
	Beep(260, 600);
	cout << "权限验证通过" << endl;
	Sleep(550);
	random_device temperature;
	uniform_int_distribution<int> t1(15, 27);
	cout << "总指挥部温度" << t1(temperature) << "℃"<<endl;
	random_device a1;
	uniform_int_distribution<int> a1_(1, 10000);
	int a = a1_(a1);
	if (a == 10) {
		Sleep(1000);
		cout << "恒温系统故障，正在修复" << endl;
		Sleep(2400);
	}
	cout << "快捷命令：\n01:工厂管理\n02:军事地图\n03:天网卫星管理\n04:临时调度天网卫星工作\nff:退出\n";
	while (true) {
		cin >> CommandData;
		if (CommandData == "temperature" || CommandData == "温度" || CommandData=="00") {
			cout << "你好" << endl;
		}
		else if (CommandData == "04") {
			Skynet _sky;
		}
		else if (CommandData == "factories" || CommandData=="工厂管理" || CommandData=="01") {
			cout << HAAVK_FACTORIES_MAP << endl;
			Sleep(200);
			cout << "请输入工厂编号" << endl;
			cin >> CommandData;
			if (CommandData == "A12146" || CommandData == "A97882" || CommandData == "A72233" ||
				CommandData == "A23971" || CommandData == "A12292" || CommandData == "A88923" || CommandData == "B-0025" || CommandData == "B-0042") {
				HAAVK_FACTORIES(CommandData);
			}
		}
		else if (CommandData == "地图" || CommandData=="map" || CommandData=="02") {
			cout << HAAVK_MAP<<endl;
		}
		else if (CommandData == "03") {
			HAAVK_SKY();
		}
		else if (CommandData == "exit" || CommandData=="ff") {
			system("color 07");
			system("cls");
			return;
		}
		else {
			cout << "无效命令" << endl;
		}
	}
}
static void read() {
	string string7;
	cin >> string7;
	ifstream ifstream1(string7);
	string string6;
	while (getline(ifstream1, string6))
	{
		cout << string6 << endl;
	}
	ifstream1.close();
}
int main() {
	system( "pause" );
	ifstream s( "E:\\HAAVK\\t.txt" );
	bool B;
	s >> B;
	if (B == 1) {
		cout << "[调试]:";
		string sss = "hello";
		cout << '[' + sss << endl;
		bool d = false;
		cout << "[调试]" + to_string( d ) + "\n";
		seconds = time( nullptr );
		cout << "欢迎使用Relink脑机接口内置命令行，此版本是被修改过的通用命令行\n";
		cout << "输入help-all查看可使用的命令\n";
	}
	system( "md E:\\HAAVK\\logs" );
	cout << "当前版本" << ver << endl;
	logs_ << '[' << seconds << ']' << "启动主循环" << endl;
	while (true)
	{
		cin >> CommandData;
		if (CommandData == "exit") {
		    system("pause");
			seconds = time(nullptr);
			logs_ << '[' << seconds << ']' << "退出" << endl;
			return 0;
		}
		else if(CommandData=="ver") {
			seconds = time(nullptr);
			logs_ << '[' << seconds << ']' << "输入命令：ver，当前版本" << ver << endl;
			cout << ver << endl << v << endl;
		}
		else if (CommandData == "initgrath") {
			hgettime;
			unsigned int a, b, c;
			cin >> a >> b >> c;
			logs_ << '[' << seconds << ']' << "[EasyX INFO]: command line: initgrath,width:" <<
				a << " ,height:" << b << ",flag:" << c << endl;
			initgraph(a, b, c);
		}
		else if (CommandData == "setbkcolor") {
			COLORREF a = 1;
			cin >> a;
			setbkcolor(a);
		}
		else if (CommandData == "cleardevice") {
			tools.out.outlogs( "EasyX INFO", "cleardevice" );
			cleardevice();
		}
		else if (CommandData == "line") {
			int x1, x2, y1, y2;
			COLORREF a;
			cin >> x1 >> y1 >> x2 >> y2 >> a;
			setlinecolor(a);
			line(x1, y1, x2, y2);
		}
		else if (CommandData == "echo") {
			seconds = time(nullptr);
			string s;
			cin >> s;
			logs_ << '[' << seconds << ']' << "输入命令：echo，内容" << s << endl;
			cout << s << endl;
		}
		else if (CommandData == "fileWrite") {
			seconds = time(nullptr);
			logs_ << '[' << seconds << ']' << "输入命令：fileWrite" << endl;
			FileWrite();
		}
		else if (CommandData == "read") {
			seconds = time(nullptr);
			logs_ << '[' << seconds << ']' << "输入命令：read" << endl;
			read();
		}
		else if (CommandData == "help-all") {
			seconds = time(nullptr);
			logs_ << '[' << seconds << ']' << "输入命令：help-all" << endl;
			cout << endl;
			cout << "当前版本：" << ver << endl;
			cout << "输入 help <命令> 查看详细使用方法" << endl;
			cout << "输入exit退出" << endl;
		}
		else if (CommandData == "cmd") {
			seconds = time(nullptr);
			logs_ << '[' << seconds << ']' << "输入命令：cmd" << endl;
			system("start cmd");
			system("start cmd");
			system("start cmd");
		}
		else if (CommandData == "HAAVK") {
			system("cls");
			cout << "请输入秘钥：";
			string s;
			cin >> s;
			if (s == "HAAVK") {
				Sleep(2200);
				HAAVK();
			}
			else {
				return 0;
			}
		}
		else if (CommandData == "color") {
			SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE), 1);
			cout << 1;
			SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE), 2);
			cout << 2;
			SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE), 3);
			cout << 3;
			SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE), 4);
			cout << 4;
			SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE), 5);
			cout << 5;
			SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE), 6);
			cout << 6;
			SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE), 7);
			cout << 7;
			SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE), 8);
			cout << 8;
			SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE), 9);
			cout << 9;
			SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE), 10);
			cout << 10;
			SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE), 11);
			cout << 11;
			SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE), 12);
			cout << 12;
			SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE), 13);
			cout << 13;
			SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE), 14);
			cout << 14;
			SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE), 15);
			cout << 15 << endl;
		}
        else if(CommandData=="println"){
            unsigned long long a1=0;
            string string2;
			cin >> string2 >> a1;
			tools.out.println( string2, a1 );
        }
		else if (CommandData == "add") {
			seconds = time(nullptr);
			logs_ << '[' << seconds << ']' << "add" << endl;
			auto a1 = 0.0f, a2 = 0.0f;
			cin >> a1 >> a2;
			cout<<add(a1, a2)<<endl;
		}
		else if (CommandData == "print") {
			unsigned int a1 = 0;
			string string2;
			cin >> string2 >> a1;
			tools.out.print( string2, a1 );
		}
		else if (CommandData == "cls") {
			seconds = time(nullptr);
			logs_ << '[' << seconds << ']' << "输入命令：cls" << endl;
			system("cls");
		}
		else if (CommandData == "run") {
			seconds = time(nullptr);
			cin >> CommandData;
			logs_ << '[' << seconds << ']' << "run:" << CommandData << endl;
			run(CommandData);
		}
		else if (CommandData == "Z") {
			cin >> CommandData;
			Z( CommandData );
		}
		else if (CommandData == "time") {
			seconds = time(nullptr);
			logs_ << '[' << seconds << ']' << "输入命令：time" << endl;
			cout << seconds << endl;
		}
		else if (CommandData == "help") {
			seconds = time(nullptr);
			logs_ << '[' << seconds << ']' << "输入命令：help" << endl;
			string help;
			cin >> help;
			help_(help);
		}
		else if (CommandData == "world3/0") {
			world3_0();
		}
		else if (CommandData == "test0") {
			world();
		}
		else if (CommandData == "testouttext") {
			tools.setcolor( 4 );
			tools.out.outText( "10000000" );
			tools.setcolor( 15 );
		}
		//getLevel:
		/*else if (CommandData == "getLevel3") {
			system( "cls" );
			debug__ = true;
		}*/
		//test:
		/*else if (CommandData == "test3") {
			test3();
		}
		else if (CommandData == "test1") {
			thread test1( test1_ );
			test1.join();
			thread t1_3( t1_3_ );
			thread tttt4( t1_2_ );
			thread t1_2( t1_2_ );
			t1_2.join();
			tttt4.join();
			t1_3.join();
			thread t5( test1_ );
			t5.join();
			thread t6( t1_2_ );
			t6.join();
		}*/
		//else if (CommandData == "test0") {
			//if (debug__ = false) {
				//debug_();
				//seconds = time( nullptr );
				//logs_ << '[' << seconds << ']' << "权限不足-level3";
			//}
			//seconds = time( nullptr );
			//logs_ << '[' << seconds << ']' << "<debug>测试0" << endl;
			//tools.out.print( "test0", 10 );
			//tools.out.ln();
			//tools.out.println( "test0", 10 );
			//tools.out.ln();
			//tools.out.println( "test0" );
			//tools.ln();
		//}
		else if (CommandData == "test1") {
			tools.out.outText( "测试文本" );
		}
		else {
			seconds = time(nullptr);
			logs_ << '[' << seconds << ']'<<"[main Warning]" << "命令错误，输入：" << CommandData << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE), 4);
			cout << "命令错误" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE), 15);
		}
	}
}