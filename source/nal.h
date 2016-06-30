#ifndef XIAOC_NAL_H
#define XIAOC_NAL_H
//作者  蔡砚刚  20160630  xiaoc@pku.edu.cn
#define  NALPLAYLOAD 100000

enum nal_unit_type_e
{
	NAL_UNKNOWN     = 0,
	NAL_SLICE       = 1,
	NAL_SLICE_DPA   = 2,
	NAL_SLICE_DPB   = 3,
	NAL_SLICE_DPC   = 4,
	NAL_SLICE_IDR   = 5,    /* ref_idc != 0 */
	NAL_SEI         = 6,    /* ref_idc == 0 */
	NAL_SPS         = 7,
	NAL_PPS         = 8,
	NAL_AUD         = 9,
	NAL_FILLER      = 12,
	/* ref_idc == 0 for 6,9,10,11,12 */
};

typedef enum
{
	NAL_UNIT_CODED_SLICE_TRAIL_N = 0,
	NAL_UNIT_CODED_SLICE_TRAIL_R,
	NAL_UNIT_CODED_SLICE_TSA_N,
	NAL_UNIT_CODED_SLICE_TLA_R,
	NAL_UNIT_CODED_SLICE_STSA_N,
	NAL_UNIT_CODED_SLICE_STSA_R,
	NAL_UNIT_CODED_SLICE_RADL_N,
	NAL_UNIT_CODED_SLICE_RADL_R,
	NAL_UNIT_CODED_SLICE_RASL_N,
	NAL_UNIT_CODED_SLICE_RASL_R,
	NAL_UNIT_CODED_SLICE_BLA_W_LP = 16,
	NAL_UNIT_CODED_SLICE_BLA_W_RADL,
	NAL_UNIT_CODED_SLICE_BLA_N_LP,
	NAL_UNIT_CODED_SLICE_IDR_W_RADL,
	NAL_UNIT_CODED_SLICE_IDR_N_LP,
	NAL_UNIT_CODED_SLICE_CRA,
	NAL_UNIT_VPS = 32,
	NAL_UNIT_SPS,
	NAL_UNIT_PPS,
	NAL_UNIT_ACCESS_UNIT_DELIMITER,
	NAL_UNIT_EOS,
	NAL_UNIT_EOB,
	NAL_UNIT_FILLER_DATA,
	NAL_UNIT_PREFIX_SEI,
	NAL_UNIT_SUFFIX_SEI,
	NAL_UNIT_INVALID = 64,
} NalUnitType;

struct NAL
{
	unsigned char payload[NALPLAYLOAD];//NAL负载
	unsigned char nalType;             //NAL类型
	unsigned int  size;                //NAL长度
	unsigned int  startcodesize;       //NAL起始符占用字节
};
#endif