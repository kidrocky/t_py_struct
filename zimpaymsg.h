#ifndef _ZIMPAY_MSG_H
#define _ZIMPAY_MSG_H

#include <stdlib.h>
#include <time.h>
#include "../os/zxcommon.h"

#ifdef HP_UNIX
#pragma pack  1
#elif defined(AIX)
#pragma options align=packed
#else
#pragma pack(1)
#endif

// 错误码定义
#define ERR_OTHERS -9999

// 最大未收到握手消息次数，超过次次数，即认为模块宕机
#define MAX_ACTIVE_TEST_COUNT 4

// znode基础路径定义
#define ZOO_BASE_PROC "/proc"
#define ZOO_BASE_MSGQUEUE_NOTIFY "/msgqueue/notify"
#define ZOO_BASE_MSGQUEUE_REQ "/msgqueue/req"
#define ZOO_BASE_MSGQUEUE_RES "/msgqueue/res"
#define ZOO_BASE_SYSCONFIG "/system/sysconfig"
#define ZOO_BASE_FUNCDEF "/system/funcdef"
#define ZOO_BASE_ROUTER "/router_buf"
#define ZOO_BASE_POSREQ "/posp/httpreq"
#define ZOO_BASE_LOCK "/lock"
#define ZOO_BASE_SOURCEID "/sourceid"
#define ZOO_BASE_POSDLL "/posp/dll"
#define ZOO_BASE_HSMREQ "/hsmp/tcpreq"
#define ZOO_BASE_BLACKDATA "/blackdata"
#define ZOO_BASE_BLACKLIST_MSG "/blacklist"

#define ZOO_PID_NODENAME "PID"
#define ZOO_ACTIVETEST_NODENAME "activetest"
#define ZOO_STATUS_NODENAME "status"
#define ZOO_LIVE_NODENAME "live"
#define SYS_STRING_DELIMITER '|'
#define SYS_CONFIG_DELIMITER '.'

#define MAX_FUNCDEF_COUNT 1000
#define MAX_MODULENAME_LEN 32
#define MAX_LIBNAME_LEN 64
#define MAX_VERSION_LEN 6
#define MAX_FUNCNAME_LEN 32

#define LEN_WORKKEY 32

#define MAX_PORTAL_MSG_LEN 1024

#define MAX_ZOO_LIST_LEN (1024)
#define SYSCFG_ZOO_LIST "sys.zookeeperlist"
#define SYSCFG_STRING_HEAD "sys."

#define DLL_MODULE_TABLENAME "tb_module"
#define DLL_FUNCDEF_TABLENAME "tb_funcdef"

#ifndef C_OS_SUCCESS
#define C_OS_SUCCESS (INT32)0
#endif
#ifndef C_OS_FAIL
#define C_OS_FAIL (INT32)(-1)
#endif

#define FPOS( type, field ) ((UINT32) &(( type *) 0)-> field)
#define FSIZ( type, field ) sizeof( ((type *) 0)->field )

#define MAX_SQL_STRING_LEN (2048)

#define LEN_PARAM 128

//10000000～11000000表示平台内部失败原因
#define ERR_INNERSTART      10000000  // 保留不用

#define ERR_INNEREND        11000000  // 保留不用
//10000000～11000000表示平台内部失败原因

typedef enum
{
    cardstatus_normal = 0,
    cardstatus_lock = 3
}Cardstatus;

typedef enum
{
    posstatus_normal = 0,
    posstatus_cancel = 1,
    posstatus_pause = 2
}Posstatus;

typedef enum
{
    POSType     = 0,
    EncyptType  = 1,
    WalletType  = 2,
    POSStatus   = 3,
    TradeType   = 4,
    Paytype     = 5
}Pos_Codetype;

typedef enum
{
    pfversion   = 0,
    blversion   = 1,
    paraversion = 2
}Pos_Versiontype;

typedef enum
{
    source_web = 0,
    source_pos,
    source_batch
}SourceId;

typedef enum
{
    MerchantCreate = 0,
    MerchantCharge = 2,
    CustCreate     = 8,
    CustcardIssue  = 16
}ReqType;

typedef enum
{
    result_init = 0, // 初始化
    result_audit = 1, // 待审核
    result_process = 2, // 待审核
    result_succ = 3,    // 成功 
    result_fail = 4,    // 失败



    rlt_upkey_succ                  = 11,  //预充值成功
    rlt_upkey_fail_nopos            = 12,  //预充值失败-POS不存在
    rlt_upkey_fail_posstatus        = 13,  //预充值失败-POS状态不正常
    rlt_upkey_fail_nomerchant       = 14,  //预充值失败-商户不存在
    rlt_upkey_fail_checkin          = 15,  //预充值失败-POS未签到
    rlt_upkey_fail_getkey           = 16,  //预充值失败-获取key失败
    rlt_upkey_fail_insertreq        = 17,  //预充值失败-插入流水失败
    rlt_upkey_fail_sendmsg          = 18,  //预充值失败-消息发送失败
    rlt_upkey_fail_getssn           = 19,  //预充值失败-获取流水失败
    rlt_upkey_fail_account          = 20,  //预充值失败-账户充值失败

    rlt_recharge_succ               = 31,  //充值成功
    rlt_recharge_fail_nopos         = 32,  //充值失败-pos未注册
    rlt_recharge_fail_posstatus     = 33,  //充值失败-pos状态不正常
    rlt_recharge_fail_nomerchant    = 34,  //充值失败-pos所在商户不存在
    rlt_recharge_fail_checkin       = 35,  //充值失败-pos未签到
    rlt_recharge_fail_record        = 36,  //充值失败-插入流水失败
    rlt_recharge_fail_reversal_succ = 37,  //预充值失败-冲正成功
    rlt_recharge_fail_reversal_fail = 38,  //预充值失败-冲正失败
    rlt_recharge_fail_getssn        = 39,  //充值失败-获取流水号失败
    rlt_recharge_succ_dup_trade     = 40,  //已经充值成功-重复交易
    rlt_recharge_fail_logic_fail    = 41,  //充值失败-加业务逻辑锁失败
    rlt_recharge_fail_no_data       = 42,  //充值失败-预充值流水表无数据
    rlt_recharge_fail_upkey_fail    = 43,  //充值失败-预充值失败
    
    result_commission               = 71,  //批结算成功

    rlt_checkin_fail_nopos          = 91,  //签到-pos未注册
    rlt_checkin_fail_nomerchant     = 92,  //签到-pos商户不存在
    rlt_checkin_fail_posstatus      = 93,  //签到-pos状态不正常
    rlt_checkin_fail_checkin        = 94,  //签到-pos签到失败
    rlt_checkin_fail_dup_check_succ = 95,  //签到-pos重复签到成功
    rlt_checkin_succ                = 96,   //签到-pos签到成功

    rlt_batch_task_succ             = 111,  //本批次的文件解析成功
    rlt_batch_task_fail             = 112,  //本批次的文件解析失败
    
    rlt_batch_open_acc_succ         = 131,  //用户开户成功
    rlt_batch_open_acc_fail         = 132,  //用户开户失败

    rlt_issue_param_fail            = 151,  //param illegal
    rlt_issue_dbcon_fail            = 152,  //db can't connect
    rlt_issue_exesql_fail           = 153,  //execute sql fail
    rlt_issue_nocard                = 154,  //custcard is not exist
    rlt_issue_subexist              = 155,  //subscriber is already exist
    rlt_issue_card_nowashed         = 156,  //custcard is not in washed status
    rlt_issue_acctype_illegal       = 157,  //acctype is illegal
    rlt_issue_nocust                = 158,  //customer is not exist
    rlt_issue_acc_exist             = 159,  //account is already exist
    rlt_issue_create_acc_fail       = 160,  //create account fail
    rlt_issue_get_subid_fail        = 161,  //get subscriber id fail
    rlt_issue_create_sub_fail       = 162,  //create subscriber fail
    rlt_issue_get_accid_fail        = 163   //get account id fail
}ResultId;

typedef enum
{
    acc_cust_online  = 0,       // 消费者联机账户
    acc_merchant     = 2,       // 商户账户
    acc_merchant_commission = 3, //商户分成账户
    acc_cust_bus     = 101,     // 公交脱机账户
    acc_cust_rest    = 102      // 食堂脱机账户
}AccountType;

typedef enum
{
    recharge = 0,          // 充值
    reverse_recharge  = 1, // 充值冲正
    consume  = 2          // 消费
}PosTradeType;

typedef enum
{
    deduction = 1,         // 扣费
    increase  = 2          // 充值
}AccTradeType;

typedef enum
{
    washed   = 1,
    issued   = 2
}CardStatusType;

//for HSM
typedef enum
{
	tagKeyAreaNum = 0x0002,
	tagKeyType    = 0x0001,
	tagKeyVer     = 0x0003,
	tagKeyIndex   = 0x0004,
	tagEncKeyType = 0x0023,
	tagEncKeyVer  = 0x0005,
	tagEncKeyIndex= 0x0006,

	tagKeyHeaderLen = 0x000F,
	tagKeyHeader  = 0x0010,
	tagSeed       = 0x0025,
	tagCIPP       = 0x0026,
	tagcardType   = 0x0024,

	tagDvsFlag       = 0x0007,
	tagKeyDvsNum     = 0x0008,
	tagKeyDvsDataLen = 0x0009,
	tagKeyDvsData    = 0x000A,
	tagEncKeyDvsNum  = 0x000B,
	tagEncKeyDvsDataLen = 0x000C,
	tagEncKeyDvsData    = 0x000D
}HSMTagType;

typedef enum
{
	InitAppMainKeyType  = 0x01,
	InitAppMainKeyVer   = 0x00,
	InitAppMainKeyIndex = 0x00
}INITAPPMAINKEY;

typedef enum
{
	PsamAppMainKeyType  = 0x03,
	PsamAppMainKeyVer   = 0x00,
	PsamAppMainKeyIndex = 0x03
}PSAM_APPMAINKEY;

typedef enum
{
	RechargeKeyType  = 0x21,
	RechargeKeyVer   = 0x01,
	RechargeKeyIndex = 0x01
}RECHARGEKEY;

// pos版本长度
#define LEN_VERSION_BCD 5
#define LEN_VERSION (LEN_VERSION_BCD * 2)

// pos黑名单版本长度
#define LEN_BLVERSION_BCD 5
#define LEN_BLVERSION (LEN_BLVERSION_BCD * 2)

// pos参数版本长度
#define LEN_PARAMVERSION_BCD 8
#define LEN_PARAMVERSION (LEN_PARAMVERSION_BCD * 2)

// pos 日期长度
#define LEN_POSDATE_BCD 4
#define LEN_POSDATE (LEN_POSDATE_BCD * 2)

// pos 时间长度
#define LEN_POSTIME_BCD 3
#define LEN_POSTIME (LEN_POSTIME_BCD * 2)

// 商户号长度
#define LEN_BUSINESS_BCD 8
#define LEN_BUSINESS (LEN_BUSINESS_BCD * 2)

// pos机编码长度
#define LEN_POSID_BCD 8
#define LEN_POSID (LEN_POSID_BCD * 2)

// psam卡流水长度
#define LEN_PSAMSERIAL_BCD 10
#define LEN_PSAMSERIAL (LEN_PSAMSERIAL_BCD * 2)

// pos流水号长度
#define LEN_POSSERIAL_BCD 8
#define LEN_POSSERIAL (LEN_POSSERIAL_BCD * 2)

// 工作密钥长度
#define LEN_COMKEY_BCD 8
#define LEN_COMKEY (LEN_COMKEY_BCD * 2)
// 加密密钥长度
#define LEN_ENCRYPTKEY LEN_COMKEY

// 企业代码长度
#define LEN_CORPID_BCD 6
#define LEN_CORPID (LEN_CORPID_BCD * 2)

// pos线路id长度
#define LEN_LINEID_BCD 6
#define LEN_LINEID (LEN_LINEID_BCD * 2)

// app代码长度
#define LEN_APPSEQ_BCD 10
#define LEN_APPSEQ (LEN_APPSEQ_BCD * 2)

// psam卡编号长度
#define LEN_PSAMNO_BCD 10
#define LEN_PSAMNO (LEN_PSAMNO_BCD * 2)

// 终端编号
#define LEN_PSAMTERM_BCD 6
#define LEN_PSAMTERM (LEN_PSAMTERM_BCD * 2)

// pos操作员id
#define LEN_OPERID_BCD 6
#define LEN_OPERID (LEN_OPERID_BCD * 2)

// 发卡方标识
#define LEN_FACTORY_BCD 8
#define LEN_FACTORY (LEN_FACTORY_BCD * 2)

// 充值交易流水号
#define LEN_CHGSERIAL_BCD 8
#define LEN_CHGSERIAL (LEN_CHGSERIAL_BCD * 2)

// 平台操作员长度
#define LEN_PF_OPER 32
//指纹数据长度
#define LEN_FINGER_DATA 1024

// 充值预处理一次性密钥长度
#define LEN_TOPUPKEY 28

#define MAX_BATCH_TRADEDETAIL_COUNT 5

#define LEN_MSGMAC 8

#define LEN_SESSIONID 32
#define LEN_STATUS_TEXT 32


#define LEN_NAME        128
#define LEN_ADDR        128
#define LEN_AREA        32
#define LEN_POSTCODE    32
#define LEN_IDCODE      64
#define LEN_SUBSCRIBER  64

#define DB_POSTERM_LEN 32
#define DB_ENCRYPTKEY_LEN 32
#define DB_BLVERSION_LEN 32
#define DB_PFVERSION_LEN 32
#define DB_PARAMVERSION_LEN 32
#define DB_PSAMNO_LEN 32
#define DB_WORKKEY_LEN 32

// 商户资料管理 
#define DB_MERCHANTNAME_LEN 128
#define DB_MERCHANTNO_LEN 32
#define DB_LEGALPERSON_LEN 128
#define DB_IDCODE_LEN 64
#define DB_TELNUMBER_LEN 32
#define DB_CONTACTPERSION_LEN 32
#define DB_CONTACTTELNUMBER_LEN 32
#define DB_ADDRESS_LEN 200
#define DB_MAINBUSINESS_LEN 200
#define DB_BANKACCOUNT_LEN 64
#define DB_BANKNAME_LEN 64
#define DB_APPLYOPER_LEN 32
#define DB_AUTHORITYOPER_LEN 32
#define DB_CHECKINNAME_LEN 16
#define DB_CHECKINPASS_LEN 16
#define DB_DATETIME_LEN 20 // '2003.11.12 11:03:41'
#define DB_BLVER_VALUE_LEN 32

#define DB_CUSTNAME_LEN 128
#define DB_AREA_LEN 32
#define DB_POSTCODE_LEN 24
#define DB_OPER_LEN  32

#define DB_SESSIONID_LEN 32
#define DB_CORPID_LEN 16

#define DB_APPSEQ_LEN 32
#define DB_VERSIONVALUE_LEN 32

#define SYS_PRIORITY_COUNT 4
typedef enum
{
    priority_low = 0,
    priority_normal = 1,
    priority_high = 2,
    priority_urgent = 3
}Priority;

typedef enum
{
    blacktype_normal = 1,
    blacktype_loss = 2,
    blacktype_cancel = 3,
    blacktype_destory = 4
}Blacktype;

typedef enum
{
    rt_merchant_reg = 0,
    rt_merchant_cancel = 1,
    rt_merchant_recharge = 2,
    rt_pos_reg = 3,
    rt_pos_recharge = 4,
    rt_pos_topupkey = 5,
    rt_pos_chg_online = 6,
    rt_pos_checkin = 7,
    rt_cust_reg = 8,
    rt_cust_cancel = 9,
    rt_pos_batchtrade = 10,
    rt_pos_batchsettlement = 11,
    rt_module_upd = 12,
    rt_func_upd = 13,
    rt_card_to_black = 17,
    rt_card_outof_black = 18,
    rt_card_lock = 19,
    rt_batch_task = 20,
    rt_pos_blackupdate = 21
}Reqtype;

typedef enum
{
    pos_status_normal = 0,
    pos_status_cancel = 1,
    pos_status_stop = 2
}PosStatus;

typedef enum
{
    acctype_main = 0,
    acctype_offline,
    acctype_merchant_main,
    acctype_merchant_commission
}AccType;

typedef struct
{
    UINT32   msglen;                                 // 整个消息长度
    UINT16   eventno;                                // 消息事件号
    UINT8    sessionid[LEN_SESSIONID + 1];           // 系统内部sessionid
    UINT8    relate_sessionid[LEN_SESSIONID + 1];    // 系统内部关联sessionid
    SourceId sourceid;                               // 消息来源内部id
    Reqtype  reqtype;                                // 系统内部唯一操作类型id
    time_t   recvtime;
    time_t   dealtime;
    time_t   donetime;
    PID      source;                                 // 消息发送源PID
    PID      dest;                                   // 消息发送目的PID
    Priority priority;                               // 消息优先级
}T_ZIMPAY_HEAD;

/******************************** POS 接口相关 ****************************************/
// 消息头
typedef struct
{
    WORD16  wMagic;                             /* 0x5aa5*/
    BYTE    ucSenderPno;                        /*对应发送pno*/  
    BYTE    ucReceiverPno;                      /*对应接收Pno*/
    BYTE    ucBusiness[LEN_BUSINESS + 1];       /* 商户号 */
    BYTE    ucPOSID[LEN_POSID + 1];             /* 终端号 */
    BYTE    ucPSAMSerial[LEN_PSAMSERIAL + 1];   /* PSAM卡应用序列号后面10个字节 */
    BYTE    ucPOSSerial[LEN_POSSERIAL + 1];     /* 终端序列号后8个字节 */
    BYTE    ucPOSType;                          /* POS机类型 
                                                1：超市POS
                                                2：公交POS
                                                */
    BYTE    ucEncyptType;                       /* 消息中校验的类型
                                                1: XOR校验有效
                                                2: MAC校验有效
                                                0:不做校验
                                                */
    BYTE    ucWalletType;    	                /* 钱包类型
                             		            1: 第一个钱包
                             		            2: 第二个钱包
                           		                */
    WORD16	wEventId;                           /*消息号*/
    WORD16	wMsgDataLen;                        /*数据长度，不包括消息头*/  
    WORD32	wMsgSequence;                       /*消息序号*/
}T_PosCommMsgHead;

typedef struct
{
    WORD16  wMagic;                             /* 0x5aa5*/
    BYTE    ucSenderPno;                        /*对应发送pno*/  
    BYTE    ucReceiverPno;                      /*对应接收Pno*/
    BYTE    ucBusiness[LEN_BUSINESS_BCD];       /* 商户号 */
    BYTE    ucPOSID[LEN_POSID_BCD];             /* 终端号 */
    BYTE    ucPSAMSerial[LEN_PSAMSERIAL_BCD];   /* PSAM卡应用序列号后面10个字节 */
    BYTE    ucPOSSerial[LEN_POSSERIAL_BCD];     /* 终端序列号后8个字节 */
    BYTE    ucPOSType;                          /* POS机类型 
                                                1：超市POS
                                                2：公交POS
                                                */
    BYTE    ucEncyptType;                       /* 消息中校验的类型
                                                1: XOR校验有效
                                                2: MAC校验有效
                                                0:不做校验
                                                */
    BYTE    ucWalletType;    	                /* 钱包类型
                             		            1: 第一个钱包
                             		            2: 第二个钱包
                           		                */
    WORD16	wEventId;                           /*消息号*/
    WORD16	wMsgDataLen;                        /*数据长度，不包括消息头*/  
    WORD32	wMsgSequence;                       /*消息序号*/
}T_PosCommMsgHead_BCD;

#ifndef MAX_PATH
#define MAX_PATH 255
#endif
#define MAX_POS_MSG_LEN 1024
// postcp消息，到posp消息解析动态库消息
typedef struct
{
    T_ZIMPAY_HEAD pf_head;
    UINT8 posmsg[MAX_POS_MSG_LEN];
    INT32 posmsglen;
}T_POSHTTP_MSG;

// 设备签到
typedef struct
{
    BYTE    ucSWVersion[LEN_VERSION + 1];           /* POS机程序版本
                                                    YYMMDDxxxx
                                                    其中xxxx表示YYMMDD这一天生成的版本号，从0001到9999
                                                    */
    BYTE    ucBLVersion[LEN_BLVERSION + 1];         /* POS机黑名单版本
                                                    YYMMDDxxxx
                                                    其中xxxx表示YYMMDD这一天的版本号，从0001到9999
                                                    */
    BYTE    ucParamVersion[LEN_PARAMVERSION + 1];   /* 程序现有参数版本 */
    BYTE    ucPOSDate[LEN_POSDATE + 1];             /* POS日期 */
    BYTE    ucPOSTime[LEN_POSTIME + 1];             /*  POS时间 */
    BYTE    ucXOR;                                  /* XOR校验值，包括消息头*/
}T_PosHandShakQuest;


// 签到、握手应答
typedef struct
{
    WORD32  dwResult;                               /* 返回标志，0-成功；1-失败 */
    BYTE    ucPFPOSStatus;                          /* 平台侧POS状态；
                                                        0：正常，可使用;
                                                        1：暂停，POS不可使用
                                                    */
    BYTE    ucPFVersion[LEN_VERSION + 1];           /* 系统程序版本，
                                                    YYMMDDxxAB
                                                    其中xx表示YYMMDD这一天生成的版本号，从01到99。
                                                    AB为版本的类型,其中AB=01，表示该版本为可选版本，AB=10,表示该版本为强制更新的版本。
                                                    */
    WORD16  dwPFSize;                               /*
                                                    系统程序版本字节数
                                                    By:chenxue 2012.12.05
                                                    由于该类型为short，无法正确表示升级文件实际长度，所以该字段暂时不使用，填0即可
                                                    */
    WORD16  dwPFTotalPages;                         /* 系统程序版本总页面数 */
    BYTE    ucBLVersion[LEN_BLVERSION + 1];         /* 系统侧黑名单版本
                                                    YYMMDDxxxx
                                                    其中xxxx表示YYMMDD这一天的版本号，从0001到9999
                                                    */
    WORD16  dwBLCount;                              /* 当前黑名单数量 */
    BYTE    ucParamVersion[LEN_PARAMVERSION+ 1];    /* 系统侧参数版本
                                                    000000YYMMDDxxAB
                                                    其中xx表示YYMMDD这一天生成的版本号，从01到99。
                                                    AB为版本的类型,其中AB=01，表示该版本为可选版本，AB=10,表示该版本为强制更新的版本。
                                                    */
    BYTE    ucHostDate[LEN_POSDATE + 1];            /* 主机日期 */
    BYTE    ucHostTime[LEN_POSTIME + 1];            /*  主机时间 */
    BYTE    ucComKey[LEN_COMKEY + 1];               /* 工作密钥 */
    BYTE    ucXOR;                                  /* XOR校验值，包括消息头*/
}T_PosHandShakeAck;

// 平台内部，pos设备签到消息
typedef struct
{
    T_ZIMPAY_HEAD pf_head;
    T_PosCommMsgHead pos_comhead;
    T_PosHandShakQuest pos_handshakequest;
    T_PosHandShakeAck pos_handshakeack;
}T_PF_POSHANDSHAKE_REQ_AND_RES;

// 交易明细
typedef enum
{
    postradetype_consume = 6,
    postradetype_print_commission = 8,
    postradetype_trade_cancel_print_commission = 9,
    postradetype_bus_card = 10,
    postradetype_print_fee = 11,
    postradetype_card_lock = 53
}PosConsumeTradeType;

typedef struct
{
    BYTE     ucCorpID[LEN_CORPID + 1];          /* 商户号
                                                对于公交POS来说是公交公司ID
                                                */
    BYTE     ucLineID[LEN_LINEID + 1];          /* 线路ID
                                                第1个字节表示乘客类型:00-04
                                                第2个字节表示乘客的段数:01-70
                                                3-6字节表示线路号
                                                对于超市POS来说填0即可
                                                */
    BYTE     ucBUSID[LEN_BUSINESS + 1];         /* busid
                                                对于超市POS来说填0即可
                                                */
    BYTE     ucOperID[LEN_OPERID + 1];          /* 操作员ID或司机ID */
    BYTE     ucAppSequence[LEN_APPSEQ + 1];     /* 用户卡卡号:应用序列号*/    
    BYTE     ucPSAMNO[LEN_PSAMNO + 1];          /* PSAM卡卡号 */
    BYTE     ucPSAMTerminal[LEN_PSAMTERM + 1];  /* 终端编号 */
    BYTE     ucPOSSerial[LEN_POSSERIAL + 1];    /* POS流水*/
    WORD32   dwPSAMSeq;                         /* 终端交易序号 */
    PosConsumeTradeType ucTradeType;                       /* 交易类型 
                                                  6: 用户刷卡消费
                                                  8：打印佣金；
                                                  9：用户申请交易撤销时向用户扣除的佣金
                                                  10：政府补贴的学生卡乘车
                                                  11: 用户查询余额后进行打印的收费
                                                  53：用户黑名单锁定上报
                                                */
    BYTE     ucPaytype;                         /* 付费类型
                                                   1：现金
                                                   2: 13.56M CPU卡
                                                   3：2.4G RFSIM卡
                                                   51：BUS司机签到;
                                                   50：BUS司机签出
                                                   52: BUS核查员签到
                                                */
    WORD32   dwTransactionTAC;                  /* 交易TAC */
    WORD32   dwBFBalance;                       /* 钱包余额(交易前) */
    WORD32   dwMoney;                           /*  交易金额 */
    WORD32   dwCutMoney;                        /*  扣款金额 
                                                    对于超市POS，交易金额=扣费金额
                                                */
    BYTE     ucPOSDate[LEN_POSDATE + 1];        /* 终端交易时间 */
    BYTE     ucPOSTime[LEN_POSTIME + 1];        /* 终端交易时间 */
} T_PosTradeDetail;

// POS批量上送交易明细
typedef struct
{
    WORD32              dwBatchTradeRecordSeq;                      //批次号
    BYTE                ucTradeDetailCount;                         //每包的交易明细的个数，最大5个
    BYTE                ucIsOver;                                   //是否结束。1表示结束, 其他没结束。
    T_PosTradeDetail    atTradeDetail[MAX_BATCH_TRADEDETAIL_COUNT]; //
    BYTE                ucXOR ;                                     /* XOR校验值，包括消息头*/
    BYTE                ucMessageMAC[LEN_MSGMAC];                   /* 消息的MAC */
}T_PosBatchTradeReporting;

// POS批量上送响应
typedef struct
{
	WORD32  dwResult;                   /* 返回标志，0-成功；1-失败 */
    WORD32  dwBatchTradeRecordSeq;      // 本次批上送流水号
    BYTE    ucXOR;                      /* XOR校验值，包括消息头*/
    BYTE    ucMessageMAC[LEN_MSGMAC];   /* 消息的MAC */
}T_PosBatchTradeReportingAck, T_BatchTradeReportingAck;

// 平台内部，pos批上送
typedef struct
{
    T_ZIMPAY_HEAD pf_head;
    T_PosCommMsgHead pos_comhead;
    T_PosBatchTradeReporting pos_batchtradereport;
    T_PosBatchTradeReportingAck pos_batchtradereportack;
}T_PF_POSBATCHTRADEREQPORT_REQ_AND_RES;

// pos批结算请求
typedef struct
{
    WORD32  dwBatchTradeRecordSeq;      //批结算流水
    BYTE    ucCorpID[LEN_CORPID + 1];       /* 商户号 BCD码
                                        对于公交POS来说是公交公司ID
                                        */
    BYTE    ucPOSDate[LEN_POSDATE + 1];     /* 终端交易时间 BCD*/
    BYTE    ucPOSTime[LEN_POSTIME + 1];     /* 终端交易时间 BCD*/
    WORD32  dwTotalPayCount;            /* 该批次总的交易次数 */
    WORD32  dwTotalPayAmount;           /* 该批次总的交易金额 */
    BYTE    ucXOR ;                     /* XOR校验值，包括消息头*/
    BYTE    ucMessageMAC[LEN_MSGMAC];   /* 消息的MAC */
}T_BatchSettlement;

typedef struct
{
    WORD32  dwResult;                   /* 返回标志，0-成功；1-失败 */
    WORD32  dwBatchTradeRecordSeq;      // 本次批上送批次号
    BYTE    ucXOR ;                     /* XOR校验值，包括消息头*/
    BYTE    ucMessageMAC[LEN_MSGMAC];   /* 消息的MAC */
}T_BatchSettlementAck, T_BatchSettlementRes;

// 平台批结算消息 
typedef struct
{
    T_ZIMPAY_HEAD pf_head;
    T_PosCommMsgHead pos_comhead;
    T_BatchSettlement pos_settlement;
    T_BatchSettlementAck pos_settlementack;
}T_PF_POSSETTLEMENT_REQ_AND_RES;

// 充值预处理
typedef struct 
{
	BYTE    ucCardType;         /* 卡类型 */
    BYTE    idFactory[LEN_FACTORY + 1];         /* 发卡方标识 BCD*/
    BYTE    ucAppSequence[LEN_APPSEQ + 1];  /* 应用序列号BCD*/	
    BYTE    ucCountryCode;      /* 省代码 */
    WORD32  dwBalance;         /* 钱包余额 */
    WORD32  dwAmount;         /* 充值金额 */
    BYTE    ucPSAMNO[LEN_PSAMNO + 1];    /* PSAM卡应用序列号 BCD */
    BYTE    ucPSAMTerminal[LEN_PSAMTERM + 1]; /* 终端编号 BCD */
    WORD32  dwPSAMRand;     /* PSAM卡产生的随机数 */
    WORD32  dwBatchTradeRecordSeq; /* 批次号 */
    BYTE    ucPOSSerial[LEN_POSSERIAL + 1];  /* POS流水 BCD*/
    BYTE    ucTradeType;      /*  交易类型 
                                   01: 现金充值
                                   02: 领取补贴
    */
    BYTE    ucPOSDate[LEN_POSDATE + 1];    /* 终端交易时间 BCD*/
    BYTE    ucPOSTime[LEN_POSTIME + 1];    /* 终端交易时间 BCD*/
    BYTE    ucXOR ;           /* XOR校验值，包括消息头*/
    BYTE    ucMessageMAC[LEN_MSGMAC]; /* 消息的MAC */
} T_PosUpKeyReq;

typedef struct
{
    WORD32  dwResult;           /* 返回值 */
    BYTE    ucCardType;        /* 卡类型 */
    BYTE    ucAppSequence[LEN_APPSEQ + 1];  /* 应用序列号BCD*/	
    BYTE    ucCountryCode;      /* 省代码 */
    WORD32  dwBalance;         /* 钱包余额 */
    WORD32  dwAmount;         /* 充值金额
                                    如果交易类型为02/21/22，则这个字段填写确认的待领取补贴的金额
    */
    BYTE    ucPSAMNO[LEN_PSAMNO + 1];    /* PSAM卡应用序列号 BCD */
    BYTE    ucPSAMTerminal[LEN_PSAMTERM + 1]; /* 终端编号 BCD */
    WORD32  dwBatchTradeRecordSeq; /* 批次号 */
    BYTE    ucPOSSerial[LEN_POSSERIAL + 1];  /* POS流水 BCD*/
    BYTE    ucTradeType;      /*  交易类型 
                                   01: 现金充值
                                   02: 领取补贴
                                   21: 学生补贴
                                   22: M-PAiSA充值
                                   23: 补卡
    */
    BYTE    ucTopUpKey[LEN_TOPUPKEY + 1];    /*  充值密钥加密密文 */
    BYTE    ucXOR ;           /* XOR校验值，包括消息头*/
    BYTE    ucMessageMAC[LEN_MSGMAC]; /* 消息的MAC */
} T_PosUpKeyRes;

typedef struct
{
    T_ZIMPAY_HEAD pf_head;
    T_PosCommMsgHead pos_comhead;
    T_PosUpKeyReq pos_upkey_req;
    T_PosUpKeyRes pos_upkey_res;
}T_PF_UPKEY_REQ_AND_RES;

// 充值交易上传
typedef struct
{
	BYTE    ucResultStatus;       /* 充值的交易结果
                                0：成功；
                                1：失败；
                                2：卡片侧验证MAC2状态未知
                              */
    BYTE    ucCardType;         /* 卡类型 */
    WORD32  dwBatchTradeRecordSeq; /* 批次号 */
    BYTE    ucPOSSerial[LEN_CHGSERIAL + 1];      /* 充值流水号 BCD*/
    BYTE    idFactory[LEN_FACTORY + 1];         /* 发卡方标识 BCD*/
    BYTE    ucAppSequence[LEN_APPSEQ + 1];  /* 应用序列号 BCD*/	
    BYTE    ucKeyIndex;        /* 密钥索引号 */
    BYTE    ucKeyVersion;      /* 密钥版本号 */
    WORD32  dwTransactionTAC;  /* 交易TAC */
    WORD32  dwBalance;         /* 钱包余额(交易后) */
    WORD16  wOnlineCount;      /* 联机交易序号(交易前) */
    WORD32  dwMoney;         /*  交易金额 */
    BYTE    ucTradeType;      /*  交易类型 
                                   01: 现金充值
                                   02: 领取补贴
                                   03:撤销充值
                                   04:TOPUP回滚
    */
    BYTE    ucTerminalNo[LEN_POSSERIAL + 1];  /* 终端机编号 BCD*/
    BYTE    ucPOSDate[LEN_POSDATE + 1];    /* 终端交易时间 BCD*/
    BYTE    ucPOSTime[LEN_POSTIME + 1];    /* 终端交易时间 BCD*/
    BYTE    ucXOR ;          /* XOR校验值，包括消息头*/
    BYTE    ucMessageMAC[LEN_MSGMAC]; /* 消息的MAC */
}T_ChargeOnlineCheck; 

typedef struct
{
	WORD32  dwResult;
    BYTE    ucXOR ;          /* XOR校验值，包括消息头*/
    BYTE    ucMessageMAC[LEN_MSGMAC]; /* 消息的MAC */
}T_ChargeOnlineDataAck; 

// 平台充值记录上传消息
typedef struct
{
    T_ZIMPAY_HEAD pf_head;
    T_PosCommMsgHead pos_comhead;
    T_ChargeOnlineCheck chgonline_req;
    T_ChargeOnlineDataAck chgonline_rsp;
}T_CHGONLINE_REQ_AND_RSP;

typedef struct
{
    UINT8 basekey[DB_ENCRYPTKEY_LEN];
    UINT8 workkey[DB_WORKKEY_LEN];
}tb_poskey_def;

typedef struct
{
    UINT8  sessionid[DB_SESSIONID_LEN];
    UINT32 totalcount;
    UINT32 totalpayamount;
}T_POS_PAYINFO;

//指纹信息存储
typedef struct 
{
    BYTE     ucAppSequence[LEN_APPSEQ + 1];   /* cardno, customer’s card no, BCD code*/
    BYTE     ucFingerType;        /*
                                                             Customer’s Finger Flag
                                                              for rightleft hand
                                                              Thumb:1
                                                              Forefinger:2
                                                               Middle fnger:3
                                                              Third finger:4
                                                             Little finger:5
                               
                                                              for left hand
                                                                 Thumb:6
                                                             Forefinger:7
                                                              Middle fnger:8
                                                              Third finger:9
                                                               Little finger:10

                                                         */
    BYTE     ucFingerFormat;        /* 
                                                           Proprietary
                                                           ANSI 378 template
                                                               MINEX A template
                                                            ISO FMR template
                                                            ISO FMC NS template
                                                            ISO FMC CS template
                                                                   */
    WORD16  wFingerDataLen;        /* The length of finger data in ucFingerData segment,
                                                           The max value is 500
                                                   */
    BYTE     ucFingerData[LEN_FINGER_DATA + 1];    /* The actual finger data, the max value is 500 byte
                                                                It is a minutiae value for finger data
                                                            */
    BYTE     ucXOR ;                    /* XOR value, it include the Head message */
    BYTE     ucMessageMAC[LEN_MSGMAC];        /* MAC value for message */
} T_AddFingerQuest;

typedef struct 
{
    WORD32  dwResult;           /* Result */
    BYTE     ucXOR ;           /* XOR value */
    BYTE     ucMessageMAC[LEN_MSGMAC]; /* MAC value for message*/
} T_AddFingerQuestAck;

typedef struct
{
    T_ZIMPAY_HEAD pf_head;
    T_PosCommMsgHead pos_comhead;
    T_AddFingerQuest addfingerquest;
    T_AddFingerQuestAck addfingerack;
}T_ADDFINGERDATA_REQ_AND_RSP;

//指纹信息的回送
typedef struct 
{
BYTE     ucAppSequence[LEN_APPSEQ + 1];   /* cardno, customer’s card no, BCD code*/
BYTE     ucFingerType;        /*
                               Customer’s Finger Flag to ask
                                 for right hand
                               Thumb:1
                               Forefinger:2
                               Middle fnger:3
                               Third finger:4
                               Little finger:5
                               
                                 for left hand
                               Thumb:6
                               Forefinger:7
                               Middle fnger:8
                               Third finger:9
                               Little finger:10
                              */
BYTE     ucFingerFormat;      /* 
Proprietary
ANSI 378 template
MINEX A template
ISO FMR template
ISO FMC NS template
ISO FMC CS template
*/
WORD16  wFingerDataLen;     /* The length of finger data in ucFingerData segment,
                                The max value is 500
*/
BYTE     ucFingerData[LEN_FINGER_DATA + 1];    /* The actual finger data, the max value is 500 byte
                                It is a minutiae value for finger data
                              */
BYTE     ucXOR ;           /* XOR value, it include the Head message */
BYTE     ucMessageMAC[LEN_MSGMAC]; /* MAC value for message */
} T_AskFingerDataQuest;

typedef struct 
{
WORD32  dwResult;           /* Result */
WORD16  wFingerDataLen;     /* The length of finger data in ucFingerData segment,
                                The max value is 500
*/
BYTE     ucFingerData[LEN_FINGER_DATA + 1];    /* The actual finger data, the max value is 500 byte
                                It is a minutiae value for finger data
                              */
BYTE     ucXOR ;           /* XOR value */
BYTE     ucMessageMAC[LEN_MSGMAC]; /* MAC value for message*/
} T_AskFingerDataQuestAck;

typedef struct
{
    T_ZIMPAY_HEAD pf_head;
    T_PosCommMsgHead pos_comhead;
    T_AskFingerDataQuest backfingerdataques;
    T_AskFingerDataQuestAck backfingerdatarsp;
}T_BACKFINGERDATA_REQ_AND_RSP;

//Query the user information
typedef struct
{
    INT32 custid;
    UINT8 custname[DB_CUSTNAME_LEN];
    INT32 idtype;
    UINT8 idcode[LEN_IDCODE];
}tb_cust_to_finger;

// 黑名单处理
typedef enum
{
    pagetype_total = 0,
    pagetype_upper_half,
    pagetype_lower_half
}Pagetype;

typedef struct
{
    BYTE        ucBLVersion[LEN_BLVERSION + 1];       /* POS机黑名单版本
                                YYMMDDxxxx
                                其中xxxx表示YYMMDD这一天的版本号，从0001到9999
                              */
    WORD16      wBLPage;            /*
                                请求的黑名单的页数
                              */
    Pagetype    ucPageType;          /*
                                0：全页
                                1：上半页
                                2：下半页
                              */
    BYTE        ucXOR;           /* XOR校验值，包括消息头*/
    BYTE        ucMessageMAC[LEN_MSGMAC]; /* 消息的MAC */
} T_GetBlackListQuest;

#define POS_BLACKDATA_PAGE_LEN 512 // 内部消息，按asc码保存
typedef struct
{
    WORD32      dwResult;             /*  返回值  */
    BYTE        ucBLVersion[LEN_BLVERSION + 1];       /* 系统侧黑名单版本
                                YYMMDDxxxx
                                其中xxxx表示YYMMDD这一天的版本号，从0001到9999
                              */
    WORD16      wBLPage;            /*
                                请求的黑名单的页数
                              */
    Pagetype    ucPageType;          /*
                                0：全页
                                1：上半页
                                2：下半页
                              */
    BYTE        ucBlackListData[POS_BLACKDATA_PAGE_LEN + 1];  /*
                                黑名单数据
                                如果ucPageType为0，则该字段长度为256；否则，长度为128
                              */
    BYTE        ucXOR;           /* XOR校验值，包括消息头*/
    BYTE        ucMessageMAC[LEN_MSGMAC]; /* 消息的MAC */
} T_GetBlackListQuestAck;

typedef struct 
{
    T_ZIMPAY_HEAD pf_head;
    T_PosCommMsgHead pos_comhead;
    T_GetBlackListQuest blackupdreq;
    T_GetBlackListQuestAck blackupdack;
}T_POS_UPDBLACK_REQ_AND_RSP;

/******************************** POS 接口相关 ****************************************/

/******************************** 处理机交互消息定义 ****************************************/
// 系统业务操作结果信息
#define MAX_STATUS_TEXT_LEN 64
typedef struct
{
    ResultId result;    // 系统操作结果码
    INT32 status;       // 协议结果码
    UINT8 statustext[MAX_STATUS_TEXT_LEN + 1]; // 操作结果描述
}T_REQ_RESULT;


// pos机资料注册工单信息
typedef struct
{
    UINT32  id;
    UINT32  merchantid;
    UINT8   postermno[DB_POSTERM_LEN];
    INT32   postype;
    INT32   posstatus;
    UINT8   encryptkey[DB_ENCRYPTKEY_LEN];
    UINT8   blversion[DB_BLVERSION_LEN];
    UINT32  blcount;
    UINT8   pfversion[DB_PFVERSION_LEN];
    UINT32  pftotalpages;
    UINT8   paramversion[DB_PARAMVERSION_LEN];
    UINT8   psamno[DB_PSAMNO_LEN];
}T_POS_REQ;

// pos机信息管理
typedef struct
{
    T_ZIMPAY_HEAD pf_head;
    T_POS_REQ posinfo_req;
    T_REQ_RESULT resultinfo;
}T_POSINFO_REQ;

typedef struct
{
    UINT32  id;
    UINT8   merchantname[DB_MERCHANTNAME_LEN];
    UINT8   merchantno[DB_MERCHANTNO_LEN];
    UINT8   legalperson[DB_LEGALPERSON_LEN];
    INT32   idtype;
    UINT8   idcode[DB_IDCODE_LEN];
    UINT8   idbegindate[DB_DATETIME_LEN];
    UINT8   idexpirydate[DB_DATETIME_LEN];
    UINT8   telnumber[DB_TELNUMBER_LEN];
    UINT8   contactperson[DB_CONTACTPERSION_LEN];
    UINT8   contacttelnum[DB_CONTACTTELNUMBER_LEN];
    UINT8   address[DB_ADDRESS_LEN];
    UINT8   mainbusiness[DB_MAINBUSINESS_LEN];
    UINT8   bankaccount[DB_BANKACCOUNT_LEN];
    UINT8   bankname[DB_BANKNAME_LEN];
    INT32   commissionsltid;
    UINT8   applyoper[DB_APPLYOPER_LEN];
    UINT8   authorityoper[DB_AUTHORITYOPER_LEN];
    UINT8   checkinname[DB_CHECKINNAME_LEN];
    UINT8   checkinpasswd[DB_CHECKINPASS_LEN];
}T_MERCHANT_REQ;



// 商户管理
typedef struct
{
    T_ZIMPAY_HEAD pf_head;
    T_MERCHANT_REQ merchantinfo_req;
    T_REQ_RESULT resultinfo;
}T_MERCHANTINFO_REQ;


// 客户注册
typedef struct
{
    UINT32  id;
    UINT8   custname[DB_CUSTNAME_LEN];
    INT32   idtype;
    UINT8   idcode[DB_IDCODE_LEN];
    UINT8   idbegindate[DB_DATETIME_LEN];
    UINT8   idexpirydate[DB_DATETIME_LEN];
    UINT8   telnumber[DB_TELNUMBER_LEN];
    UINT8   address[DB_ADDRESS_LEN];
    UINT8   area[DB_AREA_LEN];
    UINT8   postcode[DB_POSTCODE_LEN];
    UINT8   oper[DB_OPER_LEN];
}T_CUST_REQ;

// 客户注册
typedef struct
{
    UINT32  id;
    UINT8   custname[DB_CUSTNAME_LEN +1];
    INT32   idtype;
    UINT8   idcode[DB_IDCODE_LEN +1];
    UINT8   idbegindate[DB_DATETIME_LEN +1];
    UINT8   idexpirydate[DB_DATETIME_LEN +1];
    UINT8   telnumber[DB_TELNUMBER_LEN +1];
    UINT8   address[DB_ADDRESS_LEN +1];
    UINT8   area[DB_AREA_LEN +1];
    UINT8   postcode[DB_POSTCODE_LEN +1];
    UINT8   oper[DB_OPER_LEN +1];
}T_CUST_REQ_STR;

// 客户信息管理
typedef struct
{
    T_ZIMPAY_HEAD pf_head;
    T_CUST_REQ custinfo_req;
    T_REQ_RESULT resultinfo;
}T_CUSTINFO_REQ;

// 商户充值
typedef struct
{
    UINT32  id;
    UINT32  merchantid;
    UINT8   merchantname[DB_MERCHANTNAME_LEN];
    UINT8   merchantno[DB_MERCHANTNO_LEN];
    UINT8   legalperson[DB_LEGALPERSON_LEN];
    INT32   idtype;
    UINT8   idcode[DB_IDCODE_LEN];
    UINT8   idbegindate[DB_DATETIME_LEN];
    UINT8   idexpirydate[DB_DATETIME_LEN];
    UINT8   telnumber[DB_TELNUMBER_LEN];
    UINT8   contactpersion[DB_CONTACTPERSION_LEN];
    UINT8   contacttelnumber[DB_CONTACTTELNUMBER_LEN];
    UINT8   addr[DB_ADDRESS_LEN];
    UINT8   mainbusiness[DB_MAINBUSINESS_LEN];
    UINT8   bankaccount[DB_BANKACCOUNT_LEN];
    UINT8   bankname[DB_BANKNAME_LEN];
    INT32   commisionsltid;
    UINT32  accid;
    UINT32  acctype;
    UINT32  chargevalue;
}T_MERCHANT_CHARGE_REQ;

// 商户充值
typedef struct
{
    T_ZIMPAY_HEAD pf_head;
    T_MERCHANT_CHARGE_REQ merchant_chg;
    T_REQ_RESULT resultinfo;
}T_MERCHANT_CHG_REQ;

// 黑名单更新
typedef struct
{
    UINT32 id;
    INT32 reqtype;
    Blacktype blacktype;
    UINT8 appseqno[DB_APPSEQ_LEN];
    UINT32 newversion;
}T_BLACKLIST_UPDATE;

typedef struct
{
    T_ZIMPAY_HEAD pf_head;
    T_BLACKLIST_UPDATE blackupd;
    T_REQ_RESULT resultinfo;
}T_BLACKLIST_UPDATE_REQ;

// 发用户卡
typedef struct
{
    UINT32  id;
    UINT32  appid;
    UINT8   appsequence[DB_APPSEQ_LEN];
    UINT32  custid;
    UINT8   oper[DB_OPER_LEN];
}T_DB_CUSTCARD_ISSUE;

typedef struct
{
    T_ZIMPAY_HEAD pf_head;
    T_DB_CUSTCARD_ISSUE custcard_issue;
    T_REQ_RESULT resultinfo;
}T_CUSTCARD_ISSUE_REQ;

// 门户 -- 处理机请求
typedef struct
{
    T_ZIMPAY_HEAD pf_head;
    UINT32 req_table_id;
    T_REQ_RESULT resultinfo;
}T_PORTAL_REQ_AND_RES;

#define MAX_CFGNAME_LEN 32
#define MAX_CFGVALUE_LEN 128
typedef struct
{
    UINT8 configname[MAX_CFGNAME_LEN + 1];
    UINT8 configvalue[MAX_CFGVALUE_LEN + 1];
}T_SYSCONFIG_UPD;
//批量开户
#define REQNAME_VALUE_LEN 64
#define REQFILE_VALUE_LEN 256
#define BATCH_OPEN_SSN_LEN 32
typedef struct
{
    UINT32 id;
    UINT8 sessionid[BATCH_OPEN_SSN_LEN];
    UINT32 reqtype;
    UINT8 reqname[REQNAME_VALUE_LEN];
    UINT8 requestfile[REQFILE_VALUE_LEN];
}T_BATCH_OPEN_REQ;
//end
typedef union
{
    T_POS_REQ posreq;
    T_MERCHANT_REQ merchantreq;
    T_CUST_REQ custreq;
    T_MERCHANT_CHARGE_REQ merchantchargereq;
    T_BATCH_OPEN_REQ batchopenreq;
    T_BLACKLIST_UPDATE blackreq;
}T_DB_REQINFO;

typedef struct
{
    T_ZIMPAY_HEAD pf_head;
    T_DB_REQINFO req;
    T_REQ_RESULT resultinfo;
}T_PORTAL_MSG_DETAIL;

// 卡锁定
typedef struct
{
    T_ZIMPAY_HEAD pf_head;
    UINT8 appseqno[LEN_APPSEQ + 1];
}T_POS_CARD_LOCK;
/******************************** 处理机和门户交互消息定义 ****************************************/

/******************************** master控制注册，心跳等消息 *************************************/
/*模块注册请求消息结构*/
typedef struct
{
    UINT8 moduleName[MAX_MODULENAME_LEN];       // 模块名
}MODULEREGREQ;

/*模块注册响应消息结构*/
typedef struct
{
	UINT8 nResult;	            // 0:成功;1:失败
	UINT8 szResultDesc[128];	// 失败:失败原因，成功:zookeeper serverlist
}MODULEREGRSP;

typedef struct
{
    UINT8 moduleName[MAX_MODULENAME_LEN];       // 发消息者模块名
}ACTIVETESTREQ;

typedef struct
{
    UINT8 nResult;	            // 0:成功;1:失败
    UINT8 moduleName[MAX_MODULENAME_LEN];       // 发消息者模块名
}ACTIVETESTRSP;

// module 更新信息
typedef struct
{
    UINT8 modulename[MAX_MODULENAME_LEN];
    UINT8 libname[MAX_LIBNAME_LEN];
    UINT8 verion[MAX_VERSION_LEN];
    UINT8 f_init[MAX_FUNCNAME_LEN];
    UINT8 f_updcfg[MAX_FUNCNAME_LEN];
    UINT8 f_exit[MAX_FUNCNAME_LEN];
}T_MODULE_UPD;

// func 更新信息
typedef struct
{
    UINT8 modulename[MAX_MODULENAME_LEN];
    UINT8 funcname[MAX_FUNCNAME_LEN];
    INT32 eventno;
}T_FUNC_UPD;

typedef enum
{
    update_module = 0,
    update_func
}ShareLibUpdType;

// master给process的module/func更新信息
typedef struct
{
    T_PORTAL_REQ_AND_RES portalmsg;
    ShareLibUpdType type;
    union
    {
        T_MODULE_UPD moduleinfo;
        T_FUNC_UPD funcinfo;
    }info;
}T_SHLIB_UPD_AND_RES;

/******************************** master控制注册，心跳等消息 *************************************/


/******************************** 账户模块消息 *************************************/
typedef struct
{
	BYTE        accid;        //accid
	BYTE        acctype;      //accid的账户类型
	UINT32      amount;       //交易金额
	AccTradeType acctradetype; //交易类型， 加钱还是减钱
}T_ACCOUNT_TRADE;

typedef struct
{
	UINT8           ucAppSequence[LEN_APPSEQ+1];   //卡号 或应用序列号
	BYTE            ucAppType;             //卡类型 或应用类型
	UINT8           ucPOSId[LEN_POSID+1];      //商户pos序列号
	BYTE            ucPOSType;             //postype
	BYTE            postradetype;             //交易类型: 0-充值; 1-充值冲正 ; 2-消费  ;
    UINT32          amount;                //交易金额
}T_POS_TRADE;

typedef struct
{
	T_POS_TRADE     posinfo;     //pos消息里的信息
	T_ACCOUNT_TRADE fromaccount; //传给account模块的消息,转出账户
	T_ACCOUNT_TRADE toaccount;   //传给account模块的消息,转入账户
    T_REQ_RESULT    resultinfo;
}T_PE_TRADE;


/******************************** 账户模块消息 *************************************/

/*************************************posp***********************************************/
//充值状态
typedef enum
{   
    reChargeStatusFail = 0,       //预充值失败后的状态
    reChargeStatusSucc = 1,       //预充值成功后的状态
    afterChargeStatus = 2,    //充值成功以后状态
    chargeReversalStatus = 3,  // 充值失败，冲正成功状态
    chargeReversalFailStat = 4, //冲正失败状态
    chargeprocfailure = 5       //平台处理失败
}POS_RE_AF_CHARGE_STATUS;

//充值的交易结果
typedef enum
{
    onChargResultStatussucc = 0, //成功
    onChargResultStatusfail = 1, //失败
    onChargResultStatusmacfail = 2 //卡片侧验证MAC2状态未知
}pos_onCharge_Result_Status;


// posdll 和 hsm间消息
typedef struct
{
    T_ZIMPAY_HEAD pf_head;
	INT32 dwPSAMRand;
	INT8  szUserCard[LEN_APPSEQ + 1];
	INT8  szPsamCard[LEN_PSAMNO + 1];
	INT8  szSessionid[LEN_SESSIONID + 1];
}T_PTOH_TOPUP_REQ;

typedef struct
{
    T_ZIMPAY_HEAD pf_head;
    INT32 iResult ;
	INT8 szTopupKey[LEN_TOPUPKEY + 1];
	INT8 szSessionid[LEN_SESSIONID + 1];
    INT8 szStatusText[LEN_STATUS_TEXT + 1] ;
}T_HTOP_TOPUP_RSP;


#define LEN_KEY_HEADER    255
#define LEN_SEED          16
#define LEN_CIPP          8
#define LEN_PER_DVS       0x8
#define LEN_MAX_DVS       0x8 * 5

typedef struct
{
   UINT32 dwCmd;
   UINT8  KeyAreaNum;
   UINT8  KeyType;
   UINT8  KeyVer;
   UINT8  KeyIndex;
   UINT8  EncKeyType;
   UINT8  EncKeyVer;
   UINT8  EncKeyIndex;
   UINT8  KeyHeaderLen;
   UINT8  KeyHeader[LEN_KEY_HEADER+1];
   UINT8  Seed[LEN_SEED+1];
   UINT8  CIPP[LEN_CIPP+1];
   UINT8  cardType;
   UINT8  DvsFlag;
   UINT8  KeyDvsNum;
   UINT8  KeyDvsDataLen;
   UINT8  KeyDvsData[LEN_MAX_DVS+1];
   UINT8  EncKeyDvsNum;
   UINT8  EncKeyDvsDataLen;
   UINT8  EncKeyDvsData[LEN_MAX_DVS+1];
}T_SUBKEYGEN_REQ;



/*************************************posp***********************************************/


#ifdef HP_UNIX
#pragma pack 4
#elif defined(AIX)
#pragma options align=reset
#else
#pragma pack()
#endif


#ifdef __cplusplus
extern "C"
{
#endif



#ifndef Snprintf
#ifdef _WIN32
#define Snprintf _snprintf
#else
#define Snprintf snprintf
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif /* _ZIMPAY_MSG_H */

