#include "a.h"
using std::string; using std::cout; using std::cin; using std::time_t;
using std::fstream; using std::ofstream; using std::ifstream; using std::ios; using std::endl;
static fstream fileRunLogs("E:\\HAAVK\\logs\\fileRunLogs.txt",ios::out);
static time_t t;
static unsigned int fileRunIntVarCnt = 0;
static int fileRunIntVarData[1024];
static string fileRunIntVarName[1024];
static ifstream run_;
inline void fileRunPrint2() {
    int a;
    string string13;
    run_ >> string13 >> a;
    t = time(nullptr);
    fileRunLogs << '[' << t << ']' << "print:" << string13 << endl;
    for (int i = 1;i <= a;i++) {
        cout << string13;
    }
}
static void fileRunIf_RunTrueCode2() {
    string string19, string20;
    run_ >> string19 >> string20;
    if (string19 == "code_start" && string20 == "print") {
        fileRunPrint2();
    }
    else {
        t = time(nullptr);
        fileRunLogs << '[' << t << ']' << "错误:不存在的标识符" << endl;
        cout << "请检查你的代码";
        return;
    }
}
static void fileRunIf2() {
    string string15, string16, string17;
    run_ >> string15 >> string16 >> string17;
    bool Var1, Var2;
    int var_1, var_2;
    if (string16 == "type:==") {
        for (int i = 0;i < 1024;i++) {
            if (string15 == fileRunIntVarName[i]) {
                Var1 = true;
                var_1 = fileRunIntVarData[i];
            }
            if (string17 == fileRunIntVarName[i]) {
                Var2 = true;
                var_2 = fileRunIntVarData[i];
            }
        }
        if (Var1 = false || Var2 == false) {
            t = time(nullptr);
            fileRunLogs << '[' << t << ']' << "错误:变量不存在" << endl;
            cout << "请检查你的代码";
            return;
        }
        if (var_1 == var_2) {
            fileRunIf_RunTrueCode2();
        }
    }
    else if (string16 == "type:<=") {
        for (int i = 1;i <= 1000000;i++) {
            if (string15 == fileRunIntVarName[i]) {
                Var1 = true;
                var_1 = fileRunIntVarData[i];
            }
            if (string17 == fileRunIntVarName[i]) {
                Var2 = true;
                var_2 = fileRunIntVarData[i];
            }
        }
        if (Var1 == false || Var2 == false) {
            t = time(nullptr);
            fileRunLogs << '[' << t << ']' << "错误:变量不存在";
            cout << "请检查你的代码";
            return;
        }
        if (var_1 <= var_2) {
            fileRunIf_RunTrueCode2();
        }
    }
    else if (string16 == "type:>=") {
        for (int i = 1;i <= 10000000;i++) {
            if (string15 == fileRunIntVarName[i])
            {
                Var1 = true;
                var_1 = fileRunIntVarData[i];
            }
            if (string17 == fileRunIntVarName[i]) {
                Var2 = true;
                var_2 = fileRunIntVarData[i];
            }
        }
        if (Var1 == false || Var2 == false) {
            t = time(nullptr);
            fileRunLogs << '[' << t << ']' << "错误:变量不存在";
            cout << "请检查你的代码";
            return;
        }
        if (var_1 >= var_2) {
            fileRunIf_RunTrueCode2();
        }
    }
    else {
        cout << "请检查你的代码";
        return;
    }
}
static void fileRunPrint(string s, int a) {
    t = time(nullptr);
    fileRunLogs << '[' << t << ']' << "print:" << s << endl;
	for (int i = 1;i <= a;i++) {
		cout << s;
	}
}
static void fileRunIntVar() {
	int data1;
	string name1;
	run_ >> name1 >> data1;
	fileRunIntVarCnt++;
	fileRunIntVarData[fileRunIntVarCnt] = data1;
	fileRunIntVarName[fileRunIntVarCnt] = name1;
    t = time(nullptr);
    fileRunLogs << '[' << t << ']' << "定义整型变量 name:" << name1 << ",data:" << data1 << endl;
}
inline void fileRunPrint() {
    int a;
    string string13;
    run_ >> string13 >> a;
    t = time(nullptr);
    fileRunLogs << '[' << t << ']' << "print:" << string13 << endl;
    for (int i = 1;i <= a;i++) {
        cout << string13;
    }
}
static void fileRunIf_RunTrueCode() {
    string string19, string20;
    run_ >> string19 >> string20;
    if (string19 == "code_start" && string20 == "print") {
        fileRunPrint();
    }
    else if (string19 == "code_start" && string20 == "if") {
        fileRunIf2();
    }
    else {
        t = time(nullptr);
        fileRunLogs << '[' << t << ']' << "错误:不存在的标识符" << endl;
        cout << "请检查你的代码" << endl;
        return;
    }
}
static void fileRunIf() {
    string string15, string16, string17;
    run_ >> string15 >> string16 >> string17;
    bool Var1, Var2;
    int var_1, var_2;
    if (string16 == "type:==") {
        for (int i = 0;i < 1024;i++) {
            if (string15 == fileRunIntVarName[i]) {
                Var1 = true;
                var_1 = fileRunIntVarData[i];
            }
            if (string17 == fileRunIntVarName[i]) {
                Var2 = true;
                var_2 = fileRunIntVarData[i];
            }
        }
        if (Var1 = false || Var2 == false) {
            t = time(nullptr);
            fileRunLogs << '[' << t << ']' << "错误:变量不存在" << endl;
            cout << "请检查你的代码" << endl;
            return;
        }
        if (var_1 == var_2) {
            fileRunIf_RunTrueCode();
        }
    }
    else if (string16 == "type:<=") {
        for (int i = 1;i <= 1000000;i++) {
            if (string15 == fileRunIntVarName[i]) {
                Var1 = true;
                var_1 = fileRunIntVarData[i];
            }
            if (string17 == fileRunIntVarName[i]) {
                Var2 = true;
                var_2 = fileRunIntVarData[i];
            }
        }
        if (Var1 == false || Var2 == false) {
            t = time(nullptr);
            fileRunLogs << '[' << t << ']' << "错误:变量不存在" << endl;
            cout << "错误：变量不存在" << endl;
            return;
        }
        if (var_1 <= var_2) {
            fileRunIf_RunTrueCode();
        }
    }
    else if (string16 == "type:>=") {
        for (int i = 1;i <= 10000000;i++) {
            if (string15 == fileRunIntVarName[i])
            {
                Var1 = true;
                var_1 = fileRunIntVarData[i];
            }
            if (string17 == fileRunIntVarName[i]) {
                Var2 = true;
                var_2 = fileRunIntVarData[i];
            }
        }
        if (Var1 == false || Var2 == false) {
            t = time(nullptr);
            fileRunLogs << '[' << t << ']' << "错误:变量不存在" << endl;
            cout << "请检查你的代码" << endl;
            return;
        }
        if (var_1 >= var_2) {
            fileRunIf_RunTrueCode();
        }
    }
    else {
        cout << "请检查你的代码" << endl;
        return;
    }
}
static void fileRunFor__Print(int n) {
    int a2;
    string s;
    run_ >> s >> a2;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= a2;j++) {
            cout << s;
        }
    }
}
static void fileRunFor__Println(int n) {
    int a2;
    string s;
    run_ >> s >> a2;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= a2;j++) {
            cout << s << endl;
        }
    }
}
static void fileRunFor_(string s) {//for a code_start print a 1
    int a;
    bool b1 = false;
    for (int i = 0;i < 1024;i++) {
        if (fileRunIntVarName[i] == s) {
            b1 = true;
            a = fileRunIntVarData[i];
        }
    }
    if (b1 == false) {
        t = time(nullptr);
        fileRunLogs << '[' << t << ']' << "错误:变量不存在" << endl;
        cout << "错误:变量不存在" << endl;
        return;
    }
    string s1, s2;
    run_ >> s1 >> s2;
    if (s1 == "code_start") {
        t = time(nullptr);
        fileRunLogs << '[' << t << ']' << "正常";
    }
    else {
        t = time(nullptr);
        fileRunLogs << '[' << t << ']' << "错误:for语句不正确";
        cout << "错误:for语句不正确";
        return;
    }
    if (s2 == "print") {
        fileRunFor__Print(a);
    }
    else if (s2 == "if") {
        fileRunIf();
    }
    else if (s2 == "println") {
        fileRunFor__Println(a);
    }
}
static void run(string s) {
    t = time(nullptr);
    fileRunLogs << '[' << t << ']' << "开始运行"<<endl;
	string s1, s2;
	int data1;
	run_.open(s);
	//run_ >> s1;
    while (run_>>s1) {
        if (s1 == "int") {
            fileRunIntVar();
        }
        else if (s1 == "print") {
            run_ >> s2 >> data1;
            fileRunPrint(s2, data1);
        }
        else if (s1 == "if") {
            fileRunIf();
        }
        else if (s1 == "_for_") {
            string a1;
            run_ >> a1;
            fileRunFor_(a1);
        }
        else if (s1 == "return") {
            cout << "执行完毕" << endl;
            system("pause");
            return;
        }
        else {
            cout << "错误" << endl;
            return;
        }
        if (run_.end == true) {
            return;
        }
    }
}