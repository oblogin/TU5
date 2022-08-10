// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/Critter.h"

// Sets default values
ACritter::ACritter()
{
	PrimaryActorTick.bCanEverTick = false;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
	
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(GetRootComponent());
	Camera->SetRelativeLocation(FVector(-300.f, 0.f, 300.f));
	Camera->SetRelativeRotation(FRotator(-45.f, 0.f, 0));
}

// Called when the game starts or when spawned
void ACritter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACritter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACritter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("Move Forward / Backward", this, &ACritter::MoveForwardBackward);
	InputComponent->BindAxis("Move Right / Left", this, &ACritter::MoveRightLeft);
	InputComponent->BindAxis("Move Up / Down", this, &ACritter::MoveUpDown);
}

void ACritter::MoveForwardBackward(float Value)
{
	FHitResult OutSweepHitResult;
	AddActorLocalOffset(GetActorForwardVector() * Value * Speed * GetWorld()->GetDeltaSeconds(), true, &OutSweepHitResult);
}

void ACritter::MoveRightLeft(float Value)
{
	FHitResult OutSweepHitResult;
	AddActorLocalOffset(GetActorRightVector() * Value * Speed * GetWorld()->GetDeltaSeconds(), true, &OutSweepHitResult);
}

void ACritter::MoveUpDown(float Value)
{
	FHitResult OutSweepHitResult;
	AddActorLocalOffset(GetActorUpVector() * Value * Speed * GetWorld()->GetDeltaSeconds(), true, &OutSweepHitResult);
}



