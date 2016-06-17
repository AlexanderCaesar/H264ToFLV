#ifndef XIAOC_H264TOFLV_H
#define XIAOC_H264TOFLV_H
//作者  蔡砚刚  20160614  xiaoc@pku.edu.cn

typedef struct flv_param
{
    /* 配置信息
    -v 配置 如：-v brazil-bq.264
    -a 配置 如：-a brazil-bq.aac
    -t 配置 如：-t brazil-bq.log
    -o 配置 如：-v brazil-bq.flv
    -f 配置 如：-f 25
    **/
    int  b_log;   //是否打印log详细信息        -t 配置 如：-t brazil-bq.log
    int  i_fps;   //flv的fps信息               -f 配置 如：-f 25
    int  b_audio; //是否有音频信息             -a 配置 如：-a brazil-bq.aac
	int  b_video; //是否有视频信息             -a 配置 如：-v brazil-bq.264

}flv_param;

/* 设置flv的默认参数 */
void flv_param_default(flv_param *param);

/* 解析配置参数 */
bool parse(flv_param *param,int argc, char **argv);

#endif