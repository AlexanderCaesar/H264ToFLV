#ifndef XIAOC_H264TOFLV_H
#define XIAOC_H264TOFLV_H
//作者  蔡砚刚  20160614  xiaoc@pku.edu.cn

typedef struct flv_param
{
    /* 配置信息
    -i 配置 如：-i brazil-bq.264
    -t 配置 如：-t brazil-bq.log
    -o 配置 如：-v brazil-bq.flv
    -f 配置 如：-f 25
    **/
    int  b_tag;   //是否打印log详细信息        -t 配置 如：-t brazil-bq.log
    int  i_fps;   //flv的fps信息               -f 配置 如：-f 25

}flv_param;

/* 设置flv的默认参数 */
void flv_param_default(flv_param *param);

/* 解析配置参数 */
bool parse(flv_param *param,int argc, char **argv);

#endif