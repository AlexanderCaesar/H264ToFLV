//作者  蔡砚刚  20160617  xiaoc@pku.edu.cn
#include "encapsulation.h"

EncaFlv::EncaFlv()
{
	m_param          = NULL;
}

void EncaFlv::create(flv_param *param)/* 申请内存 */
{
	bool ok = true;
	m_param = param;
}
void EncaFlv::destory()/* 释放内存 */
{

}

/* 封装flv */
void EncaFlv::encapsulate()
{

}