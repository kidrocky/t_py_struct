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

// �����붨��
#define ERR_OTHERS -9999

// ���δ�յ�������Ϣ�����������δ���������Ϊģ��崻�
#define MAX_ACTIVE_TEST_COUNT 4

// znode����·������
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

//10000000��11000000��ʾƽ̨�ڲ�ʧ��ԭ��
#define ERR_INNERSTART      10000000  // ��������

#define ERR_INNEREND        11000000  // ��������
//10000000��11000000��ʾƽ̨�ڲ�ʧ��ԭ��

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
    result_init = 0, // ��ʼ��
    result_audit = 1, // �����
    result_process = 2, // �����
    result_succ = 3,    // �ɹ� 
    result_fail = 4,    // ʧ��



    rlt_upkey_succ                  = 11,  //Ԥ��ֵ�ɹ�
    rlt_upkey_fail_nopos            = 12,  //Ԥ��ֵʧ��-POS������
    rlt_upkey_fail_posstatus        = 13,  //Ԥ��ֵʧ��-POS״̬������
    rlt_upkey_fail_nomerchant       = 14,  //Ԥ��ֵʧ��-�̻�������
    rlt_upkey_fail_checkin          = 15,  //Ԥ��ֵʧ��-POSδǩ��
    rlt_upkey_fail_getkey           = 16,  //Ԥ��ֵʧ��-��ȡkeyʧ��
    rlt_upkey_fail_insertreq        = 17,  //Ԥ��ֵʧ��-������ˮʧ��
    rlt_upkey_fail_sendmsg          = 18,  //Ԥ��ֵʧ��-��Ϣ����ʧ��
    rlt_upkey_fail_getssn           = 19,  //Ԥ��ֵʧ��-��ȡ��ˮʧ��
    rlt_upkey_fail_account          = 20,  //Ԥ��ֵʧ��-�˻���ֵʧ��

    rlt_recharge_succ               = 31,  //��ֵ�ɹ�
    rlt_recharge_fail_nopos         = 32,  //��ֵʧ��-posδע��
    rlt_recharge_fail_posstatus     = 33,  //��ֵʧ��-pos״̬������
    rlt_recharge_fail_nomerchant    = 34,  //��ֵʧ��-pos�����̻�������
    rlt_recharge_fail_checkin       = 35,  //��ֵʧ��-posδǩ��
    rlt_recharge_fail_record        = 36,  //��ֵʧ��-������ˮʧ��
    rlt_recharge_fail_reversal_succ = 37,  //Ԥ��ֵʧ��-�����ɹ�
    rlt_recharge_fail_reversal_fail = 38,  //Ԥ��ֵʧ��-����ʧ��
    rlt_recharge_fail_getssn        = 39,  //��ֵʧ��-��ȡ��ˮ��ʧ��
    rlt_recharge_succ_dup_trade     = 40,  //�Ѿ���ֵ�ɹ�-�ظ�����
    rlt_recharge_fail_logic_fail    = 41,  //��ֵʧ��-��ҵ���߼���ʧ��
    rlt_recharge_fail_no_data       = 42,  //��ֵʧ��-Ԥ��ֵ��ˮ��������
    rlt_recharge_fail_upkey_fail    = 43,  //��ֵʧ��-Ԥ��ֵʧ��
    
    result_commission               = 71,  //������ɹ�

    rlt_checkin_fail_nopos          = 91,  //ǩ��-posδע��
    rlt_checkin_fail_nomerchant     = 92,  //ǩ��-pos�̻�������
    rlt_checkin_fail_posstatus      = 93,  //ǩ��-pos״̬������
    rlt_checkin_fail_checkin        = 94,  //ǩ��-posǩ��ʧ��
    rlt_checkin_fail_dup_check_succ = 95,  //ǩ��-pos�ظ�ǩ���ɹ�
    rlt_checkin_succ                = 96,   //ǩ��-posǩ���ɹ�

    rlt_batch_task_succ             = 111,  //�����ε��ļ������ɹ�
    rlt_batch_task_fail             = 112,  //�����ε��ļ�����ʧ��
    
    rlt_batch_open_acc_succ         = 131,  //�û������ɹ�
    rlt_batch_open_acc_fail         = 132,  //�û�����ʧ��

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
    acc_cust_online  = 0,       // �����������˻�
    acc_merchant     = 2,       // �̻��˻�
    acc_merchant_commission = 3, //�̻��ֳ��˻�
    acc_cust_bus     = 101,     // �����ѻ��˻�
    acc_cust_rest    = 102      // ʳ���ѻ��˻�
}AccountType;

typedef enum
{
    recharge = 0,          // ��ֵ
    reverse_recharge  = 1, // ��ֵ����
    consume  = 2          // ����
}PosTradeType;

typedef enum
{
    deduction = 1,         // �۷�
    increase  = 2          // ��ֵ
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

// pos�汾����
#define LEN_VERSION_BCD 5
#define LEN_VERSION (LEN_VERSION_BCD * 2)

// pos�������汾����
#define LEN_BLVERSION_BCD 5
#define LEN_BLVERSION (LEN_BLVERSION_BCD * 2)

// pos�����汾����
#define LEN_PARAMVERSION_BCD 8
#define LEN_PARAMVERSION (LEN_PARAMVERSION_BCD * 2)

// pos ���ڳ���
#define LEN_POSDATE_BCD 4
#define LEN_POSDATE (LEN_POSDATE_BCD * 2)

// pos ʱ�䳤��
#define LEN_POSTIME_BCD 3
#define LEN_POSTIME (LEN_POSTIME_BCD * 2)

// �̻��ų���
#define LEN_BUSINESS_BCD 8
#define LEN_BUSINESS (LEN_BUSINESS_BCD * 2)

// pos�����볤��
#define LEN_POSID_BCD 8
#define LEN_POSID (LEN_POSID_BCD * 2)

// psam����ˮ����
#define LEN_PSAMSERIAL_BCD 10
#define LEN_PSAMSERIAL (LEN_PSAMSERIAL_BCD * 2)

// pos��ˮ�ų���
#define LEN_POSSERIAL_BCD 8
#define LEN_POSSERIAL (LEN_POSSERIAL_BCD * 2)

// ������Կ����
#define LEN_COMKEY_BCD 8
#define LEN_COMKEY (LEN_COMKEY_BCD * 2)
// ������Կ����
#define LEN_ENCRYPTKEY LEN_COMKEY

// ��ҵ���볤��
#define LEN_CORPID_BCD 6
#define LEN_CORPID (LEN_CORPID_BCD * 2)

// pos��·id����
#define LEN_LINEID_BCD 6
#define LEN_LINEID (LEN_LINEID_BCD * 2)

// app���볤��
#define LEN_APPSEQ_BCD 10
#define LEN_APPSEQ (LEN_APPSEQ_BCD * 2)

// psam����ų���
#define LEN_PSAMNO_BCD 10
#define LEN_PSAMNO (LEN_PSAMNO_BCD * 2)

// �ն˱��
#define LEN_PSAMTERM_BCD 6
#define LEN_PSAMTERM (LEN_PSAMTERM_BCD * 2)

// pos����Աid
#define LEN_OPERID_BCD 6
#define LEN_OPERID (LEN_OPERID_BCD * 2)

// ��������ʶ
#define LEN_FACTORY_BCD 8
#define LEN_FACTORY (LEN_FACTORY_BCD * 2)

// ��ֵ������ˮ��
#define LEN_CHGSERIAL_BCD 8
#define LEN_CHGSERIAL (LEN_CHGSERIAL_BCD * 2)

// ƽ̨����Ա����
#define LEN_PF_OPER 32
//ָ�����ݳ���
#define LEN_FINGER_DATA 1024

// ��ֵԤ����һ������Կ����
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

// �̻����Ϲ��� 
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
    UINT32   msglen;                                 // ������Ϣ����
    UINT16   eventno;                                // ��Ϣ�¼���
    UINT8    sessionid[LEN_SESSIONID + 1];           // ϵͳ�ڲ�sessionid
    UINT8    relate_sessionid[LEN_SESSIONID + 1];    // ϵͳ�ڲ�����sessionid
    SourceId sourceid;                               // ��Ϣ��Դ�ڲ�id
    Reqtype  reqtype;                                // ϵͳ�ڲ�Ψһ��������id
    time_t   recvtime;
    time_t   dealtime;
    time_t   donetime;
    PID      source;                                 // ��Ϣ����ԴPID
    PID      dest;                                   // ��Ϣ����Ŀ��PID
    Priority priority;                               // ��Ϣ���ȼ�
}T_ZIMPAY_HEAD;

/******************************** POS �ӿ���� ****************************************/
// ��Ϣͷ
typedef struct
{
    WORD16  wMagic;                             /* 0x5aa5*/
    BYTE    ucSenderPno;                        /*��Ӧ����pno*/  
    BYTE    ucReceiverPno;                      /*��Ӧ����Pno*/
    BYTE    ucBusiness[LEN_BUSINESS + 1];       /* �̻��� */
    BYTE    ucPOSID[LEN_POSID + 1];             /* �ն˺� */
    BYTE    ucPSAMSerial[LEN_PSAMSERIAL + 1];   /* PSAM��Ӧ�����кź���10���ֽ� */
    BYTE    ucPOSSerial[LEN_POSSERIAL + 1];     /* �ն����кź�8���ֽ� */
    BYTE    ucPOSType;                          /* POS������ 
                                                1������POS
                                                2������POS
                                                */
    BYTE    ucEncyptType;                       /* ��Ϣ��У�������
                                                1: XORУ����Ч
                                                2: MACУ����Ч
                                                0:����У��
                                                */
    BYTE    ucWalletType;    	                /* Ǯ������
                             		            1: ��һ��Ǯ��
                             		            2: �ڶ���Ǯ��
                           		                */
    WORD16	wEventId;                           /*��Ϣ��*/
    WORD16	wMsgDataLen;                        /*���ݳ��ȣ���������Ϣͷ*/  
    WORD32	wMsgSequence;                       /*��Ϣ���*/
}T_PosCommMsgHead;

typedef struct
{
    WORD16  wMagic;                             /* 0x5aa5*/
    BYTE    ucSenderPno;                        /*��Ӧ����pno*/  
    BYTE    ucReceiverPno;                      /*��Ӧ����Pno*/
    BYTE    ucBusiness[LEN_BUSINESS_BCD];       /* �̻��� */
    BYTE    ucPOSID[LEN_POSID_BCD];             /* �ն˺� */
    BYTE    ucPSAMSerial[LEN_PSAMSERIAL_BCD];   /* PSAM��Ӧ�����кź���10���ֽ� */
    BYTE    ucPOSSerial[LEN_POSSERIAL_BCD];     /* �ն����кź�8���ֽ� */
    BYTE    ucPOSType;                          /* POS������ 
                                                1������POS
                                                2������POS
                                                */
    BYTE    ucEncyptType;                       /* ��Ϣ��У�������
                                                1: XORУ����Ч
                                                2: MACУ����Ч
                                                0:����У��
                                                */
    BYTE    ucWalletType;    	                /* Ǯ������
                             		            1: ��һ��Ǯ��
                             		            2: �ڶ���Ǯ��
                           		                */
    WORD16	wEventId;                           /*��Ϣ��*/
    WORD16	wMsgDataLen;                        /*���ݳ��ȣ���������Ϣͷ*/  
    WORD32	wMsgSequence;                       /*��Ϣ���*/
}T_PosCommMsgHead_BCD;

#ifndef MAX_PATH
#define MAX_PATH 255
#endif
#define MAX_POS_MSG_LEN 1024
// postcp��Ϣ����posp��Ϣ������̬����Ϣ
typedef struct
{
    T_ZIMPAY_HEAD pf_head;
    UINT8 posmsg[MAX_POS_MSG_LEN];
    INT32 posmsglen;
}T_POSHTTP_MSG;

// �豸ǩ��
typedef struct
{
    BYTE    ucSWVersion[LEN_VERSION + 1];           /* POS������汾
                                                    YYMMDDxxxx
                                                    ����xxxx��ʾYYMMDD��һ�����ɵİ汾�ţ���0001��9999
                                                    */
    BYTE    ucBLVersion[LEN_BLVERSION + 1];         /* POS���������汾
                                                    YYMMDDxxxx
                                                    ����xxxx��ʾYYMMDD��һ��İ汾�ţ���0001��9999
                                                    */
    BYTE    ucParamVersion[LEN_PARAMVERSION + 1];   /* �������в����汾 */
    BYTE    ucPOSDate[LEN_POSDATE + 1];             /* POS���� */
    BYTE    ucPOSTime[LEN_POSTIME + 1];             /*  POSʱ�� */
    BYTE    ucXOR;                                  /* XORУ��ֵ��������Ϣͷ*/
}T_PosHandShakQuest;


// ǩ��������Ӧ��
typedef struct
{
    WORD32  dwResult;                               /* ���ر�־��0-�ɹ���1-ʧ�� */
    BYTE    ucPFPOSStatus;                          /* ƽ̨��POS״̬��
                                                        0����������ʹ��;
                                                        1����ͣ��POS����ʹ��
                                                    */
    BYTE    ucPFVersion[LEN_VERSION + 1];           /* ϵͳ����汾��
                                                    YYMMDDxxAB
                                                    ����xx��ʾYYMMDD��һ�����ɵİ汾�ţ���01��99��
                                                    ABΪ�汾������,����AB=01����ʾ�ð汾Ϊ��ѡ�汾��AB=10,��ʾ�ð汾Ϊǿ�Ƹ��µİ汾��
                                                    */
    WORD16  dwPFSize;                               /*
                                                    ϵͳ����汾�ֽ���
                                                    By:chenxue 2012.12.05
                                                    ���ڸ�����Ϊshort���޷���ȷ��ʾ�����ļ�ʵ�ʳ��ȣ����Ը��ֶ���ʱ��ʹ�ã���0����
                                                    */
    WORD16  dwPFTotalPages;                         /* ϵͳ����汾��ҳ���� */
    BYTE    ucBLVersion[LEN_BLVERSION + 1];         /* ϵͳ��������汾
                                                    YYMMDDxxxx
                                                    ����xxxx��ʾYYMMDD��һ��İ汾�ţ���0001��9999
                                                    */
    WORD16  dwBLCount;                              /* ��ǰ���������� */
    BYTE    ucParamVersion[LEN_PARAMVERSION+ 1];    /* ϵͳ������汾
                                                    000000YYMMDDxxAB
                                                    ����xx��ʾYYMMDD��һ�����ɵİ汾�ţ���01��99��
                                                    ABΪ�汾������,����AB=01����ʾ�ð汾Ϊ��ѡ�汾��AB=10,��ʾ�ð汾Ϊǿ�Ƹ��µİ汾��
                                                    */
    BYTE    ucHostDate[LEN_POSDATE + 1];            /* �������� */
    BYTE    ucHostTime[LEN_POSTIME + 1];            /*  ����ʱ�� */
    BYTE    ucComKey[LEN_COMKEY + 1];               /* ������Կ */
    BYTE    ucXOR;                                  /* XORУ��ֵ��������Ϣͷ*/
}T_PosHandShakeAck;

// ƽ̨�ڲ���pos�豸ǩ����Ϣ
typedef struct
{
    T_ZIMPAY_HEAD pf_head;
    T_PosCommMsgHead pos_comhead;
    T_PosHandShakQuest pos_handshakequest;
    T_PosHandShakeAck pos_handshakeack;
}T_PF_POSHANDSHAKE_REQ_AND_RES;

// ������ϸ
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
    BYTE     ucCorpID[LEN_CORPID + 1];          /* �̻���
                                                ���ڹ���POS��˵�ǹ�����˾ID
                                                */
    BYTE     ucLineID[LEN_LINEID + 1];          /* ��·ID
                                                ��1���ֽڱ�ʾ�˿�����:00-04
                                                ��2���ֽڱ�ʾ�˿͵Ķ���:01-70
                                                3-6�ֽڱ�ʾ��·��
                                                ���ڳ���POS��˵��0����
                                                */
    BYTE     ucBUSID[LEN_BUSINESS + 1];         /* busid
                                                ���ڳ���POS��˵��0����
                                                */
    BYTE     ucOperID[LEN_OPERID + 1];          /* ����ԱID��˾��ID */
    BYTE     ucAppSequence[LEN_APPSEQ + 1];     /* �û�������:Ӧ�����к�*/    
    BYTE     ucPSAMNO[LEN_PSAMNO + 1];          /* PSAM������ */
    BYTE     ucPSAMTerminal[LEN_PSAMTERM + 1];  /* �ն˱�� */
    BYTE     ucPOSSerial[LEN_POSSERIAL + 1];    /* POS��ˮ*/
    WORD32   dwPSAMSeq;                         /* �ն˽������ */
    PosConsumeTradeType ucTradeType;                       /* �������� 
                                                  6: �û�ˢ������
                                                  8����ӡӶ��
                                                  9���û����뽻�׳���ʱ���û��۳���Ӷ��
                                                  10������������ѧ�����˳�
                                                  11: �û���ѯ������д�ӡ���շ�
                                                  53���û������������ϱ�
                                                */
    BYTE     ucPaytype;                         /* ��������
                                                   1���ֽ�
                                                   2: 13.56M CPU��
                                                   3��2.4G RFSIM��
                                                   51��BUS˾��ǩ��;
                                                   50��BUS˾��ǩ��
                                                   52: BUS�˲�Աǩ��
                                                */
    WORD32   dwTransactionTAC;                  /* ����TAC */
    WORD32   dwBFBalance;                       /* Ǯ�����(����ǰ) */
    WORD32   dwMoney;                           /*  ���׽�� */
    WORD32   dwCutMoney;                        /*  �ۿ��� 
                                                    ���ڳ���POS�����׽��=�۷ѽ��
                                                */
    BYTE     ucPOSDate[LEN_POSDATE + 1];        /* �ն˽���ʱ�� */
    BYTE     ucPOSTime[LEN_POSTIME + 1];        /* �ն˽���ʱ�� */
} T_PosTradeDetail;

// POS�������ͽ�����ϸ
typedef struct
{
    WORD32              dwBatchTradeRecordSeq;                      //���κ�
    BYTE                ucTradeDetailCount;                         //ÿ���Ľ�����ϸ�ĸ��������5��
    BYTE                ucIsOver;                                   //�Ƿ������1��ʾ����, ����û������
    T_PosTradeDetail    atTradeDetail[MAX_BATCH_TRADEDETAIL_COUNT]; //
    BYTE                ucXOR ;                                     /* XORУ��ֵ��������Ϣͷ*/
    BYTE                ucMessageMAC[LEN_MSGMAC];                   /* ��Ϣ��MAC */
}T_PosBatchTradeReporting;

// POS����������Ӧ
typedef struct
{
	WORD32  dwResult;                   /* ���ر�־��0-�ɹ���1-ʧ�� */
    WORD32  dwBatchTradeRecordSeq;      // ������������ˮ��
    BYTE    ucXOR;                      /* XORУ��ֵ��������Ϣͷ*/
    BYTE    ucMessageMAC[LEN_MSGMAC];   /* ��Ϣ��MAC */
}T_PosBatchTradeReportingAck, T_BatchTradeReportingAck;

// ƽ̨�ڲ���pos������
typedef struct
{
    T_ZIMPAY_HEAD pf_head;
    T_PosCommMsgHead pos_comhead;
    T_PosBatchTradeReporting pos_batchtradereport;
    T_PosBatchTradeReportingAck pos_batchtradereportack;
}T_PF_POSBATCHTRADEREQPORT_REQ_AND_RES;

// pos����������
typedef struct
{
    WORD32  dwBatchTradeRecordSeq;      //��������ˮ
    BYTE    ucCorpID[LEN_CORPID + 1];       /* �̻��� BCD��
                                        ���ڹ���POS��˵�ǹ�����˾ID
                                        */
    BYTE    ucPOSDate[LEN_POSDATE + 1];     /* �ն˽���ʱ�� BCD*/
    BYTE    ucPOSTime[LEN_POSTIME + 1];     /* �ն˽���ʱ�� BCD*/
    WORD32  dwTotalPayCount;            /* �������ܵĽ��״��� */
    WORD32  dwTotalPayAmount;           /* �������ܵĽ��׽�� */
    BYTE    ucXOR ;                     /* XORУ��ֵ��������Ϣͷ*/
    BYTE    ucMessageMAC[LEN_MSGMAC];   /* ��Ϣ��MAC */
}T_BatchSettlement;

typedef struct
{
    WORD32  dwResult;                   /* ���ر�־��0-�ɹ���1-ʧ�� */
    WORD32  dwBatchTradeRecordSeq;      // �������������κ�
    BYTE    ucXOR ;                     /* XORУ��ֵ��������Ϣͷ*/
    BYTE    ucMessageMAC[LEN_MSGMAC];   /* ��Ϣ��MAC */
}T_BatchSettlementAck, T_BatchSettlementRes;

// ƽ̨��������Ϣ 
typedef struct
{
    T_ZIMPAY_HEAD pf_head;
    T_PosCommMsgHead pos_comhead;
    T_BatchSettlement pos_settlement;
    T_BatchSettlementAck pos_settlementack;
}T_PF_POSSETTLEMENT_REQ_AND_RES;

// ��ֵԤ����
typedef struct 
{
	BYTE    ucCardType;         /* ������ */
    BYTE    idFactory[LEN_FACTORY + 1];         /* ��������ʶ BCD*/
    BYTE    ucAppSequence[LEN_APPSEQ + 1];  /* Ӧ�����к�BCD*/	
    BYTE    ucCountryCode;      /* ʡ���� */
    WORD32  dwBalance;         /* Ǯ����� */
    WORD32  dwAmount;         /* ��ֵ��� */
    BYTE    ucPSAMNO[LEN_PSAMNO + 1];    /* PSAM��Ӧ�����к� BCD */
    BYTE    ucPSAMTerminal[LEN_PSAMTERM + 1]; /* �ն˱�� BCD */
    WORD32  dwPSAMRand;     /* PSAM������������� */
    WORD32  dwBatchTradeRecordSeq; /* ���κ� */
    BYTE    ucPOSSerial[LEN_POSSERIAL + 1];  /* POS��ˮ BCD*/
    BYTE    ucTradeType;      /*  �������� 
                                   01: �ֽ��ֵ
                                   02: ��ȡ����
    */
    BYTE    ucPOSDate[LEN_POSDATE + 1];    /* �ն˽���ʱ�� BCD*/
    BYTE    ucPOSTime[LEN_POSTIME + 1];    /* �ն˽���ʱ�� BCD*/
    BYTE    ucXOR ;           /* XORУ��ֵ��������Ϣͷ*/
    BYTE    ucMessageMAC[LEN_MSGMAC]; /* ��Ϣ��MAC */
} T_PosUpKeyReq;

typedef struct
{
    WORD32  dwResult;           /* ����ֵ */
    BYTE    ucCardType;        /* ������ */
    BYTE    ucAppSequence[LEN_APPSEQ + 1];  /* Ӧ�����к�BCD*/	
    BYTE    ucCountryCode;      /* ʡ���� */
    WORD32  dwBalance;         /* Ǯ����� */
    WORD32  dwAmount;         /* ��ֵ���
                                    �����������Ϊ02/21/22��������ֶ���дȷ�ϵĴ���ȡ�����Ľ��
    */
    BYTE    ucPSAMNO[LEN_PSAMNO + 1];    /* PSAM��Ӧ�����к� BCD */
    BYTE    ucPSAMTerminal[LEN_PSAMTERM + 1]; /* �ն˱�� BCD */
    WORD32  dwBatchTradeRecordSeq; /* ���κ� */
    BYTE    ucPOSSerial[LEN_POSSERIAL + 1];  /* POS��ˮ BCD*/
    BYTE    ucTradeType;      /*  �������� 
                                   01: �ֽ��ֵ
                                   02: ��ȡ����
                                   21: ѧ������
                                   22: M-PAiSA��ֵ
                                   23: ����
    */
    BYTE    ucTopUpKey[LEN_TOPUPKEY + 1];    /*  ��ֵ��Կ�������� */
    BYTE    ucXOR ;           /* XORУ��ֵ��������Ϣͷ*/
    BYTE    ucMessageMAC[LEN_MSGMAC]; /* ��Ϣ��MAC */
} T_PosUpKeyRes;

typedef struct
{
    T_ZIMPAY_HEAD pf_head;
    T_PosCommMsgHead pos_comhead;
    T_PosUpKeyReq pos_upkey_req;
    T_PosUpKeyRes pos_upkey_res;
}T_PF_UPKEY_REQ_AND_RES;

// ��ֵ�����ϴ�
typedef struct
{
	BYTE    ucResultStatus;       /* ��ֵ�Ľ��׽��
                                0���ɹ���
                                1��ʧ�ܣ�
                                2����Ƭ����֤MAC2״̬δ֪
                              */
    BYTE    ucCardType;         /* ������ */
    WORD32  dwBatchTradeRecordSeq; /* ���κ� */
    BYTE    ucPOSSerial[LEN_CHGSERIAL + 1];      /* ��ֵ��ˮ�� BCD*/
    BYTE    idFactory[LEN_FACTORY + 1];         /* ��������ʶ BCD*/
    BYTE    ucAppSequence[LEN_APPSEQ + 1];  /* Ӧ�����к� BCD*/	
    BYTE    ucKeyIndex;        /* ��Կ������ */
    BYTE    ucKeyVersion;      /* ��Կ�汾�� */
    WORD32  dwTransactionTAC;  /* ����TAC */
    WORD32  dwBalance;         /* Ǯ�����(���׺�) */
    WORD16  wOnlineCount;      /* �����������(����ǰ) */
    WORD32  dwMoney;         /*  ���׽�� */
    BYTE    ucTradeType;      /*  �������� 
                                   01: �ֽ��ֵ
                                   02: ��ȡ����
                                   03:������ֵ
                                   04:TOPUP�ع�
    */
    BYTE    ucTerminalNo[LEN_POSSERIAL + 1];  /* �ն˻���� BCD*/
    BYTE    ucPOSDate[LEN_POSDATE + 1];    /* �ն˽���ʱ�� BCD*/
    BYTE    ucPOSTime[LEN_POSTIME + 1];    /* �ն˽���ʱ�� BCD*/
    BYTE    ucXOR ;          /* XORУ��ֵ��������Ϣͷ*/
    BYTE    ucMessageMAC[LEN_MSGMAC]; /* ��Ϣ��MAC */
}T_ChargeOnlineCheck; 

typedef struct
{
	WORD32  dwResult;
    BYTE    ucXOR ;          /* XORУ��ֵ��������Ϣͷ*/
    BYTE    ucMessageMAC[LEN_MSGMAC]; /* ��Ϣ��MAC */
}T_ChargeOnlineDataAck; 

// ƽ̨��ֵ��¼�ϴ���Ϣ
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

//ָ����Ϣ�洢
typedef struct 
{
    BYTE     ucAppSequence[LEN_APPSEQ + 1];   /* cardno, customer��s card no, BCD code*/
    BYTE     ucFingerType;        /*
                                                             Customer��s Finger Flag
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

//ָ����Ϣ�Ļ���
typedef struct 
{
BYTE     ucAppSequence[LEN_APPSEQ + 1];   /* cardno, customer��s card no, BCD code*/
BYTE     ucFingerType;        /*
                               Customer��s Finger Flag to ask
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

// ����������
typedef enum
{
    pagetype_total = 0,
    pagetype_upper_half,
    pagetype_lower_half
}Pagetype;

typedef struct
{
    BYTE        ucBLVersion[LEN_BLVERSION + 1];       /* POS���������汾
                                YYMMDDxxxx
                                ����xxxx��ʾYYMMDD��һ��İ汾�ţ���0001��9999
                              */
    WORD16      wBLPage;            /*
                                ����ĺ�������ҳ��
                              */
    Pagetype    ucPageType;          /*
                                0��ȫҳ
                                1���ϰ�ҳ
                                2���°�ҳ
                              */
    BYTE        ucXOR;           /* XORУ��ֵ��������Ϣͷ*/
    BYTE        ucMessageMAC[LEN_MSGMAC]; /* ��Ϣ��MAC */
} T_GetBlackListQuest;

#define POS_BLACKDATA_PAGE_LEN 512 // �ڲ���Ϣ����asc�뱣��
typedef struct
{
    WORD32      dwResult;             /*  ����ֵ  */
    BYTE        ucBLVersion[LEN_BLVERSION + 1];       /* ϵͳ��������汾
                                YYMMDDxxxx
                                ����xxxx��ʾYYMMDD��һ��İ汾�ţ���0001��9999
                              */
    WORD16      wBLPage;            /*
                                ����ĺ�������ҳ��
                              */
    Pagetype    ucPageType;          /*
                                0��ȫҳ
                                1���ϰ�ҳ
                                2���°�ҳ
                              */
    BYTE        ucBlackListData[POS_BLACKDATA_PAGE_LEN + 1];  /*
                                ����������
                                ���ucPageTypeΪ0������ֶγ���Ϊ256�����򣬳���Ϊ128
                              */
    BYTE        ucXOR;           /* XORУ��ֵ��������Ϣͷ*/
    BYTE        ucMessageMAC[LEN_MSGMAC]; /* ��Ϣ��MAC */
} T_GetBlackListQuestAck;

typedef struct 
{
    T_ZIMPAY_HEAD pf_head;
    T_PosCommMsgHead pos_comhead;
    T_GetBlackListQuest blackupdreq;
    T_GetBlackListQuestAck blackupdack;
}T_POS_UPDBLACK_REQ_AND_RSP;

/******************************** POS �ӿ���� ****************************************/

/******************************** �����������Ϣ���� ****************************************/
// ϵͳҵ����������Ϣ
#define MAX_STATUS_TEXT_LEN 64
typedef struct
{
    ResultId result;    // ϵͳ���������
    INT32 status;       // Э������
    UINT8 statustext[MAX_STATUS_TEXT_LEN + 1]; // �����������
}T_REQ_RESULT;


// pos������ע�Ṥ����Ϣ
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

// pos����Ϣ����
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



// �̻�����
typedef struct
{
    T_ZIMPAY_HEAD pf_head;
    T_MERCHANT_REQ merchantinfo_req;
    T_REQ_RESULT resultinfo;
}T_MERCHANTINFO_REQ;


// �ͻ�ע��
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

// �ͻ�ע��
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

// �ͻ���Ϣ����
typedef struct
{
    T_ZIMPAY_HEAD pf_head;
    T_CUST_REQ custinfo_req;
    T_REQ_RESULT resultinfo;
}T_CUSTINFO_REQ;

// �̻���ֵ
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

// �̻���ֵ
typedef struct
{
    T_ZIMPAY_HEAD pf_head;
    T_MERCHANT_CHARGE_REQ merchant_chg;
    T_REQ_RESULT resultinfo;
}T_MERCHANT_CHG_REQ;

// ����������
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

// ���û���
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

// �Ż� -- ���������
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
//��������
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

// ������
typedef struct
{
    T_ZIMPAY_HEAD pf_head;
    UINT8 appseqno[LEN_APPSEQ + 1];
}T_POS_CARD_LOCK;
/******************************** ��������Ż�������Ϣ���� ****************************************/

/******************************** master����ע�ᣬ��������Ϣ *************************************/
/*ģ��ע��������Ϣ�ṹ*/
typedef struct
{
    UINT8 moduleName[MAX_MODULENAME_LEN];       // ģ����
}MODULEREGREQ;

/*ģ��ע����Ӧ��Ϣ�ṹ*/
typedef struct
{
	UINT8 nResult;	            // 0:�ɹ�;1:ʧ��
	UINT8 szResultDesc[128];	// ʧ��:ʧ��ԭ�򣬳ɹ�:zookeeper serverlist
}MODULEREGRSP;

typedef struct
{
    UINT8 moduleName[MAX_MODULENAME_LEN];       // ����Ϣ��ģ����
}ACTIVETESTREQ;

typedef struct
{
    UINT8 nResult;	            // 0:�ɹ�;1:ʧ��
    UINT8 moduleName[MAX_MODULENAME_LEN];       // ����Ϣ��ģ����
}ACTIVETESTRSP;

// module ������Ϣ
typedef struct
{
    UINT8 modulename[MAX_MODULENAME_LEN];
    UINT8 libname[MAX_LIBNAME_LEN];
    UINT8 verion[MAX_VERSION_LEN];
    UINT8 f_init[MAX_FUNCNAME_LEN];
    UINT8 f_updcfg[MAX_FUNCNAME_LEN];
    UINT8 f_exit[MAX_FUNCNAME_LEN];
}T_MODULE_UPD;

// func ������Ϣ
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

// master��process��module/func������Ϣ
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

/******************************** master����ע�ᣬ��������Ϣ *************************************/


/******************************** �˻�ģ����Ϣ *************************************/
typedef struct
{
	BYTE        accid;        //accid
	BYTE        acctype;      //accid���˻�����
	UINT32      amount;       //���׽��
	AccTradeType acctradetype; //�������ͣ� ��Ǯ���Ǽ�Ǯ
}T_ACCOUNT_TRADE;

typedef struct
{
	UINT8           ucAppSequence[LEN_APPSEQ+1];   //���� ��Ӧ�����к�
	BYTE            ucAppType;             //������ ��Ӧ������
	UINT8           ucPOSId[LEN_POSID+1];      //�̻�pos���к�
	BYTE            ucPOSType;             //postype
	BYTE            postradetype;             //��������: 0-��ֵ; 1-��ֵ���� ; 2-����  ;
    UINT32          amount;                //���׽��
}T_POS_TRADE;

typedef struct
{
	T_POS_TRADE     posinfo;     //pos��Ϣ�����Ϣ
	T_ACCOUNT_TRADE fromaccount; //����accountģ�����Ϣ,ת���˻�
	T_ACCOUNT_TRADE toaccount;   //����accountģ�����Ϣ,ת���˻�
    T_REQ_RESULT    resultinfo;
}T_PE_TRADE;


/******************************** �˻�ģ����Ϣ *************************************/

/*************************************posp***********************************************/
//��ֵ״̬
typedef enum
{   
    reChargeStatusFail = 0,       //Ԥ��ֵʧ�ܺ��״̬
    reChargeStatusSucc = 1,       //Ԥ��ֵ�ɹ����״̬
    afterChargeStatus = 2,    //��ֵ�ɹ��Ժ�״̬
    chargeReversalStatus = 3,  // ��ֵʧ�ܣ������ɹ�״̬
    chargeReversalFailStat = 4, //����ʧ��״̬
    chargeprocfailure = 5       //ƽ̨����ʧ��
}POS_RE_AF_CHARGE_STATUS;

//��ֵ�Ľ��׽��
typedef enum
{
    onChargResultStatussucc = 0, //�ɹ�
    onChargResultStatusfail = 1, //ʧ��
    onChargResultStatusmacfail = 2 //��Ƭ����֤MAC2״̬δ֪
}pos_onCharge_Result_Status;


// posdll �� hsm����Ϣ
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

