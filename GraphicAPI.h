#ifndef __GRAPHICAPI_H
#define __GRAPHICAPI_H

#include <windows.h>

#define KbEventFunc(funcname) void funcname(void* arg)
#define Draw(win, func) func             \
                        RefreshWin(win); \


typedef void* WIN;

typedef enum{
    Continuous = 0,
    Once = 1
}KbEventMode;

//初始化函数
/**
 * @brief InitComGraph函数可以创建一个普通绘图窗口，在绘图之前必须调用此函数来初始化绘图窗口
 * @details 使用此函数可以创建多个绘图窗口，也可以调节窗口的透明度
 * @param width 窗口的宽度
 * @param height 窗口的高度
 * @param bkcolor 窗口的背景颜色，可以使用RGB宏来获取颜色
 * @param wintitle 窗口标题
 * @param bAlpha 窗口的透明度，取值范围为0-255
 * @return 创建的绘图窗口结构空指针
 */
__declspec(dllexport) WIN InitComGraph(int width, int height, COLORREF bkcolor, LPCSTR wintitle, BYTE bAlpha);

/**
 * @brief InitImaGraph函数可以创建一个带有背景图片的绘图窗口，在绘图之前必须调用此函数来初始化绘图窗口
 * @details 使用此函数可以创建多个绘图窗口，也可以调节窗口的透明度，背景图片必须为.bmp格式
 * @param bkimagepath 背景图片的相对路径或绝对路径
 * @param magnification 缩放倍数，传入的数字为百分数，如传入90则缩小为原来的90%
 * @param wintitle 窗口标题
 * @param bAlpha 窗口的透明度，取值范围为0-255
 * @return 创建的绘图窗口结构空指针
 */
__declspec(dllexport) WIN InitImaGraph(LPCSTR bkimagepath, int magnification, LPCSTR wintitle, BYTE bAlpha);

//绘图函数
/**
 * @brief Pixel函数可以改变绘图窗口上某像素的颜色
 * @param win 绘图窗口空指针，必须为InitGraph函数的返回值
 * @param x 需要改变颜色的像素点的横坐标
 * @param y 需要改变颜色的像素点的纵坐标
 * @param color 像素点的颜色，可以使用RGB宏来获取颜色
 * @return 绘制的元素指针
 */
__declspec(dllexport) void Pixel(WIN win, int x, int y, COLORREF color);

/**
 * @brief Line函数可以在绘图窗口上绘制一条线段
 * @param win 绘图窗口空指针，必须为InitGraph函数的返回值
 * @param x_1 线段起点的横坐标
 * @param y_1 线段起点的纵坐标
 * @param x_2 线段终点的横坐标
 * @param y_2 线段终点的纵坐标
 * @param width 线段的粗细程度
 * @param color 线段的颜色，可以使用RGB宏来获取颜色
 * @return 绘制的元素指针
 */
__declspec(dllexport) void Line(WIN win, int x_1, int y_1, int x_2, int y_2, int width, COLORREF color);

/**
 * @brief DrawBezier函数可以在绘图窗口上绘制一条贝塞尔曲线
 * @details DrawBezier函数会根据传入顶点的顺序绘制贝塞尔曲线，使用时注意传入点的顺序
 * @param win 绘图窗口空指针，必须为InitGraph函数的返回值
 * @param color 贝塞尔曲线的颜色，可以使用RGB宏来获取颜色
 * @param width 曲线的粗细程度
 * @param point_count 传入点的个数
 * @param ... 依次传入起始点，控制点（可以为多个）与终止点
 * @return 绘制的元素指针
 */
__declspec(dllexport) void DrawBezier(WIN win, COLORREF color, int width, int point_count, ...);

/**
 * @brief FrameRectan函数可以在绘图窗口上绘制一个矩形框架
 * @param win 绘图窗口空指针，必须为InitGraph函数的返回值
 * @param left 矩形左上角横坐标
 * @param top 矩形左上角纵坐标
 * @param right 矩形右下角横坐标
 * @param bottom 矩形右下角纵坐标
 * @param width 框架粗细程度
 * @param color 矩形框架的颜色，可以使用RGB宏来获取颜色
 * @return 绘制的元素指针
 */
__declspec(dllexport) void FrameRectan(WIN win, int left, int top, int right, int bottom, int width, COLORREF color);

/**
 * @brief FillRectan函数可以在绘图窗口上绘制一个填充矩形
 * @param win 绘图窗口空指针，必须为InitGraph函数的返回值
 * @param left 矩形左上角横坐标
 * @param top 矩形左上角纵坐标
 * @param right 矩形右下角横坐标
 * @param bottom 矩形右下角纵坐标
 * @param color 填充矩形的颜色，可以使用RGB宏来获取颜色
 * @return 绘制的元素指针
 */
__declspec(dllexport) void FillRectan(WIN win, int left, int top, int right, int bottom, COLORREF color);

/**
 * @brief FramePolygon函数可以在绘图窗口上绘制一个多边形框架
 * @details FramePolygon函数会根据传入顶点的顺序绘制多边形，使用时注意传入点的顺序
 * @param win 绘图窗口空指针，必须为InitGraph函数的返回值
 * @param color 多边形框架的颜色，可以使用RGB宏来获取颜色
 * @param width 框架粗细程度
 * @param point_count 传入顶点的个数
 * @param ... 依次传入多边形顶点，传入的参数必须为POINT类型的变量
 * @return 绘制的元素指针
 */
__declspec(dllexport) void FramePolygon(WIN win, COLORREF color, int width, int point_count, ...);

/**
 * @brief FillPolygon函数可以在绘图窗口上绘制一个填充多边形
 * @details FillPolygon函数会根据传入顶点的顺序绘制多边形，使用时注意传入点的顺序
 * @param win 绘图窗口空指针，必须为InitGraph函数的返回值
 * @param color 多边形的颜色，可以使用RGB宏来获取颜色
 * @param point_count 传入顶点的个数
 * @param ... 依次传入多边形顶点，传入的参数必须为POINT类型的变量
 * @return 绘制的元素指针
 */
__declspec(dllexport) void FillPolygon(WIN win, COLORREF color, int point_count, ...);

/**
 * @brief ReguFramePolygon函数可以在绘图窗口上绘制一个正多边形框架
 * @details ReguFramePolygon函数会根据传入的两个顶点的顺序按顺时针方向绘制正多边形，使用时注意传入顶点的顺序
 * @param win 绘图窗口空指针，必须为InitGraph函数的返回值
 * @param color 多边形的颜色，可以使用RGB宏来获取颜色
 * @param width 框架粗细程度
 * @param edge_num 正多边形的边数
 * @param point_1 正多边形的其中一个顶点
 * @param point_2 正多边形中与point_1相邻的另一个顶点
 * @return 绘制的元素指针
 */
__declspec(dllexport) void ReguFramePolygon(WIN win, COLORREF color, int width, int edge_num, POINT point_1, POINT point_2);

/**
 * @brief ReguFillPolygon函数可以在绘图窗口上绘制一个填充正多边形
 * @details ReguFillPolygon函数会根据传入的两个顶点的顺序按顺时针方向绘制正多边形，使用时注意传入顶点的顺序
 * @param win 绘图窗口空指针，必须为InitGraph函数的返回值
 * @param color 多边形的颜色，可以使用RGB宏来获取颜色
 * @param edge_num 正多边形的边数
 * @param point_1 正多边形的其中一个顶点
 * @param point_2 正多边形中与point_1相邻的另一个顶点
 * @return 绘制的元素指针
 */
__declspec(dllexport) void ReguFillPolygon(WIN win, COLORREF color, int edge_num, POINT point_1, POINT point_2);

/**
 * @brief FrameEllipse函数可以在绘图窗口上绘制一个椭圆框架
 * @details FrameEllipse函数也可以绘制圆形，只需传入的两个焦点均为圆形的圆心即可
 * @param win 绘图窗口空指针，必须为InitGraph函数的返回值
 * @param foci_1 椭圆的其中一个焦点
 * @param foci_2 椭圆的另一个焦点
 * @param point 椭圆外任意一点
 * @param width 框架粗细程度
 * @param color 椭圆框架的颜色，可以使用RGB宏来获取颜色
 * @return 绘制的元素指针
 */
__declspec(dllexport) void FrameEllipse(WIN win, POINT foci_1, POINT foci_2, POINT point, int width, COLORREF color);

/**
 * @brief FillEllipse函数可以在绘图窗口上绘制一个填充椭圆
 * @details FillEllipse函数也可以绘制圆形，只需传入的两个焦点均为圆形的圆心即可
 * @param win 绘图窗口空指针，必须为InitGraph函数的返回值
 * @param foci_1 椭圆的其中一个焦点
 * @param foci_2 椭圆的另一个焦点
 * @param point 椭圆外任意一点
 * @param color 椭圆的颜色，可以使用RGB宏来获取颜色
 * @return 绘制的元素指针
 */
__declspec(dllexport) void FillEllipse(WIN win, POINT foci_1, POINT foci_2, POINT point, COLORREF color);

/**
 * @brief Text函数可以在绘图窗口上写文字
 * @param win 绘图窗口空指针，必须为InitGraph函数的返回值
 * @param x 显示文字区域左上角横坐标
 * @param y 显示文字区域左上角纵坐标
 * @param size 文字大小
 * @param bItalic 是否启用斜体，传入TRUE为启用，FALSE为不启用
 * @param bUnderline 是否启用下划线，传入TRUE为启用，FALSE为不启用
 * @param bStrikeOut 是否启用中划线，传入TRUE为启用，FALSE为不启用
 * @param color 文字颜色
 * @param pszFaceName 文字字体
 * @param string 文字内容
 * @return 绘制的元素指针
 */
__declspec(dllexport) void Text(WIN win, int x, int y, int size, DWORD bItalic, DWORD bUnderline, DWORD bStrikeOut, COLORREF color, LPCSTR pszFaceName, LPCTSTR string);

/**
 * @brief DrawImage函数可以在窗口上绘制位图
 * @details 图片必须为.bmp格式
 * @param win 绘图窗口空指针，必须为InitGraph函数的返回值
 * @param path 位图相对路径或绝对路径
 * @param x 左上角横坐标
 * @param y 左上角纵坐标
 * @param magnification 缩放倍数，传入的数字为百分数，如传入90则缩小为原来的90%
 * @return 绘制的元素指针
 */
__declspec(dllexport) void DrawImage(WIN win, LPCSTR path, int x, int y, int magnification);

//控制函数

/**
 * @brief RefreshWin函数可以更新当前窗口，在绘制之后必须调用才可以让屏幕更新
 * @details 在绘制之后,必须调用才可以让屏幕更新,也可以使用Draw宏完成
 * @param win 绘图窗口空指针，必须为InitGraph函数的返回值
 */
__declspec(dllexport) void RefreshWin(WIN win);

//事件函数

/**
 * @brief AddKbEvent函数可以添加键盘事件
 * @param win 绘图窗口空指针，必须为InitGraph函数的返回值
 * @param ASCILL 键盘按键所对应的ACSILL码
 * @param func_down 键盘按下时触发的函数指针
 * @param func_up 键盘释放时触发的函数指针
 * @param arg_down 键盘按下时触发的函数所需传参的空指针
 * @param arg_up 键盘释放时触发的函数所需传参的空指针
 * @param mode 键盘事件模式，分为Once（单次触发）与Continuous（连续触发）
 * @details 事件函数必须为void类型，并且参数只能是void*类型，或者也可以使用KbEventFunc宏定义事件函数
 */
__declspec(dllexport) void AddKbEvent(WIN win, int ASCILL, void(*func_down)(void *arg), void(*func_up)(void *arg), void* arg_down, void* arg_up, KbEventMode mode);

#endif
