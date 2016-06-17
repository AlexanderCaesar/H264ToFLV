#ifndef XIAOC_FLV_FILE_H
#define  XIAOC_FLV_FILE_H
//作者  蔡砚刚  20160615  xiaoc@pku.edu.cn

#include <stdio.h>
#include "h264toflv.h"


extern FILE *g_h264_file;  //H264 视频流文件
extern FILE *g_aac_file;   //aac  音频流信息
extern FILE *g_flv_log;    //打印详细信息
extern FILE *g_flv_out;    //输出封装后的flv流

extern char *flv_h264_name;  //视频流文件           -v 配置 如：-v brazil-bq.264
extern char *flv_aac_name;   //音频流文件           -a 配置 如：-a brazil-bq.aac 
extern char *flv_log_name;   //打印详细信息         -t 配置 如：-t brazil-bq.log
extern char *flv_out_name;   //输出flv文件          -o 配置 如：-v brazil-bq.flv 

extern int  g_errors;        //统计错误个数

void openFlvFiles();    //打开flv相关文件
void closeFlvFiles();   //关闭flv相关文件
#endif