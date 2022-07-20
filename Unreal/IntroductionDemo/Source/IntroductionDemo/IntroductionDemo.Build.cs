// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class IntroductionDemo : ModuleRules
{
	public IntroductionDemo(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
