#ifndef _CNWSMODULE_H_
#define _CNWSMODULE_H_
#include "nwndef.h"
#include "CExoString.h"
#include "CNWSPlayerTURD.h"
#include "CPathfindInformation.h"
#include "CNWSArea.h"
#include "CResRef.h"
#include "CExoLocString.h"
#include "CNWSPlayer.h"
#include "CResGFF.h"
#include "nwnstructs.h"
#include "CExoArrayList.h"
#include "CERFFile.h"
#include "Vector.h"
#include "CGameObject.h"
#include "CExoLinkedList.h"

class CNWSModule
{
public:
	int AIUpdate();
	void AddObjectToLimbo(unsigned long);
	int AddObjectToLookupTable(CExoString, unsigned long);
	int AddTURDsToWorld();
	void AddToTURDList(CNWSPlayerTURD *);
	int AddWorldJournalEntryStrref(unsigned long, unsigned long, unsigned long, unsigned long);
	void AddWorldJournalEntry(int, CExoString, CExoString, unsigned long, unsigned long);
	CNWSModule * AsNWSModule();
	void CleanUpLimboList();
	int ClearAreaVisitedFlags();
	int ComputeInterAreaPath(CPathfindInformation *);
	int DeleteWorldJournalAllEntries();
	void DeleteWorldJournalEntryStrref(unsigned long);
	void DeleteWorldJournalEntry(int);
	void DoUpdate();
	void EventHandler(unsigned long, unsigned long, void *, unsigned long, unsigned long);
	unsigned long FindObjectByTagOrdinal(CExoString const &, unsigned long);
	unsigned long FindObjectByTagTypeOrdinal(CExoString const &, int, unsigned long);
	int FindTagPositionInTable(char *);
	int GenerateInterAreaDFSSuccessors(int, CPathfindInformation *, unsigned long **);
	int GetAreaByName(CExoString &);
	CNWSArea * GetAreaByTag(CExoString &);
	int GetAreaList();
	CNWSArea * GetArea(CResRef);
	CNWSArea * GetArea(unsigned long);
	int GetCustomScriptEventId();
	int GetDawnHour();
	int GetDuskHour();
	int GetEnableScriptDebugger();
	unsigned char * GetFullCipher(CExoString);
	int GetInvisibleCreaturesList();
	int GetIsDigitalDistributionDemo();
	int GetIsNWMFile();
	int GetIsSaveGame();
	int GetLastEnter();
	int GetLastExit();
	int GetLastItemAcquiredBy();
	int GetLastItemAcquiredFrom();
	int GetLastItemAcquiredStackSize();
	int GetLastItemAcquired();
	int GetLastItemActivatedArea();
	int GetLastItemActivatedPosition();
	int GetLastItemActivatedTarget();
	int GetLastItemActivated();
	int GetLastItemActivator();
	int GetLastItemLoser();
	int GetLastItemLostStackSize();
	int GetLastItemLost();
	int GetLastPCCancelCutscene();
	int GetLastPCLevellingUp();
	int GetLastPlayerChatMessageType();
	CExoString GetLastPlayerChatMessage();
	int GetLastPlayerChatObject();
	int GetLastPlayerDied();
	int GetLastPlayerDying();
	int GetLastRespawnButtonPresser();
	int GetLastRestEventType();
	int GetLastRested();
	int GetLimboArray();
	int GetMaxHenchmen();
	int GetMinutesPerHour();
	CExoLocString GetModuleDescription();
	int GetModuleEntryInfo();
	CExoLocString GetModuleName();
	CExoString GetNWMResName();
	int GetPCItemLastEquippedBy();
	int GetPCItemLastEquipped();
	int GetPCItemLastUnequippedBy();
	int GetPCItemLastUnequipped();
	unsigned long GetPlayerIndexInPlayerList(CNWSPlayer *);
	int GetPlayerPathfindRule();
	CNWSPlayerTURD * GetPlayerTURDFromList(CNWSPlayer *);
	unsigned long GetPrimaryPlayerIndex();
	int GetScriptName(int);
	int GetScriptVarTable();
	int GetStartMovie();
	CExoString GetTag();
	int GetTimeOfDayState();
	void GetTime(unsigned long *, unsigned long *, unsigned long *, unsigned long *, unsigned char *, unsigned long *);
	unsigned long GetWaypoint(CExoString const &);
	unsigned long GetWorldJournalIndexUnique();
	int GetXPScale();
	int InterAreaDFS(int, int, CPathfindInformation *);
	int IsObjectInLimbo(unsigned long);
	unsigned char IsOfficialCampaign();
	int LoadLimboCreatures(CResGFF *, CResStruct *, int);
	unsigned long LoadModuleFinish();
	unsigned long LoadModuleInProgress(int, int);
	unsigned long LoadModuleStart(CExoString, int);
	void LoadTURDList(CResGFF *, CResStruct *);
	void PackModuleIntoMessage(unsigned long);
	void PackPlayerCharacterListIntoMessage(CNWSPlayer *, CExoArrayList<NWPlayerCharacterList_st *> &);
	unsigned long PlotInterAreaPath(CPathfindInformation *, unsigned long);
	unsigned long PlotPathInArea(CPathfindInformation *, unsigned long);
	unsigned long PlotPath(CPathfindInformation *, unsigned long);
	void PostProcess();
	void RemoveFromTURDList(CNWSPlayer *);
	void RemoveObjectFromLimbo(unsigned long);
	int RemoveObjectFromLookupTable(CExoString, unsigned long);
	void SaveLimboCreatures(CResGFF *, CResStruct *);
	int SaveModuleFAC(CERFFile *);
	int SaveModuleFinish(CExoString &, CExoString &);
	int SaveModuleIFOFinish(CResGFF *, CResStruct *, CERFFile *, CExoString &, CExoArrayList<unsigned long> &);
	int SaveModuleIFOStart(CResGFF *, CResStruct *);
	int SaveModuleInProgress();
	void SaveModuleStart(CExoString &, CExoString &);
	int SavePlayers(CResGFF *, CResStruct *, CExoString &, CExoArrayList<unsigned long> &);
	int SaveStatic(CERFFile *, CExoString, unsigned short, int);
	int SaveTURDList(CResGFF *, CResStruct *);
	int SetCustomScriptEventId(int);
	int SetEnableScriptDebugger(unsigned char);
	void SetIntraAreaGoal(CPathfindInformation *);
	int SetIsNWMFile(int);
	int SetIsSaveGame(int);
	int SetLastEnter(unsigned long);
	int SetLastExit(unsigned long);
	int SetLastItemAcquiredBy(unsigned long);
	int SetLastItemAcquiredFrom(unsigned long);
	int SetLastItemAcquiredStackSize(int);
	int SetLastItemAcquired(unsigned long);
	int SetLastItemActivatedArea(unsigned long);
	int SetLastItemActivatedPosition(Vector const &);
	int SetLastItemActivatedTarget(unsigned long);
	int SetLastItemActivated(unsigned long);
	int SetLastItemActivator(unsigned long);
	int SetLastItemLoser(unsigned long);
	int SetLastItemLostStackSize(int);
	int SetLastItemLost(unsigned long);
	int SetLastPCCancelCutscene(unsigned long);
	int SetLastPCLevellingUp(unsigned long);
	int SetLastPlayerChatMessageType(unsigned char);
	int SetLastPlayerChatMessage(CExoString const &);
	int SetLastPlayerChatObject(unsigned long);
	int SetLastPlayerDied(unsigned long);
	int SetLastPlayerDying(unsigned long);
	int SetLastRespawnButtonPresser(unsigned long);
	int SetLastRestEventType(unsigned char);
	int SetLastRested(unsigned long);
	int SetMaxHenchmen(int);
	int SetNWMResName(CExoString &);
	int SetPCItemLastEquippedBy(unsigned long);
	int SetPCItemLastEquipped(unsigned long);
	int SetPCItemLastUnequippedBy(unsigned long);
	int SetPCItemLastUnequipped(unsigned long);
	int SetPlayerPathfindRule(unsigned char);
	void SetScriptName(int, CExoString);
	int SetXPScale(unsigned char);
	void TimeStopSanityCheck();
	int UnloadModule();
	void UpdateTime(unsigned long, unsigned long, unsigned long);
	~CNWSModule();
	CNWSModule(CExoString, int, int);

	/* 0x0/0 */ CGameObject GameObject;
	/* 0x10/16 */ unsigned long ModuleExpansionList;
	/* 0x14/20 */ unsigned long field_14;
	/* 0x18/24 */ unsigned long AreasResrefList;
	/* (mtype:CExoArrayList<unsigned long>) */
	/* 0x1C/28 */ CExoArrayList<unsigned long> Areas;
	/* 0x28/40 */ unsigned long field_28;
	/* 0x2C/44 */ unsigned long field_2C;
	/* 0x30/48 */ unsigned long field_30;
	/* 0x34/52 */ unsigned long field_34;
	/* 0x38/56 */ unsigned long field_38;
	/* 0x3C/60 */ unsigned long field_3C;
	/* 0x40/64 */ unsigned long field_40;
	/* 0x44/68 */ unsigned long field_44;
	/* 0x48/72 */ unsigned long field_48;
	/* (mtype:CExoLinkedList<CNWSPlayerTURD>) */
	/* 0x4C/76 */ CExoLinkedList<CNWSPlayerTURD> TURDList;
	/* 0x58/88 */ char rsvd1[8];
	/* 0x58/88 */ CExoString m_sCustomTLK;
	/* 0x80/128 */ char rsvd2[32];
	/* 0x80/128 */ unsigned long field_80;
	/* 0x84/132 */ unsigned long field_84;
	/* 0x88/136 */ unsigned long field_88;
	/* (mtype:CExoArrayList<CExoString>) */
	/* 0x8C/140 */ CExoArrayList<CExoString> HakList;
	/* 0xB8/184 */ char rsvd3[32];
	/* 0xB8/184 */ CExoString OnHeartbeat;
	/* 0xD4/212 */ char rsvd4[20];
	/* 0xD4/212 */ CExoString field_F0;
	/* 0xDC/220 */ CExoString field_F8;
	/* 0xE4/228 */ CExoString OnPlayerDeath;
	/* 0xEC/236 */ CExoString OnPlayerDying;
	/* 0xF4/244 */ CExoString field_110;
	/* 0x1CC/460 */ char rsvd5[208];
	/* 0x1CC/460 */ unsigned long field_1CC;
	/* 0x1D0/464 */ unsigned long field_1D0;
	/* 0x1D4/468 */ unsigned long field_1D4;
	/* 0x1D8/472 */ unsigned long field_1D8;
	/* 0x1DC/476 */ unsigned long field_1DC;
	/* 0x1E0/480 */ unsigned long field_1E0;
	/* 0x1E4/484 */ unsigned long field_1E4;
	/* 0x1E8/488 */ unsigned long field_1E8;
	/* 0x1EC/492 */ unsigned long field_1EC;
	/* 0x1F0/496 */ unsigned long field_1F0;
	/* 0x1F4/500 */ unsigned long field_1F4;
	/* 0x1F8/504 */ unsigned long field_1F8;
	/* 0x1FC/508 */ unsigned long field_1FC;
	/* 0x200/512 */ unsigned long field_200;
	/* 0x204/516 */ unsigned long field_204;
	/* 0x208/520 */ unsigned long field_208;
	/* 0x20C/524 */ unsigned long field_20C;
	/* 0x210/528 */ unsigned long field_210;
	/* 0x214/532 */ unsigned long field_214;
	/* 0x218/536 */ unsigned long field_218;
	/* 0x21C/540 */ unsigned long field_21C;
	/* 0x220/544 */ unsigned long field_220;
	/* 0x224/548 */ unsigned long SaveGameERF;
	/* 0x228/552 */ unsigned long field_228;
	/* 0x22C/556 */ unsigned long field_22C;
	/* 0x230/560 */ unsigned long field_230;
	/* 0x234/564 */ unsigned long field_234;
	/* 0x238/568 */ unsigned long field_238;
	/* 0x23C/572 */ unsigned long field_23C;
	/* 0x240/576 */ unsigned long field_240;
	/* 0x244/580 */ unsigned long field_244;
	/* 0x248/584 */ unsigned long field_248;
	/* 0x24C/588 */ unsigned long field_24C;
	/* 0x250/592 */ unsigned long field_250;
	/* 0x254/596 */ unsigned long field_254;
	/* 0x258/600 */ unsigned long field_258;
	/* 0x25C/604 */ unsigned long field_25C;
};
#endif
