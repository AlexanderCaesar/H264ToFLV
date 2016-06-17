//作者  蔡砚刚  20160615  xiaoc@pku.edu.cn

#include <stdio.h>
#include <stdlib.h>
#include "flvfile.h"
#include "h264toflv.h"

/* 打印help信息 */
static void showHelp()
{
    #define H0 printf
    H0("\n-h 打印参数配置信息并退出\n");
    H0("\n-v 配置264流       如：-v brazil-bq.264\n");
	H0("\n-a 配置aac流       如：-a brazil-bq.aac\n");
    H0("\n-t 配置log         如：-t brazil-bq.log\n");
    H0("\n-o 配置输出yuv文件 如：-v brazil-bq.flv\n");
    H0("\n-f 配置fps         如：-f 25\n");
}
/* 设置flv的默认参数 */
void flv_param_default(flv_param *param)
{
    param->b_log   = 1;
    param->b_video = 1;
    param->b_audio = 0;    
    param->i_fps   = 0;
}

/* 解析配置参数 */
bool parse(flv_param *param,int argc, char **argv)
{
    if (argc <= 1)
    {
        printf("没有任何配置参数\n");
        return false;
    }
    
    for(int i = 1; i < argc; i += 2)
    {
        if(argv[i][0] != '-')
        {
            printf("参数配置有误:%s\n",argv[i]);
            return false;
        }
        switch(argv[i][1])
        {
        case 'h':showHelp();system("pause\n");exit(0);          break;
        case 'v':flv_h264_name = argv[i+1]; param->b_video = 1; break;
        case 't':flv_log_name = argv[i+1];  param->b_log   = 1; break;
        case 'a':flv_aac_name = argv[i+1];  param->b_audio = 1; break;
        case 'o':flv_out_name = argv[i+1];  break;
		case 'f':param->i_fps = atoi(argv[i+1]);  break;
        default:printf("参数配置有误:%s\n",argv[i]); return false;
        }
    }
    return true;
}
