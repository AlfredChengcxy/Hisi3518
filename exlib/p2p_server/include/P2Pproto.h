#ifndef _PROTO_H_
#define _PROTO_H_

#include "BaseType.h"

#define PEER_INFO void 

#define HEART_TIME_OUT 30

#define MAX_CHANNNEL_NUM 4

#define MAX_STREAM_NUM 2

#define MAX_USERNAME 15
#define MAX_PASSWORD 15
#define STREAM_FRAM_ID 0x00000002
#define  DATAPACKHEAD  0xF9EAF5F1    //���ݰ���ͷ ���4λΪ�汾��
#define  CMDPACKHEAD   0xF5EAF5F1    //�������ͷ


#define  MAX_FRAME_SIZE  (512*1024)
#define  MAX_AUDIO_SIZE  (4*1024)
#define  MAX_TALK_SIZE  (4*1024)
#define  MAX_CMD_SIZE  (64*1024)


typedef enum _EVENTTYPE
{
	EVENT_ALARM,    //����
	EVENT_DATA      //����
}EVENTTYPE;


//��������
typedef enum
{
  ALARM_VIDEO_LOST = 100,  
  ALARM_VIDEO_MOTION,  
  ALARM_VIDEO_OCCLUSION,  
  ALARM_PORT_IN,  
}ALARM_TYPE;




typedef struct 
{
    INT32 m_iDataType; 
    INT32 m_iFrameType; 
    INT32 m_iFrameSize; 
}FramePack;

//��Ƶ��������ö��
typedef enum STREAM_TYPE_E
{
    STREAM_VIDEO = 1,     
    STREAM_AUDIO,   
    STREAM_VIDEOAUDIO,       
    STREAM_BUTT
} STREAM_TYPE_T;

//��Ƶ��������ö��
typedef enum VIDEO_ENCTYPE_E
{
    VIDEO_H264 = 1,     //h.264
    VIDEO_MPEG,         //mpeg
    VIDEO_BUTT
} VIDEO_ENCTYPE_T;

//��Ƶ��������ö��ADPCM_A :0x03;G726:0x04  PCM 0x05
typedef enum AUDIO_ENCTYPE_E
{
    AUDIO_G711A = 1,     //G711A
    AUDIO_G711U,         //G711U    
    AUDIO_ADPCMA,    
    AUDIO_G726,
    AUDIO_PCM,
    AUDIO_BUIT
} AUDIO_ENCTYPE_T;



typedef enum DATA_TYPE_E
{
    DATA_VIDEO = 0,   
    DATA_AUDIO,   
    DATA_TALK,         
    DATA_BUTT
} DATA_TYPE_T;


typedef enum FRAME_TYPE_E
{
    FRAME_I = 0,   
    FRAME_P,      
    FRAME_BUTT
} FRAME_TYPE_T;


typedef enum{
	PTZ_TU_P2P = 1, //��
	PTZ_TD_P2P,		//��
	PTZ_PL_P2P,		//��
	PTZ_PR_P2P,		//��
	PTZ_TUPR_P2P,	//����
	PTZ_TUPL_P2P,	//�� ��
	PTZ_TDPR_P2P,	//����
	PTZ_TDPL_P2P,	//����
	PTZ_STOP_P2P,	//ֹͣ
	PTZ_ZIN_P2P,	// ��������
	PTZ_ZOUT_P2P,	//������Զ
	PTZ_IST_P2P,	//�仯ֹͣ
	PTZ_FN_P2P,		//�������
	PTZ_FR_P2P,		//�����Զ
	PTZ_FST_P2P,	//����仯ֹͣ
	PTZ_IA_ON_P2P,	//��Ȧ�Զ�����
	PTZ_IO_P2P,		//��Ȧ����
	PTZ_IC_P2P,		//��Ȧ��С
	PTZ_WP_ON_P2P,//��������
	PTZ_WP_OFF_P2P,//����ֹͣ
	PTZ_LP_ON_P2P,	//�ƹ⿪��
	PTZ_LP_OFF_P2P,//�ƹ�ֹͣ
	PTZ_AUTO_START_P2P,//Ѳ����ʼ
	PTZ_AUTO_STOP_P2P,//Ѳ��ֹͣ
	PTZ_GOTO_PRESET_P2P,//ת��Ԥ���
	PTZ_START_TRACK_CRUISE_P2P,//��ʼ�켣Ѳ��
	PTZ_STOP_TRACK_CRUISE_P2P,//ֹͣ�켣Ѳ��
	PTZ_SET_PRESET_P2P,
	PTZ_POWER_ON_P2P,	        //��Դ����
	PTZ_POWER_OFF_P2P,          //��Դ�ر�
	PTZ_3D_POSITION_P2P,		//PTZ 3D��λ
	PTZ_3D_ROCKER_P2P,			//��3άҡ�˵���Ӧ
	PTZ_ASSISTANT_ON_P2P,		//�������ؿ�
	PTZ_ASSISTANT_OFF_P2P,		//�������ع�
	PTZ_RM_PRESET_P2P,         //ɾ��Ԥ�õ�
}ENUM_PTZ;


#if defined(_MSC_VER) // Microsoft compiler
#define __attribute__(x)
#elif defined(__GNUC__) // GNU compiler
#else
#endif

#if defined(_MSC_VER)
#pragma pack(1)
#endif

typedef struct
{
	UINT32	  m_ui32Head;		//���ݰ���ͷ
	UINT16    m_ui16Channel;    //ͨ����
    UINT16    m_ui16Stream;     //��������
	UINT16    m_ui16Size;       //���ݳ���
	UINT16    m_u16Type;        //����  �Խ���������Ƶ��
	UINT16    m_u16Postion;     //λ��1----��ʼ  2----����  
	UINT16    m_u16FrameType;   //֡����  
	UINT32    m_u32FrameID;     //֡ID
	UINT32    m_u32TotalLen;     //֡�ܳ���
	UINT32    m_u32Pad[4];     //��չ  0�ֽ�Ϊ1��ʾ¼��ط�����
}__attribute__ ((packed))DATAHEADP2P,*PDATAHEADP2P;

//�������ͷ
typedef struct
{
	INT32    m_ui32Head;			//�������ͷ
	INT32    m_iMsgType;
	UINT16    m_u16Postion;         //λ��1----��ʼ  2----����  
	UINT16    m_ui16Size;     
	UINT32    m_u32TotalLen;     //�����ܳ���
	UINT32    m_u32Pad[4];     //��չ
}__attribute__ ((packed))HEADP2P,*PHEADP2P;

//�������ͷ
typedef struct
{
	INT32     m_iMsgType; 
	UINT32    m_u32TotalLen;     //�����ܳ���
	UINT32    m_u32Pad[4];     //��չ
}__attribute__ ((packed))CMDHEADP2P,*PCMDHEADP2P;

typedef struct
{	
    INT16 m_iChannel;	
	INT16 m_iStream;
	INT16 m_iAlarmNum;
	INT16 m_iPad;
}__attribute__ ((packed))DevCapabilities;

typedef struct 
{ 
	INT32 Width;   //��Ƶ���
	INT32 Height;  //��Ƶ�߶�
	INT32 BitRat;   //��Ƶ����
	INT32 FrameRate; //��Ƶ֡��
	INT32 IFrameRate;//��ƵI֡֡��
	INT32 Quity;    //��Ƶ����
	INT32 VideoType;//��ƵƵ��������1---H264 
	INT32 AudioType;//��Ƶ��������G711_A:0x01; G711_U:0x02;ADPCM_A :0x03;G726:0x04  PCM 0x05
}__attribute__ ((packed))ChannelIfor;

typedef struct 
{       
	INT32 Brightness;                       
	INT32 Contrast;                         
	INT32 Saturation;                       
	INT32 Hue;                              
}__attribute__ ((packed))VideoPara;


//�û���¼
#define REQ_LOGIN 1
typedef struct 
{
	CHAR szUserName[MAX_USERNAME]; //�û���
	CHAR szPassword[MAX_PASSWORD]; //����
}__attribute__ ((packed))LogInReq;


//�û���¼
#define REQ_LOGIN2 1000
typedef struct 
{
	CHAR szUserName[MAX_USERNAME+1]; //�û���
	CHAR szPassword[MAX_PASSWORD+1]; //����
}__attribute__ ((packed))LogInReq2;

typedef struct 								//�û���¼��Ӧ
{
	INT32 m_iLogInRes;							//������
    DevCapabilities m_Capabilities;
    ChannelIfor  m_ChannelIfor[MAX_CHANNNEL_NUM][MAX_STREAM_NUM];
    VideoPara m_VideoPara[MAX_CHANNNEL_NUM];
} __attribute__ ((packed))LogInRsp;

//�û��ǳ�
#define REQ_LOGOUT 0x02
typedef struct 								    //�û���¼��Ӧ
{
	INT32 m_iLogOutRs;							//������
} __attribute__ ((packed))LogOutRsp;


//��ȡĳͨ����Ƶ����
#define REQ_GETCHANNELINFOR 0x03

typedef struct 
{
	UINT16 nChannelId;   //ͨ����0----
	UINT16 nStreamId;    //������0--�� 1--��           
}__attribute__ ((packed))GetChannelIforReq;

typedef struct 
{
	INT16 nChannelId;   //ͨ����0----
	INT16 nStreamId;    //������0--�� 1--��        
    ChannelIfor mChannelIfor;
}__attribute__ ((packed))GetChannelIforRsp;


//����ĳͨ����Ƶ����
#define REQ_SETCHANNELINFOR 0x04
typedef struct 
{
	INT16 nChannelId;   //ͨ����0----
	INT16 nStreamId;    //������0--�� 1--�� 
    ChannelIfor mChannelIfor;
}__attribute__ ((packed))SetChannelIforReq;

typedef struct 
{
	INT32 m_iSetRs;							//������
}__attribute__ ((packed))SetChannelIforRsp;

//��Ƶ���� ���ȶԱȶ�?
#define REQ_GETVIDEOPARA 0x05

typedef struct 
{
	INT16 nChannelId;   //ͨ����0----
	INT16 nStreamId;    //������0--�� 1--��           
}__attribute__ ((packed))GetVideoParaReq;

typedef struct 
{
	INT16 nChannelId;   //ͨ����0----
	INT16 nStreamId;    //������0--�� 1--��          
    VideoPara mVideoPara;                            
}__attribute__ ((packed))GetVideoParaRsp;


#define REQ_SETVIDEOPARA 0x06
typedef struct 
{
	INT16 nChannelId;   //ͨ����0----
	INT16 nStreamId;    //������0--�� 1--��    
    VideoPara mVideoPara;                                        
}__attribute__ ((packed))SetVideoParaReq;

//��������
#define REQ_PLAYSTREAM 0x07
typedef struct 
{
	INT16 nChannelId;   //ͨ����0----
	INT16 nStreamId;    //������0--�� 1--��     
	INT16 nStreamType;    //     
	INT16 nPad;    //               
}__attribute__ ((packed))PlayStreamReq;

typedef struct 
{
	INT32 m_iSetRs;							//������
}__attribute__ ((packed))PlayStreamRsp;

#define REQ_SHUTDOWNSTREAM 0x08
typedef struct 
{
	INT16 nChannelId;   //ͨ����0----
	INT16 nStreamId;    //������0--�� 1--��           
}__attribute__ ((packed))ShutDownStreamReq;

typedef struct 
{
	INT32 m_iSetRs;							//������
}__attribute__ ((packed))ShutDownStreamRsp;


//PTZ����
#define REQ_PTZCONTRIL 0x09
typedef struct 
{
    INT32 iAction;  //�����ENUM_PTZ
	INT32 iData;    //��������������������Ԥ�õ������  ��ʾԤ�õ�
	INT32 iSpeedX;  //�����ٶ�
	INT32 iSpeedY;  //�����ٶ�
	INT32 iCount;   //��ʱû��
	CHAR DecBuf[32];//��ʱû��
}PtzData;

typedef struct 
{
	INT16 nChannelId;			   //����ͨ��
	PtzData mPtzData;
}__attribute__ ((packed))PtzControlReq;


#define REQ_ACTIVE    0x0a   //����

#define MSG_TRANS 0x0B

#define REQ_TALK 0x0C

#define REQ_TALKCLOSE 0x0D

typedef struct 
{
	INT16 nAudioTYpe;  //��Ƶ��������G711_A:0x01; G711_U:0x02;ADPCM_A :0x03;G726:0x04  PCM 0x05
	INT16 nAudioSample; //������
	INT16 nAudioBit; //����λ��	
	INT16 nAudioChannel; //������
}__attribute__ ((packed))P2pTalkMsg;




#define REQ_GETRECORDLIST 0x10  //��ȡ¼���ļ��б�

typedef struct _P2PRecordFile_Sql
{
    INT32 m_iStartTime;
    INT32 m_iEndTime;
    INT32 m_iType;
}__attribute__ ((packed))P2PRecordFile_Sql;


typedef struct _P2PRecordFile_Infor
{
    INT32 m_iStartTime;
    INT32 m_iEndTime;
    INT32 m_iType;
}__attribute__ ((packed))P2PRecordFile_Infor;







typedef struct 
{
    CHAR m_cID[MAX_ID_LEN + 1];	  //�ڵ�ID
    INT32 m_iTime;               //����ʱ��
    INT32 m_iChannel;               //����ʱ��
    INT32 m_iAlarmType;          //��������
    CHAR m_cTmp[32];               //Ԥ��
}__attribute__ ((packed))PeerAlarm_Msg;











typedef struct
{
    CHAR m_cID[MAX_ID_LEN + 1];	//Ҫ�����Ľڵ�ID ����Ϊ��    
	int m_iChanNum;
}__attribute__ ((packed))PeerLook;















typedef struct _User_Infor
{
    CHAR m_cUser[MAX_ID_LEN + 1];
    CHAR m_cPassWord[MAX_ID_LEN + 1];
    INT32 m_iRole;
}__attribute__ ((packed))User_Infor;

typedef struct _Dev_Infor
{
    CHAR m_cDevID[MAX_ID_LEN + 1];
    CHAR m_cDevName[MAX_DEVNAME_LEN + 1];
    CHAR m_cUser[MAX_ID_LEN + 1];
    CHAR m_cPassWord[MAX_ID_LEN + 1];
    INT32 m_iChannelNum;
}__attribute__ ((packed))Dev_Infor;


typedef struct _DevElec_Sql
{
    CHAR m_cDevID[MAX_ID_LEN + 1];
    INT32 m_iStartTime;
    INT32 m_iEndTime;
}__attribute__ ((packed))DevElec_Sql;


#define REQ_GETELEC 0x70
typedef struct _Dev_Electricity
{
    CHAR m_cDevID[MAX_ID_LEN + 1];
    INT32 m_iTime;
    INT32 m_iWindBV;            //���ܵ�ص�ѹ:0.0V~62.0V������Ϊ0.1V
    INT32 m_iWindBI;            //��س�������0.0~60.0A  ����Ϊ0.1A
    INT32 m_iWindBW;            //�����繦�ʣ�0.1~2000.0W  ����Ϊ0.1W
    INT32 m_iWindRPM;           //���ת�٣�0~2000 RPM   ����Ϊ 1 RPM
    INT32 m_iWindE;             //����ۻ���������0~999.9 KWH���ȣ� ����Ϊ0.1KWH
    INT32 m_iLightV;            //��� ��������ѹ��0.0V~100.0V  ����Ϊ0.1V
    INT32 m_iLightI;            //������������0.0V~40.0A  ����Ϊ0.1A    
    INT32 m_iLightBV;           //��ص�ѹ:0.0V~62.0V������Ϊ0.1V
    INT32 m_iLightBI;           //��س�������0.0~60.0A  ����Ϊ0.1A
    INT32 m_iLightBW;           //�����繦�ʣ�0.1~2000.0W  ����Ϊ0.1W
    INT32 m_iLightE;            //����ۻ���������0~6553.5 KWH  ����Ϊ0.1KWH    (Ԥ��)
    INT32 m_iDCBV;              //��ص�ѹ��0.0V~50.0V������Ϊ0.1V
    INT32 m_iDCV;               //�����ѹ��0.0V~300.0V 
    INT32 m_iDCI;               //���������0.0A~30.0A��
    INT32 m_iDCW;               //������ʣ�0W~3000W
    INT32 m_iDCBQ;              //��ص�����0%~100%
    INT32 m_iDevStat;           //�豸����״̬0---����  ����---�쳣(������)
    INT32 m_iDevPowerStat;       //���ػ�״̬1--����  0--�ػ�
    UINT64 m_u64StartTime; //�Զ�����ʱ��
    UINT64 m_u64StopTime; //�Զ��ػ�ʱ��
    
}__attribute__ ((packed))Dev_Electricity;


#define REQ_DEVPOWCONTORL 0x71
typedef struct _Dev_CONTORL
{
    INT32 m_iDevContorl;    //1--����0---�ػ� 2---�Զ����ػ�����
    UINT64 m_u64StartTime; //�Զ�����ʱ��
    UINT64 m_u64StopTime; //�Զ��ػ�ʱ��   
    INT32 m_iState;
}__attribute__ ((packed))Dev_CONTORL;


#define REQ_CHANGPASSWD 0x72
typedef struct _Dev_CHPASSWD
{
    CHAR m_cPasswdOld[MAX_ID_LEN + 1];
    CHAR m_cPasswdNew[MAX_ID_LEN + 1];
    INT32 m_iState;
}__attribute__ ((packed))Dev_CHPASSWD;


#define REQ_FILE 0x73
#define RSP_FILE 0x74

typedef struct _File_Infor
{
    CHAR  m_cFileName[MAX_FILENAME_LEN + 1];
    CHAR  m_cPad[4];
    INT32 m_iSsrc;
    INT32 m_iFlag; 
    INT32 m_iPackLen; 
    void *m_pData;
}__attribute__ ((packed))File_Infor;


typedef struct _Dev_ElecState
{   
    INT32 m_iDCBQ;              //��ص�����0%~100%
    INT32 m_iDevStat;           //�豸����״̬0---����  ����---�쳣(������)
    INT32 m_iDevPowerStat;       //���ػ�״̬1--����  0--�ػ�
    UINT64 m_u64StartTime; //�Զ�����ʱ��0---��ʾδ����
    UINT64 m_u64StopTime; //�Զ��ػ�ʱ��  0----��ʾδ����
    INT32 m_iPad;
}__attribute__ ((packed))Dev_ElecState;



#if defined(_MSC_VER)
#pragma pack()
#endif



typedef INT32  (*PEERNVSSERCH_PROCESS)(void * _pData,PeerLook * _pNvs);





#endif



