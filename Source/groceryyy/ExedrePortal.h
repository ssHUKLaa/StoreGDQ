#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExedrePortal.generated.h"

UCLASS()
class EXEDRE_API AExedrePortal : public AActor
{
    GENERATED_UCLASS_BODY()

    protected:
    virtual void BeginPlay() override;

    public:
    virtual void Tick(float DeltaTime) override;

    //Status of the Portal (being visualized by the player or not)
    UFUNCTION(BlueprintPure, Category = "Exedre|Portal")
        bool IsActive();

    UFUNCTION(BlueprintCallable, Category = "Exedre|Portal")
        void SetActive(bool NewActive);

    //Render target to use to display the portal
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Exedre|Portal")
        void ClearRTT();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Exedre|Portal")
        void SetRTT(UTexture* RenderTexture);

    UFUNCTION(BlueprintNativeEvent, Category = "Exedre|Portal")
        void ForceTick();

    //Target of where the portal is looking
    UFUNCTION(BlueprintPure, Category = "Exedre|Portal")
        AActor* GetTarget();

    UFUNCTION(BlueprintCallable, Category = "Exedre|Portal")
        void SetTarget(AActor* NewTarget);

    //Helpers
    UFUNCTION(BlueprintCallable, Category = "Exedre|Portal")
        bool IsPointInFrontOfPortal(FVector Point, FVector PortalLocation, FVector PortalNormal);

    UFUNCTION(BlueprintCallable, Category = "Exedre|Portal")
        bool IsPointCrossingPortal(FVector Point, FVector PortalLocation, FVector PortalNormal);

    UFUNCTION(BlueprintCallable, Category = "Exedre|Portal")
        void TeleportActor(AActor* ActorToTeleport);

    protected:
    UPROPERTY(BlueprintReadOnly)
        USceneComponent* PortalRootComponent;

    private:
    bool bIsActive;

    AActor* Target;

    //Used for Tracking movement of a point
    FVector LastPosition;
    bool    LastInFront;
};