#ifndef _CNWSDOOR_H_
#define _CNWSDOOR_H_
#include "nwndef.h"
#include "CNWSObject.h"
#include "Vector.h"
#include "CExoString.h"
#include "CResRef.h"
#include "CExoLocString.h"
#include "CExoArrayList.h"

class CNWSDoor : public CNWSObject
{
public:
    void AIUpdate();
    void AddToArea(CNWSArea *, float, float, float, int);
    CNWSDoor * AsNWSDoor();
    void DoDamage(int);
    void EventHandler(unsigned long, unsigned long, void *, unsigned long, unsigned long);
    Vector GetActionPoint(int, unsigned char);
    int GetActive();
    int GetAppearanceType();
    int GetAutoRemoveKey();
    int GetBaseType();
    int GetBearing();
    int GetCreatureList();
    CExoString GetDescriptionOverride();
    CExoLocString & GetDescription();
    int GetDetectDC();
    int GetDetectable();
    CResRef GetDialogResref();
    int GetDisarmDC();
    int GetDisarmable();
    CExoString GetDisplayName();
    int GetFactionId();
    CExoLocString & GetFirstName();
    int GetFlagged();
    int GetFortitudeSave();
    int GetGenericType();
    int GetHardness();
    int GetIsLinked();
    CExoString * GetKeyName();
    CExoString GetKeyRequiredFeedbackMessage();
    int GetKeyRequired();
    int GetLastClosed();
    int GetLastDisarmed();
    int GetLastLocked();
    int GetLastOpened();
    int GetLastTriggered();
    int GetLastUnlocked();
    CNWSObject * GetLinkedObject();
    CExoString GetLinkedToTag();
    unsigned short GetLoadScreenID();
    int GetLockDC();
    int GetLockable();
    int GetLocked();
    Vector GetNearestActionPoint(Vector const &, int);
    int GetOneShot();
    int GetOpenLockDC();
    unsigned char GetOpenState();
    int GetRecoverable();
    int GetReflexSave();
    int GetScriptName(int);
    int GetSecretDoorDC();
    int GetTrapCreator();
    int GetTrapFactionId();
    int GetTrapped();
    int GetUpdateDisplayName();
    int GetVisibleModel();
    int GetWillSave();
    int LoadDoor(CResGFF *, CResStruct *);
    int NoNonWalkPolysInDoor(float, float, float, float, float, float, float);
    void PostProcess();
    void RemoveFromArea();
    int SaveDoor(CResGFF *, CResStruct *);
    int SetActive(int);
    int SetAppearanceType(unsigned long);
    int SetAutoRemoveKey(int);
    int SetBaseType(unsigned char);
    int SetBearing(float);
    void SetDescriptionOverride(CExoString);
    void SetDescription(CExoLocString);
    int SetDetectDC(unsigned char);
    int SetDetectable(int);
    int SetDialogResref(CResRef);
    int SetDisarmDC(unsigned char);
    int SetDisarmable(int);
    void SetDisplayName(CExoString);
    int SetFactionId(int);
    void SetFirstName(CExoLocString);
    int SetFlagged(unsigned char);
    int SetFortitudeSave(unsigned char);
    int SetGenericType(unsigned long);
    int SetHardness(unsigned char);
    int SetKeyName(CExoString const &);
    void SetKeyRequiredFeedbackMessage(CExoString);
    int SetKeyRequired(int);
    int SetLastClosed(unsigned long);
    int SetLastDisarmed(unsigned long);
    int SetLastLocked(unsigned long);
    int SetLastOpened(unsigned long);
    int SetLastTriggered(unsigned long);
    int SetLastUnlocked(unsigned long);
    int SetLinkedFlags(unsigned char);
    void SetLinkedToTag(CExoString);
    int SetLockDC(unsigned char);
    int SetLockable(int);
    int SetLocked(int);
    int SetOneShot(int);
    int SetOpenLockDC(unsigned char);
    void SetOpenState(unsigned char);
    int SetRecoverable(int);
    int SetReflexSave(unsigned char);
    void SetScriptName(int, CExoString);
    int SetSecretDoorDC(unsigned char);
    int SetTrapCreator(unsigned long);
    int SetTrapFactionId(int);
    int SetTrapped(int);
    int SetUpdateDisplayName(int);
    int SetVisibleModel(int);
    int SetWillSave(unsigned char);
    ~CNWSDoor();
    CNWSDoor(unsigned long);

    /* 0x1C4/452 */ CExoString Scripts[14];
    /* 0x234/564 */ unsigned long field_234;
    /* 0x238/568 */ unsigned long field_238;
    /* 0x23C/572 */ unsigned long Appearance;
    /* 0x240/576 */ unsigned long GenericType;
    /* 0x244/580 */ CResRef Conversation;
    /* 0x254/596 */ unsigned long Bearing;
    /* 0x258/600 */ unsigned long Faction;
    /* 0x25C/604 */ unsigned char SaveFort;
    /* 0x25D/604 */ unsigned char SaveReflex;
    /* 0x25E/604 */ unsigned char SaveWill;
    /* 0x25F/604 */ unsigned char LockOpenDC;
    /* 0x260/608 */ unsigned char LockDC;
    /* 0x261/608 */ unsigned char SecretDoor;
    /* 0x262/608 */ unsigned char Hardness;
    /* 0x263/608 */ unsigned char field_263;
    /* 0x264/612 */ int Locked;
    /* 0x268/616 */ int Locakable;
    /* 0x26C/620 */ unsigned long field_26C;
    /* 0x270/624 */ CExoString LockKeyName;
    /* 0x278/632 */ CExoString LockKeyMessage;
    /* 0x280/640 */ unsigned long LockKeyRequired;
    /* 0x284/644 */ CExoArrayList<unsigned long> CreatureList;
    /* 0x290/656 */ nwobjid TrapCreator;
    /* 0x294/660 */ unsigned long Trapped;
    /* 0x298/664 */ unsigned char TrapDisarmDC;
    /* 0x299/664 */ unsigned char TrapDetectDC;
    /* 0x29A/664 */ unsigned char field_29A;
    /* 0x29B/664 */ unsigned char field_29B;
    /* 0x29C/668 */ unsigned long LockKeyRemove;
    /* 0x2A0/672 */ unsigned long TrapFlagged;
    /* 0x2A4/676 */ unsigned long TrapBaseType;
    /* 0x2A8/680 */ unsigned long TrapDisarmable;
    /* 0x2AC/684 */ unsigned long TrapDetectable;
    /* 0x2B0/688 */ unsigned long TrapOneShot;
    /* 0x2B4/692 */ unsigned long TrapRecoverable;
    /* 0x2B8/696 */ unsigned long TrapActive;
    /* 0x2BC/700 */ unsigned long TrapFaction;
    /* 0x2C0/704 */ unsigned long VisibleModel;
    /* 0x2C4/708 */ unsigned long field_2C4;
    /* 0x2C8/712 */ unsigned long field_2C8;
    /* 0x2CC/716 */ unsigned long LastLocked;
    /* 0x2D0/720 */ unsigned long LastUnlocked;
    /* 0x2D4/724 */ unsigned long LastOpened;
    /* 0x2D8/728 */ unsigned long LastClosed;
    /* 0x2DC/732 */ unsigned long LastTriggered;
    /* 0x2E0/736 */ unsigned long LastDisarmed;
    /* 0x2E4/740 */ CNWDoorSurfaceMesh* SurfaceMesh;
    /* 0x2E8/744 */ unsigned long field_2E8;
    /* 0x2EC/748 */ unsigned long field_2EC;
    /* 0x2F0/752 */ unsigned long field_2F0;
    /* 0x2F4/756 */ unsigned long field_2F4;
    /* 0x2F8/760 */ unsigned long field_2F8;
    /* 0x2FC/764 */ unsigned long field_2FC;
    /* 0x300/768 */ char LinkedFlags;
    /* 0x301/769 */ char field_301;
    /* 0x302/770 */ char field_302;
    /* 0x303/771 */ char field_303;
    /* 0x304/772 */ CExoString LinkedTo;
    /* 0x30C/780 */ unsigned long field_30C;
    /* 0x310/784 */ CExoLocString Name;
    /* 0x318/792 */ CExoLocString Description;
    /* 0x320/800 */ CExoString DescriptionOverride;
    /* 0x328/808 */ CExoString NameOverride;
    /* 0x330/816 */ unsigned long UpdateDisplayName;
    /* 0x334/820 */ unsigned short LoadScreenID;
    /* 0x336/822 */ unsigned short field_336;
};

static_assert_size(CNWSDoor, 0x338);

#endif
