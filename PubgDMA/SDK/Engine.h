#pragma once
#include "ActorEntity.h"
#include "EngineStructs.h"

// For these offsets just 7 dumper the game and open Engine_Classes
class Engine
{

private:

	uint64_t OwningActorOffset = 0xA0; // NetConnection -> OwningActor
	uint64_t MaxPacketOffset = 0xA8; // NetConnection -> MaxPacket
	uint64_t OwningActor;
	int MaxPacket;
	CameraCacheEntry CameraEntry; // ScriptStruct Engine.CameraCacheEntry
	MinimalViewInfo CameraViewInfo; // ScriptStruct Engine.MinimalViewInfo
	std::vector<std::shared_ptr<ActorEntity>> Actors;

	uint64_t UWorldCache = 0x1016CA18;
	uint64_t CurrentLevelCache = 0x38;
	uint64_t GameInstanceCache = 0x168;
	uint64_t LocalPlayersCache = 0x50;
	uint64_t PlayerControllerCache = 0x38;
	uint64_t AcknowledgedPawnCache = 0x4C0;
	uint64_t PlayerCameraManagerCache = 0x4E8;
	uint64_t GNamesCache = 0x103CB888;


	uint64_t DecryptPtr; //Ω‚√‹÷∏’Î
	int32_t DecryptKey;

	uint64_t GNames_offset = 0x10;
	// 2024-10-17
	uint64_t UWorld = 0x1016CA18;
	uint64_t Decrypt = 0xE6A1428;
	uint64_t GNames = 0x103CB888;
	uint64_t ElementsPerChunk = 0x3F80;

	uint64_t Offset = 0x24;
	uint64_t NameIndexXor1 = 0xD5A35476;
	uint64_t NameIndexOne = 0xA;
	uint64_t NameIndexTwo = 0x10;
	uint64_t NameIndexXor2 = 0x81D55476;
	uint64_t NameIsROR = 0x1;


	uint64_t CurrentLevel = 0x38;
	uint64_t GameInstance = 0x168;
	uint64_t LocalPlayers = 0x50;
	uint64_t LeaveActors = 0x50;
	uint64_t ObjectID = 0x8;
	uint64_t PlayerController = 0x38;
	uint64_t AcknowledgedPawn = 0x4C0;
	uint64_t PlayerCameraManager = 0x4E8;
	uint64_t RootComponent = 0x1A0;
	uint64_t PlayerState = 0x430;
	uint64_t PlayerStatistics = 0x878;
	uint64_t Mesh = 0x628;
	uint64_t AnimScriptInstance = 0xDE8;
	uint64_t StaticMesh = 0xAD0;

	uint64_t Health = 0x978;
	uint64_t HeaFlag = 0x2A8;
	uint64_t Health1 = 0x990;
	uint64_t Health2 = 0xA30;
	uint64_t Health3 = 0x98C;
	uint64_t Health4 = 0x978;
	uint64_t Health5 = 0x98D;
	uint64_t Health6 = 0x988;
	uint64_t HealthXorKey0 = 0xCEC7A547;
	uint64_t HealthXorKey1 = 0x9B63B2A1;
	uint64_t HealthXorKey2 = 0xCAA9702B;
	uint64_t HealthXorKey3 = 0xA138485D;
	uint64_t HealthXorKey4 = 0xCB911D0A;
	uint64_t HealthXorKey5 = 0x23DDDF83;
	uint64_t HealthXorKey6 = 0x9455DC8;
	uint64_t HealthXorKey7 = 0x2B4DA521;
	uint64_t HealthXorKey8 = 0xBDF7A58;
	uint64_t HealthXorKey9 = 0x2BEFA187;
	uint64_t HealthXorKey10 = 0xE2758433;
	uint64_t HealthXorKey11 = 0x708ADBA9;
	uint64_t HealthXorKey12 = 0xBDCBA1D5;
	uint64_t HealthXorKey13 = 0xA1935D07;
	uint64_t HealthXorKey14 = 0x11099E38;
	uint64_t HealthXorKey15 = 0x14332A5E;

	uint64_t GroggyHealth = 0x1480;
	uint64_t LastTeamNum = 0x1968;
	uint64_t CharacterName = 0x3378;
	uint64_t SpectatedCount = 0x16F8;
	uint64_t Eyes = 0x75C;

	uint64_t WorldToMap = 0x9C4;
	uint64_t ComponentToWorld = 0x320;
	uint64_t ComponentLocation = 0x330;
	uint64_t ComponentVelocity = 0x350;
	uint64_t CameraFov = 0xA44;
	uint64_t CameraRot = 0xA30;
	uint64_t CameraPos = 0xFE0;

	uint64_t ItemID = 0x268 + 0x4;
	uint64_t ItemTable = 0xB0;
	uint64_t DroppedItemGroup = 0x1F0;
	uint64_t DroppedItemGroup_UItem = 0x850;

	uint64_t WeaponProcessor = 0xA90;
	uint64_t EquippedWeapons = 0x208;
	uint64_t CurrentWeaponIndex = 0x311;
	uint64_t WeaponTrajectoryData = 0x10D8;
	uint64_t TrajectoryConfig = 0x108;
	uint64_t ControlRotation_CP = 0xCA8;
	uint64_t RecoilADSRotation_CP = 0x91C;
	uint64_t LeanLeftAlpha_CP = 0xCFC;
	uint64_t LeanRightAlpha_CP = 0xD00;

	// uint64_t TrainingMapGrid = 0x708;
	uint64_t AimOffsets = 0x1C28;
	uint64_t ReplicatedMovement = 0x70;
	uint64_t VehicleRiderComponent = 0x2070;
	uint64_t LastVehiclePawn = 0x270;


public:
	Engine();
	inline bool InitDecrypt(uint64_t offset);
	void restore();
	void Cache();
	void UpdatePlayers();
	std::vector<std::shared_ptr<ActorEntity>> GetActors();
	CameraCacheEntry GetCameraCache();
	void RefreshViewMatrix(VMMDLL_SCATTER_HANDLE handle);
	uint64_t GetActorSize();
	uintptr_t xe_decrypt(const uintptr_t encrypted);
	DWORD DecryptCIndex(DWORD Encrypted);
	void GetGNames();
	std::string GetNames(DWORD ID);
};