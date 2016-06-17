#ifndef XIAOC_ENCAPSULATION_H
#define XIAOC_ENCAPSULATION_H
//作者  蔡砚刚  20160615  xiaoc@pku.edu.cn
#include "h264toflv.h"
#include "flvfile.h"

class EncaFlv
{
public:
	flv_param* m_param;         //配置参数信息

	EncaFlv();
	void create(flv_param *param);/* 申请内存 */
	void destory();/* 释放内存 */

	/* 封装flv */
	void encapsulate();

};

#endif