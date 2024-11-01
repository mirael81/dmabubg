#include "Pch.h"
#include "Drawing.h"
#include "Globals.h"
#include "Camera.h"
#include "ActorEntity.h"
#include "Engine.h"
#include "PlayerEsp.h"
#include "ConfigUtilities.h"

std::shared_ptr<CheatFunction> UpdatePlayers = std::make_shared<CheatFunction>(5, [] {
	if (!EngineInstance)
		return;
	EngineInstance->UpdatePlayers();
	});

void DrawPlayerEsp()
{
	if (!EngineInstance)
		return;
	for (auto entity : EngineInstance->GetActors())
	{
		if (!entity->Class)
			continue;
		if (!entity->RootComponent)
			continue;
		if (!entity->PlayerState)
			continue;
		if (!entity->isCheck) // players aren't pawns
			continue;
		if (entity->Mesh < 65535) {
			continue;
		}
		
		Vector3 Head3d = Vector3(entity->Head3D.X, entity->Head3D.Y, entity->Head3D.Z);
		Vector3 neck3d = Vector3(entity->neck3D.X, entity->neck3D.Y, entity->neck3D.Z);
		Vector3 pelvis3d = Vector3(entity->pelvis3D.X, entity->pelvis3D.Y, entity->pelvis3D.Z);
		Vector3 Lshoulder3d = Vector3(entity->Lshoulder3D.X, entity->Lshoulder3D.Y, entity->Lshoulder3D.Z);
		Vector3 Lelbow3d = Vector3(entity->Lelbow3D.X, entity->Lelbow3D.Y, entity->Lelbow3D.Z);
		Vector3 Lhand3d = Vector3(entity->Lhand3D.X, entity->Lhand3D.Y, entity->Lhand3D.Z);
		Vector3 Rshoulder3d = Vector3(entity->Rshoulder3D.X, entity->Rshoulder3D.Y, entity->Rshoulder3D.Z);
		Vector3 Relbow3d = Vector3(entity->Relbow3D.X, entity->Relbow3D.Y, entity->Relbow3D.Z);
		Vector3 Rhand3d = Vector3(entity->Rhand3D.X, entity->Rhand3D.Y, entity->Rhand3D.Z);
		Vector3 Lbuttock3d = Vector3(entity->Lbuttock3D.X, entity->Lbuttock3D.Y, entity->Lbuttock3D.Z);
		Vector3 Lknee3d = Vector3(entity->Lknee3D.X, entity->Lknee3D.Y, entity->Lknee3D.Z);
		Vector3 Lfoot3d = Vector3(entity->Lfoot3D.X, entity->Lfoot3D.Y, entity->Lfoot3D.Z);
		Vector3 Rbuttock3d = Vector3(entity->Rbuttock3D.X, entity->Rbuttock3D.Y, entity->Rbuttock3D.Z);
		Vector3 Rknee3d = Vector3(entity->Rknee3D.X, entity->Rknee3D.Y, entity->Rknee3D.Z);
		Vector3 Rfoot3d = Vector3(entity->Rfoot3D.X, entity->Rfoot3D.Y, entity->Rfoot3D.Z);
		if (Head3d == Vector3(0, 0, 0) || neck3d == Vector3(0, 0, 0))
			continue;
		PlayerConfig config = Configs.Survivor;

		Vector2 Head = {}, neck = {}, pelvis = {}, Lshoulder = {}, Lelbow = {}, Lhand = {}, Rshoulder = {}, Relbow = {}, Rhand = {}, Lbuttock = {}, Lknee = {}, Lfoot = {}, Rbuttock = {}, Rknee = {}, Rfoot = {};

		Head = Camera::WorldToScreen(EngineInstance->GetCameraCache().POV, Head3d);
		neck = Camera::WorldToScreen(EngineInstance->GetCameraCache().POV, neck3d);
		pelvis = Camera::WorldToScreen(EngineInstance->GetCameraCache().POV, pelvis3d);
		Lshoulder = Camera::WorldToScreen(EngineInstance->GetCameraCache().POV, Lshoulder3d);
		Lelbow = Camera::WorldToScreen(EngineInstance->GetCameraCache().POV, Lelbow3d);
		Lhand = Camera::WorldToScreen(EngineInstance->GetCameraCache().POV, Lhand3d);
		Rshoulder = Camera::WorldToScreen(EngineInstance->GetCameraCache().POV, Rshoulder3d);
		Relbow = Camera::WorldToScreen(EngineInstance->GetCameraCache().POV, Relbow3d);
		Rhand = Camera::WorldToScreen(EngineInstance->GetCameraCache().POV, Rhand3d);
		Lbuttock = Camera::WorldToScreen(EngineInstance->GetCameraCache().POV, Lbuttock3d);
		Lknee = Camera::WorldToScreen(EngineInstance->GetCameraCache().POV, Lknee3d);
		Lfoot = Camera::WorldToScreen(EngineInstance->GetCameraCache().POV, Lfoot3d);
		Rbuttock = Camera::WorldToScreen(EngineInstance->GetCameraCache().POV, Rbuttock3d);
		Rknee = Camera::WorldToScreen(EngineInstance->GetCameraCache().POV, Rknee3d);
		Rfoot = Camera::WorldToScreen(EngineInstance->GetCameraCache().POV, Rfoot3d);

		Vector3 campos = Vector3(EngineInstance->GetCameraCache().POV.Location.X, EngineInstance->GetCameraCache().POV.Location.Y, EngineInstance->GetCameraCache().POV.Location.Z);
		float distance = (Vector3::Distance(campos, Head3d) / 100.0f);
		if (distance < 0)
			continue;
		std::wstring wdistance = config.Distance ? L"[" + std::to_wstring((int)distance) + L"m]" : L"";
		if (distance > config.MaxDistance)
			continue;
		float deltaZ = (Head3d.z - campos.z) / 100;
		if (deltaZ > 100.f) {
			continue;
		}
		if ((Head.x - neck.x) > 500)
			continue;

		if (!Head.IsZero() && !Lhand.IsZero() && !Rhand.IsZero() && !neck.IsZero() && !Lshoulder.IsZero() && !Lelbow.IsZero() && !Rshoulder.IsZero()
			&& !Relbow.IsZero() && !Lbuttock.IsZero() && !Lknee.IsZero() && !Lfoot.IsZero()) {
			DrawText(Rfoot.x, Rfoot.y, wdistance, "Verdana", config.FontSize, config.TextColour, CentreCentre);
			FilledLine(Head.x, Head.y, neck.x, neck.y, 1, Colour(255, 255, 255));
			FilledLine(neck.x, neck.y, pelvis.x, pelvis.y, 1, Colour(255, 255, 255));
			FilledLine(Lshoulder.x, Lshoulder.y, neck.x, neck.y, 1, Colour(255, 255, 255));
			FilledLine(Lelbow.x, Lelbow.y, Lshoulder.x, Lshoulder.y, 1, Colour(255, 255, 255));
			FilledLine(Lhand.x, Lhand.y, Lelbow.x, Lelbow.y, 1, Colour(255, 255, 255));

			FilledLine(Rshoulder.x, Rshoulder.y, neck.x, neck.y, 1, Colour(255, 255, 255));
			FilledLine(Relbow.x, Relbow.y, Rshoulder.x, Rshoulder.y, 1, Colour(255, 255, 255));
			FilledLine(Rhand.x, Rhand.y, Relbow.x, Relbow.y, 1, Colour(255, 255, 255));

			FilledLine(Lbuttock.x, Lbuttock.y, pelvis.x, pelvis.y, 1, Colour(255, 255, 255));
			FilledLine(Lknee.x, Lknee.y, Lbuttock.x, Lbuttock.y, 1, Colour(255, 255, 255));
			FilledLine(Lfoot.x, Lfoot.y, Lknee.x, Lknee.y, 1, Colour(255, 255, 255));

			FilledLine(Rbuttock.x, Rbuttock.y, pelvis.x, pelvis.y, 1, Colour(255, 255, 255));
			FilledLine(Rknee.x, Rknee.y, Rbuttock.x, Rbuttock.y, 1, Colour(255, 255, 255));
			FilledLine(Rfoot.x, Rfoot.y, Rknee.x, Rknee.y, 1, Colour(255, 255, 255));
		}
	}
	
}