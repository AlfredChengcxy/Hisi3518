
#ifndef _CLIENT_H_
#define _CLIENT_H_

#include "BaseType.h"
#include "P2Pproto.h"


#if defined(__cplusplus)
extern "C" {
#endif




/*
    ��Ϣ�ص��������ڴ���P2PЭ������������������Ϣ(���籨����Ϣ)
    
       _pContext----P2PNetClientSdkInit������������һ������  
*/
typedef INT32  (*P2PEVENT_PROCESS)(EVENTTYPE _EventID,void *_pMsg,void *_pContext);



/*
    ��Ϣ�ص��������ڴ���server��(IPC)���͹�������Ϣ
       _pContext----OpenStream������������һ������  
*/
typedef INT32  (*P2PMSG_PROCESS)(PEER_INFO * _pNvs, CHAR *_pMsg,INT32 _nLen,void *_pContext);


/*
   �����ص�����
   _pNvs----ConnectNvs �����ķ���ֵ
   _cBuf----���ݵ�ַ
   _iLen----���ݳ���
   nDataType---�������� �����enum DATA_TYPE_E
   _iFrameType---֡����  ע����ƵΪI֡���� �����enum FRAME_TYPE_E
   _pContext----OpenStream������������һ������  
*/
typedef INT32  (*P2PSTREAM_DATA_PROCESS)(PEER_INFO * _pNvs,CHAR *_cBuf,UINT32 _iLen,INT16 nDataType,INT16 _iFrameType,void *_pContext);



#if 0

/*
    �û�ע�ắ��
    ����:
  cUser-----------�û���
   cPassWd----����
   _sPort----��ʹ�õı��ض˿�
   cServer----P2PЭ����������ַ����ΪIP��������
   ����ֵ:  0---�ɹ�   ��0---ʧ��
*/
DLL_DECLARE INT32 P2PNetClientUserRegister(CHAR * cUser,CHAR * cPassWd,CHAR * cServer);
/*
    �û���½����
  cUser-----------�û���
   cPassWd----����
   _sPort----��ʹ�õı��ض˿�
   cServer----P2PЭ����������ַ����ΪIP��������
*/
DLL_DECLARE INT32 P2PNetClientUserLogon(CHAR * cUser,CHAR * cPassWd,CHAR * cServer);
DLL_DECLARE INT32 P2PNetClientAddDev(CHAR * cDevID,CHAR * cDevName,CHAR * cUserName,CHAR * cUserPassWd,INT32 iChannelNum);

DLL_DECLARE INT32 P2PNetClientModyDev(CHAR * cDevID,CHAR * cDevName,CHAR * cUserName,CHAR * cUserPassWd,INT32 iChannelNum);

DLL_DECLARE INT32 P2PNetClientDelDev(CHAR * cDevID);

DLL_DECLARE INT32 P2PNetClientShareDev(CHAR * cDevID,CHAR *cUser);

DLL_DECLARE INT32 P2PNetClientCancelShareDev(CHAR * cDevID,CHAR *cUser);

DLL_DECLARE INT32 P2PNetClientUserGetDevList(Dev_Infor *pDev,INT32 *iNum);


#endif



/*
   SDK��ʼ������
    cID-----------�ͻ���ID����ʹ��P2PNetClientUserRegisterע����û���
   _iNvsNum----ͬ��֧�ֵ����IPC��DVR������
   _sPort----��ʹ�õı��ض˿�
   cServer----P2PЭ����������ַ����ΪIP��������
   P2PServerCallBack---��Ϣ�ص����� ͳһ���ܱ�������Ϣ
   _pContext--------P2PServerCallBack�ص���ȥ�����һ������
*/
#ifdef _WIN32
DLL_DECLARE INT32 P2PNetClientSdkInit(CHAR * cID,INT32 _iNvsNum,UINT16 _sPort,CHAR * cServer,P2PEVENT_PROCESS P2PServerCallBack,void *_pContext);
#else
DLL_DECLARE INT32 P2PNetClientSdkInit(CHAR * cID,INT32 _iNvsNum,UINT16 _sPort,CHAR * cServer,UINT32 u32Key,P2PEVENT_PROCESS P2PServerCallBack,void *_pContext);
#endif
/*
   ��ȡSDK״̬
   ����ֵ1----ע�ᵽЭ��������
                   ���� ------ע��ʧ��
*/
DLL_DECLARE INT32 P2PNetClientGetSdkState(void);



DLL_DECLARE INT32 P2PNetClientSetSdkKey(UINT32 u32Key);



/*
    ��ȡ
    cDevID-----------��Ҫ��ȡ�ĵ�����Ϣ���豸ID
   iStartTime----��ʼʱ��
   iEndTime----����ʱ��
   pDevElec----�������������ַ
   iNum---��������ȡ����  ������ȡ���ĸ���
*/
DLL_DECLARE INT32 P2PNetClientUserGetDevElectricity(CHAR * cDevID,INT32 iStartTime,INT32 iEndTime,Dev_Electricity *pDevElec,INT32 *iNum);


/*
   ��ȡ��ǰ������Ϣ
   peer_infor-----��BaseType.h
*/
DLL_DECLARE INT32 P2PNetClientGetPeerInfor(peer_infor *pInfor);


/*
   ����IPC����DVR   NVR
   ����:
   cNvsId----IPC���豸ID��
   _iConnectMod----������ģʽ0----�Զ�  1---��ת
   _iIsReconnect----�Ƿ���Ҫ���� 0--������   1---SDK�Զ�����

   ����ֵ:
   NULL-----ʧ��
   ����---�ɹ�IPC��Ψһ��ʾ
   
   �˺������е�ʱ����ݶԷ��Ƿ����P2P ����ͬ���10S
*/
DLL_DECLARE PEER_INFO * P2PNetClientConnectNvs(CHAR * cNvsId,INT32 _iConnectMod,INT32 _iIsReconnect);


/*
   ��¼IPC����DVR   NVR
   ����:
   _pNvs----ConnectNvs�ķ���ֵ
   _pUserName----IPC���û���
   _pUserPasswd----IPC������
   iTimeOut----��ʱʱ�����
    ����ֵ
    0---�ɹ�
    ��0----ʧ��
*/
DLL_DECLARE INT32 P2PNetClientLoginNvs(PEER_INFO * _pNvs,CHAR * _pUserName,CHAR * _pUserPasswd,INT32 iTimeOut,P2PMSG_PROCESS _MsgDataCallBack,void *_pContext);

/*
   ��������Ƶ���˺������Բ��õ��ùر������Ľӿ��ظ����������޸���������
   ����:
   _pNvs----ConnectNvs�ķ���ֵ
   _nChannel----���ӵ�ͨ����
   _nStream----���ӵ���������  0--������ 1--������
   _nSreamType----��������������1---��Ƶ 2---��Ƶ  3---����Ƶ�ο�STREAM_TYPE_T   
   _StreamDataCallBack----�����ص�����
   _pContext-----�����ص�ʱʹ��
   ����ֵ:
    0---�ɹ�
    ��0----ʧ��
*/
DLL_DECLARE INT32 P2PNetClientOpenStream(PEER_INFO * _pNvs,INT32 _nChannel,INT32 _nStream,INT32 _nSreamType,P2PSTREAM_DATA_PROCESS _StreamDataCallBack,void * _pContext);

/*
   ��ȡ����Ƶ��
   ��������ûص�������ȡ����Ƶ����,�ڵ���OpenStream�����ɹ���
   ����ʹ�ñ�������ȡ����Ƶ����
   ����������֤��һ�ε��õ�ʱ���ȡ����I֡
   ����:
   _pNvs----ConnectNvs�ķ���ֵ
   _nChannel----���ӵ�ͨ����
   _nStream----���ӵ���������  0--������ 1--������
   pData-------����Ƶ����BUF  �ɵ���������Ҫ�㹻��
   pLen--------����Ƶ���ݵĳ���
   pDataType-----��������  ��Ƶ������Ƶ����ο�ö��DATA_TYPE_T
   pFrameType -----֡���;���ο�ö��FRAME_TYPE_T
    _bBlock   -----1����  0---������  
   ����ֵ:
    0---�ɹ�
    ��0----ʧ��С��0˵�������Ѿ��ر�
*/

DLL_DECLARE INT32 P2PNetClientGetStreamData(PEER_INFO * _pNvs,INT32 _nChannel,INT32 _nStream,char * pData,INT32 *pLen,INT32 * pDataType,INT32 *pFrameType,INT32 _bBlock);


/*
   �޸�ǰ�˵�¼����
   ����:
   _pNvs----ConnectNvs�ķ���ֵ
  _pOldPasswd--- �������15�ֽ�
   _pNewPasswd----�������15�ֽ�         
   ����ֵ:
    0---�ɹ�
    ��0----ʧ��
*/
DLL_DECLARE INT32 P2PNetClientChangePasswd(PEER_INFO * _pNvs,CHAR * _pOldPasswd,CHAR * _pNewPasswd);


/*
   ��ȡ��ⷢ��ϵͳ�Ĳ���
   ����:
   _pNvs----ConnectNvs�ķ���ֵ
   pDevElecState ---��ⷢ��ϵͳ״̬  ��Ҫ�ϲ����ռ�
    ��0----ʧ��
*/
DLL_DECLARE INT32 P2PNetClientGetElecState(PEER_INFO * _pNvs,Dev_ElecState *pDevElecState);



/*
   ����ǰ�˹ؿ�����ⷢ����Ŀ��
   ����:
   _pNvs----ConnectNvs�ķ���ֵ
   _iCmd----������1--����  0--�ػ� 2--���ö�ʱ���ػ�
   _u64StartTime----��ʱ����ʱ��
                            ��CUT��Coordinated Universal Time��ʱ��1970��1��1��00:00:00����ΪUNIXϵͳ��Epochʱ�䣩����ǰʱ�̵�����
   _u64StopTime----��ʱ�ػ�ʱ��
                            ��CUT��Coordinated Universal Time��ʱ��1970��1��1��00:00:00����ΪUNIXϵͳ��Epochʱ�䣩����ǰʱ�̵�����
   ����ֵ:
    0---�ɹ�
    ��0----ʧ��
*/
DLL_DECLARE INT32 P2PNetClientControlDev(PEER_INFO * _pNvs,INT32 _iCmd,UINT64 _u64StartTime,UINT64  _u64StopTime);




DLL_DECLARE INT32 P2PNetClientGetDevElectricity(PEER_INFO * _pNvs,Dev_Electricity *pDevElec);



/*
   �Ͽ�����Ƶ��
   ����:
   _pNvs----ConnectNvs�ķ���ֵ
   _nChannel----���ӵ�ͨ����
   _nStream----���ӵ���������  0--������ 1--������
   ����ֵ:
    0---�ɹ�
    ��0----ʧ��
*/
DLL_DECLARE INT32 P2PNetClientCloseStream(PEER_INFO * _pNvs,INT32 _nChannel,INT32 _nStream);

/*
   �ǳ�IPC
   ����:
   _pNvs----ConnectNvs�ķ���ֵ
   ����ֵ:
    0---�ɹ�
    ��0----ʧ��
*/
DLL_DECLARE INT32 P2PNetClientLogoutNvs(PEER_INFO * _pNvs);

/*
  �Ͽ���IPC������
   ����:
   _pNvs----ConnectNvs�ķ���ֵ
   ����ֵ:
    0---�ɹ�
    ��0----ʧ��
*/
DLL_DECLARE INT32 P2PNetClientDisconnectNvs(PEER_INFO * _pNvs);

/*
  ��ȡ��IPC������
   ����:
   _pNvs----ConnectNvs�ķ���ֵ
   ����ֵ:
    0---��¼�ɹ�
    ��0----���������ӻ��ߵ�¼ʧ��
*/

DLL_DECLARE INT32 P2PNetClientGetNvsState(PEER_INFO * _pNvs);


/*
  ������Ƶ���� ����ɫ�ȶԱȶ�
   ����:
   _pNvs----ConnectNvs�ķ���ֵ
   _nChannel----ͨ����
   _pVideoPara---��Ҫ���õ�ֵ ���忴�ýṹ��(�ڴ� Ӧ�ò����)
   
   ����ֵ:
    0---�ɹ�
    ��0----ʧ��
*/
DLL_DECLARE INT32 P2PNetClientSetVideoPara(PEER_INFO * _pNvs,INT32 _nChannel,VideoPara *_pVideoPara);

/*
  ������Ƶͨ������
   ����:
   _pNvs----ConnectNvs�ķ���ֵ
   _nChannel----ͨ����
   _nStream  ----��������  0--������  1--������
   _pVideo---��Ҫ���õ�ֵ ���忴�ýṹ��(�ڴ� Ӧ�ò����)
   
   ����ֵ:
    0---�ɹ�
    ��0----ʧ��
*/
DLL_DECLARE INT32 P2PNetClientSetChannelInfo(PEER_INFO * _pNvs,INT32 _nChannel,INT32 _nStream,ChannelIfor * _pVideo);

/*
   �ƾ�����
   ����:
   _pNvs----ConnectNvs�ķ���ֵ
   _nChannel----ͨ����
   _pPtz---��Ҫ���õ�ֵ ���忴�ýṹ��(�ڴ� Ӧ�ò����)
   
   ����ֵ:
    0---�ɹ�
    ��0----ʧ��
*/
DLL_DECLARE INT32 P2PNetClientPtzControl(PEER_INFO * _pNvs,INT32 _nChannel,PtzControlReq * _pPtz);

/*
   ��ȡ�豸����
   ����:
   _pNvs----ConnectNvs�ķ���ֵ
   pCapabilities---���忴�ýṹ��(�ڴ� Ӧ�ò����)
   
   ����ֵ:
    0---�ɹ�
    ��0----ʧ��
*/
DLL_DECLARE INT32 P2PNetClientGetNvsCapabilities(PEER_INFO * _pNvs,DevCapabilities * pCapabilities);

/*
   ��ȡͨ����Ƶ����
   ����:
   _pNvs----ConnectNvs�ķ���ֵ   
   _nChannel----ͨ����
   _pVideoPara---���忴�ýṹ��(�ڴ� Ӧ�ò����)
   
   ����ֵ:
    0---�ɹ�
    ��0----ʧ��
*/
DLL_DECLARE INT32 P2PNetClientGetVideoPara(PEER_INFO * _pNvs,INT32 _nChannel,VideoPara *_pVideoPara);

/*
   ��ȡͨ����Ƶ�������
   ����:
   _pNvs----ConnectNvs�ķ���ֵ   
   _nChannel----ͨ����
   _nStream  ----��������  0--������  1--������
   _pVideoPara---���忴�ýṹ��(�ڴ� Ӧ�ò����)
   
   ����ֵ:
    0---�ɹ�
    ��0----ʧ��
*/
DLL_DECLARE INT32 P2PNetClientGetChannelInfo(PEER_INFO * _pNvs,INT32 _nChannel,INT32 _nStream,ChannelIfor * _pInfor);

/*
   ������ǰ�˶Խ�
   ����:
   _pNvs----ConnectNvs�ķ���ֵ   
   _pTalk----���ڻ�ȡǰ��֧�ֵ���Ƶ�����ɵ����߷����ڴ�   
   ����ֵ:
    0---�ɹ�
    ��0----ʧ��
*/
DLL_DECLARE INT32 P2PNetClientTalkReq(PEER_INFO * _pNvs,P2pTalkMsg * _pTalk);




/*
   �ر���ǰ�˶Խ�
   ����:
   _pNvs----ConnectNvs�ķ���ֵ   
    ����ֵ:
    0---�ɹ�
    ��0----ʧ��
*/
DLL_DECLARE INT32 P2PNetClientTalkClose(PEER_INFO * _pNvs);


/*
   ��IPC�˷���͸��ͨ����ϢIPC�˻����ݻص��������յ���Ϣ
   ����:
   _pNvs----ConnectNvs�ķ���ֵ   
   cBuf----��Ϣ����
   nLen  ----��Ϣ����
   ����ֵ:
    0---�ɹ�
    ��0----ʧ��
*/
DLL_DECLARE void P2PNetClientSndMsgToServer(PEER_INFO * _pNvs,CHAR * cBuf, INT32 nLen);


/*
   ��IPC�˷��ͶԽ���Ƶ����
   ����:
   _pNvs----ConnectNvs�ķ���ֵ   
   cBuf----��Ƶ��������
   nLen  ----��Ƶ���ݳ���
   ����ֵ:
    0---�ɹ�
    ��0----ʧ��
*/
DLL_DECLARE void P2PNetClientSndTalkDataToServer(PEER_INFO * _pNvs,CHAR * cBuf, INT32 nLen);


DLL_DECLARE INT32 P2PNetClientGetFile(PEER_INFO * _pNvs,CHAR *pSrcFileName,CHAR *pDstFileName,INT32 iOutTime);


DLL_DECLARE INT32 P2PNetClientSdkUnInit(void);


#if defined(__cplusplus)
}
#endif


#endif


