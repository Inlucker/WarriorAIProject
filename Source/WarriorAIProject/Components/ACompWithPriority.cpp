// Fill out your copyright notice in the Description page of Project Settings.


#include "ACompWithPriority.h"

int UACompWithPriority::GetPriority() const
{
	return priority;
}

void UACompWithPriority::SetPriority(int newPriority)
{
	priority = newPriority;
}
