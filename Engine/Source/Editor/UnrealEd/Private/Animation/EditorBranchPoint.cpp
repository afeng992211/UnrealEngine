// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

/*=============================================================================
	AnimMontage.cpp: Montage classes that contains slots
=============================================================================*/ 

#include "UnrealEd.h"



UEditorBranchPoint::UEditorBranchPoint(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

	BranchIndex = INDEX_NONE;
}

void UEditorBranchPoint::InitBranchPoint(int BranchIndexIn)
{
	BranchIndex = BranchIndexIn;
	if(UAnimMontage* Montage = Cast<UAnimMontage>(AnimObject))
	{
		if(Montage->BranchingPoints.IsValidIndex(BranchIndex))
		{
			BranchingPoint = Montage->BranchingPoints[BranchIndex];
		}
	}
}

bool UEditorBranchPoint::ApplyChangesToMontage()
{
	if(UAnimMontage* Montage = Cast<UAnimMontage>(AnimObject))
	{
		if(Montage->BranchingPoints.IsValidIndex(BranchIndex))
		{
			BranchingPoint.OnChanged(BranchingPoint.GetTime());
			Montage->BranchingPoints[BranchIndex] = BranchingPoint;
			return true;
		}
	}

	return false;
}
