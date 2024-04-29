// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class WarriorAIProject : ModuleRules
{
	public WarriorAIProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "UMG", "AIModule", "GameplayTasks" });
        
		PublicIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "./") });
	}
}
