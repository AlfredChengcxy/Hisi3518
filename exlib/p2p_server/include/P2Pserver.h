
#ifndef _SERVER_H_
#define _SERVER_H_

#include "BaseType.h"
#include "P2Pproto.h"

#if defined(__cplusplus)
extern "C" {
#endif



/*
�յ��ͻ������ݺ�Ļص�����
*/
typedef INT32 (*P2PNET_READ_CALLBACKEX)(PEER_INFO* pPeerInfo, CHAR* Data, INT32 length);

/*
   SDK��ʼ������
   cID----�豸ID
   _sPort----��ʹ�õı��ض˿�
   cServer----P2PЭ����������ַ����ΪIP��������
   _NetReadCallBack---�յ��ͻ������ݺ�Ļص�����
   nMainSteamBuf-----�����������С ��λ��K
   nSubSteamBuf-----�����������С ��λ��K
   
*/
DLL_DECLARE INT32 P2PNetServerSdkInit(CHAR * cID,INT16 sPort,CHAR *cServer,UINT32 u32Key,P2PNET_READ_CALLBACKEX _NetReadCallBack,UINT16 nMainSteamBuf,UINT16 nSubSteamBuf);

DLL_DECLARE INT32 P2PNetServerSetSdkKey(UINT32 u32Key);
/*
     ��һ���ͻ���   ��������
     cBuf------�����ַ
     nLen------�����
     _reply-----�Ƿ���Ҫ�ɿ�����0--����Ҫ  1---�ɿ�����

*/
DLL_DECLARE INT32 P2PNetServerSndCmd2Link(void * _pLink,CHAR * cBuf,UINT32 nLen);

/*
     �������������(sdk���Զ��ַ�����Ҫ�Ŀͻ���)?
     nChannel------ͨ���Ŵ�0��ʼ
     nStream------��������0--��  1--��
     cBuf-----���ݵ�ַ
     nLen---���ݳ���
     cFrameType---֡���;��嶨�����enum FRAME_TYPE_E  ��ƵһֱδI֡ 
     cDataType----�������� ���嶨�����enum DATA_TYPE_E 
*/
DLL_DECLARE void  P2PNetServerChannelDataSndToLink(INT32 nChannel,INT32 nStream,CHAR * cBuf, INT32 nLen,INT16 cFrameType,INT16 cDataType);


/*
    ����͸��ͨ����Ϣ
     _pLink------�ͻ��˱�ʾ
     cBuf-----���ݵ�ַ
     nLen---���ݳ���
*/
DLL_DECLARE void P2PNetServerSndMsgToLink(PEER_INFO * _pLink,CHAR * cBuf, INT32 nLen);


/*
    �������Ѿ����ӵĿͻ��˷���͸��ͨ����Ϣ (���㲥������Ϣ)
     _pLink------�ͻ��˱�ʾ
     cBuf-----���ݵ�ַ
     nLen---���ݳ���
*/
DLL_DECLARE void P2PNetServerSndMsgToAllLink(CHAR* _u8Buf,INT32 _iBufLength);



/*
     ��ȡ�Խ�����
     _pLink------�Խӿͻ��˾��
     pData------��ȡ���ĶԽ�����
     pLen-----�Խ����ݳ���
     _bBlock---������־1--���� 0--������
     ��������ֵ
     ������ȡ��ʱ��0---�ɹ�  -1��ʾ�Խ����ӶϿ�
     ��������ʱ��0---�ɹ� ������ʧ��  С��0��ʾ���ӶϿ�
*/
DLL_DECLARE INT32 P2PNetServerGetTalkData(PEER_INFO * _pLink,char * pData,INT32 *pLen,INT32 _bBlock);





DLL_DECLARE void P2PNetServerSndAlarm(ALARM_TYPE _eAlarmType,INT32 _iTime,INT32 _iChan,CHAR * cTmp);








#if defined(__cplusplus)
}
#endif
#endif






