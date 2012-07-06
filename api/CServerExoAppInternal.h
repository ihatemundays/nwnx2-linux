#ifndef _CSERVEREXOAPPINTERNAL_H_
#define _CSERVEREXOAPPINTERNAL_H_
#include "nwndef.h"
#include "CExoString.h"
#include "CNWSPlayer.h"
#include "CExoLinkedList.h"
#include "CWorldTimer.h"
#include "CNWSArea.h"
#include "CNWSAreaOfEffectObject.h"
#include "CNWSClient.h"
#include "CNWSCreature.h"
#include "CNWSDoor.h"
#include "CNWSEncounter.h"
#include "CExtendedServerInfo.h"
#include "CGameObject.h"
#include "CNWSItem.h"
#include "CNWSModule.h"
#include "CNWSPlaceable.h"
#include "CNWSSoundObject.h"
#include "CNWSStore.h"
#include "CNWSTrigger.h"
#include "CNWSWaypoint.h"
#include "CResRef.h"
#include "nwnstructs.h"
#include "CNetLayer.h"
#include "CFactionManager.h"

class CServerExoAppInternal
{
public:
	void AddCDKeyToBannedList(CExoString);
	void AddCharListRequest(unsigned long);
	void AddIPToBannedList(CExoString);
	int AddPendingAuthorization(unsigned long);
	void AddPlayerNameToBannedList(CExoString);
	int AddSubNetProfileRecvSize(unsigned long, unsigned long);
	void AddSubNetProfileSendSize(unsigned long, unsigned long);
	void AddSubNetProfile(unsigned long, CExoString, CExoString);
	void AddToExclusionList(unsigned long, unsigned char);
	int AdmitNetworkAddress(unsigned long, CExoString);
	int AdmitPlayerName(CExoString);
	void CheckMasterServerTranslation();
	void ConnectionLibMainLoop();
	int ContinueMessageProcessing();
	int CopyModuleToCurrentGame(CExoString &, CExoString &, unsigned short);
	int CreateServerVaultLostAndFound();
	void DealWithLoadGameError(unsigned long);
	int EndGame(CExoString const &);
	int ExportAllPlayers();
	int ExportPlayer(CNWSPlayer *);
	CExoLinkedList<unsigned long> * GetActiveExclusionList();
	unsigned char GetActivePauseState();
	CWorldTimer * GetActiveTimer(unsigned long);
	CNWSArea * GetAreaByGameObjectID(unsigned long);
	CNWSAreaOfEffectObject * GetAreaOfEffectByGameObjectID(unsigned long);
	CExoString GetBannedListString();
	CNWSPlayer * GetClientObjectByObjectId(unsigned long);
	CNWSClient * GetClientObjectByPlayerId(unsigned long, unsigned char);
	CNWSCreature * GetCreatureByGameObjectID(unsigned long);
	int GetDifficultyOption(int);
	CNWSDoor * GetDoorByGameObjectID(unsigned long);
	CNWSEncounter * GetEncounterByGameObjectID(unsigned long);
	void GetExtendedServerInfo(CExtendedServerInfo *);
	int GetFactionOfObject(unsigned long, int *);
	unsigned long GetFirstPCObject();
	CGameObject * GetGameObject(unsigned long);
	int GetIsCDKeyOnBannedList(CExoString);
	int GetIsIPOnBannedList(CExoString);
	int GetIsPlayerNameOnBannedList(CExoString);
	CNWSItem * GetItemByGameObjectID(unsigned long);
	CNWSModule * GetModuleByGameObjectID(unsigned long);
	int GetModuleExists(CExoString const &);
	int GetModuleLanguage();
	CExoString GetModuleName();
	CNWSModule * GetModule();
	unsigned long GetNextPCObject();
	int GetPauseState(unsigned char);
	CNWSPlaceable * GetPlaceableByGameObjectID(unsigned long);
	int GetPlayerAddressData(unsigned long, unsigned long *, unsigned char **, unsigned char **, unsigned long *);
	unsigned long GetPlayerIDByGameObjectID(unsigned long);
	int GetPlayerLanguage(unsigned long);
	CExoString GetPlayerListString();
	CExoString GetPortalListString();
	void GetServerInfoFromIniFile();
	CNWSSoundObject * GetSoundObjectByGameObjectID(unsigned long);
	CNWSStore * GetStoreByGameObjectID(unsigned long);
	CNWSTrigger * GetTriggerByGameObjectID(unsigned long);
	CNWSWaypoint * GetWaypointByGameObjectID(unsigned long);
	void HandleGameSpyToServerMessage(int, void *, int);
	int HandleMessage(unsigned long, unsigned char *, unsigned long, int);
	void InitializeNetLayer();
	int Initialize();
	void InitiateModuleForPlayer(void *);
	int IsOnActiveExclusionList(unsigned long);
	int IsOnExclusionList(unsigned long);
	int LoadCharacterFinish(CNWSPlayer *, int, int);
	int LoadCharacterStart(unsigned char, CNWSPlayer *, CResRef, void *, unsigned long);
	int LoadGame(unsigned long, CExoString &, CExoString &, CNWSPlayer *);
	int LoadModule(CExoString, int, CNWSPlayer *);
	int LoadPrimaryPlayer(CNWSPlayer *);
	int MainLoop();
	int MarkUpdateClientsForObject(unsigned long);
	void MovePlayerToArea(void *);
	int OnCDChange();
	int OnExit();
	int OnGainFocus();
	int OnLostFocus();
	int OnVideoChange();
	void PlayerListChange(unsigned long, int, int);
	void PushMessageOverWall(unsigned char *, unsigned long);
	void ReadBannedLists();
	void RemoveCDKeyFromBannedList(CExoString);
	void RemoveFromExclusionList(unsigned long, unsigned char);
	void RemoveIPFromBannedList(CExoString);
	void RemovePCFromWorld(CNWSPlayer *);
	int RemovePendingAuthorization(unsigned long);
	void RemovePlayerNameFromBannedList(CExoString);
	void RemoveSubNetProfile(unsigned long);
	int ReprocessExclusionListActions(unsigned char);
	unsigned long ResolvePlayerByFirstName(CExoString const &);
	int RestartNetLayer();
	int RunModule();
	int SaveGame(unsigned long, CExoString &, CExoString &, CNWSPlayer *, int, CExoString &);
	int SendCharacterQuery(CNWSPlayer *);
	int SendEnteringStartNewModuleMessage();
	int SendExitingStartNewModuleMessage(int);
	int SendHeartbeatToMasterServer();
	int SendStartStallEvent(unsigned long);
	void SetEstimatedSaveSize(CExoString const &, unsigned short);
	int SetGameSpyReporting(int);
	int SetNetworkAddressBan(unsigned long, CExoString, int);
	void SetPauseState(unsigned char, int);
	int ShutdownNetLayer();
	void ShutdownServerProfiles();
	void Shutdown(int, int);
	void StallEventSaveGame();
	int StartNewModule(CExoString &);
	void StartServices();
	int StartShutdownTimer(unsigned long long, unsigned long long);
	void StopServices();
	int StorePlayerCharacters();
	int StripColorTokens(CExoString &);
	int Test_Unit_Script_Compile();
	int Test_Unit_Script_Run();
	void TogglePauseState(unsigned char);
	void Uninitialize();
	int UnloadModule();
	void UnlockBiowareModule(CNWSModule *);
	int UpdateAutoSaveTimer();
	int UpdateClientGameObjectsForPlayer(CNWSPlayer *, int, unsigned long long);
	int UpdateClientGameObjects(int);
	int UpdateClientsForObject(unsigned long);
	int UpdateLogHeartbeatTimer(unsigned long long);
	int UpdateShutdownTimer(unsigned long long);
	int UpdateWindowTitle();
	unsigned long ValidateCreateServerCharacter(CNWSPlayer *, void *, unsigned long);
	int ValidatePlayerLogin(void *);
	void VomitServerOptionsToLog();
	void WriteServerInfoToIniFile();
	~CServerExoAppInternal();
	CServerExoAppInternal();

	/* 0x0/0 */ unsigned long field_0[16384];
	/* 0x10000/65536 */ unsigned long UseNetworking;
	/* 0x10004/65540 */ unsigned long UseGameSpy;
	/* 0x10008/65544 */ unsigned long field_10008;
	/* 0x1000C/65548 */ CServerExoAppConfig *config;
	/* 0x10010/65552 */ unsigned short State;
	/* 0x10014/65556 */ char rsvd1[2];
	/* 0x10014/65556 */ unsigned long field_10014;
	/* 0x10018/65560 */ unsigned long CNWSMessage;
	/* 0x1001C/65564 */ unsigned long field_1001C;
	/* 0x10020/65568 */ unsigned long field_10020;
	/* 0x10024/65572 */ unsigned long NotTranslatedAddresses;
	/* 0x10028/65576 */ unsigned long field_10028;
	/* 0x1002C/65580 */ unsigned long field_1002C;
	/* 0x10030/65584 */ unsigned long ShutdownServer;
	/* 0x10034/65588 */ unsigned long field_10034;
	/* 0x10038/65592 */ unsigned long field_10038;
	/* 0x1003C/65596 */ unsigned long field_1003C;
	/* 0x10040/65600 */ unsigned long field_10040;
	/* 0x10044/65604 */ unsigned long field_10044;
	/* 0x10048/65608 */ unsigned long field_10048;
	/* 0x1004C/65612 */ unsigned long field_1004C;
	/* 0x10050/65616 */ unsigned long field_10050;
	/* 0x10054/65620 */ unsigned long field_10054;
	/* 0x10058/65624 */ unsigned long field_10058;
	/* 0x1005C/65628 */ unsigned long field_1005C;
	/* 0x10060/65632 */ CNetLayer *m_NetLayer;
	/* 0x10064/65636 */ unsigned long m_ServerAIMaster;
	/* 0x10068/65640 */ unsigned long WorldTimer1;
	/* 0x1006C/65644 */ unsigned long WorldTimer2;
	/* 0x10070/65648 */ unsigned long WorldTimer3;
	/* 0x10074/65652 */ CFactionManager *m_FactionManager;
	/* 0x10078/65656 */ unsigned long m_ConnectionLib;
	/* 0x1007C/65660 */ unsigned long field_1007C;
	/* 0x10080/65664 */ unsigned long m_GameObjectArray;
	/* 0x10084/65668 */ unsigned long field_10084;
	/* 0x10088/65672 */ void *ClientsList;
	/* 0x1008C/65676 */ unsigned long field_1008C;
	/* 0x10090/65680 */ unsigned long field_10090;
	/* 0x10094/65684 */ unsigned long field_10094;
	/* 0x10098/65688 */ unsigned long field_10098;
	/* 0x1009C/65692 */ unsigned long field_1009C;
	/* 0x100A0/65696 */ unsigned long field_100A0;
	/* 0x100A4/65700 */ unsigned long field_100A4;
	/* 0x100A8/65704 */ unsigned long m_StartNewModule;
	/* 0x100AC/65708 */ unsigned long ModuleName;
	/* 0x100B0/65712 */ unsigned long field_100B0;
	/* 0x100B4/65716 */ unsigned long m_EndGame;
	/* 0x100B8/65720 */ unsigned long field_100B8;
	/* 0x100BC/65724 */ unsigned long field_100BC;
	/* 0x100C0/65728 */ unsigned long field_100C0;
	/* 0x100C4/65732 */ unsigned long field_100C4;
	/* 0x100C8/65736 */ unsigned long field_100C8;
	/* 0x100CC/65740 */ unsigned long field_100CC;
	/* 0x100D0/65744 */ unsigned long ExportCharacters;
	/* 0x100D4/65748 */ unsigned long CharacterToExport;
	/* 0x100D8/65752 */ unsigned long field_100D8;
	/* 0x100DC/65756 */ unsigned long field_100DC;
	/* 0x100E0/65760 */ unsigned long field_100E0;
	/* 0x100E4/65764 */ unsigned long field_100E4;
	/* 0x100E8/65768 */ unsigned long field_100E8;
	/* 0x100EC/65772 */ unsigned long field_100EC;
	/* 0x100F0/65776 */ unsigned long field_100F0;
	/* 0x100F4/65780 */ unsigned long field_100F4;
	/* 0x100F8/65784 */ unsigned long field_100F8;
	/* 0x100FC/65788 */ unsigned long field_100FC;
	/* 0x10100/65792 */ unsigned long field_10100;
	/* 0x10104/65796 */ unsigned long field_10104;
	/* 0x10108/65800 */ unsigned long field_10108;
	/* 0x1010C/65804 */ unsigned long field_1010C;
	/* 0x10110/65808 */ unsigned long field_10110;
	/* 0x10114/65812 */ unsigned long field_10114;
	/* 0x10118/65816 */ unsigned long field_10118;
	/* 0x1011C/65820 */ unsigned long field_1011C;
	/* 0x10120/65824 */ unsigned long field_10120;
	/* 0x10124/65828 */ unsigned long field_10124;
	/* 0x10128/65832 */ unsigned long field_10128;
	/* 0x1012C/65836 */ unsigned long field_1012C;
	/* 0x10130/65840 */ unsigned long field_10130;
	/* 0x10134/65844 */ unsigned long field_10134;
	/* 0x10138/65848 */ unsigned long field_10138;
	/* 0x1013C/65852 */ unsigned long field_1013C;
	/* 0x10140/65856 */ unsigned long field_10140;
	/* 0x10144/65860 */ unsigned long field_10144;
	/* 0x10148/65864 */ unsigned long field_10148;
	/* 0x1014C/65868 */ unsigned long field_1014C;
	/* 0x10150/65872 */ unsigned long field_10150;
	/* 0x10154/65876 */ unsigned long field_10154;
	/* 0x10158/65880 */ unsigned long LogDots;
	/* 0x1015C/65884 */ unsigned long field_1015C;
};
#endif
