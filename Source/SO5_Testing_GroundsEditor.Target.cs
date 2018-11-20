// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class SO5_Testing_GroundsEditorTarget : TargetRules
{
	public SO5_Testing_GroundsEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("SO5_Testing_Grounds");
	}
}
