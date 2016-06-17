//作者  蔡砚刚  20160615  xiaoc@pku.edu.cn
#include <stdlib.h>
#include "flvfile.h"

#pragma warning(disable: 4996) // POSIX setmode and fileno deprecated

FILE *g_h264_file  = NULL;    //H264 视频流文件
FILE *g_aac_file   = NULL;    //aac  音频流信息
FILE *g_flv_log    = NULL;    //打印详细信息
FILE *g_flv_out    = NULL;    //输出封装后的flv流

extern char *flv_h264_name  = NULL;   //视频流文件           -v 配置 如：-v brazil-bq.264
extern char *flv_aac_name   = NULL;   //音频流文件           -a 配置 如：-a brazil-bq.aac 
extern char *flv_log_name   = NULL;   //打印详细信息         -t 配置 如：-t brazil-bq.log
extern char *flv_out_name   = NULL;   //输出flv文件          -o 配置 如：-v brazil-bq.flv 

int  g_errors        = 0;    //统计错误个数

//打开flv相关文件
void openFlvFiles()    
{
	if(flv_h264_name)
	{
		g_h264_file = fopen(flv_h264_name,"rb");
		if(!g_h264_file)
		{
			printf("打开文件失败: %s\n",flv_h264_name);
			system("pause");
			exit(0);
		}
	}
	if(flv_aac_name)
	{
		g_aac_file = fopen(flv_aac_name,"rb");
		if(!g_aac_file)
		{
			printf("打开文件失败: %s\n",flv_aac_name);
			system("pause");
			exit(0);
		}
	}
	if(flv_log_name)
	{
		g_flv_log = fopen(flv_log_name,"w");
		if(!g_flv_log)
		{
			printf("打开文件失败: %s\n",flv_log_name);
			system("pause");
			exit(0);
		}
	}

	if(flv_out_name)
	{
		g_flv_out = fopen(flv_out_name,"wb");
		if(!g_flv_out)
		{
			printf("打开文件失败: %s\n",flv_out_name);
			system("pause");
			exit(0);
		}
	}
}

//关闭flv相关文件
void closeFlvFiles()   
{
	if(g_h264_file)
		fclose(g_h264_file);
	if(g_aac_file)
		fclose(g_aac_file);
	if(g_flv_log)
		fclose(g_flv_log);
	if(g_flv_out)
		fclose(g_flv_out);
}