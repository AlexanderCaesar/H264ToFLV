#ifndef XIAOC_ENCAPSULATION_H
#define XIAOC_ENCAPSULATION_H
//作者  蔡砚刚  20160615  xiaoc@pku.edu.cn
#include "h264toflv.h"
#include "flvfile.h"
#include "nal.h"

#define  TAGTYPE_AUDIO  8
#define  TAGTYPE_VIDEO  9
#define  TAGTYPE_META   18

#define M16E6 16777216 //16^6
#define M16E4 65536    //16^4
#define M16E2 256      //16^4
struct FlvHeader
{
	union
	{
		struct
		{
			unsigned char signature[3]; //分别是ASCII码表示的 F L V
			unsigned char version;      //版本用一个字节表示：一般为0x01
			unsigned char present;      //4表示只有音频 1表示只有视频 5 表示既有视频也有音频 其他值非法
			unsigned char size[4];      //为FLV Header的长度，为固定值0x00000009  在标准中规定，版本1一定为9，在未来版本中可能会修正
		};
		unsigned char data[9];          //存储整个FLV头的数据 与上述数据共享内存
	};
};

struct TagHeader
{
	union
	{
		struct
		{
			unsigned char tagType;      //TAG类型: 8 表示音频tag 9表示视频tag 18表示脚本数据 40 表示经过滤波的音频 41表示经过滤波的视频 50表示经过滤波的脚本数据 其它值错误
			unsigned char datasize[3];  //占24位 表示当前tag的后续长度等于当前整个tag长度减去11（tag头信息）
			unsigned char timestamp[4]; //占24位为相对第一个Tag的时间戳，因此第一个Tag的时间戳为0。也可以将所有Tag的时间戳全配置为0，解码器会自动处理。 每个tag的第五个字节开始
			unsigned char streamID;     //一直为0
		};
		unsigned char data[11];
	};
	unsigned int getSize()//获取size
	{
		int s = datasize[0]*M16E4 + datasize[1]*M16E2 + datasize[2];
		return s + 11;
	}
};

struct Video
{
    /*
    1 关键帧 （应用于AVC）
    2 非关键帧（应用于AVC）
    3 h263的非关键帧
    4 服务器生成关键帧
    5 视频信息或命令帧   **/
    int          m_frameType;//帧类型

    /*
    2 H.263
    3 屏幕视频
    4 VP6
    5 VP6 并且有alpha通道
    6 屏幕视频版本2
    7 AVC（H.264）    **/
    int          m_codecID; //编码器类型

    /*
    仅在AVC时有此字段
    0  AVC sequence header (SPS、PPS信息等)
    1 AVC NALU
    2 AVC end of sequence (lower level NALU sequence ender is
    not required or supported)**/
    int          m_AVCPacketType; //AVC包类型

    /*
    相对时间戳 如果AVCPacketType=0x01， 为相对时间戳；
    其它，均为0；  
    该值表示当前帧的显示时间  tag的时间为解码时间    
    显示时间等于 解码时间 + CompositionTime    **/
    int          m_CompositionTime; //显示时间偏移
};
class EncaFlv
{
public:
	flv_param* m_param;         //配置参数信息

	FlvHeader    m_flvHeader;     //flv头信息
	TagHeader    m_tagHeader;     //tag头信息
	unsigned int m_tagConter;     //计数tag个数
	NAL          m_nal;           //存储NAL单元
	Video        m_video;         //存储video信息

	double       m_DTS;           //解码时间

	EncaFlv();
	void create(flv_param *param);/* 申请内存 */
	void destory();/* 释放内存 */

	//设置FLV头信息
	void setFlvHeader();
	//写FLV头信息
	void writeFlvHeader();

	/* 写第一个Tag Size */
	void writeFirstTagSize();

	/* 写前一个Tag Size */
	void writePreTagSize();

	/*设置Tag头信息*/
	void setTagHeader(unsigned char tagType, unsigned int timestamp);
	/*设置Tag数据长度*/
	void setTagHeaderDataSize(unsigned int datasize);
	//写Tag头信息
	void writeTagHeader();

	//写MetaData信息
	void writeMetaData();

	//检查NAL起始符 并返回起始符长度
	int checkStartecode(unsigned char data[4],unsigned char pos);

	//读取NAL单元
	bool readNal();

	/* 封装 SPS PPS */
	void encapsulateSPSPPS();

	/* 封装 NAL*/
	void encapsulateNAL();

	/* 封装 SEI*/
	void encapsulateSEI();

	/* 封装flv */
	void encapsulate();

};

#endif