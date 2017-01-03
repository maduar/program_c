#ifndef STATUS_H
#define STATUS_H

/* 状态码 */
#define TRUE        1  //真
#define FALSE       0  //假
#define YES         1  //是
#define NO          0  //否
#define OK          1  //通过
#define ERROR       0  //错误
#define SUCCESS     1  //成功
#define UNSUCCESS   0  //失败
#define INFEASIBLE  -1 //不可行

#ifndef _MATH_H_
#define OVERFLOW    -2  //堆栈下溢
#define UNDERFLOW   -3  //堆栈上溢
#endif   


#ifndef NULL
#define NULL ((VOID*)0)
#endif 

typedef int Status;

#endif
