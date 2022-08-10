// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TU5 : ModuleRules
{
	public TU5(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
